#pragma once
#include <vector>
#include <string>
#include "json.hpp"

namespace HelperNs {
struct EntityStruct
{
        int x;
        int y;
        char sprite;
        int dir;
        std::string type;
        EntityStruct(int y, int x, char sprite, int dir, std::string type)
            : y(y), x(x), sprite(sprite), dir(dir), type(type) {}
    };
}

class HelperCl {
    public:
        std::vector<HelperNs::EntityStruct> ToEntityStruct(const nlohmann::json& data);
};