/*什麼是抽象類別？

在 C++ 中，抽象類別就像是一份設計藍圖(?)。它用來規定繼承它的子類別必須實作哪些功能。

只要一個類別裡面包含**至少一個「純虛擬函式 (Pure Virtual Function)」，這個類別就會自動變成抽象類別。

什麼是純虛擬函式 (Pure Virtual Function)？

就是在宣告虛擬函式的最後面加上 = 0。他可以現在先不寫內容，留給繼承我的子類別那邊再寫。

virtual void draw() = 0;
所以一個抽象類別 be like:
*/
#include<iostream>
using namespace std;
class hi {
    public:
    virtual void sayHI() = 0;
};
class Hello : public hi{
    public:
    void sayHI(){
        cout<<"hello"<<endl;
    }
};
int main()
{
    Hello H;
    H.sayHI();
    return 0;
}
//包含 sayHI 這個純虛擬函式，因此 Hello 會是抽象類別
