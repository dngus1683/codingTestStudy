// 2024는 무엇이 특별할까?
// To(n)은 n의 약수 중 홀수의 개수며, Te(n)은 n의 약수 중 짝수의 개수다.
// N, K가 주어질 때, Te(n) = K x To(n)을 만족하는 N 이하의 양의 정수 개수를 구하라.


// 내 답안1
#include <iostream>

#define MAX_T 100'001
#define MAX_N 10e18
#define MAX_K 10e18
#define ull unsigned long long

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T = 0;

	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		ull answer = 0;
		ull N = 0;
		ull K = 0;
		ull twos = 1;
		ull num = 1;

		cin >> N >> K;

		for (ull i = 1; i <= K && twos <= N; i++)
		{
			twos *= 2;
		}

		answer = (N / twos + 1) / 2;

		cout << answer << '\n';
	}
}




// 답안 예시1 - https://www.acmicpc.net/source/89541782
/*
#include <bits/stdc++.h>

using namespace std;
//타우e와 타우o의 "k 배수 관계 라는 것에" 초점.


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	unsigned long long n, k;

	cin >> T;
	while(T--){
		cin >> n >> k;
		if(k > 62){
			cout << 0 << "\n";
		}else{
			cout << (((n >> k) +1 )/ 2 ) << "\n";
		}
	}
}
*/