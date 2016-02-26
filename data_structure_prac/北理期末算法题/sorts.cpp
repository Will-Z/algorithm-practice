//
// Created by Will on 11/7/15.
//

#include "sorts.h"

int main()
{
    int n;
    int a[1000],b[1000];

    read(n,a);

    //qsort (a,1,n);            //测试快排[Will]版
    //qsort1(a,1,n);            //测试快排[严蔚敏]版
    //HeapSort (a,n);           //测试堆排
    // MergeSort(a,b,1,n);      //测试归并[严蔚敏]版
    msort(a,1,n);               //测试归并[Will]版


    /*                          //测试向上调整 AdjustUp
    BuildMaxHeap(a,n);
    a[n+1]=100;
    AdjustUp(a, n+1);
    print(a,n+1);
    */


    print (a,n);
    return 0;

}