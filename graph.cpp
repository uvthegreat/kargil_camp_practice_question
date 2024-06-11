#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>> n >> m;
    vector<vector<int>> adjMat( n , vector<int> (n));
    for(int i=0;i<m; i++){
        int x,y;
        cin>>x>>y;
        adjMat[x][y] =1;
    }



   

    return 0;
}