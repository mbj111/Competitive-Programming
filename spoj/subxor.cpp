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

int a[100000+5];

typedef struct node{
    int count;
    node * left,* right;
} node;

node * newnode(){
    node * newnode_ = (node *) malloc(sizeof(node));
    newnode_ -> right = NULL;
    newnode_ -> left = NULL;
    newnode_ -> count = 1;
}

int count_subarray_endwith_i(node * root, int level, int value, int k){
    int cnt = 0;
    if( level <= 0) return cnt;
    if( root == NULL) return 0;    

    if( value & (1<<level) ) {
        if( k & (1<<level) ) 
            cnt += (root->left != NULL) ? root->left->count:0;
        cnt += count_subarray_endwith_i(root->right, level--, value, k);
    } else {
        if( k & (1<<level) ) 
            cnt += (root->right!= NULL) ? root->right->count:0;
        cnt += count_subarray_endwith_i(root->left, level--, value, k);
    }
    return root->count = cnt;
}

int insert(node * root, int level, int value){
    if( level <= 0) return 1;

    if( value & (1<<level)){
        if( root-> right == NULL) 
            root->right = newnode();
        root->count = insert(root->right, --level, value);
    } else {
        if( root-> left == NULL) 
            root->left = newnode();
        root->count = insert(root->left, --level, value);
    }
    return root->count;
}

int main() {
    int tc;
    scanf("%d", &tc);

    while(tc--){
        int n,k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        int temp = 0, ans = 0;
        node * root = newnode();
        for(int i = 0; i < n; i++){
            temp = temp ^ a[i];
            ans += count_subarray_endwith_i(root, 17, temp, k);
            root-> count = insert(root, 17, temp);            
            ans += (temp < k) ?1:0;
        }
        printf("%d\n", ans);
    }

    return 0;
}

