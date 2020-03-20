#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node{
	int height, data; //树高度从下往上 
	node *left, *right;
};
node *newNode(int data){  //创建新节点 
	node *Node = new node; 
	Node->data = data;
	Node->height = 1;   //初始高度为1 
	Node->left = Node->right = NULL;
	return Node;
}
int getHeight(node *root){ //返回节点高度 
	if(root->NULL) return 0;
	return root->height;
}
int getBalanceFactor(node *root){//查看当前节点左右高度差 
	return getHeight(root->left) - getHeight(root->right);
}
void updateHeight(node *root){ //更新高度，当有变化时必须更新 
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;//+1 
}
void search(node *root, int x){ //搜索x 
	if(root == NULL){
		printf("Search failed\n");
		return;
	}
	if(x == root->data) printf("%d\n", x);
	else if(x < root->data) search(root->left, x);
	else search(root->right, x);
}
void L(node *root){ //左旋 
	node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node *root){右旋 
	node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node *&root, int data){ //插入，平衡二叉搜索树 
	if(root==NULL){
		root = newNode(data);
		return; 
	}
	if(root->data > data){
		insert(root->left, data);
		updateHeight(root); //上面有插入操作，所以要更新 
		if(getBalanceFactor(root) == 2){ //因为是往左侧，所以当左侧大于1时进行旋转 
			if(getBalanceFactor(root->left) == 1){ // LL，进行一次右旋 
				R(root);
			}else if(getBalanceFactor(root->left == -1)){ //LR，先左旋后右旋 
				L(root->left);
				R(root);
			}
		}
	}
	else { //同上面，只是反了一下 
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
node *create(int data[], int n){ //创建平衡二叉树。 
	node *root = NULL;
	for(int i = 0; i < n; ++i){
		insert(root, data[i]);
	}
	return root;
}
int main()
{
	
}

