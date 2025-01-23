
#include "Registry.hpp"
#include "Entity.hpp"

/// @brief handling entities
Entity Registry::createEntity() {
  if (!killedEntities.empty()) {
        Entity tmp = killedEntities.back();
        killedEntities.pop_back();
        return tmp;
    } else {
        ++_entitiesCount;
        return Entity(_entitiesCount - 1, *this);
    }
};

Entity Registry::entityFromIndex(std::size_t idx) {
    return Entity(idx, *this);
};

void Registry::killEntity(Entity const &e) {
    killedEntities.push_back(e);
    for (const auto &f: componentsRemoves) {
        f(*this, e);
    }
};

/// @brief handling components

size_t Registry::addSystem(std::function<void(Registry &)> f) {
    systems.push_back(f);
    return systems.size() - 1;
};

void Registry::removeSystem(size_t idx) {
    systems.erase(systems.begin() + idx);
};

void Registry::update() {
    for (auto &f: systems) {
        f(*this);
    }
};