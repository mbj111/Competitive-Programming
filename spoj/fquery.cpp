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

struct node {
    int left_val, left_count;
    int right_val, right_count;
    int seg_val, seg_count;
};

typedef struct node * NODE;
const int max_node = (1<<20)+5;
const int maxn = 100005;
NODE tree[max_node];
int a[maxn];

void init_node(int idx, int a_idx){
    tree[idx] = (NODE) malloc(sizeof(struct node));
    tree[idx]->left_val = tree[idx]->right_val = tree[idx]->seg_val = a[a_idx];
    tree[idx]->left_count = tree[idx]->right_count = tree[idx]->seg_count = 1;
}

NODE merge(NODE left_node, NODE right_node){

    NODE ret_node = (NODE) malloc(sizeof(struct node));

    if(left_node->seg_count > right_node->seg_count){
        ret_node->seg_count = left_node->seg_count;
        ret_node->seg_val = left_node->seg_val;
    } else {
        ret_node->seg_count = right_node->seg_count;
        ret_node->seg_val = right_node->seg_val;
    }

    if(left_node->right_val == right_node->left_val){
        if(ret_node->seg_count < left_node->right_count + right_node->left_count){
            ret_node->seg_val = left_node->right_val;
            ret_node->seg_count = left_node->right_count+right_node->left_count;
        } 
    } 

    ret_node->left_val = left_node->left_val;
    ret_node->left_count = left_node->left_count;
    if(left_node->left_val == right_node->left_val){
        ret_node->left_count = left_node->left_count + right_node->left_count;
    }

    ret_node->right_val = right_node->right_val;
    ret_node->right_count = right_node->right_count;
    if(left_node->right_val == right_node->right_val){
        ret_node->right_count = left_node->right_count + right_node->right_count;
    }

    return ret_node;
}

NODE build_tree(int idx, int left, int right){

    if(left == right){
        init_node(idx, left); 
        return tree[idx];
    }

    int mid = (left+right)/2;
    NODE left_node  = build_tree(idx<<1, left, mid);
    NODE right_node = build_tree((idx<<1)+1, mid+1, right);
    tree[idx]  = merge(left_node, right_node);

    return tree[idx];
}

NODE query(int idx, int seg_left, int seg_right, int q_left, int q_right){
    if( seg_left >= q_left && seg_right <= q_right){
        return tree[idx];
    }
    int mid = (seg_left+seg_right)/2;
    if(mid >= q_right){
        return  query(idx<<1, seg_left, mid, q_left, q_right);
    } else if(q_left > mid) {
        return query((idx<<1)+1, mid+1, seg_right, q_left, q_right);
    } else {
        NODE left_node = query(idx<<1, seg_left, mid, q_left, q_right);
        NODE right_node = query((idx<<1)+1, mid+1, seg_right, q_left, q_right);
        NODE ret_node  = merge(left_node, right_node);
        return ret_node; 
    }
}


int main() {

    while(true){
        int n, q;
        scanf("%d", &n);
        if(n == 0) return 0;
        scanf("%d", &q);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]); 
        }

        build_tree(1, 0, n-1);
        int l, r;
        for(int i = 0; i < q; i++){
            scanf("%d %d", &l, &r); 
            printf("%d\n", query(1, 0, n-1, l-1, r-1)->seg_count);
        }
    }
    return 0;
}

