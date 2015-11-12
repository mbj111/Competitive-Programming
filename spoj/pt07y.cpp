#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int visited[10005];
vector< vector<int> > vvi(10005);

void dfs(int v){	
	int sz = vvi[v].size();
	for(int i = 0; i < sz; i++){
		if( visited[vvi[v][i]] == false){
			visited[vvi[v][i]]= true;
			dfs(vvi[v][i]);
		} 
	}
}
int main(){
	int n,m;
	cin >> n >> m;

	int u,v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		vvi[u].push_back(v);
		vvi[v].push_back(u);
	}
	memset(visited, false, sizeof (visited));
	if( n == m+1){
		dfs(1);
		for(int i = 1; i <= n; i++)
			if( visited[i] == false) {puts("NO"); return 0;}
		puts("YES");
	} else 	puts("NO");
	return 0;
}
