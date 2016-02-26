//
// Created by Will on 12/17/15.
//

#include <iostream>
using namespace std;

const int maxnum = 1000000000;

int main() {
    int f[100][100];
    int d[100];
    bool flag[100];
    int i, j, k, n, m, min, x, y, z;

    cin>>n>>m;              // n点  m边
    for (i = 1; i <= n; i++) {       //初始化
        for (j = 1; j <= n; j++)
            if (i == j)
                f[i][j] = 0;
            else {
                f[i][j] = maxnum;
                f[j][i] = maxnum;
            }
        d[i] = maxnum;
        flag[i] = false;
    }

    for (i = 1; i <= m; i++) {   //读数
        cin>>x>>y>>z;
        f[x][y] = z;
        //f[y][x] = z;       有向图和无向图的差别
    }
    for (i = 2; i <= n; i++)
        if (f[1][i] != maxnum)
            d[i] = f[1][i];


    flag[1] = true;                   //默认1为源点;
    d[1] = 0;


    for (i = 1; i < n; i++) {
        min = maxnum;
        for(j = 1; j <= n; j++)
            if(!flag[j] && d[j] < min) {
                k = j;
                min = d[k];
            }
        flag[k] = true;
        for (j = 1; j <= n; j++)
            if (!flag[j] && d[j] > d[k] + f[k][j])
                d[j] = d[k] +f[k][j];
    }

    for (i = 1; i <= n; i++)
        cout<<d[i]<<" ";
    return 0;

}