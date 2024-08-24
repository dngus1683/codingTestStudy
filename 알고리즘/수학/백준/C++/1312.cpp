// 소수
// 피제수(분자) A와 제수(분모) B가 있다. 두 수를 나누었을 때, 소숫점 아래 N번째 자리수를 구하려고 한다. 예를 들어, A=3, B=4, N=1이라면, A÷B=0.75 이므로 출력 값은 7이 된다.


// 내 답안1
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A = 0;
	int B = 0;
	int tmp = 0;
	int N = 0;
	int answer = 0;

	cin >> A >> B >> N;

	tmp = A % B;
	for (int i = 0; i < N; i++)
	{
		tmp *= 10;
		answer = tmp / B;
		tmp = tmp % B;
	}

	cout << answer << endl;
	
}
