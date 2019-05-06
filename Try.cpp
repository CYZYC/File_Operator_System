#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <dirent.h>
#include <direct.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
  string dirName1;
  cout << "Input1:";
  cin >> dirName1;
  cout << opendir(dirName1.c_str()) << endl;
  if(opendir(dirName1.c_str()) == 0) {
    cout << "Success!" << endl;
  }
  else{
    cout << "Fail!" << endl;
  }

  cout << "Input2:";
  string dirName2;
  cin >> dirName2;
  if (_mkdir(dirName2.c_str()) == 0) {
    cout << "Success!" << endl;
  }
  else{
    cout << "Fail!" << endl;
  }
  system("pause");
  return 0;
}
