// 카드1
// 1~N의 숫자 카드를 작은 숫자가 위로 오도록 쌓아놓는다. 이후, 맨 위 카드를 버리고 그 다음 위 카드를 덱 맨 아래에 놔두는 것을 반복한다.
// 버리는 카드를 순서대로 출력하고 마지막에 남게 되는 카드를 출력하라.


// 내 답안1
#include <iostream>
#include <queue>

using namespace std;

int N = 0;
queue<int> cards;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cards.push(i);
	}

	while (true)
	{
		int answer = cards.front();
		
		cout << answer << ' ';
		cards.pop();

		if (cards.empty())
		{
			break;
		}

		cards.push(cards.front());
		cards.pop();
	}


}