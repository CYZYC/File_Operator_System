// #include <dir.h>
// #include <stdio.h>
// #include <string.h>

// using namespace std;

// char *current_directory(char *path)
// {
//    strcpy(path, "X:\\");      /* fill string with form of response: X:\ */
//    path[0] = 'A' + getdisk();    /* replace X with current drive letter */
//    getcurdir(0, path+3);  /* fill rest of string with current directory */
//    return(path);
// }

// int main(void)
// {
//    char curdir[29];

//    current_directory(curdir);
//    printf("The current directory is %s\n", curdir);

//    return 0;
// }
#include <dir.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// stack<int> dec2bin(int num){
//         stack<int> bin;
//         while(num!=0){
//             bin.push(num % 2);
//             num /= 2;
//         }
//         return bin;
//     }
void change(int x) {
  for (int i = 31; i > -1; i--) {
    printf("%c", x & (1 << i) ? '1' : '0');
  }
  printf("\n");
}

int main() {
  change(GetLogicalDrives());
  system("pause");
  return 0;
}
