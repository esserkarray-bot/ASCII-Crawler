#include "helper.hpp"
#include <vector>
#include "json.hpp"
#include <iostream>

std::vector<HelperNs::EntityStruct> HelperCl::ToEntityStruct(const nlohmann::json& data)
{
    std::vector<HelperNs::EntityStruct> entities;

    for (auto& entity : data)
    {
        HelperNs::EntityStruct e;

        e.y = entity[0];
        e.x = entity[1];
        e.sprite = entity[2].get<std::string>()[0];
        e.dir = entity[3];
        e.type = entity[4];

        entities.push_back(e);
    }

    return entities;
}