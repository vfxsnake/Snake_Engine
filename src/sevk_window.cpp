#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdexcept>

#include "sevk_window.h"

namespace sevk
{
    SevkWindow::SevkWindow(int width, int height, std::string name) : _width(width), _height(height), _name(name)
    {
        initWindow();
    }

    SevkWindow::~SevkWindow()
    {
        glfwDestroyWindow(_windowPtr);
        glfwTerminate();
    }
    void SevkWindow::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        _windowPtr = glfwCreateWindow(_width, _height, _name.c_str(), nullptr, nullptr);
    }

    bool SevkWindow::ShouldClose()
    {
        return glfwWindowShouldClose(_windowPtr);
    }

    void SevkWindow::CreateWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
    {
        if (glfwCreateWindowSurface(instance, _windowPtr, nullptr, surface) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create window surface");
        }
    }
}

