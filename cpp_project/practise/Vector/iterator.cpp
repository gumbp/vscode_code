#include <iostream>
#include <vector>
using namespace std;



int main()
{
    vector<char>::const_iterator p;
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    p = v.begin();
    char a;
    cout << "输入字符并按#结束输入" << endl;
    cin >> a;
    while(a!='#'){
        v.push_back(a);
       cin >> a;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << *p<<endl;
        p++;
    }
    return 0;
}
