// 팰린드롬?
// N개의 정수가 주어지고, M개의 (S, E) 질문이 주어진다. 질문은 S번째에서 E번째까지 정수배열이 팰린드롬인지를 물어본다. 각 질문에 그렇다 1, 아니다 0 으로 답하라.


// 내 답안1
// Hash table 활용. - 메모리 초과
/*
#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_N 2'001
#define MAX_M 1'000'001

using namespace std;

string NumArr = "";
unordered_map<string, bool> HashMap;

void backtracking(int start, int N, string& key)
{
	if (key != "")
	{
		if (HashMap.find(key) == HashMap.end())
		{
			bool flag = true;
			for (int i = 0; i < key.length()/2; i++)
			{
				if (key[i] != key[key.length() - 1 - i])
				{
					flag = 0;
					break;
				}
			}
			HashMap[key] = flag;
		}
	}
	for (int i = start; i < N; i++)
	{
		key.push_back(NumArr[i]);
		backtracking(i+1, N, key);
		key.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	string key = "";

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char num = ' ';

		cin >> num;
		NumArr += num;
	}
	backtracking(0, N, key);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int S = 0;
		int E = 0;

		cin >> S >> E;
		cout << HashMap[NumArr.substr(S-1, E - S + 1)] << '\n';
	}
}
*/


// 내 답안2
// dp 활용. 배열의 개수를 기준으로 반복문을 활용 -> 배열의 개수를 늘려가며, 중간의 배열이 팰린드롬이라면, 그 배열의 양 끝단이 같으면 해당 배열은 팰린드롬이라 판단.
#include <iostream>
#include <vector>

#define MAX_N 2001

using namespace std;

vector<int> NumArr;
bool dp[MAX_N][MAX_N];

void cache(const int N)
{
	for (int i = 0; i < N; i++)
	{
		dp[i][i] = true;
		if (i + 1 < N && NumArr[i] == NumArr[i + 1])
		{
			dp[i][i + 1] = true;
		}

	}
	for (int k = 3; k <= N; k++)
	{
		for (int i = 0; i <= N-k; i++)
		{
			if (dp[i + 1][i + k - 2] && (NumArr[i] == NumArr[i + k - 1]))
			{
				dp[i][i + k - 1] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N = 0;
	int M = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;

		cin >> num;
		NumArr.push_back(num);
	}
	cache(N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int S = 0;
		int E = 0;

		cin >> S >> E;
		cout << dp[S - 1][E - 1] << '\n';
	}
}




// 답안 예시1 - https://www.acmicpc.net/source/75566934
// 배열에 대해서, 양 끝단의 같음을 확인한 후, 그 다음 끝단에 대해서 같은 계산을 하는 재귀 함수를 통해서 구현.
/*

#include<unistd.h>
#include<sys/syscall.h>
#include<cstdio>
char readbuf[1 << 20], writebuf[1 << 20];

void stdio_bufset() {
	setvbuf(stdin, readbuf, _IOFBF, 1 << 20);
	setvbuf(stdout, writebuf, _IOFBF, 1 << 20);
}

template<typename T>
inline T readd(void) {
	T temp = 0;
	//bool flag = 0;
	//char c = getchar_unlocked();
	//if (c == '-') flag = 1;
	char c;
	while ((c = getchar_unlocked()) & 16) { // only usable when inputs are numbers or space
		// c&16 is true when c is
		// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, :, ;, <, =, >, ?
		// p, q, ..., z, {, |, }, ~
		temp = 10 * temp + (c & 15);
	}
	//return flag ? -temp : temp; 
	return temp;
}




#include<iostream>
#include<cstring>

bool mem[2001][2001];
bool checked[2001][2001];
int arr[2001];

char check(int s, int e) {
	if (!checked[s][e]) {
		// not evaluated yet
		if (e - s < 2) {
			mem[s][e] = (arr[s] == arr[e]);
		}
		else {
			mem[s][e] = (arr[s] == arr[e]) && check(s + 1, e - 1);
		}
		checked[s][e] = true;
	}
	return mem[s][e];
}

int main() {
	stdio_bufset();

	int n = readd<int>();
	for (int i = 1; i <= n; ++i) {
		arr[i] = readd<int>();
	}

	int m = readd<int>();
	for (int i = 0; i < m; ++i) {
		int s, e;
		s = readd<int>();
		e = readd<int>();
		putchar_unlocked(check(s, e) ? '1' : '0');
		putchar_unlocked('\n');
	}
}

*/