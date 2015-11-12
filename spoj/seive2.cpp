#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
 
int main() {
    int primes[4000];
    int num_of_primes = 0;
 
    primes[num_of_primes++] = 2;

    for (int i = 3; i <= 32000; i+=2) {
        bool isprime = true;
	//generate only even primes
        int sqrt_ = sqrt(i)+1;
        for (int j = 0; j < num_of_primes; j++) {
            if (primes[j] >= sqrt_) break;
            if (i % primes[j] == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime) primes[num_of_primes++] = i;
    }
 
    int T,N,M;
    scanf("%d",&T);
 
    for (int t = 0; t < T; t++) {
        if (t) printf("\n");
        scanf("%d %d",&M,&N);
        if (M < 2) M = 2;
 
        int sqrt_ = sqrt(N) + 1;
 
        
		bool isprime[100001]; // final list of prime
        memset(isprime,true,sizeof(isprime));   //optimize-function to set same value to array 
	

        for (int i = 0; i < num_of_primes; i++) {
            int p = primes[i];
 
            if(p >= sqrt_) break;
 
            int start; // knock out the multiple of p(composite numbers) and which begin with start
 			
                        if (p >= M) start = p*2;
            else start = M + ((p - M % p) % p);
 
            
 
            for (int j = start; j <= N; j += p) {
                isprime[j - M] = false;
            }
        }
 
        int start = (M % 2)?M:M+1;    
 
        if (M == 2) {
            printf("2\n");
        }
        for (int i = start; i <= N; i+=2) {
            if (isprime[i-M]) printf("%d\n",i);
        }
    }
    return 0;
}

