// 출력 형식이 잘못되었습니다.
// 두 문자열이 주어질 때, 아래의 규칙에 따라 두 문자열이 같은지 다른지 구분하라.
// 1. 대문자 소문자 구분 x
// 2. 공백이 존재한다면 크기는 상관 x
// 3. 문자열 맨 앞과 맨 뒤의 공백은 상관 x
// 4. 특수 부호의 앞 뒤 공백은 상관 x
// 5. 여는 괄호끼리 구분 x
// 6. 닫는 괄호끼리 구분 x
// 7. 쉼표와 세미콜론 구분 x


// 내 답안1
#include <iostream>
#include <string>

using namespace std;

int T = 0;

string transform(string& A)
{
	string Atemp;

	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] >= 'A' && A[i] <= 'Z')
		{
			Atemp += A[i] - ('A' - 'a');
		}
		else if (A[i] == ' ')
		{
			bool IsFront = false;
			bool IsBack = true;
			bool IsNearBySp = false;

			if (i == 0) IsFront = true;

			if ((i - 1) >= 0)
			{
				if (A[i - 1] == '(' || A[i - 1] == ')'
					|| A[i - 1] == '[' || A[i - 1] == ']'
					|| A[i - 1] == '{' || A[i - 1] == '}'
					|| A[i - 1] == '.' || A[i - 1] == ','
					|| A[i - 1] == ';' || A[i - 1] == ':')
				{
					IsNearBySp = true;
				}
			}
			while (++i < A.length())
			{
				if (A[i] == '(' || A[i] == ')'
					|| A[i] == '[' || A[i] == ']'
					|| A[i] == '{' || A[i] == '}'
					|| A[i] == '.' || A[i] == ','
					|| A[i] == ';' || A[i] == ':')
				{
					IsNearBySp = true;
				}
				if (A[i] != ' ')
				{
					IsBack = false;
					break;
				}
			}

			if (!(IsFront || IsBack || IsNearBySp))
			{
				Atemp += ' ';
			}
			i--;
		}
		else if (A[i] == '[' || A[i] == '{')
		{
			Atemp += '(';
		}
		else if (A[i] == ']' || A[i] == '}')
		{
			Atemp += ')';
		}
		else if (A[i] == ';')
		{
			Atemp += ',';
		}
		else
		{
			Atemp += A[i];
		}
	}

	return Atemp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	cin.ignore();

	int cnt = 1;
	while (cnt <= T)
	{
		string A = "";
		string B = "";
		string Atemp = "";
		string Btemp = "";

		getline(cin, A);
		getline(cin, B);

		Atemp = transform(A);
		Btemp = transform(B);

		cout << "Data Set " << cnt++ << ": ";
		if (Atemp == Btemp)
		{
			cout << "equal" << '\n';
		}
		else
		{
			cout << "not equal" << '\n';
		}
		cout << '\n';
	}
}