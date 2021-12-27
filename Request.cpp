//  Request.cpp
//  BusReservationSystem
//  Created by admin on 2021/11/18.
#ifndef REQUEST
#define REQUEST
#include "cmath"
#include "string"
#define MAX_BUS_SEAT_NUM 30
using namespace std;
class Request{
private:
    long Id;
    long userId;
    long tripId;
    char paymentMethod;
    int seatIndex[MAX_BUS_SEAT_NUM];
    int seatNum;

public:
    
    //default constrctor for using container
    Request(){}
    
    // full constractor to intial the object variables through the parameters value
    Request(long userId, long tripId, char paymentMethod, int seatIndex[], int seatNum){
        this->Id = generateId();
        this->userId = userId;
        this->tripId = tripId;
        this->paymentMethod = paymentMethod;
        this->seatNum = seatNum;
        for(int i=0;i<seatNum;i++)this->seatIndex[i] = seatIndex[i];
    }
    
    // generate function
    // the working for this function is we declare one char array with all digit we need inside our id
    // then depend in need we create for loop
    // inside for loop each loop we create new random num which we will use it as index
    // we take the index add pass it to our array to take what ever the value from array and add it to the result multi with power of 10^n
    // 10
    // 200
    // 3000
    // 50000
    // result is 5321
    long generateId(){
        long id=0;
        char digit[] =  "0123456789";
        for(int i=1;i<=9;i++){id+=digit[rand()%10+1]*pow(10, i);}
        return id;
    }
    
    long getID(){return this->Id;}
    long getUserID(){return this->userId;}
    
    // descrition function which give us short intro for specific object
    string description(){
        return "request id is "+to_string(Id)+" for user id  "+to_string(userId)+" to trip id "+to_string(tripId)+" with "+(paymentMethod =='c' ? "card":"cash")+" payment method.";
    }
};
#endif
