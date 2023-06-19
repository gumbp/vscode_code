#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main()
{
    list<char> line;
    vector<char> word(3);
    line.push_back('S');
    line.push_back('T');
    line.push_back('L');
    // list<char>::iterator q = line.begin();
    copy(line.begin(), line.end(), word.begin());
    vector<char>::iterator p = word.begin();
    while (p != word.end())
    {
        cout << *p++;
    }

    cout << endl;
    return 0;
}