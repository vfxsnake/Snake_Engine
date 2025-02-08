#include "first_app.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
    sevk::FirstApp app{};

    try
    {
        app.Run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
}