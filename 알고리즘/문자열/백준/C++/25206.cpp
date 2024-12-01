// 너의 평점은
// 20개의 과목에 대해 과목명 + 학점 + 등급 이 공백으로 구분되어 주어질 때, 해당 학생의 전공평점을 출력하라.


// 내 답안1
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

float answer = 0.f;
float SumOfCredit = 0.f;
unordered_map<string, float> grades;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	grades["A+"] = 4.5f;
	grades["A0"] = 4.0f;
	grades["B+"] = 3.5f;
	grades["B0"] = 3.0f;
	grades["C+"] = 2.5f;
	grades["C0"] = 2.0f;
	grades["D+"] = 1.5f;
	grades["D0"] = 1.0f;
	grades["F"] = 0.0f;

	for (int i = 0; i < 20; i++)
	{
		string name;
		float credit;
		string grade;

		cin >> name >> credit >> grade;

		if (grade == "P") continue;

		answer += (credit * grades[grade]);
		SumOfCredit += credit;
	}

	answer /= SumOfCredit;

	cout << answer << '\n';

}






// 답안 예시 - https://www.acmicpc.net/source/56726247
// A+과 같은 등급 역시 문자열로 처리.
/*
#include <stdio.h>

int main(){
	char a[51],b[3];
	float c,sum=0;
	int n=0;

	for(int i=0;i<20;i++){
		scanf("%s %f %s",a,&c,b);
		sum += c*(((b[0]<'F')?'E'-b[0]:0) + ((b[1]=='+')?0.5:0));
		if(b[0]!='P') n+=c;
	}
	printf("%f",sum/n);
	return 0;
}
*/