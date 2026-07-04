#include "code.hpp"
#include <iostream>

class MyCustomComponent : public Component {
public:
  void execute() override {
    std::cout << "[Component] Hello from inside the dynamically loaded shared "
                 "library!"
              << std::endl;
  }
};

extern "C" Component *create_component() { return new MyCustomComponent(); }
