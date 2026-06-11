#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
class Date
{
    protected:
    int d,m,d1,m1;
    public:
    Date(int month,int date,int month1,int date1)
    {
        d=date;
        m=month;
        m1=month1;
        d1=date1;
    }
    virtual int getFirstDayWeek()=0;
    
    int get_month()
    {
        return m;
    }
    int get_date()
    {
        return d;
    }
};
class Date2026 : public Date
{
    private:
    const int year=2026;
    public:
    int getFirstDayWeek()
    {
        int y=year-1;
        int date=1,month=1,k=y%100,q=y/100;
        int w =(( date + (13*(month+1))/5 +k +k/4+q/4+5*q)+6)%7;
        return w;
    }
    char compareTwoDay()
    {
        if(m>m1)
        {
            return '>';
        }
        else if(m<m1)
        {
            return '<';
        }
        else
        {
            if(d>d1) return '>';
            else if(d<d1) return '<';
            else return '=';
        }
    }
    Date2026(int month,int date,int month1,int date1) : Date(month,date,month1,date1){}
};
class Date2027 : public Date
{
    private:
    const int year=2027;
    public:
    Date2027(int month,int date,int month1,int date1) : Date(month,date,month1,date1){}
    int getFirstDayWeek()
    {
        int y=year-1;
        int date=1,month=1,k=y%100,q=y/100;
        int w =(( date + (13*(month+1))/5 +k +k/4+q/4+5*q)+6)%7;
        return w;
    }
};
int calculateDays(Date* D,int year)
{
    int w,q,y=year,k;
    int month = D->get_month();
    int date = D->get_date();
    if(month < 3 )
    {
        month += 12;
        y=year-1;
    }
    q=y/100;
    k=y%100;
    w =(( date + (13*(month+1))/5 +k +k/4+q/4+5*q)+6)%7;
    return w;
}
void printDate(Date* D,int year) 
{   
    int m,d;
    m=D->get_month();
    d=D->get_date();
    int w=calculateDays(D,year);
    string month[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},\
    week[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout<<week[abs(w)]<<", "<<month[abs(((m-1)+12)%12)]<<" "<<d<<", "<<year;
}
int main(int argc, char * argv[]) {
    cin.tie(0);ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int month, day,year,month1,day1;
        cin >> month>> day>>month1>>day1;
        Date2026 date(month,day,month1,day1);
        cout<< date.compareTwoDay()<<endl;
    }
}