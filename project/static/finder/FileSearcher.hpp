/**
 * @file FileSearcher.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup utility
 * @{
 */

#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <sys/stat.h>

/**
 * @brief class to help handling files when working with shared libraries 
 */
class FileSearcher {
    public:

        FileSearcher() = default;
        ~FileSearcher() = default;

        static void displayFiles(std::string folder) {
            struct stat _sb;
            std::string path;

            if (stat(folder.c_str(), &_sb) == 0) {
                for (const auto& entry : std::filesystem::directory_iterator(folder)) {
                    path = entry.path().string();

                    if (stat(path.c_str(), &_sb) == 0 && !(_sb.st_mode & S_IFDIR) && path.find(".so") != path.size())
                        std ::cout << path.substr(folder.size() + (folder.back() != '/')) << std::endl;
                }
            }
        }

        static void displayFiles(std::string folder, std::string extension) {
            struct stat _sb;
            std::string path;

            if (stat(folder.c_str(), &_sb) == 0) {
                for (const auto& entry : std::filesystem::directory_iterator(folder)) {
                    path = entry.path().string();
                    if (stat(path.c_str(), &_sb) == 0 && !(_sb.st_mode & S_IFDIR) && path.find("." + extension) != path.size())
                        std ::cout << path.substr(folder.size() + (folder.back() != '/')) << std::endl;
                }
            }
        }

        static std::vector<std::string> searchFiles(std::string folder) {
            struct stat _sb;
            std::string path;
            std::vector<std::string> res;

            if (stat(folder.c_str(), &_sb) == 0) {
                for (const auto& entry : std::filesystem::directory_iterator(folder)) {
                    path = entry.path().string();

                    if (stat(path.c_str(), &_sb) == 0 && !(_sb.st_mode & S_IFDIR))
                        res.push_back(path.substr(folder.size() + (folder.back() != '/')));
                }
            }
            for (int i = 0; i < res.size(); i++) {
                std::cout << "--------------------" << std::endl;
                std::cout << res[i] << std::endl;
                std::cout << "--------------------" << std::endl;
            }
            return res;
        }

        static std::vector<std::string> searchFiles(std::string folder, std::string extension) {
            struct stat _sb;
            std::string path;
            std::vector<std::string> res;

            if (stat(folder.c_str(), &_sb) == 0) {
                for (const auto& entry : std::filesystem::directory_iterator(folder)) {
                    path = entry.path().string();
                    if (stat(path.c_str(), &_sb) == 0 && !(_sb.st_mode & S_IFDIR) && path.find("." + extension) != path.npos)
                        res.push_back(path.substr(folder.size() + (folder.back() != '/')));
                }
            }
            
            return res;
        }

        typedef enum {
            SHARED_LIB,
            STATIC_LIB,
        } lib_e;

        static std::vector<std::string> searchSharedLibraries(std::string folder, bool sub_directory = false) {
            std::string extension;

            #if defined(__APPLE__)
                extension = "dylib";
            #elif defined(__linux__)
                extension = "so";
            #elif defined(_WIN32)
                extension = "dll";
            #endif

            return searchPathFiles(folder, extension, sub_directory);
        }

        static std::vector<std::string> searchPathFiles(std::string folder, std::string extension, bool sub_directory = false) {
            struct stat _sb;
            std::string path;
            std::vector<std::string> res;

            if (stat(folder.c_str(), &_sb) == 0) {
                for (const auto& entry : std::filesystem::directory_iterator(folder)) {
                    path = entry.path().string();
                    if (entry.is_directory() && !entry.is_symlink() && sub_directory) {
                        std::vector<std::string> tmp = searchPathFiles(path, extension);
                        res.insert(res.end(), tmp.begin(), tmp.end());
                    } else {
                        if (stat(path.c_str(), &_sb) == 0 && !(_sb.st_mode & S_IFDIR) && path.find("." + extension) != path.npos)
                            res.push_back(path);
                    }
                }
            }
            return res;
        }


    private:

    private:
};