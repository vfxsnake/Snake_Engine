#pragma once

#include <string>
#include <vulkan/vulkan.h>

namespace sevk
{
    class SevkWindow
    {
    public:
        SevkWindow(int width, int height, std::string name);
        ~SevkWindow();
        
        // deleting the copy constructor and copy operator from the class 
        SevkWindow(const SevkWindow &) = delete;
        SevkWindow &operator =(const SevkWindow &)= delete;

        bool ShouldClose();
        void CreateWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    private:
        void initWindow();
        
        const int _width;
        const int _height;
        std::string _name;
        // forward declaration of Glfw window
        struct GLFWwindow *_windowPtr;
    };
}