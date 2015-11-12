#include <stdio.h>
#include <iostream>

long nums[10000+5];
long dp[10000+5];

int main(){
	int tc;
	while(tc--){
		int n;
		scanf("%d", &n);
		if(n >= 1) printf("%d", &dp[0]);
		if(n >= 2) {
			printf("%d", &nums[1]);
			dp[1] = max(nums[1], dp[0]);
		}
	
		for(int i = 2; i < n; i++){
			scanf("%d", &nums[i]);
			dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
		}
		
		printf("%d", dp[n-1]);
		
	}
	return 0;
}
