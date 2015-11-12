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

struct node{
    int clr, cnt;
    node(int c, int cl){
        clr = cl, cnt = c;
    }
};
typedef struct node Node;
int main() {

    Node node(1,5);

    cout << node.clr << endl;
    return 0;
}


