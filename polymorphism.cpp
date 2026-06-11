#include<bits/stdc++.h>
using namespace std;
class Date
{
    protected:
    int d,m;
    public:
    Date(int month,int date)
    {
        d=date;
        m=month;
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
    Date2026(int month ,int date) : Date(month,date){}
    // int calculate_week(int month,int date)
    // {
    //     int w,q,y=year,k;
    //     if(month < 3 )
    //     {
    //         month += 12;
    //         y=year-1;
    //     }
    //     q=y/100;
    //     k=y%100;
    //     w =(( date + (13*(month+1))/5 +k +k/4+q/4+5*q)+6)%7;
    //     return w;
    // }
    // void print(){
    //     int w=calculate_week(m,d);
    //     string month[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},\
    //     week[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    //     cout<<week[abs(w)]<<", "<<month[abs(((m-1)+12)%12)]<<" "<<d<<", 2026";
    // }
};
class Date2027 : public Date
{
    private:
    const int year=2027;
    public:
    Date2027(int month ,int date) : Date(month,date){}
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
        int month, day,year;
        cin >> month>> day>>year;
        Date *date;
        if(year==2026)
        {
            date = new Date2026(month,day);
        }
        else if(year==2027)
        {
            date = new Date2027(month,day);
        }
        else
        {
            continue;
        }
        printDate(date,year);
        cout << endl;
    }
}