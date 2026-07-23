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
        bool dead;
        std::string type;
        EntityStruct(int y, int x, char sprite, int dir, std::string type, bool dead)
            : y(y), x(x), sprite(sprite), dir(dir), type(type), dead(dead) {}
        bool operator==(const EntityStruct& other) const
        {
        return x == other.x &&
               y == other.y &&
               sprite == other.sprite &&
               dir == other.dir &&
               type == other.type &&
               dead == other.dead;
        }
    };
}

class HelperCl {
    public:
        std::vector<HelperNs::EntityStruct> ToEntityStruct(const nlohmann::json& data);
        void lose();
};