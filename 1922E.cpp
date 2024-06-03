#include <bits/stdc++.h>

using namespace std;
string to_binary(long long int y)
{
    string s = bitset<64>(y).to_string();
    const auto loc1 = s.find('1');

    if (loc1 != string::npos)
        return s.substr(loc1);

    return "0";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        long long int x;
        cin >> x;
        vector<int> ans;
        long long int i = 0;
        while (pow(2, i) <= x)
        {
            i++;
        }
        if (pow(2, i) > x)
        {
            i--;
        }
        for (int temp = 0; temp < i; temp++)
        {
            ans.push_back(temp);
        }
        long long int y = x - pow(2, i);
        string yBinary = to_binary(y);
        int len = yBinary.length();

        for (int j = 0; j < len; j++)
        {
            if (yBinary[j] == '1')
            {
                ans.push_back(len - j - 1);
            }
        }

        cout << ans.size() << endl;

        for (auto var : ans)
        {
            cout << var << " ";
        }
        cout << endl;
    }
    return 0;
}