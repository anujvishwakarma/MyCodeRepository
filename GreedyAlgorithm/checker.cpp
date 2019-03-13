#include<bits/stdc++.h>
using namespace std;
int contains_not_more_one_odd_characters_that_are_in_final(int freq[], int freqfinal[])
{
	int count=0;
	for(int i=0;i<=9;i++)
	{
		if(freq[i]==freqfinal[i]&&freq[i]%2==1)
			count++;
	}
	//cout<<" ct "<<count<<endl;
	if(count>0)
		return 0;
	return 1;
}
int findlen(int freq[])
{
	int ct=0;
	for(int i=0;i<=9;i++)
		if(freq[i]%2==1)
			ct++;
	if(ct>0)
		return 0;
	int val =0;
	for(int i=0;i<=9;i++)
		val+= freq[i];
	return val;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		string s;
		cin>>s;
		int freq[10],freqfinal[10];
		for(int i=0;i<=9;i++)
		{
			freq[i] =0;
			freqfinal[i] =0;
		}
		for(int i=0;i<s.size();i++)
			freqfinal[s[i]-'0']++;
		int i=0,j=1;
		freq[s[i]-'0']++;
		int max_length=0;
		while(j<s.length())
		{
			if(contains_not_more_one_odd_characters_that_are_in_final(freq,freqfinal))
			{
				freq[s[j]-'0']++;
				max_length = max(max_length,findlen(freq));
				j++;
			}
			else
			{
 
				freq[s[i]-'0']--;
				i++;
 
			}
 
 
		}
		int val=0;
		max_length = max(max_length,findlen(freq));
		cout<<max_length<<endl;
	}
}