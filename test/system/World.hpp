class World {
  private:
    // Store systems either by type or as a flat list
    std::unordered_map<std::type_index, std::unique_ptr<System>> systems;

  public:
    // Add a new system (ensures one system per type)
    template <typename T, typename... Args>
    size_t addSystem(Args&&... args) {
        return addSystem(std::make_unique<T>(std::forward<Args>(args)...));
    }

    // Add an existing system object
    template <typename T>
    size_t addSystem(std::unique_ptr<T> existingSystem) {
        static_assert(std::is_base_of<System, T>::value, "T must derive from System");
        auto type = std::type_index(typeid(T));
        if (systems.find(type) != systems.end()) {
            throw std::runtime_error("System of this type already exists!");
            return -1;
        }

        systems[type] = std::move(existingSystem);
        return systems.size();
    }

    // Remove a system by type
    template <typename T>
    void removeSystem() {
        auto type = std::type_index(typeid(T));
        systems.erase(type);
    }

    // Update all systems
    void update() {
        for (auto& [type, system] : systems) {
            system->lambda();
        }
    }
};