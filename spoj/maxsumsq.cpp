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

int a[100005];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        int sum = 0, maxg = a[0]; 
        for(int i = 0; i < n; i++) {
            sum += a[i];
            maxg = max(maxg, sum);
            sum = sum ^ ((sum^0) & -(sum < 0) );
        }

        int cnt = 0;
        sum = 0;
        bool flag = false;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            if( sum == maxg ){ 
                if(flag == true)
                    cnt++;
                    cnt++;    
            }
            if( sum == 0)  flag = true;
            else if( sum < 0 ){ sum = 0; flag = false; }
        }
        printf("%d %d\n", maxg, cnt);
    }

    return 0;
}


