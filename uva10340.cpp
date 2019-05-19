
Conversation opened. 1 unread message.

Skip to content
Using Gmail with screen readers
in:sent 
86 of 552
uva10340
Inbox
x

heeheehaha45 <heeheehaha45@gmail.com>
Mon, Aug 20, 2018, 9:47 PM
to me

#include <iostream>
using namespace std;
#include <string.h>

#define maxLen 400000000


char t[maxLen];
char s[maxLen];

int N ;
int M ;



//return 1 if true
//else return 0;
int dp(int i,int j){
	
	//base case
	if (j == N)
		return 1;

	if (i == M){
		if (j != N){
			return 0;
		}
		else{
			return 1;
		}
	}

	if (t[i] == s[j]){
		int resultA = dp(i + 1, j + 1);
		int resultB = dp(i + 1, j);
		return (resultA || resultB);

	}
	else
		return dp(i +1, j );
	
	
	return 0;
	
}


int main() {
	
	
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);


	//read input
	while (scanf("%s %s",s,t ) == 2){


		N = strlen(s);
		M = strlen(t);
		

		int result = dp(0, 0);
		if (result)
			printf("Yes\n");
		else
			printf("No\n");

	}


	return 0;
}
