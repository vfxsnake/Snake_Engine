#include "first_app.h"
#include "GLFW/glfw3.h"

namespace sevk
{
    void FirstApp::Run()
    {
        while (!sevkWindow.ShouldClose())
        {
            glfwPollEvents();
        }
        
    }
}