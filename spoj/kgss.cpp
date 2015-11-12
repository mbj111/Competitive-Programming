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

//U  D  L  R
int dx[] = {0, 0, 1, -1};
int dy[] = {1,-1, 0, 0};
// numeric_limits<int>::min();

struct segmentTreeNode {
    int maxNum, secondMaxNum;

    void assignLeaf(int num) {
        maxNum = num;
        secondMaxNum = -1;
    }

    void merge(segmentTreeNode& left, segmentTreeNode& right) {
        maxNum = max(left.maxNum, right.maxNum);
        secondMaxNum = min(max(left.maxNum, right.secondMaxNum), max(right.maxNum, left.secondMaxNum));
    }

    int getValue() {
        return maxNum+secondMaxNum;
    }

};

template<class T, class V> 
class SegmentTree {
    segmentTreeNode * nodes;
    int N;
         
public:

    SegmentTree(T arr[], int N) {
        this->N = N;
        nodes = new segmentTreeNode[getTreeSize(N)];
        buildTree(arr, 1, 0, N-1);
    }

    ~SegmentTree(){
        delete[] nodes;
    }

    V getValue(int lo, int hi){
        segmentTreeNode result = getValue(1, 0, N-1, lo, hi);
        return result.getValue();
    }

    void update(int idx, T val) {
        update(1, 0, N-1, idx, val);
    }

private:

    void buildTree(T arr[], int stIdx, int lo, int hi) {
    
        if(lo == hi){
            nodes[stIdx].assignLeaf(arr[lo]);
            return;
        }

        int left = stIdx << 1;
        int right = left+1;
        int mid = (lo+hi) >> 2;

        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid+1, hi);
        nodes[stIdx].merge(nodes[left], nodes[right]);
    }

    segmentTreeNode getValue(int stIdx, int left, int right, int lo, int hi){
        if( left = lo && right == hi){
            return nodes[stIdx];
        }

        int mid = (left+right)/2;
        if(lo > mid)
            return getValue(2*stIdx+1, mid+1, right, lo, hi);
        if(hi <= mid)
            return getValue(2*stIdx, left, mid, lo, hi);

        segmentTreeNode leftRslt = getValue(2*stIdx, left, mid, lo, mid);
        segmentTreeNode rightRslt = getValue(2*stIdx+1, mid+1, right, mid+1, hi);
        segmentTreeNode rslt;
        rslt.merge(leftRslt, rightRslt);
        return rslt;
    }

    int getSegmentTreeSize(int N) {
        int size = 1;
        for(; size < N; size <<= 1);
        return size << 1;
    }

    void update(int stIdx, int lo, int hi, int idx, T value) {
        if(lo == hi) {
            nodes[stIdx].assignLeaf(value);
            return;
        }

        int left = stIdx << 1, right = left+1, mid = (lo+hi)/2;
        if(idx <= mid)
            update(left, lo, mid, idx, value);
        else update(right, mid+1, hi, idx, value);

        nodes[stIdx].merge(nodes[left], nodes[right]);

    }

};

int main() {
    int t;
    scanf("%d", &t);
    return 0;
}


