#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        stack<int> stack;
        for (int i = n - 1; i >= 0; i--)
        {
            if (stack.empty())
            {
                stack.push(v[i]);
            }
            if (v[i] >= stack.top())
            {
                stack.push(v[i]);
            }
            else
            {
                // int last = stack.top();
                // swap(v[i], last);
                // stack.pop();
                // stack.push(last);
                // for (i; i < n; i++)
                // {
                //     v[i] = stack.top();
                //     stack.pop();
                // }
                swap(v[i], v[i + 1]);
                while (!stack.empty())
                    stack.pop();
                break;
            }
        }
        if (stack.empty())
        {
            for (int i = 0; i < n; i++)
            {
                cout << v[i];
            }
        }
        else
            cout << -1;

        cout << endl;
    }

    return 0;
}