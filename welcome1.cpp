#include <stdlib.h>
#include <iostream>
#include <windows.h>

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

void welcome1() {
  gotoxy(10, 0);
  cout
      << "*-------------------------------------------------------------------*"
      << endl;

  gotoxy(10, 1);
  cout << "|                         �ļ�����ϵͳ                              |"
       << endl;

  gotoxy(10, 2);
  cout
      << "|-------------------------------------------------------------------|"
      << endl;

  gotoxy(10, 3);
  cout << "|                   ��01  �����ļ���                                |"
       << endl;

gotoxy(10, 4);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 5);
  cout << "|                   ��02  ��ʾ��ǰ�ļ���Ŀ¼                        |"
       << endl;

       gotoxy(10, 6);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 7);
  cout << "|                   ��03  ����Ŀ���ļ���Ŀ¼                        |"
       << endl;

gotoxy(10, 8);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 9);
  cout << "|                   ��04  ɾ���ļ��У��ļ���                        |"
       << endl;

       gotoxy(10, 10);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 11);
  cout << "|                   ��05  ��ʾ�ļ�������                            |"
       << endl;

gotoxy(10, 12);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 13);
  cout << "|                   ��06  ����ļ��У��ļ����Ƿ����                |"
       << endl;

       gotoxy(10, 14);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 15);
  cout << "|                   ��07  �����ļ��У��ļ���                        |"
       << endl;

       gotoxy(10, 16);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 17);
  cout << "|                   ��08  �����Ļ                                  |"
       << endl;

       gotoxy(10, 18);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 18);
  cout
      << "*-------------------------------------------------------------------*"
      << endl;

  gotoxy(0, 20);
}

void welcome2() {
  color(10);
  gotoxy(10, 1);
  cout
      << "*-------------------------------------------------------------------*"
      << endl;

  gotoxy(10, 2);
  cout << "|                           �ļ�����ϵͳ                            |"
       << endl;

       gotoxy(10, 3);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 4);
  cout
      << "|-------------------------------------------------------------------|"
      << endl;

gotoxy(10, 5);
      cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 6);
  cout << "|      ��01  �����ļ���               ��02  ��ʾ��ǰ�ļ���Ŀ¼      |"
       << endl;

gotoxy(10, 7);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 8);
  cout << "|      ��03  ����Ŀ���ļ���Ŀ¼       ��04  ɾ���ļ�(��)            |"
       << endl;

gotoxy(10, 9);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 10);
  cout << "|      ��05  ��ʾ�ļ�������           ��06  ����ļ�(��)�Ƿ����    |"
       << endl;

gotoxy(10, 11);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 12);
  cout << "|      ��07  �����ļ�(��)             ��08  �����Ļ                |"
       << endl;

       gotoxy(10, 13);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 14);
  cout
      << "*-------------------------------------------------------------------*"
      << endl;

  gotoxy(0, 15);
}

int main(){
  welcome2();
  system("pause");
  return 0;
}
