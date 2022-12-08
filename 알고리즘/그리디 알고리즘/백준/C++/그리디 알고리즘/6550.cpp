/* �׸��� �˰��� 6550 �κ� ���ڿ� (�ǹ�5)

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

/*	����
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
//	while()�� ���ǹ��� scanf("%s %s", s,t) �� �־��� ���� �Է��� ���̻� ���� �� ���ѷ����� ���� ������ ��°��� ��� ��������
//	cin >> s >> t�� �־��� ���� ���������� �۵��ߴ�.
//	scanf�� ����� ���̾�����, scanf("%s %s", s,t ) != EOF �� ����ؾ��ߴ�.
//  cin >> �� �Է¹��� ������ �ڷ����� ���� ������� �ʾƵ� �ȴ�. �̴� cin �� ��ü������ ó�����ֱ� �����̴�. 
//	�̷� ���� cin >> s ���� s������ �ڷ����� �����ʴ� ���𰡰� �Է��� �ȴٸ� cin��ü�� ���´� false�� �Ǵ� ���̴�.