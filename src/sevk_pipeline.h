#pragma once

#include "sevk_device.h"

#include <string>
#include <vector>

namespace sevk
{
    struct PipelineConfigInfo 
    {
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineViewportStateCreateInfo viewportInfo;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
 
    };
    

    class SevkPipeline
    {
    public:
        SevkPipeline(
            SevkDevice &device,
            const std::string vertex_file_path, 
            const std::string fragment_file_path, 
            const PipelineConfigInfo& configInfo
        );

        ~SevkPipeline();

        SevkPipeline(const SevkPipeline&) = delete;
        void operator =(const SevkPipeline) = delete;

        static PipelineConfigInfo defaultPipelineconfigInfo(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string& file_path);

        void createGraphicsPipeline(
            const std::string vertex_file_path, 
            const std::string fragment_file_path, 
            const PipelineConfigInfo& configInfo
        );

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        SevkDevice& sevkDevice;  // aggregation, the sevkDevice cant exist out of the class
        VkPipeline graphicsPipeline;
        VkShaderModule vertexShaderModule;
        VkShaderModule fragmentShaderModule;
    };
} 
