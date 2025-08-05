// 저항
// 저항 색이 주어질 때, 저항 값을 구하라.


// 내 답안1
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, pair<int, int>> hmap = {
	{"black", {0, 1}},
	{"brown", {1, 10}},
	{"red", {2, 100}},
	{"orange", {3, 1000}},
	{"yellow", {4, 10000}},
	{"green", {5, 100000}},
	{"blue", {6, 1000000}},
	{"violet", {7, 10000000}},
	{"grey", {8, 100000000}},
	{"white", {9, 1000000000}},
};

int main()
{
	long long answer = 0;
	string s1 = "";
	string s2 = "";
	string s3 = "";

	cin >> s1;
	answer = hmap[s1].first;

	cin >> s2;
	answer = answer * 10 + hmap[s2].first;

	cin >> s3;
	answer *= hmap[s3].second;

	cout << answer;
}