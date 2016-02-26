//
// Created by Will on 11/14/15.
//

#include <iostream>
using namespace std;

void qsort (int a[], int l, int r) {
    int i,j,mid;
    i=l; j=r; mid=a[(l+r)>>1];

    while (i<=j) {
        while (a[i]<mid) i++;
        while (a[j]>mid) j--;
        if (i<=j) {
            a[0]= a[i]; a[i]=a[j]; a[j]=a[0];
            i++; j--;
        }
    }

    if (i<r) qsort(a,i,r);
    if (j>l) qsort(a,l,j);
}

int main(){

    char *a="0123";
    cout<<a[2]<<endl;








    /*
    int c=(numeric_limits<int>::min)();
    cout<<c<<endl;
    */
/*
    int a[1000];
    int i,n;

    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];

    qsort (a,1,n);

    for (i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;


*/



    return 0;
}
