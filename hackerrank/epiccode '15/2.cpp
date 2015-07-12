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

char str[1000007];
ll freq[26];

ll sum(ll n){
    if( n <= 1) return 0;

    return (n-1)*n/2;
}
int main() {
    int t;
    scanf("%d\n", &t);
    scanf("%s",str);
    for(int i = 0; i < t; i++){
        freq[str[i]-'a']++;
    }
    ll ans = 0;
    for(int i = 0; i < 26; i++){
        ans += freq[i]+ sum(freq[i]);
    }
    printf("%lld\n", ans);
    return 0;
}


