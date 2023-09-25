/*
 * @Author: Mr.Gan 
 * @Date: 2023-09-17 21:32:27 
 * @Last Modified by: Mr.Gan
 * @Last Modified time: 2023-09-18 10:34:45
 */

/*
union 成员共享内存地址。允许在内存的同一位置存储不同的数据类型  即具有相同的起始地址 但是不同变量的地址长度可以不同
这意味着，一个union变量可以存储多种类型的数据，但是同一时间只能存储其中一种类型的数据。
示例：
*/
#include <iostream>
#include<cstring>
using namespace std;

union myUnion {
  int i;
  float f;
  char str[20];
};

int main() {
  myUnion u;
  u.i = 10;
  cout << "Value of i: " << u.i << endl;

  u.f = 3.14;
  cout << "Value of f: " << u.f << endl;

  strcpy(u.str, "Hello");
  cout << "Value of str: " << u.str << endl;

  return 0;
}
