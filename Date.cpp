//  Date.cpp
//  BusReservationSystem
//  Created by admin on 2021/11/16.
#include "iostream"
#ifndef DATE
#define DATE
using namespace std;
class Date {

    int year,month,day,hour,minute,second;
    
public:
    
    // default constractor , intial the all vars with zero
    Date(){
        this->year = 0;
        this->month = 0;
        this->day = 0;
        this->hour = 0;
        this->minute = 0;
        this->second = 0;

    }
    
    //this constructor for giving the inital value for date , the rest varaiable we will give it default value zero.
    Date(int year,int month,int day,int nothing){
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
    
    //this constructor for giving the inital value for time , the rest varaiable we will give it default value zero.
    Date(int hour,int minute,int second){
        this->year = 0;
        this->month = 0;
        this->day = 0;
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    
    //this comprehasive constructor for giving the inital value for all variable.
    Date(int year,int month,int day,int hour,int minute,int second){
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    
    // 12 functions getter and setter for all this class attributies.
    void setYear(int year){this->year = year;}
    int  getYear(){return year;}
    void setMonth(int month){this->month = month;}
    int getMonth(){return month;}
    void setDay(int day){this->day = day;}
    int getDay(){return day;}
    void setHour(int hour){this->hour = hour;}
    int getHour(){return this->hour;}
    void setMinute(int minute){this->minute = minute;}
    int getMinute(){return this->minute;}
    void setSecond(int second){this->second = second;}
    int getSecond(){return this->minute;}
    
    
    // custom setter for date
    void setDate(int year,int month,int day,int nothing){
        this->year = year;
        this->month = month;
        this->day = day;
    }
    
    //custom setter for time
    void setTime(int hour,int minute,int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    
    
    
    void increaseOneDay(){
        if(this->day+1>getMonthDays(this->month)){
            this->day=1;
            if(this->month+1<=12){
                this->month+=1;
            }else{
                this->month=1;
                this->year+=1;
            }
        }else{
            this->day += 1;
        }
    }
    
    
    Date decreaseByMinute(int minute){
        if(this->minute-minute>0){
            this->minute -= minute;
        }else{
            this->minute = this->minute-minute + 60;
            if(hour-1>0){
                this->hour -=1;
            }else{
                this->hour = 23;
                if(this->day-1 >0){
                    this->day-=1;
                }else{
                    if(this->month-1>0){
                        this->day = getMonthDays(this->month-1);
                        this->month-=1;
                    }else{
                        this->day = getMonthDays(12);
                        this->month = 12;
                        this->year-=1;
                    }
                }
            }
        }
        
        return  *this;
    }

    
    
    void decreaseOneDay(){
        if(this->day-1>0){
            this->day -=1;
        }else{
            if(this->month-1>0){
                this->month -=1;
                this->day = getMonthDays(this->month);
            }else{
                this->year -=1;
                this->month = 12;
                this->day = getMonthDays(this->month);
            }
        }

    }

    
    // this function return the total days in any month
    int getMonthDays(int month){
        switch (month) {
            case 1:
                return 31;break;
            case 2:
                return 28;break;
            case 3:
                return 31;break;
            case 4:
                return 30;break;
            case 5:
                return 31;break;
            case 6:
                return 30;break;
            case 7:
                return 31;break;
            case 8:
                return 31;break;
            case 9:
                return 30;break;
            case 10:
                return 31;break;
            case 11:
                return 30;break;
            case 12:
                return 31;break;
            default:
                return -1;break;
        }
    }
    
    // override "-" operation , to use it later for calculate the deadline
    Date operator - (const Date&deadline){
        Date temp;
        if(this->second < deadline.second){
            this->second+=60;
            temp.setSecond(this->second-deadline.second);
            if(minute > 0){
                this->minute--;
                temp.setMinute(this->minute - deadline.minute);
            }else{
                this->minute+=59;
                temp.setMinute(this->minute - deadline.minute);
                if(this->hour > 0){
                    this->hour--;
                    temp.setHour(this->hour - deadline.hour);
                }else{
                    this->hour=23;
                    temp.setHour(this->hour - deadline.hour);
                }
            }
        }else{
            temp.setSecond(this->second-deadline.second);
            if(this->minute > deadline.minute){
                temp.setMinute(this->minute - deadline.minute);
            }else{
                this->minute+=60;
                temp.setMinute(this->minute - deadline.minute);
                if(this->hour > 0){
                    this->hour--;
                    temp.setHour(this->hour - deadline.hour);
                }else{
                    this->hour = 23;
                    temp.setHour(this->hour - deadline.hour);
                }
            }
        }
        temp.setHour(this->hour - deadline.hour);
        temp.setMinute(this->minute - deadline.minute);
        temp.setSecond(this->second - deadline.second);
        return temp;
    }
    
    
    // similar to = operator
    void assign(Date newDate){
        this->setYear(newDate.getYear());
        this->setMonth(newDate.getMonth());
        this->setDay(newDate.getDay());
        this->setSecond(newDate.getSecond());
        this->setMinute(newDate.getMinute());
        this->setHour(newDate.getHour());
    }
    
    
    //overriding double equal sign operator to to check if these two object or same or not
    bool operator == ( Date &otherDate){
        Date temp;
        if(this->getYear()!= (otherDate.getYear()))return false ;
        if(this->getMonth() !=(otherDate.getMonth()))return false ;
        if(this->getDay()!=(otherDate.getDay()))return false ;
        if(this->getHour()!=(otherDate.getHour()))return false ;
        if(this->getMinute()!=(otherDate.getMinute()))return false ;
        if(this->getSecond()!=(otherDate.getSecond()))return false ;

        return true;

    }
    
    //overriding  not equal sign operator to to check if these two object or same or not
    bool operator != ( Date &otherDate){
        Date temp;
        if(this->getYear()!= (otherDate.getYear()))return true ;
        if(this->getMonth() !=(otherDate.getMonth()))return true ;
        if(this->getDay()!=(otherDate.getDay()))return true ;
        if(this->getHour()!=(otherDate.getHour()))return true ;
        if(this->getMinute()!=(otherDate.getMinute()))return true ;
        if(this->getSecond()!=(otherDate.getSecond()))return true ;

        return false;

    }
    
    // this function convert the date from form YYYY-MM-DD to long var 
    long dateInSecond(){
        return this->second +this->minute*60 + this->hour*3600 + this->day * 3600 * 24 + this->month * 3600 * 24 * this->getMonthDays(this->month) + this->year *this->month * 3600 * 24 * this->getMonthDays(this->month);
    }


    
    // print out the date on format yy-mm-dd hh:mm:ss
    string description(){
        return to_string(this->year)+"-"+to_string(this->month)+"-"+to_string(this->day)+"  "+to_string(this->hour)+":"+to_string(this->minute)+":"+to_string(this->second);
    }
    
    

};

#endif
