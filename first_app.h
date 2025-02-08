#pragma once

#include "sevk_window.h"

namespace sevk
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        void Run();
    
    private:
        SevkWindow sevkWindow{WIDTH, HEIGHT, "hellos vulkan!!!!!"};
    };
}