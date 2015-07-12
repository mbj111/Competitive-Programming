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
#include <climits>

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

int n;
ll a[3003];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = LLONG_MIN;
    for(int i = 0; i < n; i++){
        ll temp = 0;   
        for(int j = i, k = n-1; j < k; j++, k--){
            temp += a[j]*a[k];
            if( temp < 0) temp = 0;
            ans = max(ans, temp);
        }
    }
    for(int i = 0; i < n; i++){
        ll temp = 0;   
        for(int j = 0, k = i; j < k; j++, k--){
            temp += a[j]*a[k];
            if( temp < 0) temp = 0;
            ans = max(ans, temp);
        }
    }
    cout << ans << endl;
    return 0;
}


