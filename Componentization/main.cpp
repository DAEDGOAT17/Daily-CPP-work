#include "code.hpp"
#include <dlfcn.h> // Required for dynamic loading functions
#include <iostream>

int main() {
  std::cout << "[Manager] Starting up Component Manager...\n";

  // 1. Open the shared library
  void *handle = dlopen("./libmy_component.so", RTLD_LAZY);
  if (!handle) {
    std::cerr << "Failed to load library: " << dlerror() << "\n";
    return 1;
  }

  // 2. Locate the symbol
  CreateComponentFunc create_func =
      (CreateComponentFunc)dlsym(handle, "create_component");
  if (!create_func) {
    std::cerr << "Failed to find the symbol: " << dlerror() << "\n";
    dlclose(handle);
    return 1;
  }

  // 3. Instantiate and execute
  Component *my_node = create_func();
  my_node->execute();

  // 4. Cleanup
  delete my_node;
  dlclose(handle);
  return 0;
}
