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

int dp[5005][5005];
char a[5005];

int min_cost(int i, int j){

    if( i >= j ) return 0;

    if( a[i]==a[j] ) dp[i][j] = min(dp[i][j], min_cost(i+1, j-1));
    else {
        if( a[i+1] == a[j] ) dp[i][j] = min(dp[i][j],min_cost(i+2, j--)+1);
        else if( a[i] == a[j-1]) dp[i][j] = min( dp[i][j], min_cost(i+1, j-2)+1); 
        else dp[i][j] = min(dp[i][j], min_cost(i+1, j-1)+2);
    }
    return dp[i][j];
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", a);
    int cost = 0;
    int i = 0, j = n-1; 
    for(int i = 0; i < 5005; i++) for(int j = 0; j < 5005; j++) dp[i][j] = 5555;
    while(i < j){
        if( a[i] == a[j] ){  i++; j--;}
        else {
            if( a[i+1] == a[j]) {i+=2; j--; cost++; }
            else if(a[i] == a[j-1]) {i++; j-=2; cost++;}
            else {
                i++;
                j--;
                cost += 2;
            }
        }
    }
    printf("%d\n", cost);
	return 0;
}

