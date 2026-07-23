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

bool Player::collide(const HelperNs::EntityStruct& playerEntity, const std::vector<HelperNs::EntityStruct>& entities){
    std::vector<std::string> deadly_tags = {
        "bullet",
        "turret"
    };

    for (const HelperNs::EntityStruct& i : entities){
        if (std::find(deadly_tags.begin(), deadly_tags.end(), i.type) != deadly_tags.end()){
            if (i.x == playerEntity.x && i.y == playerEntity.y){
                return true;
            }
        }
    }

    return false;
}