// 사전 순 최대 공통 부분 수열
// 두 배열이 주어질 때, 두 배열이 공통으로 갖는 부분 수열 중 사전 순으로 가장 나중인 배열의 크기와 원소들을 구하라.


// 내 답안1
// 직접 부분 수열을 모두 구해 같은 수열 찾기 - 중도 포기(주어지는 수열의 최대 크기는 100이며, 최대 크기로 주어딘다면 해당 배열의 부분 수열 개수는 2^100이다. 이는 너무 큰 값이기 때문에 시간이 많이 소모될 우려가 있다.
/*
 #include <iostream>
 #include <vector>
 #include <algorithm>

 #define MAX_N 101

 using namespace std;

 vector<int> A;
 vector<int> B;
 vector<int> OrderA;
 vector<int> OrderB;
 vector<vector<int>> SetA;
 vector<vector<int>> SetB;

 vector<vector<int>> combination(int end, int PreIdx, vector<int>& order, vector<int>& arr, vector<int>& pick, vector<vector<int>>& set)
 {
     for(int i=0; i<end; i++)
     {
         if(PreIdx >= order[i]) continue;
         pick.push_back(arr[order[i]]);
         set.push_back(pick);
         combination(end, order[i], order, arr, pick, set);
         pick.pop_back();
     }
     return set;
 }

 vector<int> MakeOrder(vector<int>& arr)
 {
     vector<int> tmp;
     vector<int> order(arr.size());
     tmp = arr;
     sort(tmp.begin(), tmp.end());

     for(int i=0; i< arr.size(); i++)
     {
         for(int j=0; j<arr.size(); j++)
         {
             if(arr[j] == tmp[i])
             {
                 order[i] = j;
                 break;
             }
         }
     }

     return order;
 }

 int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(0);

     int N = 0;
     int M = 0;

     cin >> N;
     for(int i=0; i<N; i++)
     {
         int num = 0;

         cin >> num;
         A.push_back(num);
     }
     cin >> M;
     for(int i=0; i<M; i++)
     {
         int num = 0;

         cin >> num;
         B.push_back(num);
     }

     OrderA = MakeOrder(A);
     OrderB = MakeOrder(B);

     vector<int> pick;

     combination(A.size(), -1, OrderA, A, pick, SetA);
     combination(B.size(), -1, OrderB, B, pick, SetB);


     int sizeA = SetA.size();
     int sizeB = SetB.size();
     int AnsIdx = 0;

     for(int i=sizeA; i>= 0; i--)
     {
         for(int j=sizeB; j>=0; j--)
         {
             int flag = 1;
             if(SetA[i].size() != SetB[j].size())
             {
                 flag = 0;
                 continue;
             }
             for(int k=0; k<SetA[i].size(); k++)
             {
                 if(SetA[i][k] != SetB[j][k])
                     flag = 0;
             }
             if(flag == 1)
             {
                 cout << SetA[i].size() << '\n';
                 for(int k=0; i<SetA[i].size(); i++)
                 {
                     cout << SetA[i][k] << ' ';
                 }
                 cout << '\n';
                 return 0;
             }
         }
     }

     cout << 0 <<'\n';
 }
 */



// 내 답안2
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 101

using namespace std;

vector<int> A;
vector<int> B;
vector<int> tmp;
vector<int> order;
bool visited[MAX_N];

vector<int> FindSet(int a, int b, int PreA, vector<int>& pick)
{
    for(int i=a; i<A.size(); i++)
    {
        if(PreA != -1 && order[PreA] > order[i]) continue;
        for(int j=b; j<B.size(); j++)
        {
            if(A[order[i]] == B[j])
            {
                pick.push_back(B[j]);
                FindSet(i+1, j+1, i, pick);
                return pick;
            }
        }
    }
    return {};
}

int main()
{
    int N = 0;
    int M = 0;

    cin >> N;
    for(int i=0; i<N; i++)
    {
        int num = 0;

        cin >> num;
        A.push_back(num);
    }
    cin >> M;
    for(int i=0; i<M; i++)
    {
        int num = 0;

        cin >> num;
        B.push_back(num);
    }

    tmp = A;
    sort(tmp.begin(), tmp.end(), greater<int>());

    for(int i=0; i<A.size(); i++)
    {
        for(int j=0 ;j<A.size(); j++)
        {
            if(tmp[i] == A[j] && !visited[j])
            {
                order.push_back(j);
                visited[j] = true;
                break;
            }
        }
    }

    vector<int> pick;

    pick = FindSet(0, 0, -1, pick);

    cout << pick.size() << '\n';
    if(!pick.empty())
    {
        for(int i=0; i<pick.size(); i++)
        {
            cout << pick[i] << ' ';
        }
        cout << '\n';
    }

}
/*
 4
 1 1 3 1
 6
 9 1 2 1 4 1
 */
