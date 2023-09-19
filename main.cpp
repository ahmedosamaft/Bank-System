#include <iostream>
#include "model/Client.h"
int main() {
  Model::Client ahmed(1,"A","S","A","X");

  std::cout << ahmed.getPassword();
}
