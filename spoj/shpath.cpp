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

int main() {
	int v, E, s, t, M[][], u,v,d;
	unordered_map<string, int> map;

	int label;
	V label(v);
	
	int tcc;
	scanf("%d", &tcc);
	for(int tc = 0; tc <= tcc; tc++){
		memset(label, 2000000, sizeof(label));
		for(int i = 0; i < v-1; i++){
			make_heap(d, d+v-i-1);
		}
	}
	return 0;
}

