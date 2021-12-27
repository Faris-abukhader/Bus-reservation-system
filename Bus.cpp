//  Bus.cpp
//  BusReservationSystem
//  Created by admin on 2021/11/18.
#include "string"
#include <vector>
#define MAX_BUS_SEAT 30;
#define SMALL_BUS_EXPENSES 150;
#define SMALL_BUS_SEAT_NUMBER 20;
#define BIG_BUS_EXPENSES 200;
#define BIG_BUS_SEAT_NUMBER 50;
using namespace std;
struct Seat {
    string index;
    long passengerID;
    long requestID;
    bool isFree;
    
    
    Seat(){}
    Seat(string index,bool isFree):index(index),isFree(isFree){}
    
    
    void bookSeat(long userID,long requestID){
        this->passengerID = userID;
        this->requestID = requestID;
        isFree = false;
    }
};

class Bus {
    long id;
    char type;
    int seatNum;
    int expenses;
    vector<Seat> seats;
    bool isFull;
public:
    
    //default constrctor for using container
    Bus(){}
    
    // full constractor to intial the object variables through the parameters value
    Bus(char type){
        this->id = generateId();
        this->type = type;
        this->isFull=false;
        if(type==66||type==98){
            expenses = BIG_BUS_EXPENSES;
            seatNum = BIG_BUS_SEAT_NUMBER;
        }else if(type==83||type==115){
            expenses = SMALL_BUS_EXPENSES;
            seatNum = SMALL_BUS_SEAT_NUMBER;
        }else{
            expenses = SMALL_BUS_EXPENSES;
            seatNum = SMALL_BUS_SEAT_NUMBER;
        }
        
        
        setupSeat();
        
    }
    
    // this function to check whether this bus seat is full or not by looping into all seats (struct) and check whether this seat isFree or not
    
    // each time we create new object from this class will call this function to create the seats to the buss
    void setupSeat(){
        for(int i=1;i<=seatNum/5;i++){
            for(int j=1;j<=3;j++){
                Seat newSeat(to_string(i)+to_string(j),true);
            }
        }
    }
    
    
    int isBusFull(){
        return isFull;
    }
 
    // receiving request and add it to bus class which it will take one seat from bus seat list
    void bookSeat(long passengerID,long requestID){
        for(Seat s: seats)
            if(s.isFree==true) {
                s.bookSeat(passengerID,requestID);
                this->isFull = false;
            }
        this->isFull = true;
    }
    
    // getter and setter for class attributes
    long getID(){return this->id;}
    void setID(long id){this->id=id;}
    char getType(){return this->type;}
    void setType(char type){this->id=type;}
    int getSeatNum(){return this->seatNum;}
    int getExpenses(){return this->expenses;}

    
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
        for(int i=1;i<=10;i++){id+=digit[rand()%9+1]*pow(10, i);}
        return id;
    }

    
    
    
    // descrition function which give us short intro for specific object
    string description(){
        return "this bus type "+to_string(type)+" and it's id is "+to_string(id)+" total seat number is "+to_string(seatNum)+" its total expenses is "+to_string(expenses);
    }

};
