// 나머지와 몫이 같은 수
// N으로 나누었을 때 나머지와 몫이 같은 모든 자연수의 합을 구하는 프로그램을 작성하시오. 예를 들어 N=3일 때, 나머지와 몫이 모두 같은 자연수는 4와 8 두 개가 있으므로, 그 합은 12이다.


// 내 답안1
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	unsigned long long int answer = 0;
	unsigned long long int num;

	cin >> num;
	
	for (int i = 1; i < num; i++)
	{
		answer += ((num * i) + i);
	}

	cout << answer;

}




// 답안 예시1 - https://www.acmicpc.net/source/16789954
/*
#include <stdio.h>

int main()
{
	long long n;
	scanf("%lld", &n);
	printf("%lld",(n+1)*n*(n-1)/2);
}

*/