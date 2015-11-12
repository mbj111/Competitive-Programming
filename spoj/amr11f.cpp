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

#define eps 10e-9
#define all(s) ((s).begin(), (s).end())
#define REP(i,n) (int i = 0; i < (n); i++)
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

const int maxn = 101;

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n,f,m;
        cin >> n >> f >> m;
        REP(i, m){
            int b1, f1, b2, f2, time;
            cin >> b1 >> f1 >> b2 >> f2 >> time;
        }
    
        given_coord_to_id();
        find_coord_id_to_given_coord();
        find_coord_id_to_given_coord();
        find_co
    }
    return 0;
}


