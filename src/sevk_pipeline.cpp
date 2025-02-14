#include "sevk_pipeline.h"

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace sevk
{
    SevkPipeline::SevkPipeline(
        SevkDevice &device,
        const std::string vertex_file_path, 
        const std::string fragment_file_path, 
        const PipelineConfigInfo& configInfo
    ) : sevkDevice(device)
    {
        createGraphicsPipeline(vertex_file_path, fragment_file_path, configInfo);
    }

    SevkPipeline::~SevkPipeline() {}

    void SevkPipeline::createGraphicsPipeline(
        const std::string vertex_file_path, 
        const std::string fragment_file_path, 
        const PipelineConfigInfo& configInfo
    )
    {
        auto vertex_code = readFile(vertex_file_path);
        auto fragment_code = readFile(fragment_file_path);
        
        // just to check that it actually work
        std::cout << "Vertex shader code size: " << vertex_code.size() << "\n";
        std::cout << "Fragment shader code size: " << fragment_code.size() << "\n";
    }

    std::vector<char> SevkPipeline::readFile(const std::string& file_path)
    {
        std::cout << "opening " << file_path << "\n";
        std::filesystem::path abs_path = std::filesystem::absolute(file_path);
        std::cout << "opening  absolute path: " << abs_path << "\n";
        
        std::ifstream file{file_path, std::ios::ate | std::ios::binary};

        if (!file.is_open())
        {
            std::cout << abs_path << "\n";
            throw std::runtime_error("failed to open file ");
        }
        std::cout << "file opened: " << file_path << "\n";

        size_t file_size = static_cast<size_t>(file.tellg());
        file.seekg(0, std::ios::beg);

        std::vector<char> buffer(file_size);
        file.read(buffer.data(), 0);
        file.close();

        return buffer;
    }

    void SevkPipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
    {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(sevkDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create shader module");
        }
    }

    PipelineConfigInfo SevkPipeline::defaultPipelineconfigInfo(uint32_t width, uint32_t height)
    {
        PipelineConfigInfo configInfo{};
        return configInfo;
    }
}