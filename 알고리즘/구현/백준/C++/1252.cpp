// 이진수 덧셈
// 두 개의 이진수를 입력받아 이를 더하는 프로그램을 작성하시오.


// 내 답안1
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> char2vec(char a[]){
    vector<int> v;
    int isOne = 0;
    for(int i=0; i<strlen(a); i++){
        if(a[i] == '1') isOne = 1;
        if(isOne)
            v.push_back(a[i] - '0');
    }
    if(v.empty())
        return vector<int> (1,0);
    return v;
}

vector<int> binSbin(vector<int> a, vector<int> b){
    vector<int> c;
    vector<int>::iterator ita, itb;

    int over = 0;
    for(ita=a.end()-1, itb=b.end()-1; ita != a.begin()-1 && itb != b.begin()-1; ita--, itb--){
        int na = *ita;
        int nb = *itb;
        int s = (na ^ nb) ^ over;
        over = ((na & nb) | (na & over) | (nb & over));

        c.push_back(s);
    }

    for(;ita != a.begin()-1 ; ita--){
        int na = *ita;
        int s = na ^ over;
        over = na & over;

        c.push_back(s);
    }
    for(;itb != b.begin()-1 ; itb--){
        int nb = *itb;
        int s = nb ^ over;
        over = nb & over;

        c.push_back(s);
    }
    if(over == 1)
        c.push_back(over);


    reverse(c.begin(), c.end());
    return c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> va, vb, vc;
    char a[100], b[100];

    cin >> a >> b;
    va = char2vec(a);
    vb = char2vec(b);

    vc = binSbin(va, vb);
    for(int i =0; i<vc.size(); i++)
        cout << vc[i];
    cout << '\n';
}







// 답안 예시1
// 배열 자체로 각 인덱스 별로 계산을 진행하였고, 올림이 발생하면 다음 인덱스에 1을 추가함으로 구현하였다.
//#include <cstdio>
//
//char arr1[81];
//char arr2[81];
//int car[81];
//int main()
//{
//    int s1, s2;
//    scanf("%s %s", arr1, arr2);
//    for (s1 = 0; arr1[s1] != NULL; ++s1);
//    for (s2 = 0; arr2[s2] != NULL; ++s2);
//    --s1;
//    --s2;
//
//    for (int i = 0; i < 81; ++i) {
//        if (s1 - i >= 0) car[80 - i] += (arr1[s1 - i] - '0');
//        if (s2 - i >= 0) car[80 - i] += (arr2[s2 - i] - '0');
//        if (car[80 - i] >= 2) {
//            car[80 - i] -= 2;
//            car[79 - i] = 1;
//        }
//    }
//    bool flag = false;
//    for (int i = 0; i < 81; ++i) {
//        if (car[i] != 0) flag = true;
//        if (flag) printf("%d", car[i]);
//    }
//    if (!flag) printf("0");
