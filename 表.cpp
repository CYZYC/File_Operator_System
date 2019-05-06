#include <stdlib.h>
#include <windows.h>
#include <iostream>

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

int draw() {
  int i, j, k;
  for (i = 20; i <= 60; i++) {
    for (j = 5; j <= 25; j += 5) {
      gotoxy(i, j);
      color(12);
      printf("-");
    }
  }
  for (i = 20; i <= 60; i += 10) {
    for (j = 5; j < 25; j += 5) {
      for (k = j + 1; k < j + 5; k++) {
        gotoxy(i, k);
        printf("|");
      }
    }
  }
  gotoxy(15, 2);
  color(2);
}

int map() {
  int i, j;
  for (j = 16; j <= 62; j += 2) {
    for (i = 4; i <= 26; i++) {
      gotoxy(j, i);
      if (i == 4 || i == 26 || j == 16 || j == 62) {
        color(11);
        printf("■");
      }
    }
  }
  gotoxy(30, 2);
  color(6);
  printf("Interesting Tetris");
  gotoxy(68, 8);
  color(3);
  gotoxy(68, 10);
  color(1);
  printf("The next tetris:");
  gotoxy(68, 12);
  color(2);
  for (i = 0; i < 16; i++) printf("*");
  gotoxy(68, 20);
  for (i = 0; i < 16; i++) printf("*");
  return 0;
}

void menu()
{
	int i, j;
	color(6);
	gotoxy(36, 4);
	printf("主角团及利斯塔联盟");
	color(2);
	for (i = 12; i <= 78; i++)
	{
		for (j = 6; j <= 22; j++)
		{
			if (i == 12 || i == 78 || j == 6 || j == 22)
			{
				gotoxy(i, j);
				printf("*");
			}
		}
	}
	color(5);
	gotoxy(20, 10);
	printf("1.显示所有成员");
	gotoxy(50, 10);
	printf("2.增加成员");
	gotoxy(20, 14);
	printf("3.删除成员");
	gotoxy(50, 14);
	printf("4.修改成员");
	gotoxy(20, 18);
	printf("5.成员排名");
	gotoxy(50, 18);
	printf("6.查找成员");
}

int main() {
  // map();
  // draw();
  menu();
  cin.get();
  cin.get();
  return 0;
}
