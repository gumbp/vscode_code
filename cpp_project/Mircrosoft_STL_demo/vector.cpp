// vector_erase.cpp
// compile with: /EHsc
#include <iostream>
#include <vector>

int main()
{
    using namespace std;
    vector<int> v1;
    vector<int>::iterator Iter;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 =";
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)
        cout << " " << *Iter;
    cout << endl;

    v1.erase(v1.begin());
    cout << "v1 =";
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)
        cout << " " << *Iter;
    cout << endl;

    v1.erase(v1.begin() + 1, v1.begin() + 2);
    cout << "v1 =";
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)
        cout << " " << *Iter;
    cout << endl;
}