#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main()
{   int  n, v;
    const int p = 3000;
    cin >> n >> v;
    vector<int> weight(n + 1, 0);
    vector<int> value(n + 1, 0);
    int best[p][p]={0};//initialization has a problem that the default value are not all  zero. So why?
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (j < weight[i])
            {
                best[i][j] = best[i - 1][j];
            }
            else
            {
                best[i][j] = max(best[i - 1][j], best[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    cout << best[n][v];
    return 0;
}
