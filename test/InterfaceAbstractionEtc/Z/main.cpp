#include "DWindow.hpp"
#include "DModel.hpp"

int main(int ac, char **av)
{
    IWindow* window = new DWindow();
    IModel* model = new DModel("my model");
    window->draw(model);
}