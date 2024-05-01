// 나는야 포켓몬 마스터 이다솜
// N마리의 포켓몬이 포켓몬 도감에 저장되어 있다. 도감에 관련된 M개의 문제가 주어질 때, 문제가 도감 번호라면 그에 해당하는 포켓몬 이름을, 이름이라면 도감 번호를 출력하라.


// 내 답안1
// 해시 맵 직접 구현
/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#define MAX_N 100009
#define ullint unsigned long long int 

using namespace std;

typedef struct Node
{
	int number;
	char name[100];
	Node* NextNode;
}Node;

Node* HashTable[MAX_N + 1];
char dic[MAX_N][100];

ullint CalHashKey(char ch[])
{
	ullint HashValue = 0;
	ullint m = MAX_N;
	ullint a = 31;

	for (int i = strlen(ch) - 1; i >= 0; i--)
	{
		HashValue = (HashValue + (ch[i] - 'a' + 1) * a) % m;
		a = (a * a) % m;
	}

	return HashValue;
}

void InputHashTable(Node* n)
{
	ullint key = CalHashKey(n->name);
	if (HashTable[key] == NULL)
	{
		HashTable[key] = n;
	}
	else
	{
		n->NextNode = HashTable[key];
		HashTable[key] = n;
	}
}

int FindHashValue(char ch[])
{
	ullint key = CalHashKey(ch);

	Node* now = HashTable[key];
	while (strcmp(now->name, ch))
	{
		now = now->NextNode;
	}

	return now->number;
}

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		Node* ob = new Node;

		scanf("%s", dic[i]);

		strcpy(ob->name, dic[i]);
		ob->number = i;

		InputHashTable(ob);
	}

	for (int i = 0; i < M; i++)
	{
		int num;
		char s[100];

		if (scanf("%d", &num))
		{
			printf("%s\n", dic[num]);
		}
		else if(scanf("%s", s))
		{
			printf("%d\n", FindHashValue(s));
		}
	}
}
*/


// 내 답안2
// c++ stl 사용.
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> hm;
string dic[100009];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> dic[i];
		hm[dic[i]] = i;
	}

	for (int i = 0; i < m; i++)
	{
		string s;

		cin >> s;
		if (isdigit(s[0]))
		{
			cout << dic[stoi(s)] << '\n';
		}
		else
		{
			cout << hm[s] << '\n';
		}
	}
}

