// 보물상자 비밀번호
// 상자의 각 변에 16진수로 표현된 숫자가 같은 개수로 나열되어 있다. 이를 시계방향으로 한 칸씩 움직여 숫자 배치를 바꿀 수 있다.
// 각 변의 숫자들을 차례로 연결하여 하나의 숫자로 표현했을 때, K번 쨰로 큰 숫자가 보물상자의 비밀번호다.
// 비밀번호를 구하라.


// 내 답안1
/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	// freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N =0;
        int K = 0;
        int OneSide = 0;
        int MaxNum = 1;
        string numbers = "";
        queue<int> box;
        vector<int> answer;
        
        cin >> N >> K;
        cin >> numbers;
        for(int i = numbers.size()-1; i>=0; i--)
        {
            if(numbers[i] >= '0' && numbers[i] <='9')
            {
                box.push(numbers[i]-'0');
            }
            else
            {
                box.push(numbers[i]-'A' + 10);
            }
        }
        OneSide = N / 4;
       
       // 회전 구현
       for(int i= 0; i<OneSide; i++)
       {
           for(int j=0; j<N; j++)
           {
               int num = 0;
               int hexNum = 1;
               for(int k =0 ; k<OneSide; k++)
               {
                   num += box.front()*hexNum;
                   box.push(box.front());
                   box.pop();
                   hexNum *= 16;
               }
               answer.push_back(num);
               j += (OneSide-1);
           }
           box.push(box.front());
           box.pop();
       }
		
        sort(answer.begin(), answer.end() , greater<int>());
        int idx = 0;
        int pre = 0;
        
		while(--K)
        {
            while(answer[idx] == answer[idx+1])
            {
                idx++;
            }
            idx++;
        }

        
        
		 cout << '#' << test_case << ' ' << answer[idx] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
    
    