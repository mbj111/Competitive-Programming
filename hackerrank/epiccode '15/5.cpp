#include <iostream>
#include <cstdio>
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
#include <set>

#define maxN(a,b) ((a>b)?(a):(b))
#define minN(a,b) ((a<b)?(a):(b))
#define INF (int)10e9
#define ABS(n)	((n>0)? n:(-1*n))
#define NINF -(int)10e9
#define eps 10e-9
#define WORDSIZE 31

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

VPII vp;
bool cmp(PII p1, PII p2){
    if( p1.first > p2.first) return false;
    else if( p1.first == p2.first) return p1.second > p2.second;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        vp.push_back(make_pair(a,b));
    }
    
    sort(vp.begin(), vp.end(), cmp);
    set<int> s;
    set<int>::iterator it;
    s.clear();
    for(int i = 0; i < n; i++){
        s.insert(vp[i].second);
        it = s.find(vp[i].second);
        ++it;
        if( it != s.end() )
            s.erase(it);
    }
    
   printf("%d\n",(int)s.size());
    return 0;
}
