// 단어 나누기
// 단어 하나가 주어질 때, 세 부위로 나눈 후 각 그것들을 앞뒤를 뒤집고 다시 병합했을 때, 사전 순으로 가장 앞서는 단어를 출력하라.


// 내 답안1
#include <iostream>
#include <string>
#include <algorithm>

#define MAX_L 51

using namespace std;

string s;
string answer;
string dp[MAX_L][MAX_L];

void backtracking(int start, int cnt, string ss)
{
	if (cnt == 2)
	{
		if (dp[start][s.length() - 1] == "")
		{
			for (int j = s.length()-1; j >= start; j--)
			{
				dp[start][s.length() - 1] += s[j];
			}
		}
		ss += dp[start][s.length() - 1];
		answer = min(answer, ss);
		return;

	}
	for (int i = 1; i < s.length() - start; i++)
	{
		if (dp[start][start + i - 1] == "")
		{
			for (int j = start + i - 1; j >= start; j--)
			{
				dp[start][start + i - 1] += s[j];
			}
		}

		backtracking(start + i, cnt + 1, ss + dp[start][start + i - 1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	for (int i = 0; i < MAX_L; i++)
	{
		answer += 'z';
	}

	backtracking(0, 0, "");

	cout << answer << '\n';

}





// 답안 예시 - https://www.acmicpc.net/source/44603864
/*
#include <stdio.h>
#include <string.h>

char tmp[53];
char str[53];
char zzz[53];

void reverse(int x, int y){
   for(int i=x; i<y; i++){
	  tmp[x+y-i-1] = str[i];
   }
}


int main(){

   scanf("%s", str);
   int len = 0;

   for(int i=0 ;i<51; i++) {
	  if (str[i] == '\0') break;
	  else len++;
   }

   for(int i=0; i<len; i++) {
	  zzz[i]='z';
   }
   zzz[len]= '\0';

   for(int i=1; i<len ; i++){
	  for(int j=i+1; j<len; j++) {
		 reverse(0,i); //0번 째 인덱스부터 i-1 인덱스까지 > i개 글자
		 reverse(i,j);
		 reverse(j,len);
		 tmp[len]='\0';

		 //printf("%s %d %d\n",tmp,i,j);

		 if(strcmp(zzz,tmp) > 0){
			strcpy(zzz,tmp);
		 }

	  }
   }
   printf("%s",zzz);
   return 0;
}
*/