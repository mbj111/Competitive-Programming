#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include <math.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
#include <limits>

#define eps 10e-9
#define ALL(s) ((s).begin(), (s).end())
#define UNIQUE(c) (c).resize( unique( ALL(c) ) - (c).begin() )
#define REP(i,n) for(int i = 0; i < (n); i++)
#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl; //line num
#define D2(x,y) if(1) cout << __LINE__ <<" "<< #x " = " << (x) \
     <<", " << #y " = " << (y) << endl;
using namespace std;

typedef vector<int> V;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;
typedef vector<pair<int, int> > VPII;

//U  D  L  R
#define MAXD 4
int dx[] = {0, 0, 1,-1, 1, 1,-1, -1};
int dy[] = {1,-1, 0, 0, 1,-1, 1, -1};
// numeric_limits<int>::min();

const int maxr = 101, maxc = 101;
char grid[maxr][maxc];
int vis[maxr][maxc];
int parent[maxr][maxc];

void dfs(int x, int y){
    if( x < 0 || x >= r || y < 0 || y >= c || vis[x][y]){
        return ;
    } else {
        if(grid[x][y] == '*'){
            
            return;
        } 
        for(int i = 0; i < 4; i++){
            if( !vis[x+dx[i]][y+dy[i]] ){
                parent[x+dx[i]][y+dy[i]]=i;
                dfs(x+dx[i], y+dy[i]);
            }

        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    return 0;
}


