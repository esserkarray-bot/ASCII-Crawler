#include "helper.hpp"
#include <vector>
#include "json.hpp"
#include <iostream>

std::vector<HelperNs::EntityStruct> HelperCl::ToEntityStruct(const nlohmann::json& data)
    {
        std::vector<HelperNs::EntityStruct> entities;

        for (auto& entity : data)
        {
            for (auto& i : entity.items())
            {
                HelperNs::EntityStruct e;

                e.y = i.value()[0];
                e.x = i.value()[1];
                e.sprite = i.value()[2].get<std::string>()[0];
                e.dir = i.value()[3];
                e.type = i.value()[4];

                entities.push_back(e);
            }
        }
        for (auto& i : data) {
            std::cout << i.dump() << "\n";
        }

        return entities;
    }