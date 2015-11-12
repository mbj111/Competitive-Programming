#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <limits>

#define eps 10e-9
#define all(s) ((s).begin(), (s).end())
#define REP(i,n) (int i = 0; i < (n); i++)
using namespace std;

typedef vector<int> V;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;
typedef vector<pair<int, int> > VPII;

//U  D  L  R
int dx[] = {0, 0, 1, -1};
int dy[] = {1,-1, 0, 0};
// numeric_limits<int>::min();
// using vector

const int maxn = 1001;
int parent[maxn];
int lca(int u, int v, int n){
    int vis[n+1];
 for(int i = 0; i <= n; i++) vis[i] = 0;
    vis[u] = 1;
    while(parent[u] != u){
        u = parent[u];
        vis[u] = 1;
    }
    
    while(vis[v] != 1) v = parent[v];
    return v;
}
int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        printf("Case %d:\n", tc);
        int n;
        cin >> n;
        int edg;
        for(int i = 1; i <= n; i++) parent[i] = i;
        for(int i = 1; i <= n; i++){
            cin >> edg;
            for(int j = 0; j < edg; j++){
                 int temp; cin >> temp;
                 parent[temp] = i;
            }
        }
        int q;
        cin >> q;
        for(int i = 0; i < q; i++){
            int u,v; cin >> u >> v;
            cout << lca(u,v,n) << endl;
        }
    }
    return 0;
}


