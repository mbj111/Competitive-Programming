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

const int maxn = 300005;
const int maxm = 100005;
int c[maxn];
vector<int> v[maxm];

struct node {
    int count, color;
    node(){}
    node(int cnt, int clr){
        count = cnt;
        color = clr;
    }
};

typedef struct node Node;
Node tree[(1<<20)+5];

void build_tree(int idx, int l, int r){

    assert( l <= r); //if fails then something wrong with algorithm or input

    if( l == r){
        tree[idx].count = 1;
        tree[idx].color = c[l];
        return ;
    }

    int mid = (l+r)/2;
    build_tree( idx*2  ,     l, mid);
    build_tree( idx*2+1, mid+1, r);

    //merging
    if(tree[idx*2+1].color == tree[idx*2].color){
        tree[idx].count = tree[idx*2+1].count + tree[idx*2].count;
        tree[idx].color = tree[idx*2].color;
    } else if(tree[idx*2+1].count < tree[idx*2].count){
        tree[idx].count = tree[idx*2].count - tree[idx*2+1].count;
        tree[idx].color = tree[idx*2].color;
    } else if( tree[idx*2].count < tree[idx*2+1].count){
        tree[idx].count = tree[idx*2+1].count - tree[idx*2].count;
        tree[idx].color = tree[idx*2+1].color;
    } else {
        tree[idx].count = 0;
        tree[idx].color = 0;
    }

}

// begin - where segment begins and end  - where segment ends
Node query(int idx, int l, int r, int begin, int end){
    
   if(begin >= l && end <= r){
        return tree[idx];
   }

   int mid = (begin+end)/2;

   Node left(0,0), right(0,0), ret(0,0);

   if(l <= mid) left = query(idx*2, l, r,begin, mid);
   if(r >= mid+1) right = query(idx*2+1, l, r,mid+1, end);

    if(left.count < right.count){
        ret.count = right.count - left.count;
        ret.color = right.color;
    } else if( left.count > right.count){
        ret.count = left.count - right.count;
        ret.color = left.color;
    } else {
        ret.count = left.count + right.count;
        ret.color = left.color;
   }
    return ret;
}


int main() {
    int n, colors;
    scanf("%d %d", &n, &colors);
    REP(i, n){
       scanf("%d", &c[i]);   
       v[c[i]].push_back(i);
    }

    build_tree(1, 0, n-1);
    int m;
    scanf("%d", &m);
    int a,b;  

    REP(i, m){
        scanf("%d %d", &a, &b);
        a = a-1, b = b-1;
        Node node_ = query(1, a, b, 0, n-1);
        int num = node_.color;
        int count = upper_bound(v[num].begin() , v[num].end() , b) - lower_bound(v[num].begin() , v[num].end() , a);
        int req = b - a +1;
        if(count*2 > req && num != 0){
            printf("yes %d\n", num);
        } else {
            printf("no\n");
        }
    }

    return 0;
}


