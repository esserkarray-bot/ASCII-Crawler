#pragma once
#include "helper.hpp"
#include <vector>

class Player{
    public:
        void Move(const std::vector<std::vector<char>>& map, HelperNs::EntityStruct& playerEntity);
};