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

int main() {
    int n;
    ll p,x;
    scanf("%d %lld %lld", &n, &p, &x);
    ll mixx = -1, ;
    int maxid;
    ll temp;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &temp);
        if(temp*p > maxx){
            maxid = i;
            maxx = temp*p;
        }
        p -= x;
    }
    return 0;
}
