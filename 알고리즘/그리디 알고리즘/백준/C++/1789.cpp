// 수들의 합
// 서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값을 구하라.


// 내 답안1
#include <iostream>

#define ull unsigned long long
#define MAX_S 4'294'967'295

using namespace std;

ull S = 0;
ull N = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> S;

	for (ull i = 1; i <= S; i++)
	{
		if (S < ((i * (i + 1)) / 2))
		{
			cout << i - 1 << '\n';
			break;
		}
	}
	if (S == 1)
	{
		cout << 1 << '\n';
	}
}




// 답안 예시1 - https://www.acmicpc.net/source/29620881
// 1부터 하나씩 더해가며 비교
/*
#import<cstdio>

long int S,s,i;

main()
{
	scanf("%ld",&S);
	while((s+=++i)<=S);
	printf("%d",--i);
}
*/