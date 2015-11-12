#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <algorithm>

#define maxN(a,b) ((a>b)?(a):(b))
#define minN(a,b) ((a<b)?(a):(b))
#define INF (int)10e9
#define eps 10e-9
#define MAX 1000000007

using namespace std;

typedef vector<int> V;
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
V v;
bool prime[MAX];// Max is size of problem which is #define
void gen_prime(){
	int i,j;
	for(i=2;i<MAX;i++)	prime[i]=true;
	
	for(i=2;i<(int)sqrt(MAX);i++)
		if(prime[i])	for(j=i;j*i<MAX;j++)	prime[i*j]=false;
	
	for(int i = 2; i < MAX; i++)
		if(prime[i]) v.push_back(i);
	
}


int main() {

	int T;
	scanf("%d\n", &T);
	gen_prime();
	while( T-- ) {
		ull n;
		scanf("%lld", &n);
		if( n == 0 || n == 1) {
			puts("0");
		}
 		
 		else {
 			ull ans = 1;
 			ull i ;
 			ull sq =  sqrt(n);
			int t = 0;
			 while(v[t] < sq)
 			{
 				if(n % v[t] == 0 ) {
 					ans += v[t] + n / v[t];
 					//printf("%d %d\n",i , n/i );
				
 				}
				t++;
 			}
 			if( v[t] == sq) {
 				ans += i;
 				//printf("%d\n", i);
 			}
 			printf("%lld\n", ans);
 		}

 		
	}


	return 0;
}

