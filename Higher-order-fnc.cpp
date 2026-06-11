#include<iostream>
using namespace std;
void HI()
{
    cout<<"HI"<<endl;
}
void SAY( void (*func)())
{
    func();
}
int main()
{
    SAY(HI);
    return 0;
}
/*
只要一個函式符合以下「其中一個」條件，它就能被稱為高階函式 (Higher-Order Function)：

把函式當作「輸入參數」
把函式當作「輸出結果」回傳
*/