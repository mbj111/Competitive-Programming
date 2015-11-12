#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
	int n;
	string str;
	cin >> str;

	map<char, int> my_map;
	stack<char> my_stack;
	my_map['+'] = 1;
	my_map['-'] = 2;
	my_map['*'] = 3;
	my_map['/'] = 4;
	my_map['^'] = 5;
	
	for(int i = 0; i < n; i++) {
		if(str[i] >= 'a' && str[i] <= 'z')	putchar(str[i]);
		else {
			while( (!my_stack.empty()) && my_map[my_stack.top()] > my_map[str[i]] ){
				putchar(my_stack.top());
				my_stack.pop();
			}
			my_stack.push(str[i]);
		}
	}
	while( !my_stack.empty() ){
		putchar(my_stack.top());
		my_stack.pop();
	}

	return 0;
}
