//
// Created by Will on 11/7/15.
//

//[Y] Yan weimin's Version
//[Will] Will's Version

#ifndef DATA_STRUCTURE_PRAC_SORTS_H
#define DATA_STRUCTURE_PRAC_SORTS_H


#include <stdio.h>
#include <iostream>
using namespace std;


//------------------------------------------------------------------------------
void read(int &n,int a[]){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
}

void print(int a[],int n){
    for (int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

//------------------------------------------------------------------------------    qsort1 [Y]


int Partition(int a[],int low, int high){
    int pivot = a[low];
    while (low<high){
        while (low<high && a[high]>=pivot) high--;
        a[low]=a[high];
        while (low<high && a[low]<=pivot) low++;
        a[high]=a[low];
    }
    a[low]=pivot;

    return low;
}

void qsort1(int a[], int low, int high){
    if(low<high){
        int pivotpos=Partition(a,low,high);
        qsort1(a,low,pivotpos-1);
        qsort1(a,pivotpos+1,high);
    }
}

//--------------------------------------------------------------------------- qsort [Will]
void qsort (int a[],int l,int r){
    int i,j,mid;
    i=l; j=r; mid=a[(l+r) >> 1];

    do{
        while (a[i]<mid) i++;
        while (a[j]>mid) j--;
        if(i<=j){
            a[0]=a[i]; a[i]=a[j]; a[j]=a[0];
            i++; j--;
        }
    }while (i<=j);
    if(i<r) qsort(a,i,r);
    if(l<j) qsort(a,l,j);

}
//---------------------------------------------------------------------------------HeapSort[Y]
void AdjustDown (int a[],int k,int len){
    a[0]=a[k];
    for (int i=k*2;i<=len;i*=2){
        if (i<len && a[i]<a[i+1])
            i++;
        if(a[0]>=a[i]) break;           //MaxHeap
        else{
            a[k]=a[i];
            k=i;
        }
    }
    a[k]=a[0];
}

void BuildMaxHeap (int a[], int len){
    for (int i=len/2;i>=1;i--)
        AdjustDown(a,i,len);
}

void HeapSort(int a[],int len){      //
    BuildMaxHeap (a,len);
    for(int i=len;i>=1;i--){
        int x;
        x=a[i]; a[i]=a[1]; a[1]=x;
        AdjustDown (a,1,i-1);
    }

}
//----------------------------------------------------------------------------AdjustUp 堆在末尾插入后向上调整   大根堆
void AdjustUp(int a[],int k){
    a[0]=a[k];
    int i=k/2;
    while (i>0 && a[i]<a[0]){
        a[k]=a[i];
        k=i;
        i=i/2;
    }
    a[k]=a[0];
}

//--------------------------------------------------------------------------Mergesort[Y]

void Merge (int a[],int b[], int low, int mid, int high){
    int i,j,k;
    for(k=low;k<=high;k++)
        b[k]=a[k];
    for(i=low,j=mid+1,k=i;i<=mid && j<=high;k++){
        if(b[i]<=b[j])
            a[k]=b[i++];
        else
            a[k]=b[j++];
    }
    while (i<=mid) a[k++]=b[i++];
    while (j<=high) a[k++]=b[j++];
}


void MergeSort (int a[], int b[], int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(a,b,low,mid);
        MergeSort(a,b,mid+1,high);
        Merge(a,b,low,mid,high);
    }
}
//-----------------------------------------------------------------------msort[Will]
void msort(int a[], int low, int high){
    int i,j,mid,k;
    int b[1000];

    if (high==low)
        return;
    mid=(low+high)/2;
    msort(a,low,mid);
    msort(a,mid+1,high);

    i=low; j=mid+1; k=low;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k]=a[i]; k++; i++;
        }
        else{
            b[k]=a[j]; k++; j++;
        }
    }
    while(i<=mid){
        b[k]=a[i]; i++; k++;
    }
    while(j<=high){
        b[k]=a[j]; j++; k++;
    }
    for(i=low;i<=high;i++)
        a[i]=b[i];
}

//---------------------------------------------------------------------------------

#endif //DATA_STRUCTURE_PRAC_SORTS_H
