/*
1、实现文件夹创建、删除、进入。
2、实现当前文件夹下的内容罗列。
3、实现文件拷贝和文件夹拷贝（文件夹拷贝指深度拷贝，包括所有子目录和文件）。
*/

#include <windows.h>
#include <iostream>
#include "file.h"

using std::cin;
using std::cout;
using std::endl;

int color(int c) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
  return 0;
}

void gotoxy(int x, int y) {
  COORD pos;
  pos.X = x;
  pos.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void start() {
  color(10);
  gotoxy(10, 3);
  cout
      << "*-------------------------------------------------------------------*"
      << endl;

  gotoxy(10, 4);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 5);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 6);
  cout << "|                 ★★★欢迎使用文件管理系统★★★                  |"
       << endl;

  gotoxy(10, 7);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 8);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 9);
  cout
      << "*-------------------------------------------------------------------*"
      << endl;

  gotoxy(10, 12);
  cout << endl;

  cout << "输入回车键开始..." << endl;
}

void welcome() {
  color(10);
  gotoxy(10, 1);
  cout
      << "*-------------------------------------------------------------------*"
      << endl;

  gotoxy(10, 2);
  cout
      << "|                           文件管理系统                            |"
      << endl;

  gotoxy(10, 3);
  cout
      << "|-------------------------------------------------------------------|"
      << endl;

  gotoxy(10, 4);
  cout << "|      ★01  创建文件夹               ★02  显示当前文件夹目录      |"
       << endl;

  gotoxy(10, 5);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 6);
  cout << "|      ★03  进入目标文件夹目录       ★04  删除文件(夹)            |"
       << endl;

  gotoxy(10, 7);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 8);
  cout << "|      ★05  显示文件夹内容           ★06  检查文件(夹)是否存在    |"
       << endl;

  gotoxy(10, 9);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 10);
  cout << "|      ★07  拷贝文件(夹)             ★08  清空屏幕                |"
       << endl;

  gotoxy(10, 11);
  cout
      << "*-------------------------------------------------------------------*"
      << endl;

  gotoxy(0, 13);
}

void Switch_Menu(int num) {
  FileOperate Try;
  switch (num) {
    case 0:  // 退出
      exit(0);
      break;
    case 1:  //创建文件夹
      Try.BuildDirectory();
      break;
    case 2:  //显示当前文件夹目录
      Try.ShowDirectory_Name();
      break;
    case 3:  //进入目标文件夹目录
      Try.EnterDirectory();
      break;
    case 4:  //删除文件夹
      Try.DeleteDirectory();
      break;
    case 5:  //显示文件夹内容
      Try.ShowDirectory_content();
      break;
    case 6:  //检验文件夹是否存在
      Try.FindDiretory();
      break;
    case 7:  //复制文件夹（文件）
      Try.CopyDiretory();
      break;
    case 8:  //清空屏幕
      system("cls");
      welcome();
      Try.ShowDirectory_Name();
      break;
    default:
      break;
  }
}

void ChooseMenu() {
  FileOperate Try;
  Try.ShowDirectory_Name();
  cout << endl << "请输入菜单号码（按'0'退出）：";
  int num;
  // if (cin.peek() == 'q') {  //输入'q'退出
  //   exit(0);
  // }
  while (true) {
    cin >> num;
    if (cin.fail()) {  //输入数据类型判断
      cout << "输入数据类型错误！请重试！" << endl;
      cin.clear();  //将错误状态更改为有效状态
      cin.sync();   //清除缓冲区中的未读信息
    } else {
      try {  //限定编号范围
        if (num < 0 || num > 8) {
          throw num;
        }
      } catch (int num) {
        std::cerr << "您输入的编号错误！请重新输入！" << endl;
        cout << endl << "请输入菜单号码（按'0'退出）：";
        continue;
      }
      Switch_Menu(num);
    }
    cout << endl;
    cout << "请输入菜单号码（按'0'退出）：";
  }
}
