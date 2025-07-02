// 콰트로치즈피자
// 여러 피자 토핑의 이름이 주어진다. 토핑의 이름 마지막이 'Cheese'로 끝나는 각기 다른 치즈 토핑 네개가 있을 때 콰트로치즈피자를 만들 수 있다.
// 주어진 토핑들을 확인한 후, 콰트로치즈피자를 만들 수 있는지 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int N = 0;
int cnt = 0;
const string Cheese = "Cheese";
const string Yummy = "yummy";
const string Sad = "sad";
unordered_set<string> hset;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s = "";

		cin >> s;

		if (s.length() >= Cheese.length() && hset.find(s) == hset.end())
		{
			if (s.substr(s.length() - Cheese.length(), Cheese.length()) == Cheese)
			{
				cnt++;
				hset.insert(s);
			}
		}
	}

	if (cnt >= 4)
		cout << Yummy << '\n';
	else
		cout << Sad << '\n';
}