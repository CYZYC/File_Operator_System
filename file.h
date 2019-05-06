#ifndef _FILE_H
#define _FILE_H
#include <direct.h>
#include <errno.h>
#include <io.h>
#include <string.h>
#include <windows.h>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ios;
using std::setiosflags;
using std::setw;
using std::string;

class FileOperate {
 public:
  int BuildDirectory();
  int EnterDirectory();
  int DeleteDirectory();
  int ShowDirectory_content();
  int ShowDirectory_Name();
  int CopyDiretory();
  int FindDiretory();

  int BuildFile();
  int EnterFile();
  int DeleteFile();
  int ShowFile();
  // int CopyFileW();
};

void dir(string);
bool CopyFolder(LPCTSTR lpszFromPath, LPCTSTR lpszToPath);
bool DeleteFolder(LPCTSTR lpszPath);

int FileOperate::BuildDirectory() {
  cout << "输入创建文件夹的位置及名称（例：D:\\test）：";
  // string dirName = "D:\\test";
  string dirName;
  getchar();
  getline(cin, dirName);
  if (_mkdir(dirName.c_str()) == 0) {
    cout << "文件夹"
         << "'" << dirName << "'"
         << "创建成功！" << endl;
  } else {
    cout << "文件夹"
         << "'" << dirName << "'"
         << "创建失败！" << endl
         << "Error " << errno << " : " << strerror(errno) << endl;
  }
  return 0;
}

/* int FileOperate::DeleteDirectory() {
  string dirName;
  cout << "输入需要删除的文件夹位置及名称（例：D:\\test）：";
  getchar();
  getline(cin, dirName);
  if (rmdir(dirName.c_str()) == 0) {
    cout << "文件夹"
         << "'" << dirName << "'"
         << "删除成功！" << endl;
  } else {
    cout << "文件夹"
         << "'" << dirName << "'"
         << "删除失败！" << endl;
  }
} */

int FileOperate::DeleteDirectory() {
  string dirName;
  cout << "输入需要删除的文件(夹)位置及名称（例：D:\\test）：";
  getchar();
  getline(cin, dirName);
  dirName = dirName + '\0';
  if (DeleteFolder(dirName.c_str()) == true) {
    cout << "文件(夹)"
         << "'" << dirName << "'"
         << "删除成功！" << endl;
  } else {
    cout << "文件(夹)"
         << "'" << dirName << "'"
         << "删除失败！"
         << "    "
         << "Error " << errno << " : " << strerror(errno) << endl
         << "正在进行其他尝试，请稍后..." << endl;
    if (rmdir(dirName.c_str()) == 0) {
      cout << "文件(夹)"
           << "'" << dirName << "'"
           << "删除成功！" << endl;
    } else {
      cout << "文件(夹)"
           << "'" << dirName << "'"
           << "删除失败！"
           << "    "
           << "Error " << errno << " : " << strerror(errno) << endl;
    }
  }

  return 0;
}

bool DeleteFolder(LPCTSTR lpszPath) {
  SHFILEOPSTRUCT FileOp;
  ZeroMemory((void *)&FileOp, sizeof(SHFILEOPSTRUCT));

  FileOp.fFlags = FOF_ALLOWUNDO;  //放入回收站  //FOF_NOCONFIRMATION;
  FileOp.hNameMappings = NULL;
  FileOp.hwnd = NULL;
  FileOp.lpszProgressTitle = NULL;
  FileOp.pFrom = lpszPath;
  FileOp.pTo = NULL;
  FileOp.wFunc = FO_DELETE;

  return SHFileOperation(&FileOp) == 0;
}

int FileOperate::FindDiretory() {
  string dirName;
  cout << "输入需要检验是否存在的文件(夹)位置及名称（例：D:\\test）：";
  getchar();
  getline(cin, dirName);
  if (_access(dirName.c_str(), 0) == -1) {
    cout << "文件(夹)"
         << "'" << dirName << "'"
         << "不存在！" << endl
         << "Error " << errno << " : " << strerror(errno) << endl;
  } else {
    cout << "文件(夹)"
         << "'" << dirName << "'"
         << "存在！" << endl;
  }
  return 0;
}

int FileOperate::ShowDirectory_content() {
  string dirName;
  cout << "文件夹位置及名称（例：D:\\test）：";
  getchar();              // 消除回车符
  getline(cin, dirName);  // 获取整行文件名（避免空格）
  // cin >> dirName;      // 若文件名有空格则报错
  cout << endl;
  dir(dirName);
  return 0;
}

