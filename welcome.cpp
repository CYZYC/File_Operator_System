/*
1��ʵ���ļ��д�����ɾ�������롣
2��ʵ�ֵ�ǰ�ļ����µ��������С�
3��ʵ���ļ��������ļ��п������ļ��п���ָ��ȿ���������������Ŀ¼���ļ�����
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
  cout << "|                 ���ﻶӭʹ���ļ�����ϵͳ����                  |"
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

  cout << "����س�����ʼ..." << endl;
}

void welcome() {
  color(10);
  gotoxy(10, 1);
  cout
      << "*-------------------------------------------------------------------*"
      << endl;

  gotoxy(10, 2);
  cout
      << "|                           �ļ�����ϵͳ                            |"
      << endl;

  gotoxy(10, 3);
  cout
      << "|-------------------------------------------------------------------|"
      << endl;

  gotoxy(10, 4);
  cout << "|      ��01  �����ļ���               ��02  ��ʾ��ǰ�ļ���Ŀ¼      |"
       << endl;

  gotoxy(10, 5);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 6);
  cout << "|      ��03  ����Ŀ���ļ���Ŀ¼       ��04  ɾ���ļ�(��)            |"
       << endl;

  gotoxy(10, 7);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 8);
  cout << "|      ��05  ��ʾ�ļ�������           ��06  ����ļ�(��)�Ƿ����    |"
       << endl;

  gotoxy(10, 9);
  cout
      << "|                                                                   |"
      << endl;

  gotoxy(10, 10);
  cout << "|      ��07  �����ļ�(��)             ��08  �����Ļ                |"
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
    case 0:  // �˳�
      exit(0);
      break;
    case 1:  //�����ļ���
      Try.BuildDirectory();
      break;
    case 2:  //��ʾ��ǰ�ļ���Ŀ¼
      Try.ShowDirectory_Name();
      break;
    case 3:  //����Ŀ���ļ���Ŀ¼
      Try.EnterDirectory();
      break;
    case 4:  //ɾ���ļ���
      Try.DeleteDirectory();
      break;
    case 5:  //��ʾ�ļ�������
      Try.ShowDirectory_content();
      break;
    case 6:  //�����ļ����Ƿ����
      Try.FindDiretory();
      break;
    case 7:  //�����ļ��У��ļ���
      Try.CopyDiretory();
      break;
    case 8:  //�����Ļ
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
  cout << endl << "������˵����루��'0'�˳�����";
  int num;
  // if (cin.peek() == 'q') {  //����'q'�˳�
  //   exit(0);
  // }
  while (true) {
    cin >> num;
    if (cin.fail()) {  //�������������ж�
      cout << "�����������ʹ��������ԣ�" << endl;
      cin.clear();  //������״̬����Ϊ��Ч״̬
      cin.sync();   //����������е�δ����Ϣ
    } else {
      try {  //�޶���ŷ�Χ
        if (num < 0 || num > 8) {
          throw num;
        }
      } catch (int num) {
        std::cerr << "������ı�Ŵ������������룡" << endl;
        cout << endl << "������˵����루��'0'�˳�����";
        continue;
      }
      Switch_Menu(num);
    }
    cout << endl;
    cout << "������˵����루��'0'�˳�����";
  }
}
