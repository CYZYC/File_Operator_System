#include <stdlib.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  char cmd[256];
  char path1[2000], path2[2000];
  cout << "���븴���ļ���Դ·����";
  cin >> path1;
  cout << "���븴���ļ���Ŀ��·����";
  cin >> path2;
  system(cmd, "xcopy %s%s", path1, path2);
  system("pause");
  return 0;
}
