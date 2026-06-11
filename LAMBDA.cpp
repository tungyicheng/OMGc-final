#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    void (*HI)() = []() {
        cout << "HI" << endl;
    };
    HI(); 
    int a[3]={1,2,3};
    sort(a,a+3,[](int a,int b){return a>b;});
    cout<<a[0]<<a[1]<<a[2];
    return 0;
}
//Lambda 是無名臨時函數，能就地定義並直接使用。