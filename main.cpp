#include "json.hpp"
#include "renderer.hpp"
#include "helper.hpp"
#include "player.hpp"
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>
#include <iostream>

int main(){
    using nlohmann::json;

    // read level data
    std::ifstream f("leveldata.json");
    json file;
    f >> file;

    int current_level = 0;

    Renderer render;
    HelperCl helper;
    Player player;

    //convert leveldata into matrix
    std::vector<std::vector<char>> map = render.ToMatrix(file["levels"][current_level]["data"]);
    std::vector<std::vector<char>> default_map = map;
    
    //get entities
    std::vector<HelperNs::EntityStruct> entities = helper.ToEntityStruct(file["levels"][current_level]["entities"]);

    while (! (GetAsyncKeyState(VK_ESCAPE) & 0x8000)){
        //reset map
        map = default_map;

        //entity handling
        for (HelperNs::EntityStruct& i : entities){
            if  (i.type == "player"){
                player.Move(map, i);
            } 
        }

        //add entities to map and print
        render.AddEntities(map, entities);
        render.PrintMap(map);
        std::this_thread::sleep_for(std::chrono::milliseconds(225)); //wait before drawing next frame
    }
}