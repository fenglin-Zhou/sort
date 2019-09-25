#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void merge(int a[], int left, int mid, int right)
{
    int index = 0;
    int temp[10];
    int i = left, j = mid+1;
    while (i <= mid && j<=right){
        if(a[i] <= a[j])
            temp[index++] = a[i++];
        else
            temp[index++] = a[j++];
    }
    while(i <= mid) temp[index++] = a[i++];
    while(j <= right) temp[index++] = a[j++];
    for (int k = 0; k < index; ++k) {
        a[left+k] = temp[k];
    }
}
void mergeSort(int a[], int left, int right)
{
    if(left < right){
        int mid = (left+right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}
int main()
{
    int a[10] = {3, 5, 2, 1, 8, 7, 6, 9, 0, 4};
    mergeSort(a, 0, 9);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
