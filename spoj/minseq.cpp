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

char A[100005], B[100005];
int alen, blen;
int high[100005];

void pre(){

	high[alen] = alen;
	high[alen-1] = alen;
	A[alen] = '9'+1;
	A[alen+1] = '\0';
	alen += 1;
	for(int i = alen-2; i >= 0; i--){
		int temp = i+1;
		while( A[i] > A[temp]) {
			temp = high[temp];
		}
		high[i] = temp;
	}
	for(int i = 0; i < alen; i++) printf("%d ", high[i]);
}

insert(){
	int temp = 0;
	
	
}

int main() {
			
	while(scanf("%s\n%s", A, B)) {
		alen = strlen(A);
		blen = strlen(B);
		pre();
		insert();	
	}
	return 0;
}
