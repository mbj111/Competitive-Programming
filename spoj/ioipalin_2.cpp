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

int dp[2][5005];
char revstr[5005], str[5005];

int main() {
    int n;
    scanf("%d\n", &n);
    gets(str);
    
    
    for(int i = n-1, j = 0; i >= 0; i--) revstr[i] = str[j++];
    memset( dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if (str[i-1] == revstr[j-1]){
               dp[i%2][j] =  dp[(i-1)%2][j-1]+1; 
            } else {
               dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
            }
        }
    printf("%d\n", n-dp[n%2][n]);
	return 0;
}

