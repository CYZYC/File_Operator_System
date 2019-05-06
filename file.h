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
  cout << "���봴���ļ��е�λ�ü����ƣ�����D:\\test����";
  // string dirName = "D:\\test";
  string dirName;
  getchar();
  getline(cin, dirName);
  if (_mkdir(dirName.c_str()) == 0) {
    cout << "�ļ���"
         << "'" << dirName << "'"
         << "�����ɹ���" << endl;
  } else {
    cout << "�ļ���"
         << "'" << dirName << "'"
         << "����ʧ�ܣ�" << endl
         << "Error " << errno << " : " << strerror(errno) << endl;
  }
  return 0;
}

/* int FileOperate::DeleteDirectory() {
  string dirName;
  cout << "������Ҫɾ�����ļ���λ�ü����ƣ�����D:\\test����";
  getchar();
  getline(cin, dirName);
  if (rmdir(dirName.c_str()) == 0) {
    cout << "�ļ���"
         << "'" << dirName << "'"
         << "ɾ���ɹ���" << endl;
  } else {
    cout << "�ļ���"
         << "'" << dirName << "'"
         << "ɾ��ʧ�ܣ�" << endl;
  }
} */

int FileOperate::DeleteDirectory() {
  string dirName;
  cout << "������Ҫɾ�����ļ�(��)λ�ü����ƣ�����D:\\test����";
  getchar();
  getline(cin, dirName);
  dirName = dirName + '\0';
  if (DeleteFolder(dirName.c_str()) == true) {
    cout << "�ļ�(��)"
         << "'" << dirName << "'"
         << "ɾ���ɹ���" << endl;
  } else {
    cout << "�ļ�(��)"
         << "'" << dirName << "'"
         << "ɾ��ʧ�ܣ�"
         << "    "
         << "Error " << errno << " : " << strerror(errno) << endl
         << "���ڽ����������ԣ����Ժ�..." << endl;
    if (rmdir(dirName.c_str()) == 0) {
      cout << "�ļ�(��)"
           << "'" << dirName << "'"
           << "ɾ���ɹ���" << endl;
    } else {
      cout << "�ļ�(��)"
           << "'" << dirName << "'"
           << "ɾ��ʧ�ܣ�"
           << "    "
           << "Error " << errno << " : " << strerror(errno) << endl;
    }
  }

  return 0;
}

bool DeleteFolder(LPCTSTR lpszPath) {
  SHFILEOPSTRUCT FileOp;
  ZeroMemory((void *)&FileOp, sizeof(SHFILEOPSTRUCT));

  FileOp.fFlags = FOF_ALLOWUNDO;  //�������վ  //FOF_NOCONFIRMATION;
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
  cout << "������Ҫ�����Ƿ���ڵ��ļ�(��)λ�ü����ƣ�����D:\\test����";
  getchar();
  getline(cin, dirName);
  if (_access(dirName.c_str(), 0) == -1) {
    cout << "�ļ�(��)"
         << "'" << dirName << "'"
         << "�����ڣ�" << endl
         << "Error " << errno << " : " << strerror(errno) << endl;
  } else {
    cout << "�ļ�(��)"
         << "'" << dirName << "'"
         << "���ڣ�" << endl;
  }
  return 0;
}

int FileOperate::ShowDirectory_content() {
  string dirName;
  cout << "�ļ���λ�ü����ƣ�����D:\\test����";
  getchar();              // �����س���
  getline(cin, dirName);  // ��ȡ�����ļ���������ո�
  // cin >> dirName;      // ���ļ����пո��򱨴�
  cout << endl;
  dir(dirName);
  return 0;
}

void dir(string dirName) {
  long hFile = 0;
  struct _finddata_t fileInfo;
  string pathName, exdName;
  // \\* ����Ҫ�������е�����
  if ((hFile = _findfirst(pathName.assign(dirName).append("\\*").c_str(),
                          &fileInfo)) == -1) {
    return;
  }
  cout << setiosflags(ios::left) << setw(24) << "�ļ���" << setw(7) << "Normal"
       << setw(7) << "Read" << setw(7) << "Hid" << setw(7) << "System"
       << setw(7) << "Dir" << setw(7) << "Arch" << setw(15) << "�ļ���С"
       << setw(20) << "       ����ʱ��" << endl
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
  cout << "��ǰ�ļ���Ŀ¼Ϊ��";
  cout << getcwd(NULL, 100) << endl;
  return 0;
}

int FileOperate::EnterDirectory() {
  string dirName;
  cout << "Ŀ���ļ��е�λ�ü����ƣ�����D:\\test����";
  getchar();
  getline(cin, dirName);
  // ChangeDriver(dirName);
  if (_chdir(dirName.c_str()) == 0) {
    cout << "�ɹ�����Ŀ���ļ��У�" << endl;
  } else {
    cout << "����Ŀ���ļ���ʧ�ܣ�" << endl
         << "Error " << errno << " : " << strerror(errno) << endl;
  }
  ShowDirectory_Name();
}

/* int FileOperate::CopyFileW() {
  string source, result;
  cout << "Դ�ļ�λ�ü����ƣ�����D:\\test����";
  getchar();
  getline(cin, source);
  cout << "Ŀ���ļ�λ�ü����ƣ�����D:\\test����";
  getchar();
  getline(cin, result);
  CopyFile(
      source.c_str(), result.c_str(),
      FALSE);  //Ŀ���Ѿ����ڣ���������True��������False;����Ŀ�꣨false����
  if (CopyFile(source.c_str(), result.c_str(), FALSE) != 0) {
    cout << "�����ļ��ɹ���" << endl;
  } else {
    cout << "�����ļ�ʧ�ܣ� "
         << "Error:" << strerror(errno) << endl;
  }
} */

int FileOperate::CopyDiretory() {
  string FromPath, ToPath;
  cout << "�����븴��Դ�ļ�(��)λ�ü����ƣ�����D:\\test����";
  getchar();
  getline(cin, FromPath);
  cout << "�����븴��Ŀ���ļ���λ�ü����ƣ�����D:\\test����";
  getline(cin, ToPath);
  FromPath = FromPath + '\0';
  ToPath = ToPath + '\0';
  if (CopyFolder(FromPath.c_str(), ToPath.c_str()) == true) {
    cout << "�����ļ�(��)�ɹ���" << endl;
  } else {
    cout << "�����ļ�(��)ʧ�ܣ�" << endl
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
