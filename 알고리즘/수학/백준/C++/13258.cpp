// 복권 + 은행
// 매주 금요일마다 모든 은행 이용자의 잔고만큼의 전체 티켓 중 한장을 뽑아 해당 티켓 주인에게 이자 J원을 준다. 
// 은행 계좌를 가지고 있는 사람의 수와 그들의 초기 잔고, 이자 J원이 주어질 때, C주가 지난 후 나의 통장 잔고 기댓값을 구하라.


// 내 답안1
#include <iostream>

#define MAX_N 51

using namespace std;

int N = 0;
int C = 0;
double J = 0;
double init = 0;
double pre = 0;
double total = 0;
double answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		double num = 0;
		cin >> num;
		total += num;
		if (i == 0)
		{
			answer = pre = num;
		}
	}
	cin >> J;
	cin >> C;

	while (C--)
	{
		answer = pre/total * J + answer;
		total = total + J;
		pre = answer;
	}
	cout.precision(10);
	cout << answer;
}