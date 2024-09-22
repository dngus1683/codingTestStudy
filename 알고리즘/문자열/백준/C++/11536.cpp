// 줄 세우기
// 악독한 코치 주혁은 선수들을 이름 순으로 세우는 것을 좋아한다. 더 악독한 것은 어떤 순서로 서야할지도 알려주지 않았다! 선수들의 이름이 주어질 때 어떤 순서로 이루어져있는지 확인해보자.


// 내 답안1
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int NameCount = 0;
	short StateFlag = -1;
	string FlagArr[3] = { "DECREASING", "INCREASING", "NEITHER" };
	string PreStr;
	string NowStr;

	cin >> NameCount;

	for (int i = 0; i < NameCount; i++)
	{
		cin >> NowStr;
		if (i != 0)
		{
			if ((StateFlag == 1 || StateFlag == -1) && PreStr <= NowStr)
			{
				StateFlag = 1;
			}
			else if ((StateFlag == 0 || StateFlag == -1) && PreStr >= NowStr)
			{
				StateFlag = 0;
			}
			else
			{
				StateFlag = 2;
			}
		}
		PreStr = NowStr;
	}
	cout << FlagArr[StateFlag] << endl;


}



// 답안 예시1 - https://www.acmicpc.net/source/65763208
// 앞의 문자열과 뒷 문자열 간의 차이를 보는 방법은 같지만, 상태를 계속해서 업데이트 하는 방법은 다르다.
// 예시의 경우, 보다 단순하게 정수 하나를 증가하거나 감소시켜, 최종적으로 문자열 개수와 비교하여 출력한다.
/*
#include <stdio.h>
#include <string.h>

int main() {
	int n, rs = 0;
	char arr[13], arr1[13];
	scanf("%d %s", &n, arr);
	for (int i = 1; i < n; i++) {
		scanf("%s", arr1);
		if (strcmp(arr1, arr) > 0) rs++;
		else rs--;
		strcpy(arr, arr1);
	}
	n--;
	printf("%s", n == rs ? "INCREASING" : n == rs * -1 ? "DECREASING" : "NEITHER");
}
*/