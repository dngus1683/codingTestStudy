// 트리와 쿼리
// 무방향 무가중치 그래프가 주어진다. 입력되는 정점을 루트로 하는 서브트리의 정점 수를 출력하라.


// 내 답안1
/*
#include <iostream>
#include <vector>

#define MAX_N 100'001

using namespace std;

struct node
{
	int num = 0;
	node* parent = nullptr;
	vector<node*> children;


	node() : num(0), parent(nullptr), children(NULL) {}
	node(int num) : num(num), parent(nullptr), children(NULL) {}
	node(int num, node* parent) : num(num), parent(parent) {}
	node(int num, node* parent, vector<node*> children) : num(num), parent(parent), children(children) {}
};

int N = 0;
int R = 0;
int Q = 0;
bool visited[MAX_N];
vector<int> graph[MAX_N];
node* Nodes[MAX_N];



void MakeTree(node* now)
{
	visited[now->num] = true;
	for (auto num : graph[now->num])
	{
		if (!visited[num])
		{
			node* child = new node(num, now);

			now->children.push_back(child);
			Nodes[num] = child;
			MakeTree(child);
		}
	}
}

int dfs(node* now)
{
	int count = now->children.size();

	for (auto child : now->children)
	{
		if (!child->children.empty())
		{
			count += dfs(child);
		}
	}
	return count;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> R >> Q;
	for (int i = 0; i < N-1; i++)
	{
		int a = 0;
		int b = 0;

		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	node* root = new node(R);
	Nodes[R] = root;

	MakeTree(root);

	while (Q--)
	{
		int num = 0;

		cin >> num;
		cout << dfs(Nodes[num]) + 1 << endl;
	}
}
*/


// 내 답안2
#include <iostream>
#include <vector>

#define MAX_N 100'001

using namespace std;

int N = 0;
int R = 0;
int Q = 0;
vector<int> graph[MAX_N];
vector<bool> visited(MAX_N);
vector<int> answer(MAX_N);

int dfs(int now)
{
	visited[now] = true;
	
	int count = 1;
	for (auto next : graph[now])
	{
		if (visited[next]) continue;
		
		count += dfs(next);
	}

	answer[now] = count;

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		int a = 0;
		int b = 0;

		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(R);

	while (Q--)
	{
		int num = 0;

		cin >> num;
	
		cout << answer[num] << '\n';
		
	}
}