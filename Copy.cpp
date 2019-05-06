#include <stdlib.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  char cmd[256];
  char path1[2000], path2[2000];
  cout << "输入复制文件的源路径：";
  cin >> path1;
  cout << "输入复制文件的目标路径：";
  cin >> path2;
  system(cmd, "xcopy %s%s", path1, path2);
  system("pause");
  return 0;
}
