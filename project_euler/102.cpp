#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include <math.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
#include <limits>

#define eps 10e-9
#define ALL(s) ((s).begin(), (s).end())
#define UNIQUE(c) (c).resize( unique( ALL(c) ) - (c).begin() )
#define REP(i,n) for(int i = 0; i < (n); i++)
#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl; //line num
#define D2(x,y) if(1) cout << __LINE__ <<" "<< #x " = " << (x) \
     <<", " << #y " = " << (y) << endl;
#define x first
#define y second
using namespace std;

typedef vector<int> V;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;
typedef vector<pair<int, int> > VPII;

//U  D  L  R
#define MAXD 4
int dx[] = {0, 0, 1,-1, 1, 1,-1, -1};
int dy[] = {1,-1, 0, 0, 1,-1, 1, -1};
// numeric_limits<int>::min();

PII p1, p2, p3;
float dir(PII & p1, PII & p2, PII & p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool point_in_triangle (PII pt, PII v1, PII v2, PII v3)
{
    bool b1, b2, b3;

    b1 = dir(pt, v1, v2) < 0.0f;
    b2 = dir(pt, v2, v3) < 0.0f;
    b3 = dir(pt, v3, v1) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}
int main() {
    
    int cnt = 0;
    for(int i = 0; i < 1000; i++){
        scanf("%d,%d,%d,%d,%d,%d\n", &(p1.first) , &(p1.second), &(p2.first) , &(p2.second), &(p3.first), &(p3.second));
        if(point_in_triangle(pair<int, int> (0,0), p1, p2, p3)) { 
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}


