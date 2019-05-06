#include <direct.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string>

#include "file.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  // int _chdir( const char *dirname );
  cout << getcwd(NULL, 30) << endl;
  // char dirname[50];
  const char* p = "D:\\";
  _chdir(p);
  cout << getcwd(NULL, 30) << endl;
  FileOperate a;
  a.BuildDirectory();
  system("pause");
  return 0;
}
