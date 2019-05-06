#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

BOOL CopyFolder(LPCTSTR lpszFromPath, LPCTSTR lpszToPath) {
  SHFILEOPSTRUCT FileOp;
  ZeroMemory((void*)&FileOp, sizeof(SHFILEOPSTRUCT));

  FileOp.fFlags = FOF_NOCONFIRMATION;
  FileOp.hNameMappings = NULL;
  FileOp.hwnd = NULL;
  FileOp.lpszProgressTitle = NULL;
  FileOp.pFrom = lpszFromPath;
  FileOp.pTo = lpszToPath;
  FileOp.wFunc = FO_COPY;

  return SHFileOperation(&FileOp) == 0;
}

int main() {
  string a, b;
  cout << "input1:";
  cin >> a;
  cout << "input2:";
  cin >> b;
  CopyFolder(a.c_str(), b.c_str());
  system("pause");
  return 0;
}
