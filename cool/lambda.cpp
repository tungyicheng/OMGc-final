// 篩篩月份星期幾 今年第幾天以後 不同條件的篩法 有幾種合法的日期
#include <bits/stdc++.h>
using namespace std;

class Date2026 {
public:
    int m, d; // m=月份, d=日期

    // 回傳指定月份的天數
    int dim(int mo) {
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        return days[mo - 1];
    }

    // 計算今年第幾天 (1/1=1, 1/2=2, ...)
    int doy() {
        int tot = 0;
        for (int i = 1; i < m; i++) tot += dim(i); // 把前幾個月的天數加總
        return tot + d;
    }

    // 計算星期幾 (0=Sun, 1=Mon, ..., 6=Sat)
    // 2026/1/1 是星期四(4)，所以加4再%7
    int wd() {
        return (doy() - 1 + 4) % 7;
    }

    // 把星期幾數字轉成英文字串
    string wdName() {
        string n[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        return n[wd()];
    }

    // 把月份數字轉成英文字串
    string moName() {
        string n[] = {"January","February","March","April","May","June",
                      "July","August","September","October","November","December"};
        return n[m - 1];
    }

    string str() {
        return wdName() + ", " + moName() + " " + to_string(d) + ", 2026";
    }
};

void filterDates(vector<Date2026>& dates, function<bool(Date2026)> cond) {
    for (auto& dt : dates)
        if (cond(dt))
            cout << dt.str() << "\n";
}

int main() {
    int ft, fv;
    cin >> ft >> fv;

    vector<Date2026> dates;
    int m, d;
    while (cin >> m >> d) {
        Date2026 dt;
        dt.m = m; dt.d = d;
        dates.push_back(dt);
    }

    if (ft == 1)
        filterDates(dates, [fv](Date2026 dt) { return dt.m == fv; });      // 篩月份
    else if (ft == 2)
        filterDates(dates, [fv](Date2026 dt) { return dt.wd() == fv; });   // 篩星期幾
    else if (ft == 3)
        filterDates(dates, [fv](Date2026 dt) { return dt.doy() > fv; });   // 篩第幾天之後

    return 0;
}