#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> V;

vector<int> v;
bool prime[33002];

//Pre-processing - storing prime numbers( < 33000 ) in vector v which are suffiecient to test prime number greater than 33000^2
void gen_prime(){

	int i,j;
	int MAX = 33000;
	for(i=2;i<MAX;i++)	prime[i]=true;
 
 	int sqrt_ = (int)sqrt(MAX);
	for(i=2;i<sqrt_;i++)
		if(prime[i])	for(j=i;j*i<MAX;j++)	prime[i*j]=false;

	v.push_back(2);
	for(int i = 3; i < MAX; i+=2) if(prime[i]){
		v.push_back(i);
	}

}

//primality testing using stored number
bool isPrime(int num){
	
	for(int i = 0; i < v.size(); i++){
		if( v[i]*v[i] > num) return true;
		if( num%v[i] == 0 ) return false;
	}
	
	return true;
}


int main() {
	int tc;
	scanf("%d", &tc);
	gen_prime();
	int n,m;
	
	while(tc--){
		scanf("%d %d", &m,&n);
		for(int i = m; i <= n; i++){
			if( isPrime(i)){
				printf("%d\n", i);	
			}	
		}
		printf("\n");
	}

	return 0;
}

