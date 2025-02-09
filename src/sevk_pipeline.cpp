#include "sevk_pipeline.h"

#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace sevk
{
    SevkPipeline::SevkPipeline(const std::string vertex_file_path, const std::string fragment_file_path)
    {
        createGraphicsPipeline(vertex_file_path, fragment_file_path);
    }

    void SevkPipeline::createGraphicsPipeline(const std::string vertex_file_path, const std::string fragment_file_path)
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
}