// Hashing
// 길이가 L인 소문자 문장이 주어질 때, 가장 대표적인 해시 함수인 H = sigma(ar^i mod M) 의 해시 값을 구하라.


// 내 답안1
#include <iostream>
#include <cmath>

#define MAX_L 51

using namespace std;

char arr[MAX_L];

int pow(long long int a, int b, long long int m)
{
	long long int p = 1;

	for (int i = 0; i < b; i++)
	{
		if (i == 0) p = a % m;
		else p = ((p % m) * (a % m)) % m;
	}
	return p;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long int l, h = 0, r = 31, M = 1234567891;

	cin >> l;
	cin >> arr;

	for (int i = 0; i < l; i++)
	{
		h += (((long long int)arr[i] - 96)%M * pow(r, i, M))%M;
	}

	cout << h % M << '\n';
}