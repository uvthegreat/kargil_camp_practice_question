#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sum;
        vector<int> ans(n);

        for (int i = 0; i < m; i++)
        {
            sum.push({0, i});
        }

        for (int i = 0; i < n; i++)
        {
            pair<int, int> temp = sum.top();
            sum.pop();
            temp.first += heights[i];
            ans[i] = temp.second;
            sum.push(temp);
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}