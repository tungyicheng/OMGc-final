#include<iostream>
#include <algorithm>
using namespace std;
void HI()
{
    cout<<"HI"<<endl;
}
void SAY( void (*func)())
{
    func();
}
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    SAY(HI);
    int a[3]={1,2,3};
    sort(a,a+3,[](int a,int b){return a>b;});
    cout<<a[0]<<a[1]<<a[2];
    return 0;
}
/*
只要一個函式符合以下「其中一個」條件，它就能被稱為高階函式 (Higher-Order Function)：

把函式當作「輸入參數」
把函式當作「輸出結果」回傳
*/