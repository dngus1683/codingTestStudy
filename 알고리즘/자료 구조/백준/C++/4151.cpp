// Compound Words
// 여러 개의 문자열이 주어진다.
// 그 중, 꼭 두 개의 서로 다른 문자열을 붙인 문자열이 존재하면 모두 출력하라.


// 내 답안1
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

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

	bool func(const string& s, unordered_map<string, bool>& hmap)
	{
		int cnt = 0;
		TrieNode* node = root;

		for (char c : s)
		{
			int idx = c - 'a';

			if (node->children[idx] == nullptr)
			{
				return false;
			}

			node = node->children[idx];
			cnt++;

			if (node->isEnd)
			{
				string sub = s.substr(cnt, s.length() - cnt);

				if (hmap[sub] == true)
				{
					return true;
				}
			}
		}

		return false;
	}
};

Trie trie;
unordered_map<string, bool> hmap;
vector<string> vec;

int main()
{
	string input = "";

	while (cin >> input)
	{
		vec.push_back(input);
		hmap[input] = true;
		trie.Insert(input);
	}

	for (string s : vec)
	{
		if (trie.func(s, hmap))
		{
			cout << s << '\n';
		}
	}
}
