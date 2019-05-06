#include <stdlib.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int input;
  /* while (true) {
    cin >> input;
    cout << "1:" << cin.fail() << "," << cin.good() << endl;
    if (cin.good() == true) {
      cout << "Right Type!" << endl;
      cout << "2:" << cin.fail() << "," << cin.good() << endl << endl;
      continue;
    } else {
      cout << "Wrong Type!" << endl;
      cout << "3:" << cin.fail() << "," << cin.good() << endl;
      cin.clear();  //将错误状态更改为有效状态
      cin.sync();   //清除缓冲区中的未读信息
      cout << "4:" << cin.fail() << "," << cin.good() << endl << endl;
    } */
  while (true) {
    cin >> input;
    if (cin.fail()) {
      cout << "wrong" << endl;
      cin.clear();
      cin.sync();
    } else {
      cout << "right" << endl;
    }
    cout << "over" << endl;
  }

  system("pause");
  return 0;
}
