#include<bits/stdc++.h>
using namespace std;
class Date2026
{
    private:
    int d,m;
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
    Date2026(int month,int date){
        m=month; 
        d=date;
    };
    void print(){
        int w=calculate_week(m,d);
        string month[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},\
        week[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        cout<<week[abs(w)]<<", "<<month[abs(((m-1)+12)%12)]<<" "<<d<<", 2026";
    }
};
int main(int argc, char * argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);
    long long j=0;
    for(int i = 0;i<(1<<35);i++)
    {
        j++;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        j;
        int month, day;
        cin >> month>> day;
        Date2026 date = Date2026(month, day);
        date.print();
        cout << endl;
    }
}