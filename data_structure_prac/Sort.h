//
// Created by Will on 12/12/15.
//

#ifndef DATA_STRUCTURE_PRAC_SORT_NEW
#define DATA_STRUCTURE_PRAC_SORT_NEW


#include <cstdlib>
using namespace std;

//----------------------------------------------------------------------------------------------------------------------qsort

int Partition (int a[], int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot) low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void qsort ( int a[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition (a, low, high);
        qsort (a, low, pivotpos - 1);
        qsort (a, pivotpos + 1, high);
    }
}

//----------------------------------------------------------------------------------------------------------------------msort
/*
int n;                //n为待排序的数的个数, 作为一个全局变量在 主函数中读入
int *b = (int *) malloc ((n + 1) * sizeof (int));
void merge (int a[], int low, int mid, int high) {
    int i, j, k;

    for(i = low; i <= high; i++)
        b[i] = a[i];
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
        if (b[i] <= b[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];
    }
    while (i <= mid)
        a[k++] = b[i++];
    while (j <= mid)
        a[k++] = b[j++];
}

void msort (int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        msort (a, low, mid);
        msort (a, mid + 1, high);
        merge (a, low, mid ,high);
    }
}

*/
//----------------------------------------------------------------------------------------------------------------------msort[WILL]
/*
int n;

int *b = (int *) malloc ((n + 1) * sizeof (int));
void msort (int a[], int low, int high) {
    if (low == high)
        return;
    int mid, i, j, k;
    mid = (low + high) / 2;
    msort (a, low, mid);
    msort (a, mid+1, high);

    i = low; k = i; j = mid +1;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k] = a[i]; i++; k++;
        }
        else {
            b[k] = a[j]; j++; k++;
        }
    }
    while (i <= mid) {
        b[k] = a[i]; i++; k++;
    }
    while (j <= high) {
        b[k] = a[j]; j++; k++;
    }
    for (i = low; i <= high; i++)
        a[i] = b[i];
}

*/

int n;
int *b = new int [n + 1];

void msort (int a[], int low , int high) {
    if (low == high)
        return ;
    int i, j, k, mid;
    mid = (low + high) / 2;
    msort (a, low, mid);
    msort (a, mid + 1, high);
    i = low; k = i; j = mid + 1;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];
    for (i = low; i <= high; i++)
        a[i] = b[i];
}

//----------------------------------------------------------------------------------------------------------------------

void AdjustDown (int a[], int x, int len) {                 //向下调整 大根堆
    a[0] = a[x];
    for (int i = 2 * x; i <= len; i *= 2) {
        if (i < len && a[i] < a[i + 1])
            i++;
        if ( a[0] >= a[i]) break;
        else {
            a[x] = a[i];
            x = i;
        }
    }
    a[x] = a[0];
}

void BuildMaxHeap (int a[], int len) {                      //建堆
    for (int i = len / 2; i > 0; i--)
        AdjustDown (a, i, len);
}

void HeapSort (int a[], int len) {
    BuildMaxHeap (a, len);
    for (int i = len; i > 1; i--) {
        int x;
        x = a[i]; a[i] = a[1]; a[1] = x;
        AdjustDown (a, 1, i - 1);
    }
}




#endif //DATA_STRUCTURE_PRAC_SORT_NEW
