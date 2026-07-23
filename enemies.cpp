#include "helper.hpp"
#include "enemies.hpp"
#include <vector>

void Enemies::TurretShooting(const HelperNs::EntityStruct& turretEntity, std::vector<HelperNs::EntityStruct>& entities, const int timer) {
    if (timer % 5 == 0){
        entities.push_back(HelperNs::EntityStruct(turretEntity.y, turretEntity.x, '-', turretEntity.dir, "bullet"));
    }
}

void Enemies::StandardBullet(const std::vector<std::vector<char>>& map, HelperNs::EntityStruct& bulletEntity, std::vector<HelperNs::EntityStruct>& entities) {
    if (bulletEntity.dir == 0){bulletEntity.x++;}
    if (bulletEntity.dir == 1){bulletEntity.y++;}
    if (bulletEntity.dir == 2){bulletEntity.x--;}
    if (bulletEntity.dir == 3){bulletEntity.y--;}
}