#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int length;
	cin>>length;
	string s;
	cin>> s;
	int flaga = 0; //flag if it encounters a previous A
	int i = 1;
	int suma = 0; //sum when convering the entire string to A.
	int sumb =0; //sum when converting the entire str to B. we'll choose the min of suma and sumb+1.
	int flagb = 0;

	if (s[0] == 'A')
	{	suma = 0;
		flaga = 1;
	}
	else
		suma = 1;
//part to convert entire string to A.
	while(i < length)
	{
		if(s[i] == 'A')
		{	i++;
			flaga = 1;
			continue;
		}
		if (s[i] == 'B' && s[i-1] == 'A')
		{
			suma++;
			i++;
			continue;
		}
		if (s[i] == 'B' && s[i-1] == 'B' && flaga == 1)
		{
			flaga = 0;
			suma++;
			i++;
			continue;
		}
		else i++;

	}

	//part to convert the entire string to B.

	if (s[0] == 'B')
	{	sumb = 0;
		flagb = 1;
	}
	else
		sumb = 1;
	i = 1;

	while(i < length)
	{
		if(s[i] == 'B')
		{	i++;
			flagb = 1;
			continue;
		}
		if (s[i] == 'A' && s[i-1] == 'B')
		{
			sumb++;
			i++;
			continue;
		}
		if (s[i] == 'A' && s[i-1] == 'A' && flagb == 1)
		{
			flagb = 0;
			sumb++;
			i++;
			continue;
		}
		else i++;

	}

	cout<<min(sumb+1,suma)<<endl;
	return 0;

} 
