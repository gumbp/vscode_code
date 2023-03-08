#include  <iostream>
using namespace std;
#include  <string.h>
template <class T>

//初始类型
T Max(T a,T b){
    return a > b?a : b;
}


//重载类型
char *Max(char *a,char *b){
    return (strcmp(a, b) > 0 ? a : b);
}



int main(){
    cout << "Max(2,8) is  " << Max(2, 8) << endl;
    cout << "Max(\"ABCD,ABAB\")  is  " << Max("ABCD", "ABAB") << endl;
    return 0;
}