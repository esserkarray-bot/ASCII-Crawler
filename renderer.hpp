#pragma once

#include "helper.hpp"
#include <vector>
#include <string>

class Renderer{
    public:
        std::vector<std::vector<char>> ToMatrix(const std::vector<std::string>& rows);
        void AddEntities(std::vector<std::vector<char>>& map, std::vector<HelperNs::EntityStruct>& entities);
        void PrintMap(std::vector<std::vector<char>>& map);
};