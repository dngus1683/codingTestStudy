// 30
// 양의 정수 N이 주어진다. 해당 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 구하라.


// 내 답안1
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string N = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	sort(N.begin(), N.end(), greater<>());

	int sumOfNumber = 0;
	for (int i = 0; i < N.length(); i++)
	{
		sumOfNumber += (N[i] - '0');
	}

	if (sumOfNumber % 3 != 0 || N.back() != '0')
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << N << '\n';
	}
}