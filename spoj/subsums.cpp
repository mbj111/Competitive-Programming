#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n,a,b;
int set[35]; 
int subset1[18];
int subset2[18];

int subset1_sum[(1<<17)+5];
int subset2_sum[(1<<17)+5];

int cnt;
void gen_sub(int sum, int idx, int subset[], int subsetsum[],int maxidx){

    if( idx >= maxidx ) {
        subsetsum[cnt++] = sum;
        return;
    }
    
    gen_sub(sum+subset[idx], idx+1, subset, subsetsum, maxidx);
    gen_sub(sum, idx+1, subset, subsetsum,maxidx);
}

bool flag;
void subset(int k, int idx, int sum){
    
    if( idx > 31) {
        if( sum == k) {flag = true;}
        return;
    }

    subset(k, idx+1, sum);
    subset(k, idx+1, sum+set[idx]);
}
int main(){
    int k = 10000;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) cin >> set[i];
    int mid = (n-1)/2;
    int num_ele1 = mid+1, num_ele2 = n-mid-1; //eg n = 34 -> mid = 0 to 16[17] mid+1 to n -> [17 to 33(17)]
    //generate half size two sets
    for(int i = 0; i < n; i++) {
        if( i <= mid ) subset1[i-16] = set[i];
        else subset2[i] = set[i];
    }

    //****** meet-in-the-middle technique
    cnt = 0;
    gen_sub(0, 0, subset1, subset1_sum,num_ele1);
    sort(subset1_sum, subset1_sum+(1<<num_ele1));
    printf("1st element %d\n", subset1_sum[0]);
    cnt = 0;
    gen_sub(0, 0, subset2, subset2_sum+1, num_ele2);
    sort(subset2_sum, subset2_sum+(1<<num_ele2));

    int low_ptr = 0, high_ptr = 1 << 16;
    while( true ) {
        int sum = subset1_sum[low_ptr] + subset2_sum[high_ptr]; 
        if( sum == k ) {printf("YES\n");return 0;}
        else if( sum > k ){
            high_ptr--;
        } else {
            low_ptr++;
        }
        if( low_ptr == (1<<16) || high_ptr == -1) {printf("NO\n"); return 0;}
    }

    //***** Brute force *****

   // flag = false;
   // subset(k,0, 0);
   // if(flag) printf("YES\n");
   // else printf("NO\n");
 
    return 0;
}
