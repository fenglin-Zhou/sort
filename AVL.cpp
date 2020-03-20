#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node{
	int height, data; //���߶ȴ������� 
	node *left, *right;
};
node *newNode(int data){  //�����½ڵ� 
	node *Node = new node; 
	Node->data = data;
	Node->height = 1;   //��ʼ�߶�Ϊ1 
	Node->left = Node->right = NULL;
	return Node;
}
int getHeight(node *root){ //���ؽڵ�߶� 
	if(root->NULL) return 0;
	return root->height;
}
int getBalanceFactor(node *root){//�鿴��ǰ�ڵ����Ҹ߶Ȳ� 
	return getHeight(root->left) - getHeight(root->right);
}
void updateHeight(node *root){ //���¸߶ȣ����б仯ʱ������� 
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;//+1 
}
void search(node *root, int x){ //����x 
	if(root == NULL){
		printf("Search failed\n");
		return;
	}
	if(x == root->data) printf("%d\n", x);
	else if(x < root->data) search(root->left, x);
	else search(root->right, x);
}
void L(node *root){ //���� 
	node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node *root){���� 
	node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node *&root, int data){ //���룬ƽ����������� 
	if(root==NULL){
		root = newNode(data);
		return; 
	}
	if(root->data > data){
		insert(root->left, data);
		updateHeight(root); //�����в������������Ҫ���� 
		if(getBalanceFactor(root) == 2){ //��Ϊ������࣬���Ե�������1ʱ������ת 
			if(getBalanceFactor(root->left) == 1){ // LL������һ������ 
				R(root);
			}else if(getBalanceFactor(root->left == -1)){ //LR�������������� 
				L(root->left);
				R(root);
			}
		}
	}
	else { //ͬ���棬ֻ�Ƿ���һ�� 
		insert(root->right, data);
		updateHeight(root);
		if(getBalanceFactor(root) == -2){
			if(getBalanceFactor(root->right) == -1){
				L(root);
			}else if(getBalanceFactor(root->right) == 1){
				R(root->right);
				L(root);
			}
		} 
	}
}
node *create(int data[], int n){ //����ƽ��������� 
	node *root = NULL;
	for(int i = 0; i < n; ++i){
		insert(root, data[i]);
	}
	return root;
}
int main()
{
	
}

