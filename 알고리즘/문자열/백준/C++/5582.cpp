// 공통 부분 문자열
// 두 문자열이 주어졌을 때, 두 문자열에 모두 포함된 가장 긴 공통 부분 문자열의 길이를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int answer = 0;
string s1;
string s2;
bool dp[4001][4001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> s1;
	cin >> s2;

	int idx2 = 0;
	while (idx2 < s2.length())
	{
		int idx1 = 0;
		while (idx1 < s1.length())
		{
			if (dp[idx1][idx2])
			{
				idx1++;
				continue;
			}
			int cnt = 0;
			while (s2[idx2] == s1[idx1])
			{
				dp[idx1][idx2] = true;
				cnt++;
				idx1++;
				idx2++;

				if (idx2 >= s2.length() || idx1 >= s1.length())
				{
					break;
				}
			}
			answer = max(answer, cnt);
			idx1 -= (cnt-1);
			idx2 -= cnt;
		}
		idx2++;
	}

	cout << answer << '\n';
}




// 답안 예시 - https://www.acmicpc.net/source/38733290
// LCP 알고리즘
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 5000000;
int n, k;

vector<vector<int>> group;
int lcp(int k, int i, int j) {
	int ans = 0;
	while (i < n && j < n && k >= 0) {
		if (group[k][i] == group[k][j]) {
			ans += 1 << k;
			i += 1 << k;
			j += 1 << k;
		}
		k--;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1, s2;
	cin >> s1;
	cin >> s2;
	string s;
	s = s1 + "#" + s2;
	int m = s1.size();
	n = s.size();
	vector<int> sa(n);
	group.resize(22, vector<int>(n + 1));
	iota(sa.begin(), sa.end(), 0);
	for (int i = 0; i < n; i++) {
		group[0][i] = s[i];
	}
	group[0][n] = -1;
	int k, len;
	for (k = 0, len = 1; (len >> 1) < n; k++, len <<= 1) {
		auto cmp = [&](int v, int u) {
			if (group[k][v] == group[k][u]) {
				return group[k][v + len] < group[k][u + len];
			}
			else {
				return group[k][v] < group[k][u];
			}
		};
		sort(sa.begin(), sa.end(), cmp);
		group[k + 1][sa[0]] = 0;
		group[k + 1][n] = -1;
		for (int i = 1; i < n; i++) {
			if (cmp(sa[i - 1], sa[i])) {
				group[k + 1][sa[i]] = group[k + 1][sa[i - 1]] + 1;
			}
			else {
				group[k + 1][sa[i]] = group[k + 1][sa[i - 1]];
			}
		}
	}
	int ans = -1;
	for (int i = 1; i < n; i++) {
		if ((sa[i - 1] < m && sa[i] >= m) || (sa[i - 1] >= m && sa[i] < m)) {
			ans = max(ans, lcp(k, sa[i - 1], sa[i]));
		}
	}
	cout << ans;
}
*/