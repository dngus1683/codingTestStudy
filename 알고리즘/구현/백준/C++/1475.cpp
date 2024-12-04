// 방 번호
// 다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다.한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다.
// 다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)


// 내 답안1
#include <iostream>
#include <string>

using namespace std;

int answer = 0;
int cnt[10];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	for (char c : s)
	{
		if (c - '0' == 6 || c - '0' == 9)
		{
			cnt[6]++;
		}
		else
		{
			cnt[c - '0']++;
		}
	}
	cnt[6] = (cnt[6] / 2) + (cnt[6] % 2);

	for (int i = 0; i < 9; i++)
	{
		answer = (answer > cnt[i] ? answer : cnt[i]);
	}

	cout << answer << '\n';
}