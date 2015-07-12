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
#define MOD 1000000007LL

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

ll presum[200005];
ll premul[200005];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    for(int i = 1; i <= n+1; i++)
        premul[i] = (premul[i-1]+(ll) (i*(i+1)) )%MOD;

    for(int i = 0; i < q; i++){
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        if(type == 1){
            for(int j = x, k = 1; j <= n; j++, k++){
                presum[j] = (presum[j]+premul[k])%MOD;
            }
        } else {
            ll sum = (presum[y]-presum[x-1]+MOD)%MOD;
            printf("%lld\n", sum);
        }
    }
    return 0;
}


