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
char nums[5002];
ll dp[5002];
inline int to_int(int f, int s){
	return f-'0' + s-'0';
}
int main() {
	
	while(true){
		scanf("%s", &nums+1);	
		if( nums[1] == '0') break;
		
		int len = strlen(nums);
		
		memset(dp, 0, sizeof(dp));
		dp[1] = 1,	nums[0] = '3';
		for(int i = 2; i <= len; i++){
			if( to_int(nums[i-1], nums[i-2]) <= 26 ) dp[i] = dp[i-2];
			if( nums[i] != '0') dp[i] += dp[i-1];
		}
		printf("%d\n", dp[len]);
	}
	return 0;
}
