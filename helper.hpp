#pragma once
#include <vector>
#include <string>
#include "json.hpp"

namespace HelperNs{
    enum class Direction{
        Right,
        Down,
        Left,
        Up
    };

    struct EntityStruct
    {
        int x;
        int y;
        char sprite;
        Direction dir;
        std::string type;
    };
}

class HelperCl {
    public:
        std::vector<HelperNs::EntityStruct> ToEntityStruct(const nlohmann::json& data);
};