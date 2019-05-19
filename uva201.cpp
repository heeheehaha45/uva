

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include<vector>
#include<cstring>
#include <string>


using namespace std;

#define MAXSIZE 100
#define MAXLEN 100



char str[MAXLEN];
int ans[10];


int formSquareAt(int origin_i, int origin_j, int windowSize, vector<string> vec){
	/*cout << "vec:" << endl;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;
	cout << endl;
	*/

	//1
	//for (int i = origin_i; i < origin_i+ windowSize; i++){
	for (int j = origin_j; j < origin_j + windowSize; j++){
		string s = "H " + to_string(origin_i) + " " + to_string(j);
		if (find(vec.begin(), vec.end(), s) != vec.end())
			;// cout << "found:" << s << endl;
		else
			return -1;
	}





	//4

	for (int i = origin_i; i < origin_i + windowSize; i++){
		//for (int j = origin_j; j< origin_j + windowSize; j++){
		//	string s = "V " + to_string(i) + " " + to_string(origin_j);
		string s = "V " + to_string(origin_j) + " " + to_string(i);
		if (find(vec.begin(), vec.end(), s) != vec.end())
			;// cout << "found:" << s << endl;
		else
			return -1;
	}



	//3
	//for (int i = origin_i+windowSize-1; i < origin_i+ windowSize; i++){
	for (int j = origin_j; j< origin_j + windowSize; j++){
		string s = "H " + to_string(origin_i + windowSize ) + " " + to_string(j);
		if (find(vec.begin(), vec.end(), s) != vec.end())
			;// cout << "found:" << s << endl;
		else
			return -1;
	}

	//2

	for (int i = origin_i; i < origin_i + windowSize; i++){
		//for (int j = origin_j; j< origin_j + windowSize; j++){
		//	string s = "V " + to_string(i) + " " + to_string(origin_j + windowSize-1);
		string s = "V " + to_string(origin_j + windowSize ) + " " + to_string(i);
		if (find(vec.begin(), vec.end(), s) != vec.end())
			;// cout << "found:" << s << endl;
		else
			return -1;
	}


	return 0;
}


void solve(int n, int m, vector<string> vec){

	int windowSize;
	for (int windowSize = 1; windowSize <= n-1; windowSize++){

		for (int i = 1; i + windowSize <= n; i++){
			for (int j = 1; j + windowSize <= n; j++){
				if (formSquareAt(i, j, windowSize, vec) == 0)
					ans[windowSize]++;



			}

		}
	}
	int AllZero = 0;
	for (int i = 0; i < 10; i++){
		if (ans[i] != 0){
			printf("%d square (s) of size %d\n", ans[i], i);
			AllZero = -1;
		}

	}

	if (AllZero == 0)
		printf("No completed squares can be found.\n");


}

int main() {
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);

	int counter = 1;

	while (1){
		int n;
		int m;
		vector<string> vec;
		memset(ans, 0, sizeof(ans));


		int scan = scanf("%d\n", &n);
		//cout << "n=" << n << endl;
		if (scan != 1 || n == EOF){
			return 0;
		}
		if (counter != 1)
			cout << endl << "**********************************" << endl<<endl;


		scanf("%d\n", &m);
		//cout << "m=" << m << endl;
		for (int i = 0; i < m; i++){
			fgets(str, MAXLEN, stdin);
			if (str[strlen(str) - 1]=='\n')
				str[strlen(str) - 1] = '\0';
			string cppStr = str;
			//cout << str <<endl;
			vec.push_back(cppStr);
		}
		cout << "Problem #" << counter << endl << endl;
		
		solve(n, m, vec);


		counter++;
	}


	return 0;
}
