#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string str;
int sz;
int isDiv(int n) {
	int mod = str[0]%n;
	for(int i = 1; i < sz; ++i){
		mod = (mod%n)*10+str[i];
	}
	if(mod%n == 0) return 1;
	return 0;
}
int freq[12];
int main() {

	std::getline(std::cin, str);
	while( !cin.eof() ) {
		sz = str.size();
		memset(freq, 0, sizeof(freq));	
		int sum = 0;
		for(int i = 0; i < sz; i++) { str[i]-= '0'; freq[str[i]] += 1; sum += str[i]; }

		int ans = freq[1];
		if( str[sz-1] == 0 || str[sz-1] == 5 ) ans += freq[5];
		if( sum % 3 == 0) ans += freq[3];
		if( sum % 3 == 0 && str[sz-1]% 2 == 0) ans += freq[6];
		if( sum % 9 == 0) ans += freq[9];

		// 2
		if( str[sz-1]%2 == 0) ans += freq[2];
		// 4
		if( sz == 1 && str[sz]%4 == 0) ans += freq[4];
		else { int temp = str[sz-2]*10+str[sz-1]; if(temp%4 == 0) ans += freq[4];}
		// 8
		if( sz == 1 && str[sz]%8 == 0) ans += freq[8];
		else if( sz == 2 && ( str[sz-2]*10+str[sz-1] )%8 == 0 ) ans += freq[8];
		else {int temp = str[sz-3]*100+str[sz-2]*10+str[sz-1]; if(temp%8 == 0) ans += freq[8];}
		
		if(isDiv(7)) ans += freq[7];
		cout<< ans << endl;
		std::getline(std::cin, str);
	}

}
