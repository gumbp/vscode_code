#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<float> sample(3, 5.1); // 向量sample的元素初始化为3个5
    vector<int> intv;
    int temp, i;
    cout << "enter number and press 0 to end " << endl;
    cin >> temp;
    if (temp == 0)
    {
        return 0;
    }
    while (temp != 0)
    {
        intv.push_back(temp);
        cin >> temp;
    }


    cout << "there are" << intv.size() << "elements in intv" << endl;

    for ( i = 0; i < intv.size(); i++){
        cout << intv[i] << "  ";

    }
    cout<<*intv.begin();
    cout << endl;

    cout << "sample element is" << endl;
    for (int i = 0; i < sample.size();i++){
        cout << sample[i]<<"  ";
    }
    cout << endl;
    return 0;
}