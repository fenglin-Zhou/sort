#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int quick(int a[], int left, int right)
{
    int temp = a[left];
    while(left < right){
        while(right>left && a[right]>temp) right--;
        a[left] = a[right];
        while (left<right && a[left]<temp) left++;
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}
void quickSort(int a[], int left, int right)
{
    if(left < right){
        int pos = quick(a, left, right);
        quickSort(a, left, pos-1);
        quickSort(a, pos+1, right);
    }
}
int main()
{
    int a[10] = {3, 5, 2, 1, 8, 7, 6, 9, 0, 4};
    quickSort(a, 0, 9);
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}