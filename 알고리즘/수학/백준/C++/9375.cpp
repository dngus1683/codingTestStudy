// 패션왕 신해빈
// 해빈이는 한번 입은 옷의 조합을 다시 입지 않는다. (ex. 오늘: {모자 안경 상의} -> 다음날: 하의를 추가로 입던지, 모자말고 목도리를 하던지.)
// 입을 수 있는 옷의 조합 수를 구하라.


// 내 답안1
#include <iostream>
#include <map>
#include <cstring>

#define MAX_N 31

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TestCase = 0;

	cin >> TestCase;
	while (TestCase--)
	{
		int N = 0;
		int ans = 1;
		map<string, int> m;
		map<string, int>::iterator iter;

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string s1, s2;

			cin >> s1 >> s2;

			if (m.find(s2) == m.end())
			{
				m[s2] = 1;
			}
			else
			{
				m[s2] += 1;
			}
		}
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			ans *= (iter->second + 1);
		}
		cout << ans - 1 << '\n';
	}
} 






// 답안 예시1 - https://www.acmicpc.net/source/32110471
// 결과 도출 방식은 똑같은데, 문자열 입력한 후 개수를 세는 방식이 다름.
// 내 답안1: map stl 사용. 답안 예시1: 문자열 배열의 인덱스와 개수를 저장하는 정수 인덱스를 일치시켜 따로 저장.
/*
#include<stdio.h>
#include<string.h>
int main(void){
	int t;
	char a[21];
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		int n,b[30]={0},x=1;
		char c[30][21]={};
		scanf("%d",&n);
		for(int z=0;z<n;z++){
			scanf("%s",a);
			scanf("%s",a);
			int u=0;
			while(c[u][0]!=0){
				if(strcmp(c[u],a)==0)
					break;
				u++;
			}
			strcpy(c[u],a);
			b[u]++;
		}
			for(int m=0;m<30;m++){
				if(b[m]!=0)
					x*=b[m]+1;
			}
		printf("%d\n",x-1);
	}
}
*/