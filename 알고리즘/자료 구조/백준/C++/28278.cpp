// 스택 2
// 정수를 저장하는 스택을 구현하라.


// 내 답안1
#include <iostream>

#define MAX_N 1'000'001

using namespace std;

int N = 0;
int stack[MAX_N];

template <typename T>
class Stack
{
public:
	Stack();

	void Push(T In);
	void Pop();
	size_t Size();
	bool Empty();
	T Top();
private:
	T arr[MAX_N];
	size_t idx;
};

template <typename T>
Stack<T>::Stack() : idx(0), arr{}
{
}

template <typename T>
void Stack<T>::Push(T In)
{
	arr[idx] = In;
	idx++;
}

template <typename T>
void Stack<T>::Pop()
{
	if (idx == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << arr[idx - 1] << '\n';
		idx--;
	}
}

template<typename T>
size_t Stack<T>::Size()
{
	cout << idx << '\n';
	return idx;
}

template<typename T>
bool Stack<T>::Empty()
{
	cout << (idx == 0 ? 1 : 0) << '\n';
	return (idx == 0 ? true : false);
}

template<typename T>
T Stack<T>::Top()
{
	if (idx == 0)
	{
		cout << -1 << '\n';
		return T(-1);
	}
	else
	{
		cout << arr[idx - 1] << '\n';
		return arr[idx - 1];
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	static Stack<int> stack;

	cin >> N;
	while (N--)
	{
		int order = 0;

		cin >> order;

		switch (order)
		{
		case 1:
		{
			int x = 0;
			cin >> x;

			stack.Push(x);
		}
			break;
		case 2:
			stack.Pop();
			break;
		case 3:
			stack.Size();
			break;
		case 4:
			stack.Empty();
			break;
		case 5:
			stack.Top();
			break;
		default:
			break;
		}
	}
}