void dir(string dirName) {
  long hFile = 0;
  struct _finddata_t fileInfo;
  string pathName, exdName;
  // \\* 代表要遍历所有的类型
  if ((hFile = _findfirst(pathName.assign(dirName).append("\\*").c_str(),
                          &fileInfo)) == -1) {
    return;
  }
  cout << setiosflags(ios::left) << setw(24) << "文件名" << setw(7) << "Normal"
       << setw(7) << "Read" << setw(7) << "Hid" << setw(7) << "System"
       << setw(7) << "Dir" << setw(7) << "Arch" << setw(15) << "文件大小"
       << setw(20) << "       创建时间" << endl
       << endl;
  do {
    cout << setiosflags(ios::left) << setw(24) << fileInfo.name << setw(7)
         << (fileInfo.attrib & _A_NORMAL ? " Y" : " N") << setw(7)
         << (fileInfo.attrib & _A_RDONLY ? " Y" : " N") << setw(7)
         << (fileInfo.attrib & _A_HIDDEN ? " Y" : " N") << setw(7)
         << (fileInfo.attrib & _A_SYSTEM ? " Y" : " N") << setw(7)
         << (fileInfo.attrib & _A_SUBDIR ? " Y" : " N") << setw(7)
         << (fileInfo.attrib & _A_ARCH ? " Y" : " N") << setw(15)
         << fileInfo.size << setw(20) << ctime(&fileInfo.time_create) << endl;
  } while (_findnext(hFile, &fileInfo) == 0);
  _findclose(hFile);
  return;
}

int FileOperate::ShowDirectory_Name() {
  cout << "当前文件夹目录为：";
  cout << getcwd(NULL, 100) << endl;
  return 0;
}

int FileOperate::EnterDirectory() {
  string dirName;
  cout << "目标文件夹的位置及名称（例：D:\\test）：";
  getchar();
  getline(cin, dirName);
  // ChangeDriver(dirName);
  if (_chdir(dirName.c_str()) == 0) {
    cout << "成功进入目标文件夹！" << endl;
  } else {
    cout << "进入目标文件夹失败！" << endl
         << "Error " << errno << " : " << strerror(errno) << endl;
  }
  ShowDirectory_Name();
}

/* int FileOperate::CopyFileW() {
  string source, result;
  cout << "源文件位置及名称（例：D:\\test）：";
  getchar();
  getline(cin, source);
  cout << "目标文件位置及名称（例：D:\\test）：";
  getchar();
  getline(cin, result);
  CopyFile(
      source.c_str(), result.c_str(),
      FALSE);  //目标已经存在，不拷贝（True）并返回False;覆盖目标（false）；
  if (CopyFile(source.c_str(), result.c_str(), FALSE) != 0) {
    cout << "复制文件成功！" << endl;
  } else {
    cout << "复制文件失败！ "
         << "Error:" << strerror(errno) << endl;
  }
} */

int FileOperate::CopyDiretory() {
  string FromPath, ToPath;
  cout << "请输入复制源文件(夹)位置及名称（例：D:\\test）：";
  getchar();
  getline(cin, FromPath);
  cout << "请输入复制目标文件夹位置及名称（例：D:\\test）：";
  getline(cin, ToPath);
  FromPath = FromPath + '\0';
  ToPath = ToPath + '\0';
  if (CopyFolder(FromPath.c_str(), ToPath.c_str()) == true) {
    cout << "复制文件(夹)成功！" << endl;
  } else {
    cout << "复制文件(夹)失败！" << endl
         << "Error " << errno << " : " << strerror(errno) << endl;
  }
  return 0;
}

bool CopyFolder(LPCTSTR lpszFromPath, LPCTSTR lpszToPath) {
  SHFILEOPSTRUCT FileOp;
  ZeroMemory((void *)&FileOp, sizeof(SHFILEOPSTRUCT));

  FileOp.fFlags = FOF_NOCONFIRMATION;
  FileOp.hNameMappings = NULL;
  FileOp.hwnd = NULL;
  FileOp.lpszProgressTitle = NULL;
  FileOp.pFrom = lpszFromPath;
  FileOp.pTo = lpszToPath;
  FileOp.wFunc = FO_COPY;

  return SHFileOperation(&FileOp) == 0;
}

#endif
