//  User.cpp
//  BusReservationSystem
//  Created by admin on 2021/11/18.
//  User class
#ifndef USER
#define USER
#include "string"
#include "Card.cpp"
#include "vector"
using namespace std;
#define MAX_CARD_NUMBER 20
class User {
 private:
  long Id;
  string name;
  int phoneNumber;
  vector<Card>cards;
  
 public:
    
  //default constrctor for using container
  User(){}
    
  // full constractor to intial the object variables through the parameters value
  User(long Id,string name,int phoneNumber) {
   this->Id=Id;
   this->name=name;
   this->phoneNumber=phoneNumber;
      
  }
    
    
    long getID(){return this->Id;}
    void setID(long id){this->Id=id;}
    void setName(string name){this->name=name;}
    void setPhoneNo(int phoneNo){this->phoneNumber=phoneNo;}
    int getPhoneNo(){return this->phoneNumber;}
    
    
    void addNewCard(Card card){
        cards.push_back(card);
    }
    
    
    int* getCardsAmount(){
        int *temp = new int[this->cards.size()];
        for(int i=0;i<this->cards.size();i++)temp[i] = this->cards.at(i).getPrice();
        return temp;
    }
    

   // override == to check if two object (users) are same or not
   bool operator == (const User&otherUser){
       if(this->Id != otherUser.Id)return false;
       else if(this->name != otherUser.name)return false;
       else if(this->phoneNumber != otherUser.phoneNumber)return false;
       else return true;
        
    }
        
    Card getCard(long key){
        for(Card c:cards)if(c.getID()==key)return c;
        return Card();
    }
    
    
    // this function we add new uese for card and return bool true if it valid , false mean this time operation is not valid for one of two reason first uses exceed the limitation or card no longer valid.
    bool useCard(Card card,int tripPrice){
        return card.useCard(tripPrice);
    }
    
    
    // descrition function which give us short intro for specific object
    string description(){
        return "user id is "+to_string(Id)+" name is "+name+" phone number is "+to_string(phoneNumber)+"\n"+userCardDescription();
    }
    
    // userCardDescription function which give us short intro for user card description
    string userCardDescription(){
        string result;
        for(Card c:cards)result+=c.description()+"\n";
        return result;
    }
    
    string cardUsesDescription(){
        string result="";
        for(Card c :cards)result+= c.description()+ "\n";
        return result;
    }
};
#endif
