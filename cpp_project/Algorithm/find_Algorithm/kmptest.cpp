#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> get_kmp(vector<int> &next, string &s)
{
    int j = 0;
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        while (j > 0 && s[i] != s[j])
        {
            j = next[j];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        next[i + 1] = j;
    }
    return next;
}

int main()
{
    string s = "abaaabb";
    vector<int> next(s.length() + 1, 0);
    next = get_kmp(next, s);
    for (int i = 0; i < next.size();i++)
    {
        cout << next[i] << ' ';
    }
    return 0;
}