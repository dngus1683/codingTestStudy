// 한수
// 어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 
// 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 


// 내 답안1
#include <iostream>

#define MAX_N 1001

using namespace std;

int N = 0;
int answer = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N; 

	for (int i = 1; i <= N; i++)
	{
		int num = (i / 10);
		int gap = (i % 10) - ((i / 10) % 10);

		while ((num / 10) > 0)
		{
			if (((num % 10) - (num / 10) % 10) != gap)
			{
				answer--;
				break;
			}
			num = num / 10;
		}
		answer++;
	}

	cout << answer << '\n';
}