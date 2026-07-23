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
            entity[4],
            entity[5]
        );
    }

    return entities;
}
void lose(){
    std::cout << 
                 "__   __   ____   _    _    _____   _____   ______  \n"
              << "\\ \\ / /  / __ \\ | |  | |  |  __ \\ |_   _| |  ____|\n"
              << " \\ V /  | |  | || |  | |  | |  | |  | |   | |__   \n"
              << "  | |   | |  | || |  | |  | |  | |  | |   |  __|  \n"
              << "  | |   | |__| || |__| |  | |__| | _| |_  | |____ \n"
              << "  |_|    \\____/  \\____/   |_____/ |_____| |______|\n";
}