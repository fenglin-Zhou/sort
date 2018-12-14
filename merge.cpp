#include <iostream>
using namespace std;
void merge(int *a, int low, int high, int mid)
{
	int left = mid - low + 1;
	int right = high - mid;
	int L[left], R[right];
	int i, j;
	for(i = 0; i < left; i++)
		L[i] = a[i + low];
	for(j = 0; j < right; j++)
		R[j] = a[mid + j + 1];
	i = 0;
	j = 0;
	int k = low;
	while(i < left && j < right){
		if(L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < left){
		a[k] = L[i];
		i++;
		k++;
	}
	while(j < right){
		a[k] = R[j];
		j++;
		k++;
	}
}
void mergesort(int *a, int low, int high)
{
	int m;
	if(low < high){
		m = (high + low)/2;
		mergesort(a, low, m);
		mergesort(a, m+1, high);
		merge(a, low, high, m);
	}
}
int main()
{
	int a[10] = {1, 3, 5, 6, 10, 9, 7, 4, 2, 8};
	mergesort(a, 0, 9);
	for(int i = 0; i < 10; i++)
		cout << a[i] << endl;
	return 0;
}

