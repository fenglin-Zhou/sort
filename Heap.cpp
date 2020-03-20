#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100;
int heap[maxn], n = 10;
//��heap������[low, high]��Χ�����µ��� 
void downAdjust(int low, int high){
	int i = low, j = i * 2; //iΪ�������ڵ㣬jΪ���� 
	while(j <= high){   //���ں��� 
		if(j + 1 <= high && heap[j+1] > heap[j]){
			j = j + 1;  //ѡ�����д�� 
		}
		if(heap[j] > heap[i]){  //���Ӵ��ڸ��ף����������Ҽ����������� 
			swap(heap[j], heap[i]);
			i = j;
			j = i * 2;
		}else{
			break;
		}
	}
}
void createHeap(){ //���� 
	for(int i = n / 2; i >= 1; i--){
		downAdjust(i, n);
	}
} 
void deleteTop(){ //ɾ���Ѷ� 
	heap[1] = heap[n--];
	downAdjust(1, n);
}
//���ϵ��������������������� 
void upAdjust(int low, int high){
	int i = high, j = i / 2;
	while(j >= low){
		if(heap[j] < heap[i]){
			swap(heap[j], heap[i]);
			i = j;
			j = i / 2;
		}else{
			break;
		}
	}
} 
void insert(int x){ //���Ԫ��x 
	heap[++n] = x; // 
	upAdjust(1, n); //���ϵ��� 
}
int main()
{
	return 0;
}

