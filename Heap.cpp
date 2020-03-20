#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100;
int heap[maxn], n = 10;
//对heap数组在[low, high]范围内向下调整 
void downAdjust(int low, int high){
	int i = low, j = i * 2; //i为欲调整节点，j为左孩子 
	while(j <= high){   //存在孩子 
		if(j + 1 <= high && heap[j+1] > heap[j]){
			j = j + 1;  //选择孩子中大的 
		}
		if(heap[j] > heap[i]){  //孩子大于父亲，交换，并且继续上述操作 
			swap(heap[j], heap[i]);
			i = j;
			j = i * 2;
		}else{
			break;
		}
	}
}
void createHeap(){ //建堆 
	for(int i = n / 2; i >= 1; i--){
		downAdjust(i, n);
	}
} 
void deleteTop(){ //删除堆顶 
	heap[1] = heap[n--];
	downAdjust(1, n);
}
//向上调整，整体上与向下类似 
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
void insert(int x){ //添加元素x 
	heap[++n] = x; // 
	upAdjust(1, n); //向上调整 
}
int main()
{
	return 0;
}

