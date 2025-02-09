#pragma once

#include <string>
#include <vector>

namespace sevk
{
    class SevkPipeline
    {
    public:
        SevkPipeline(const std::string vertex_file_path, const std::string fragment_file_path);

    private:
        static std::vector<char> readFile(const std::string& file_path);

        void createGraphicsPipeline(const std::string vertex_file_path, const std::string fragment_file_path);
    };
} 
