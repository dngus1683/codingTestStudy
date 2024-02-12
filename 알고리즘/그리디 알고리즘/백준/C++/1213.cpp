// 펠린드롬 만들기
// 대문자로 된 이름이 주어졌을 때, 문자의 순서를 적절히 바꿔 펠린드롬(바로 읽어도 거꾸로 읽어도 같은, 오름내림차순)으로 바꿔라.


// 내 답안1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	char name[50];
	int asc[26] = {0};
	int oddCnt = 0;
	int oddIndex = 0;

	scanf("%s", name);

	for (int i = 0; i < strlen(name); i++) {
		asc[int(name[i]) - 65] ++;
	}
	for (int i = 0; i < 26; i++) {
		if (asc[i] % 2 == 1) {
			oddCnt++;
			oddIndex = i;
			asc[i] = (asc[i] - 1)/2;
		}
		else {
			asc[i] = asc[i] / 2;
		}
	}
	if (oddCnt >= 2 ) {
		printf("I'm Sorry Hansoo\n");
	}
	else {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < asc[i]; j++)
				printf("%c", i + 65);
		}
		if (oddCnt == 1) {
			printf("%c", oddIndex + 65);
		}
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < asc[i]; j++)
				printf("%c", i + 65);
		}
		printf("\n");

	}


	return 0;
}

// 내 답안2
#include <iostream>
#include <cstring>

typedef struct Odd
{
    int count = 0;
    int al;
}Odd;

using namespace std;

int alpha[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Odd odd;
    string s;

    cin >> s;

    for(int i=0; i<s.size(); i++)
    {
        alpha[s[i]-'A'] += 1;
    }

    int idx = 0;
    char ans[s.length()];
    for(int i=0; i<26; i++)
    {
        if(alpha[i]%2 == 1)
        {
            odd.count++;
            odd.al = i;
            alpha[i]--;
        }
        if(odd.count > 1)
        {
            cout << "I'm Sorry Hansoo" << '\n';
            return 0;
        }
        for(int j=0; j<alpha[i]/2; j++)
        {
            ans[idx] = 'A'+i;
            idx++;
        }
    }
    if(odd.count == 1)
    {
        ans[idx] = 'A'+odd.al;
        idx++;
    }
    for(int i=25; i>=0; i--)
    {
        for(int j=0; j<alpha[i]/2; j++)
        {
            ans[idx] = 'A'+i;
            idx++;
        }
    }
    for(int i=0; i<s.length(); i++)
        cout << ans[i];
    cout << '\n';
}
