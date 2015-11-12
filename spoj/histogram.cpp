#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> histogram;
stack<int> idx;

long int max_ = 0;

int main(){
	
	int n;
	scanf("%d", &n);
	while(n) {
		int height;
		printf("%d\n", n);	
		for(int i = 0; i < n; i++) {
			scanf("%d", &height);
			
			if( histogram.empty()){ histogram.push(height); idx.push(i); continue;}

			while( !histogram.empty() && histogram.top() > height){
				int hgt = histogram.top();
				int idx_ = idx.top();
				cout << hgt << "  " << idx_ << endl;
				max_ = max( max_, (long int)hgt*(i-idx_));
				histogram.pop(); idx.top();
			}
			if( !histogram.empty() && histogram.top() == height) {continue;	}
			else if( histogram.top() < height) histogram.push(height); idx.push(i);
		}
			while( !histogram.empty() && histogram.top() > height){
				int hgt = histogram.top();
				int idx_ = idx.top();
				
				cout << hgt << "  " << idx_ << endl;
				max_ = max( max_, (long int)hgt*((n-1)-idx_));
				histogram.pop(); idx.top();
			}
		cout<< max_ <<endl;
		scanf("%d", &n);
	}
}
