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

int freq[1000000+5], fw[1000000+5];
int main() {
	int n,k;
	scanf("%d %d", &n, &k);

	memset(fw, 0, sizeof(fw));
	for(int i = 0; i < k; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		for(int i = a; i <= b; i += i&(i-1)+1){
			fw[i]++;	
		}
	}
	
	for(int i = 0; i <=

	return 0;
}

