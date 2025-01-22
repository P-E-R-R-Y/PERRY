//entity
class Entity {
public:
  Entity() = delete; 
  int getId() const { return id; }

  friend class Registry;

private:
  explicit Entity(int id) : id(id) {}
  int id;
};

