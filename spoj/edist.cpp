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

int dp[2005][2005];

int main() {
    int tc;
    scanf("%d", &tc);

    while( tc-- ){
        string a,b;
        cin >> a >> b;
        for(int i = 0; i <= max(a.size(), b.size()); i++) dp[i][0] = dp[0][i] = i;
        for(int i = 1; i <= a.size(); i++){
            for(int j = 1; j <= b.size(); j++){
                if( a[i-1] == b[j-1] ){
                    dp[i][j] = min( min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]);
                } else {
                    dp[i][j] = min( min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1);
                }
            }
        }
        cout << dp[a.size()][b.size()] << endl;
    }

	return 0;
}

