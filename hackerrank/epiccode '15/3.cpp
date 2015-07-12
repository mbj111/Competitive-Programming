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

int n, k;
int boyshgt[100005], girlsh[100005];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &boyshgt[i]);
    }
    sort(boyshgt, boyshgt+n);
    for(int i = 0; i < n; i++){
        scanf("%d", &girlsh[i]);
    }
    sort(girlsh, girlsh+n);

    int cnt = 0, gp = 0, bp = 0;
    while(gp != n && bp != n){
        if( abs(boyshgt[bp]-girlsh[gp]) <= k ) cnt++, bp++, gp++;
        else if( boyshgt[bp] > girlsh[gp] ) gp++;
        else bp++;
    }
    printf("%d\n", cnt);
    return 0;
}


