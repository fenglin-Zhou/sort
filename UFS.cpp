#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int father[103];
int Father(int x){
	int a = x;
	while(x != father[x])
		x = father[x];
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void uion(int a, int b){
	int fa = Father(a);
	int fb = Father(b);
	if(fa != fb){
		father[fa] = fb;
	}
}
int isroot[103];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b;
	for(int i = 1; i <= n; ++i){
		father[i] = i;
		isroot[i] = 0;
	}
	for(int i = 0; i < m; ++i){
		scanf("%d %d", &a, &b);
		uion(a, b);
	}
	for(int i = 1; i <= n; ++i){
		isroot[father[i]] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += isroot[i];
	}
	printf("%d\n", ans);
	return 0;
}

