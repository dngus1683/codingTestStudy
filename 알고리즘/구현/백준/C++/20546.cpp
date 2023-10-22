// 기적의 매매법
// 준현이는 BNP(Buy and Pray) 매매법을 통해 주식을 산다. 이는 매일 주식을 살 수 있다면 최대한 사고 절대 팔지 않는 방법이다.
// 성민아는 TIMING을 보고 투자한다. 모든 거래는 전량 매수와 전량 매도로 진행하며, 해당 주가가 3일 연속 증가하면 매도하고,
// 3일 연속 하락하면 매수한다.
// 위의 방식을 통해 1일부터 14일 까지 총 14일 동안 한 주식에 대해 매매를 진행할 때, 최종적으로 더 많은 자산을 가진 사람은 누구인지 구하라.


// 내 답안1
#include <iostream>
#include <vector>

using namespace std;

class StockFlow{
    int down= 0;
    int up = 0;
public:
    void setFlow(int pre, int now){
        if(pre > now){
            down += 1;
            up = 0;
        }
        else if(pre < now){
            up += 1;
            down = 0;
        }
        else{
            up = 0;
            down = 0;
        }
    }
    int showDown(){
        return down;
    }
    int showUp(){
        return up;
    }
};

class Person{
protected:
    int asset;
    int stock = 0;
public:
    Person(int a){
        asset = a;
    };
    void show(){
        cout << asset << endl;
    }
    int calAsset(int price){
        asset += stock * price;
        return asset;
    }
};

class BNP : public Person{
public:
    BNP(int a) : Person(a){}
    void setAssetNStock(int price){
        if(asset >= price){
            stock += asset/price;
            asset = asset % price;
        }
    }
};

class TIMING : public Person{
public:
    TIMING(int a) : Person(a){}
    void setAssetNStock(int price, StockFlow sf){
        int up = sf.showUp(), down = sf.showDown();
        if(asset >= price && down >= 3){
            stock += asset / price;
            asset = asset % price;
        }
        else if(up >= 3){
            asset += stock * price;
            stock = 0;
        }
    }
};

int main(){
    ios_base::sync_with_stdio();

    int a, pres, bA, tA;
    StockFlow sf;
    vector<int> stock;

    cin >> a;

    BNP b(a);
    TIMING t(a);

    for(int i=0; i<14; i++){
        int s;
        cin >> s;
        stock.push_back(s);
    }
    pres = stock[0];
    for(int i=0; i<14; i++){
        sf.setFlow(pres, stock[i]);
        b.setAssetNStock(stock[i]);
        t.setAssetNStock(stock[i], sf);
        pres = stock[i];
    }
    bA = b.calAsset(stock[13]);
    tA = t.calAsset(stock[13]);
    if(bA > tA)
        cout << "BNP" << '\n';
    else if (bA < tA)
        cout << "TIMING" << '\n';
    else
        cout << "SAMESAME" << '\n';
}
