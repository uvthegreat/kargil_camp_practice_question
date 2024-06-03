#include <bits/stdc++.h>

using namespace std;

int solve(string s, int k, int n)
{
    int pair_count = 0;
    int single_count = 0;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i]]++;
    for (auto it : mp)
    {
        pair_count += it.second / 2;
        single_count += it.second % 2;
    }
    int ans = 2 * (pair_count / k);
    single_count += 2 * (pair_count % k);
    if (single_count >= k)
        return ans + 1;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        int ans = solve(s, k, n);
        cout << ans << endl;
    }

    return 0;
}