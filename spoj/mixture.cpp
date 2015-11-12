#include <stdio.h>
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;
#define DEBUG 0

long long modsum[103][103], a[103], memo[103][103];

int main(){
    int n;
    while(scanf("%d", &n) > 0){
        memset(modsum, 0, sizeof(modsum));
        memset(memo, 0, sizeof(memo));
        for(int i = 0; i < n; i++) scanf("%lld",&a[i]);

        for(int i = 0; i < n; i++){
            modsum[i][i] = a[i]%100;
            for(int j = 0; j < i; j++){
                modsum[j][i] =(modsum[j][i-1]+a[i])%100; 
                if(DEBUG)printf("%d %d %lld\n",j,i,modsum[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            memo[i][i] = 0;
            for(int j = i; j >= 0; j--){
                long long min_ = LLONG_MAX;
                for(int k = j; k < i; k++){
                    min_ = min(min_, memo[j][k]+memo[k+1][i]+modsum[j][k]*modsum[k+1][i]);
                } 
                if(min_ != LLONG_MAX) memo[j][i] = min_;
                if(DEBUG)printf("%d %d %lld\n", j,i,memo[j][i]);
            }
        }
        printf("%lld\n", memo[0][n-1]);
    }

    return 0;
}
