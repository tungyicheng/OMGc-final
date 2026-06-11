#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
class Date2026
{
    private:
    int d,m,m1,d1,plusd;
    int calculate_week(int month,int date)
    {
        int w,year=2026,q,k;
        if(month < 3 )
        {
            month += 12;
            year--;
        }
        q=year/100;
        k=year%100;
        w =(( date + (13*(month+1))/5 +k +k/4+q/4+5*q)+6)%7;
        return w;
    }
    public:
    void plusday(int days)
    {
        plusd=days;
        if(m==-1||d==-1) return;
        int dd=d;
        int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};

        for(int i = 0 ;i<m-1;i++) dd+=mon[i];

        if(dd+days<=365&&0<dd+days) dd+=days;
        else
        {
            d=-1;
            m=-1;
            return;
        }
        for(int i = 0 ;i<12;i++)
        {
            if(dd>mon[i]) dd-=mon[i];
            else{
                d1=dd;
                m1=i;
                break;;
            }
        }
        return;
    }
    Date2026(int month,int date){
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (date > 0 && date <= 31)
        {
            m = month;
            d = date;
        }
        else
        {
            m = -1;
            d = -1;
        }
        break;

    case 4: case 6: case 9: case 11:
        if (date > 0 && date <= 30)
        {
            m = month;
            d = date;
        }
        else
        {
            m = -1;
            d = -1;
        }
        break;

    case 2:
        if (date > 0 && date <= 28)
        {
            m = month;
            d = date;
        }
        else
        {
            m = -1;
            d = -1;
        }
        break;

    default:
        m = -1;
        d = -1;
        break;
    }
    }
    Date2026()
    {
        m=1;
        d=1;
    }
    void print(){
        if(d==-1||m==-1)
        {
            cout<<"a date not in 2026";
            return;
        }
        int w=calculate_week(m,d),w1=calculate_week(m1+1,d1);
        string month[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},\
        week[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        cout<<plusd<<" days after "<<week[abs(w)]<<", "<<\
        month[abs(((m-1)+12)%12)]<<" "<<d<<", 2026"<<" is "\
        <<week[abs(w1)]<<", "<<month[m1]<<" "\
        <<d1<<", 2026.";
        /*20 days after Thursday, January 1, 2026 is Wednesday, January 21, 2026.*/
        return;
    }
};
int main(int argc, char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int month, day,plusDay;
        cin >> month>> day>>plusDay;
        Date2026 date = Date2026(month, day);
        date.plusday(plusDay);
        date.print();
        cout << endl;
    }
}