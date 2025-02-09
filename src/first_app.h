#pragma once

#include "sevk_window.h"
#include "sevk_pipeline.h"

namespace sevk
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        void Run();
    
    private:
        SevkWindow sevkWindow{WIDTH, HEIGHT, "hello vulkan!!!!!"};
        SevkPipeline sevkPipeline{"bin/shaders/simple_shader.vert.spv", "bin/shaders/simple_shader.frag.spv"};
    };
}