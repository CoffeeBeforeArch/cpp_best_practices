// This program shows off RAII with memory allocation
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <memory>

// A simple object with only constructor and destructor
struct Resource{
  Resource(){ std::cout << "Resource object created!\n"; }
  ~Resource(){ std::cout << "Resource object destroyed!\n"; }
};

int main () {
  // If we use new/delete, the programmer manages the lifetime
  Resource *r1 = new Resource;

  // Some code here... (it can be easy to forget to free memory!)
  
  // Free the Resource
  delete r1;

  // If we use smart pointers, they get freed automatically when
  // the pointer goes out of scope
  std::unique_ptr<Resource> r2(new Resource);

  return 0;
}
