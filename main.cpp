#include <stdlib.h>
#include <iostream>

#include "welcome.cpp"

using std::cin;
using std::cout;
using std::endl;


int main() {
  start();
  cin.get();
  system("cls");
  welcome();
  ChooseMenu();
  cin.get();
  cin.get();
  return 0;
}
