#include "helper.hpp"
#include "enemies.hpp"
#include <vector>

void Enemies::TurretShooting(const HelperNs::EntityStruct& turretEntity, std::vector<HelperNs::EntityStruct>& entities, const int timer) {
    if (timer % 5 == 0){
        //add a bullet to the entities every 5 frames
        if (turretEntity.dir == 0) entities.push_back(HelperNs::EntityStruct(turretEntity.y, turretEntity.x+1, '*', turretEntity.dir, "bullet", false));
        if (turretEntity.dir == 1) entities.push_back(HelperNs::EntityStruct(turretEntity.y+1, turretEntity.x, '*', turretEntity.dir, "bullet", false));
        if (turretEntity.dir == 2) entities.push_back(HelperNs::EntityStruct(turretEntity.y, turretEntity.x-1, '*', turretEntity.dir, "bullet", false));
        if (turretEntity.dir == 3) entities.push_back(HelperNs::EntityStruct(turretEntity.y-1, turretEntity.x, '*', turretEntity.dir, "bullet", false));
    }
}

void Enemies::StandardBullet(const std::vector<std::vector<char>>& map, HelperNs::EntityStruct& bulletEntity) {
    //move the bullet depending on its direction
    if (bulletEntity.dir == 0){bulletEntity.x++;}
    if (bulletEntity.dir == 1){bulletEntity.y++;}
    if (bulletEntity.dir == 2){bulletEntity.x--;}
    if (bulletEntity.dir == 3){bulletEntity.y--;}

    // handle wall collisions
    if (map[bulletEntity.y][bulletEntity.x] == '#'){bulletEntity.dead = true;}
}