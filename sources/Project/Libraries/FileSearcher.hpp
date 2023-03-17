/**
 *
 * File: SearchLibrary.hpp
 * Created Date: Th Mar 2023
 * Project: PERRY
 * Author: Perry Chouteau
 *
 * Last Modified: Thu Mar 16 2023
 * Modified By: Perry Chouteau
 *
 * Copyright (c) 2023-2033 Perry Chouteau
 *
 **/

#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <sys/stat.h>

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


        static std::vector<std::string> searchPathFiles(std::string folder, std::string extension) {
            struct stat _sb;
            std::string path;
            std::vector<std::string> res;

            if (stat(folder.c_str(), &_sb) == 0) {
                for (const auto& entry : std::filesystem::directory_iterator(folder)) {
                    path = entry.path().string();
                    if (stat(path.c_str(), &_sb) == 0 && !(_sb.st_mode & S_IFDIR) && path.find("." + extension) != path.npos)
                        res.push_back(path);
                }
            }
            return res;
        }


    private:

    private:
};