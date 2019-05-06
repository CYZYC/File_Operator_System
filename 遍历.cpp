#include <io.h>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// struct _finddata_t
//         {
//              unsigned attrib;
//              time_t time_create;
//              time_t time_access;
//              time_t time_write;
//              _fsize_t size;
//              char name[_MAX_FNAME];
//         };

void dir(string path) {
  long hFile = 0;
  struct _finddata_t fileInfo;
  string pathName;
  // \\* 代表要遍历所有的类型
  if ((hFile = _findfirst(pathName.assign(path).append("\\*").c_str(),
                          &fileInfo)) == -1) {
    return;
  }
  cout << setiosflags(ios::left) << setw(24) << "文件名" << setw(7) << "Normal"
       << setw(7) << "Read" << setw(7) << "Hid" << setw(7) << "Sys" << setw(7)
       << "Dir" << setw(7) << "Arc" << setw(15) << "文件大小" << setw(20)
       << "       创建时间" << endl
       << endl;
  do {
    /* File attribute constants for _findfirst() */
    //  #define _A_NORMAL       0x00    /* Normal file - No read/write
    //  restrictions */ #define _A_RDONLY       0x01    /* Read only file */
    //  #define _A_HIDDEN       0x02    /* Hidden file */
    //  #define _A_SYSTEM       0x04    /* System file */
    //  #define _A_SUBDIR       0x10    /* Subdirectory */
    //  #define _A_ARCH         0x20    /* Archive file */

    //判断文件的属性是文件夹还是文件
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

int main() {
  //要遍历的目录
  string path = "C:\\Users\\ChenYuze\\Desktop\\FileOperateSystem";
  dir(path);
  system("pause");
  return 0;
}
