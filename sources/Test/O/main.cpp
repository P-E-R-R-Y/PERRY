#include "EWindow.hpp"
#include "EModel.hpp"

int main(int ac, char **av)
{
    EWindow* window = new EWindow();
    EModel* model = new EModel("my model");
    window->draw(model);
}