#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<char> line;
    cout<<"Enter a line of text"<<endl;
    char next;
    cin.get(next);
    while(next!='\n'){
        line.push_back(next);
        cin.get(next);
    }
    vector<char>::const_iterator where;
    where = find(line.begin(), line.end(), 'e');
    vector<char>::const_iterator p;
    cout << "before first 'e' " << endl;
    for (p = line.begin(); p != where;p++){
        cout << *p;
    }
    cout << endl;
    cout << "after the first e" << endl;
    for (p = where; p != line.end();p++){
        cout << *p;
    }
    cout << endl;
    cout <<  "The end" << endl;
    return 0;
}
