/* 그리디 알고리즘 6550 부분 문자열 (실버5)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

string s, t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (cin >> s >> t) {
		int flag = 0;
		int idx = 0;

		for (int i = 0; i < s.length(); i++) {
			for (int j = idx; j < t.length(); j++) {
				if (s[i] == t[j]) {
					flag++;
					idx = j+1;
					break;
				}
			}
			if (!flag) {
				flag++;
				cout << "No\n";
				break;
			}
			else flag = 0;
		}
		if (!flag) {
			cout << "Yes\n";
		}
	}
	return 0;
}

*/

/*	정답
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

string s, t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (cin >> s >> t) {
		int flag = 0;
		int idx = 0;

		for (int i = 0; i < t.length(); i++) {
			if (t[i] == s[idx]) {
				idx++;
			}
			if (idx == s.length()) {
				flag++;
			}
		}
		if (flag) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}
*/
//	while()의 조건문에 scanf("%s %s", s,t) 를 넣었을 때는 입력이 더이상 없을 때 무한루프를 돌아 마지막 출력값이 계속 나왔지만
//	cin >> s >> t를 넣었을 때는 정상적으로 작동했다.
//	scanf를 사용할 것이었으면, scanf("%s %s", s,t ) != EOF 로 사용해야했다.
//  cin >> 은 입력받을 변수의 자료형을 따로 명시하지 않아도 된다. 이는 cin 이 자체적으로 처리해주기 때문이다. 
//	이로 인해 cin >> s 에서 s변수의 자료형에 맞지않는 무언가가 입력이 된다면 cin객체의 상태는 false가 되는 것이다.