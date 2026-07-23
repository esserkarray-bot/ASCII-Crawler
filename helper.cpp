#include "helper.hpp"
#include <vector>
#include "json.hpp"
#include <iostream>

std::vector<HelperNs::EntityStruct> HelperCl::ToEntityStruct(const nlohmann::json& data)
{
    std::vector<HelperNs::EntityStruct> entities;

    for (auto& entity : data)
    {
        entities.emplace_back(
            entity[0],
            entity[1],
            entity[2].get<std::string>()[0],
            entity[3],
            entity[4]
        );
    }

    return entities;
}