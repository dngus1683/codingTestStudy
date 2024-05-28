// 트리 순회
// 이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.
//			A			
//		B		C
//	D		  E	  F
//					G
// 예를 들어 위와 같은 이진 트리가 입력되면,
// + 전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
// + 중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
// + 후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)


// 내 답안1
#include <iostream>
#include <vector>

#define MAX_N 27

using namespace std;

vector<char> graph[MAX_N];
vector<char> preorder;
vector<char> inororder;
vector<char> postorder;

void PreorderTraversal(char now)
{
	preorder.push_back(now);
	for (int i = 0; i < 2; i++)
	{
		if (graph[now - 'A'][i] == '.') continue;
		PreorderTraversal(graph[now-'A'][i]);
	}
}

void InorderTraversal(char now)
{
	int flag = 1;
	for (int i = 0; i < 2; i++)
	{
		if (graph[now - 'A'][i] == '.') continue;
		if (i == 1)
		{
			inororder.push_back(now);
			flag = 0;
		}
		InorderTraversal(graph[now - 'A'][i]);
	}
	if(flag)
		inororder.push_back(now);
}

void PostorderTraversal(char now)
{
	for (int i = 0; i < 2; i++)
	{
		if (graph[now - 'A'][i] == '.') continue;
		PostorderTraversal(graph[now - 'A'][i]);
	}
	postorder.push_back(now);
}

void OutputVector(vector<char>& cv)
{
	for (int i = 0; i < cv.size(); i++)
	{
		cout << cv[i];
	}
	cout << '\n';
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char A, B, C;

		cin >> A >> B >> C;
		graph[A - 'A'].push_back(B);
		graph[A - 'A'].push_back(C);
	}

	PreorderTraversal('A');
	InorderTraversal('A');
	PostorderTraversal('A');

	OutputVector(preorder);
	OutputVector(inororder);
	OutputVector(postorder);
}









// 답안 예시1 - https://www.acmicpc.net/source/40176557
// 내 답안1과 방식은 같지만, 훨씬 단순화함.
/*
#include<stdio.h>

int tree[27][2], a, b, c, n;

void f(int v, int n)
{
  if(v == '.') return;
  if(n == 2) printf("%c", v);
  f(tree[v][0], n);
  if(n == 1) printf("%c", v);
  f(tree[v][1], n);
  if(n == 0) printf("%c", v);
}

int main(void)
{
  scanf("%d", &n);
  while(n--)
  {
	scanf(" %c %c %c", &a, &b, &c);
	tree[a][0] = b;
	tree[a][1] = c;
  }
  n = 3;
  while(n--)
  {
	f('A', n);
	printf("\n");
  }

  return 0;
}
*/