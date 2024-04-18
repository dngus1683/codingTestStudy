// 설탕 배달
// N 킬로그램 설탕을 3, 5킬로그램을 담을 수 있는 봉지에 담아 모두 옮겨야 한다. 가장 적은 봉투 수를 구하라. 정확하게 킬로그램을 맞추지 못할 경우 -1을 출력하라.


// 내 답안1
// DP
#include <iostream>
#include <algorithm>

#define MAX_N 5001

using namespace std;

int kg[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;


	kg[1] = kg[2] = kg[4] = - 1;
	kg[3] = kg[5] = 1;
	for (int i = 6; i < MAX_N; i++)
	{
		if (kg[i - 3] == -1)
		{
			if (kg[i - 5] == -1)
				kg[i] = -1;
			else
				kg[i] = kg[i - 5] + 1;
		}
		else
		{
			if (kg[i - 5] == -1)
				kg[i] = kg[i - 3] + 1;
			else
				kg[i] = min(kg[i - 3], kg[i - 5]) + 1;
		}
	}

	cout << kg[n] << '\n';
}





// 답안 예시1
// 그리디 알고리즘
// n이 5의 배수가 될 때 까지 3을 뺀 후, n이 음수가 되면 -1 출력, 0이 되면 3 봉지로만 포장, 5의 배수가 되면 해당 수를 5로 나눠 5 봉지도 사용.
/*
#include<stdio.h>
main()
{
	int num,i;
	scanf("%d",&num);
	for(i=0;num%5&&num>=0;i++)num-=3;
	if(num<0)printf("-1");
	else printf("%d",i+(num/5));
}
*/