// K번째 수
// 수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N  5'000'001

using namespace std;

int N = 0;
int K = 0;
vector<int> A;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		A.push_back(num);
	}

	sort(A.begin(), A.end());

	cout << A[K - 1] << '\n';


}






// 답안 예시 - https://www.acmicpc.net/source/3502943 
// nth_element() 사용.
/*
#include<cstdio>
#include<algorithm>
using namespace std;

int map[5000000];
char buf[1 << 18];//여기에 저장함

int idx, nidx;//현재 인덱스 nidx 총몇개 입력받았는지

			  //stdin 구간만큼 입력받고 버퍼 배열에 저장 리턴은 한글자만 리턴
static inline char read()
{
	if (idx == nidx)
	{
		nidx = fread(buf, 1, 1 << 18, stdin);
		idx = 0;
	}
	return buf[idx++];
}
//한정수 리턴
static inline int readInt()
{
	int sum = 0;
	char now = read();
	bool flag = 0;
	while (now == ' ' || now == '\n')
		now = read();
	if (now == '-')
	{
		flag = true;
		now = read();
	}
	while (now != ' '&&now != '\n'&&now!=EOF)
	{
		sum = sum*10+now-'0';
		now = read();
	}
	return flag?-sum:sum;
}
int main()
{
	int N, K;
	N = readInt();
	K = readInt();

	int M = N;
	while (M--)
		map[M] = readInt();
	nth_element(map, map + K - 1, map + N);
	printf("%d", map[K-1]);
	return 0;
}

*/