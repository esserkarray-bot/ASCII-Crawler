#include "player.hpp"
#include <windows.h>
#include "helper.hpp"

void Player::Move(const std::vector<std::vector<char>>& map, HelperNs::EntityStruct& playerEntity){
    if (GetAsyncKeyState('D') & 0x8000){
    if (map[playerEntity.y][playerEntity.x + 1] == '.'){
        playerEntity.x++;
    }
}

if (GetAsyncKeyState('A') & 0x8000){
    if (map[playerEntity.y][playerEntity.x - 1] == '.'){
        playerEntity.x--;
    }
}

if (GetAsyncKeyState('W') & 0x8000){
    if (map[playerEntity.y - 1][playerEntity.x] == '.'){
        playerEntity.y--;
    }
}

if (GetAsyncKeyState('S') & 0x8000){
    if (map[playerEntity.y + 1][playerEntity.x] == '.'){
        playerEntity.y++;
    }
}
}