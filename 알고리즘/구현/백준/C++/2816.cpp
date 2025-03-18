// 디지털 티비
// 다양한 채널의 리스트가 주어질 때, KBS1을 첫 번쨰, KBS2를 두 번째로 순서를 바꾸는 방법을 구하라.


// 내 답안1
#include <iostream>
#include <string>

using namespace std;

int N = 0;
int KBS1 = 0;
int KBS2 = 0;
string li[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{	
		cin >> li[i];
	}

	int idx = 0;

	while (true)
	{
		if (li[idx] != "KBS1")
		{
			cout << 1;
			idx++;
		}
		else
		{
			while (idx > 0)
			{
				string tmp = li[idx - 1];
				li[idx - 1] = li[idx];
				li[idx] = tmp;
				idx--;
				cout << 3;
			}
			break;
		}
	}
	if (li[1] == "KBS2") return 0;

	while (true)
	{
		if (li[idx] != "KBS2")
		{
			cout << 1;
			idx++;
		}
		else
		{
			while (idx > 1)
			{
				string tmp = li[idx - 1];
				li[idx - 1] = li[idx];
				li[idx] = tmp;
				idx--;
				cout << 3;
			}
			break;
		}
	}
	
}