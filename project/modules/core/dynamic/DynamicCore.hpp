#include <vector>
#include <string>

#include "../../../interfaces/core/ICore.hpp"
#include "../../../interfaces/graphic/GraphicSharedLoader.hpp"

class DynamicCore: public ICore {
    public:
        DynamicCore(std::vector<std::string> list): _graphic(list[0]) {
          std::cout << "DynamicCore::DynamicCore implemented" << std::endl;
        }

        ~DynamicCore() {
            std::cout << "DynamicCore::~DynamicCore implemented" << std::endl;
        }

    private:
        GraphicSharedLoader _graphic;
};