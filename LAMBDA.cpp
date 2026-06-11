#include <iostream>
using namespace std;

int main() {
    void (*HI)() = []() {
        cout << "HI" << endl;
    };
    HI(); 
    return 0;
}
//Lambda 是無名臨時函數，能就地定義並直接使用。