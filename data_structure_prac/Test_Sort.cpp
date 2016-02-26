//
// Created by Will on 12/12/15.
//


#include "Sort.h"
#include <iostream>
using namespace std;

int main () {
    int i;
    cin>>n;
    int *a = new int[n + 1]; // int *a = (int *) malloc ((n + 1) * sizeof (int));


    for (i = 1; i <= n; i++)
        cin>>a[i];
    cout<<endl;
    for (i = 1; i <= n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    msort(a, 1, n);
    for (i = 1; i <= n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}