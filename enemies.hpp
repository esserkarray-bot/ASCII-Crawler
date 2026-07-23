#pragma once
#include "helper.hpp"
#include <vector>

class Enemies {
    public:
        void TurretShooting(const HelperNs::EntityStruct& turretEntity, std::vector<HelperNs::EntityStruct>& entities, const int timer);
        void StandardBullet(const std::vector<std::vector<char>>& map, HelperNs::EntityStruct& bulletEntity, std::vector<HelperNs::EntityStruct>& entities);
};