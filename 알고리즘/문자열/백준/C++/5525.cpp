// IOIOI
// N+1 개의 I와 N개의 O이 교대로 나오는 문자열을 Pn이라 하자. I, O로만 이루어져 있는 문자열이 주어졌을 때, Pn이 몇개 있는지 구하라.


// 내 답안1  50%
// substr을 사용 -> 시간복잡도가 O(n)이므로 시간초과.
/*
#include <iostream>
#include <string>

#define MAX_N 1000001

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int ans = 0;
	string s = "";
	string Pn = "";

	cin >> N;
	cin >> M;
	cin >> s;

	for (int i = 0; i < N; i++)
	{
		Pn += "IO";
	}
	Pn += "I";

	for (int i = 0; i <= M - (2*N + 1); i++)
	{
		if (s.substr(i, (2 * N + 1)) == Pn)
		{
			ans++;
		}
	}

	cout << ans << '\n';
}
*/


// 내 답안2 - 100%
// Pn 순열의 최대 길이를 구해서 계산.
#include <iostream>

#define MAX_N 1000001

using namespace std;

int N = 0;
int M = 0;
int ans = 0;
char s[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int Icnt = 0;

	cin >> N;
	cin >> M;
	cin >> s;

	if (s[0] == 'I') Icnt = 1;

	for (int i = 1; i < M; i++)
	{
		if (s[i] == 'I')
		{
			if (s[i - 1] != 'I')
				Icnt++;
			else
			{
				ans += (Icnt - N > 0 ? Icnt - N : 0);
				Icnt = 1;
			}
		}
		else if (s[i] == 'O')
		{
			if (s[i - 1] == 'O')
			{
				ans += (Icnt - N > 0 ? Icnt - N : 0);
				Icnt = 0;
			}
		}
	}

	ans += (Icnt - N > 0 ? Icnt - N : 0);

	cout << ans << '\n';
}












// 답안 예시 - https://www.acmicpc.net/source/53682507
// 직접 I와 O을 따라가면서 카운팅
/*
#include <iostream>
#include <string>
using namespace std;

int n, m, cnt;
string s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> s;

	for (int i = 0; i < m - 2 * n; i++) {
		if (s[i] == 'I') {
			int len = 0;
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				len++;
				i = i + 2;
				if (len == n)	{
					len--;
					cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}
*/