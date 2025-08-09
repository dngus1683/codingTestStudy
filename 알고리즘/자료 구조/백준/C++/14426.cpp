// 접두사 찾기
// N개의 문자열이 주어진다. M개의 접두가 리스트가 주어질 때, 문자열 집합 중 하나라도 접두사에 해당하는 횟수를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_N 10'001

using namespace std;

typedef struct TrieNode
{
	bool isEnd;
	TrieNode* children[26];

	TrieNode()
	{
		isEnd = false;
		fill(children, children + 26, nullptr);
	}
};

class Trie
{
private:
	TrieNode* root;

public:
	Trie()
	{
		root = new TrieNode();
	}

	void Insert(const string& s)
	{
		TrieNode* node = root;

		for (char c : s)
		{
			int idx = c - 'a';

			if (node->children[idx] == nullptr)
			{
				node->children[idx] = new TrieNode();
			}
			node = node->children[idx];
		}

		node->isEnd = true;
	}

	bool Search(const string& s)
	{
		TrieNode* node = root;

		for (char c : s)
		{
			int idx = c - 'a';

			if (node->children[idx] == nullptr)
			{
				return false;
			}

			node = node->children[idx];
		}

		return node->isEnd;
	}

	bool StartWith(const string& prefix)
	{
		TrieNode* node = root;

		for (char c : prefix)
		{
			int idx = c - 'a';

			if (node->children[idx] == nullptr)
			{
				return false;
			}

			node = node->children[idx];
		}

		return true;
	}
};


int N = 0;
int M = 0;
int answer = 0;
Trie trie = Trie();

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s = "";

		cin >> s;
		trie.Insert(s);
	}

	for (int q = 0; q < M; q++)
	{
		string prefix = "";

		cin >> prefix;

		if (trie.StartWith(prefix)) answer++;
	}

	cout << answer;
}