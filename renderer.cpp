#include "helper.hpp"
#include "renderer.hpp"
#include <iostream>
#include <vector>

std::vector<std::vector<char>> Renderer::ToMatrix(const std::vector<std::string>& rows){
    //i dont even know how to explain this bullshit
    //basically i loop through each character in a string vector then put them in a char matrix
    std::vector<std::vector<char>> matrix;
    std::vector<char> row;
    for (const std::string& i : rows){
        for (int j = 0; j < rows[0].size(); j++){
            row.push_back(i.at(j));
        }
        matrix.push_back(row);
        row.clear();
    }
    return matrix;
}

void Renderer::AddEntities(std::vector<std::vector<char>>& map, std::vector<HelperNs::EntityStruct>& entities){
    for (const HelperNs::EntityStruct& i : entities){
        map[i.y][i.x] = i.sprite;
    }
}

void Renderer::PrintMap(std::vector<std::vector<char>>& map){
    //step 1:
    //convert it into a string
    std::string formatted_level;
    for (const std::vector<char>& i : map) {
        for (const char& j : i) {
            formatted_level += j;
        }
        formatted_level += '\n';
    }
    //step 2:
    //print it
    std::cout << "\033c";
    std::cout << formatted_level;
}