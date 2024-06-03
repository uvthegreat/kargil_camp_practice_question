#include <bits/stdc++.h>

using namespace std;

int minSwap(string str, int n)
{
    int countT = 0, countH = 0;
    int swap = INT_MAX;
    for (char ch : str)
    {
        if (ch == 'H')
            countH++;
        else
            countT++;
    }

    for (int i = 0; i < n; i++)
    {
        int tempSwap = 0;
        for (int j = i; j < i + countH; ++j)
        {
            if (str[j % n] == 'T')
                tempSwap++;
        }
        swap = min(swap, tempSwap);
    }

    return swap;
}

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans = minSwap(str, n);
    cout << ans << endl;

    return 0;
}