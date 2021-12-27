//  Card.cpp
//  BusReservationSystem
//  Created by admin on 2021/11/18.
#ifndef CARD
#define CARD
#define CARD_INTIAL_PRICE 10
#include "Date.cpp"
#include <vector>
using namespace std;
class Card {
    long id;
    int price;
    int *amount;
    
public:
    //default constractor using with binary tree container
    Card(){this->amount= new int[1];}

    // constractor with parameter to intial all the variable and id is generated with this class using generateID function
    Card(int amount){
        this->id = generateId();
        this->amount = new int[1];
        this->amount[0]=amount;//.push_back(amount);// = amount;
        this->price = CARD_INTIAL_PRICE;
        
    }
    
    // getter and setter for all attributes
    long getID(){return this->id;}
    void setID(long id){this->id=id;}
    char getPrice(){return this->price;}
    void setPrice(char Price){this->price=Price;}
    int getAmount(){return this->amount[0];}
    void setAmount(int amount){*this->amount=amount;}
    

    void assign(Card otherCard){
        this->setID(otherCard.getID());
        this->setPrice(otherCard.getPrice());
        this->setAmount(otherCard.getAmount());
    }
    
    bool useCard(int price){
        if(price>*amount)return false;
        *this->amount-=price;
        return true;
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
        for(int i=1;i<=10;i++){id+=digit[rand()%9+1]*pow(10, i);}
        return id;
    }
    

    // descrition function which give us short intro for specific object
    string description(){
        return "card id "+to_string(id)+" amount  "+to_string(*amount);
    }
    
};
#endif
