// accepted
#include <bits/stdc++.h>

using namespace std;

int findServed(vector<int> BuildingCount, vector<int> routerLocation, vector<int> routerRange)
{
    int locationSize = routerLocation.size(), n = BuildingCount.size();

    vector<vector<int>> arrRange;
    for (int i = 0; i < locationSize; i++)
    {
        int location = routerLocation[i];
        int range = routerRange[i];
        int start = max(0, location - range);
        int end = min(n, location + range + 1);
        arrRange.push_back({start, end});
    }

    vector<int> dummy(n, 0);
    for (int i = 0; i < arrRange.size(); i++)
    {
        int start = arrRange[i][0];
        int end = arrRange[i][1];
        dummy[start]++;
        dummy[end]--;
    }

    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += dummy[i];
        if (sum >= BuildingCount[i])
            ans++;
    }

    return ans;
}

int main()
{
    vector<int> headCount = {2, 3, 3, 1, 5, 6};
    vector<int> routerLocation = {2, 4, 1};
    vector<int> routerRange = {2, 4, 3};

    int ans = findServed(headCount, routerLocation, routerRange);
    cout << "given value is : " << ans << endl;

    return 0;
}
