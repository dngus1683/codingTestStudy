/*

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int Answer;
int N, preDist, dist, idx;
int p[300000] ;
int v[300000];
int cv[300000];
int i;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int T, test_case;


	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		cin >> N;
		for (i = 0; i < N; i++) {
			cin >> p[i];
		}
		for (i = 0; i < N; i++) {
			cin >> cv[i];
			v[i] = cv[i];
		}
		sort(cv, cv + N);

		for (i = 0; i < N; i++) {
			int j = 0;
			dist = 0;
			idx = -1;

			while (!(cv[i] == v[j] && i == j) && (j < N)) {
				if (cv[i] == v[j]) {
					preDist = dist;
					dist = abs(p[i] - p[j]);
					if ((p[i] - p[j]) * (p[i] - p[idx]) < 0 && idx != -1) {
						dist = preDist;
					}
					else preDist ? (dist < preDist ? idx = j : dist = preDist) : idx = j;
				}
				j++;
			}
			if (cv[i] == v[j] && i == j) {
				dist = 0;
				idx = j;
			}
			Answer += dist;
			v[idx] = -1;
		}



		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
*/