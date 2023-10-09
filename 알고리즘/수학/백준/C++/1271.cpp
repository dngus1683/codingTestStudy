// 엄청난 부자2
// n개의 돈을 m명에서 동등하게 나눠가질 때, 한사람 당 가져가는 돈과, 모두 나누고 남은 돈을 출력하라.


// 내 답안1
// 해당 문제는 python으로는 간단하게 두 수를 입력받고 몫과 나머지만 출력하면 되지만 돈과 사람의 최댓값이 10^1000으로 어떠한 자료형으로도 받지를 못할만큼 큰 수다.
// 때문에 큰 수 사칙 연산을 구현해야한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool isBigger(vector<int> a, vector<int> b){
    bool comp = true;
    bool isbig = true;
    bool isequ = true;
    vector<int>::iterator ita, itb;
    
    if(a.size() < b.size())
        comp = false;
    else if (a.size() == b.size()){
        for(ita = a.begin(), itb = b.begin() ; ita != a.end(); ita++, itb++){
            int na = *ita;
            int nb = *itb;
            
            if(na > nb){
                isequ = false;
            }
            else if(na < nb && isequ){
                comp = false;
                break;
            }
            else if(na < nb && !isequ){
                
            }
        }
    }
    return comp;
}

vector<int> multi(vector<int> a, int b){
    vector<int> mul;
    vector<int>::iterator it;
    int over = 0;
    
    for(it=a.end()-1; it!=a.begin()-1; it--){
        int n = *it;
        mul.push_back((n*b+over) % 10);
        over = (n*b+over) / 10;
        if(it == a.begin() && over != 0)
            mul.push_back(over);
    }
    reverse(mul.begin(), mul.end());
    return mul;
}

vector<int> sub(vector<int> a, vector<int> b){
    vector<int> sub;
    vector<int>::iterator ita, itb;
    
    for(ita = a.end()-1, itb = b.end()-1; ita != a.begin()-1 && itb != b.begin()-1; ita--, itb--){
        int na = *ita;
        int nb = *itb;
        
        if((na-nb) < 0){
            (*(ita-1))--;
            sub.push_back(10+na-nb);
        }
        else{
            sub.push_back(na-nb);
        }
    }
    while(ita != a.begin()-1){
        sub.push_back(*ita);
        ita--;
    }
    
    reverse(sub.begin(), sub.end());
    
    int zeroProcess = 0;
    for(int i=1; i < sub.size() ; i++){
        if(!(sub[i-1] == 0))
            break;
        zeroProcess = i;
    }
    return vector<int> (sub.begin()+zeroProcess,sub.end());
}

vector<int> sum(vector<int> a, vector<int> b){
    vector<int> sum;
    vector<int>::iterator ita, itb;
    int over = 0;
    
    for(ita=a.end()-1, itb=b.end()-1; ita != a.begin()-1 && itb != b.begin()-1; ita--, itb--){
        int na = *ita;
        int nb = *itb;
        
        sum.push_back((na+nb)%10 + over);
        over = (na+nb) / 10;
    }
    if(ita >= a.begin()){
        while(ita != a.begin()-1){
            sum.push_back(*ita + over);
            over = 0;
            ita--;
        }
    }
    else if (itb >= b.begin()){
        while(itb != b.begin()-1){
            sum.push_back(*itb + over);
            over = 0;
            itb--;
        }
    }
    else{
        if(*(ita+1) + *(itb+1) >= 10){
            sum.push_back(over);
        }
    }
    reverse(sum.begin(), sum.end());
    return sum;
}


void divide(vector<int> a, vector<int> b){
    vector<int> div, re(a.begin(), a.begin()+b.size()-1);
    
    for(int i = b.size()-1; i < a.size(); i++ ){
        if(!isBigger(re, b)){
            if(re.size() == 1 && re[0] == 0)
                re[0] = a[i];
            else
                re.push_back(a[i]);
        }
        if(isBigger(re, b)){
            for(int j = 9; j>0 ;j--){
                vector<int> mul = multi(b, j);
                if(isBigger(re, mul)){
                    re = sub(re, mul);
                    div.push_back(j);
                    break;
                }
            }
        }
        else{
            div.push_back(0);
        }
    }
    for(int d=0; d<div.size(); d++){
        if(d == 0 && div[0] == 0) continue;
        cout << div[d];
    }
    cout << endl;
    for(int r=0; r<re.size(); r++){
        cout << re[r];
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char money[2000], man[2000];
    vector<int> my, mn;
    
    cin >> money >> man;
    
    for(int i=0; i<strlen(money); i++){
        my.push_back(money[i] - '0');
    }
    for(int i=0; i<strlen(man); i++){
        mn.push_back(man[i] - '0');
    }
    
    
    
    
//    cout << comp(my, mn);
    
    divide(my, mn);
    
}
