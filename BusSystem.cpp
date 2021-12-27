//  BusSystem.cpp
//  BusReservationSystem
//  Created by admin on 2021/11/18.
#include "string"
#include "iostream"
#include <chrono>
#include <ctime>
#include "BinaryTree.cpp"
#include "User.cpp"
#include "Trip.cpp"
#include "AVL.cpp"
#define DAY_TRIP 3
#define DAT_BUY_IN_ADVANCE 7
#define ONE_DAY_TRIPS 3
#define WEEKLY_CARD_PRICE 79
#define WEEKLY_CARD_LIMIT 3
#define MONTHLY_CARD_PRICE 399
#define MONTHLY_CARD_LIMIT 4
using namespace std;
class BusSystem{
    Date current;
    AVL<long,Trip> trips;
    AVL<long,User> users;
    int tripsTime[ONE_DAY_TRIPS];
    
public:
    BusSystem(Date currentDate,int *tripstime){
        
        
        // intialize the current date from the parameter
        this->current.assign(currentDate);
        
        // intialize the trips time from the parameter
        for(int i=0;i<ONE_DAY_TRIPS;i++)this->tripsTime[i] = tripstime[i];

        
        createTrip();
        // test system speed
//        long * ids = createTrip();
//        testSpeed(ids);

        // first statment , welcoming user , and give the user four choices
        welcoming();
        
        
    }
    
    void welcoming(){
        char userInput=' ';
        do{
            cout<<endl<<endl;
            cout<<" ______________________________"<<endl;
            cout<<"|                              |"<<endl;
            cout<<"| Choose one service [a,b,c,d] |"<<endl;
            cout<<"|                              |"<<endl;
            cout<<"|______________________________|"<<endl<<endl;
            cout<<"a) buy card"<<endl;
            cout<<"b) buy ticket"<<endl;
            cout<<"c) refund ticket"<<endl;
            cout<<"d) close"<<endl<<endl;
            cout<<"==> Please Enter your Choice :";
            char userInput;
            cin>>userInput;
            cout<<endl;

        while (userInput!='a'&&userInput!='b'&&userInput!='c'&&userInput!='d'&&userInput!='s') {
            cout<<"Enter valid input :";
            cin>>userInput;
        }
        if(userInput=='a'){
            addNewUser();
        }else if(userInput=='b'){
            sendRequest();
        }else if (userInput=='c'){
            refundRequest();
        }else if(userInput=='s'){
            trips.inorder();
            users.inorder();
        }else {
            break;
        }
            
        }while (userInput != 'd');
    }
    
    
    void addNewUser(){
        string username;int id;int phoneNo;
        cout<<endl<<endl;
        cout<<"|---------------|"<<endl;
        cout<<"|               |"<<endl;
        cout<<"| SignIn user   |"<<endl;
        cout<<"|               |"<<endl;
        cout<<"|_______________|"<<endl<<endl;

        cout<<"Please Enter your name :";
        cin>>username;
        cout<<"Please Enter your id :";
        cin>>id;
        while (!cin) {
            cout<<"Enter valid id :";
            cin>>id;
        }
        cout<<"Enter your phoneNo :";
        cin>>phoneNo;
        while (!cin) {
            cout<<"Enter valid phoneNo :";
            cin>>phoneNo;
        }
        
        if(!IsUserExist(id)){
            User newUser(id,username,phoneNo);
            users.insert(id, newUser);
        }
        
        string userAnswer;
        cout<<endl<<endl;
        cout<<" ______________________________"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"|    Buying Card operations    |"<<endl;
        cout<<"|                              |"<<endl;
        cout<<"|______________________________|"<<endl<<endl;
        cout<<endl<<endl;
        cout<<"How much you want to charge the card [int] :";
        int amount;
        cin>>amount;
        while (amount<0) {
            cout<<"Please Enter valid amount : ";
            cin>>amount;
        }
        cout<<"confrim [yes] :";
        cin>>userAnswer;
        while (userAnswer!="yes") {
            cout<<"Please Enter valid answer : ";
            cin>>userAnswer;
        }

        // create a new card
        Card newCard(amount);
        // adding the card to target user
        users.search(id)->data.addNewCard(newCard);
        // searching for target user to show his info
        User targetUser = users.search(id)->data;
        
                    
        
        cout<<endl;
        cout<<" _Bought operation info______________________________________________"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<"|   "<<targetUser.description()<<                       "|"<<endl;
        cout<<"|                                                                    |"<<endl;
        cout<<"|____________________________________________________________________|"<<endl<<endl;

        cout<<endl<<endl;
        cout<<" ================================================ "<<endl;
        cout<<"|           Card bought successfully             |"<<endl;
        cout<<" ================================================ "<<endl<<endl;
    }
    
    // change from void to long* for test speed
    long* createTrip(){
        Date temp ;
        temp.assign(current);
        
        // for test speed
        long *tripsID = new long[DAT_BUY_IN_ADVANCE*DAY_TRIP];
        int counter=0;
        
        for(int i=0;i<DAT_BUY_IN_ADVANCE;i++){
            for(int j=0;j<DAY_TRIP;j++){
                temp.setHour(this->tripsTime[j]);
                temp.setMinute(0);
                temp.setSecond(0);
                temp.setHour(this->tripsTime[j]);
                Trip newTrip(temp.dateInSecond(),4,temp);
                
                trips.insert(temp.dateInSecond(), newTrip);
                
                // for test speed
                tripsID[counter] = newTrip.getID();
                counter++;
            }
            temp.increaseOneDay();
        }
        return tripsID;
    }
    
    void sendRequest(){
        
        User newUser;
        string username,paymentMethod;int phoneNo=0;
        long tripID,userID,cardID;
        
        cout<<" ======================="<<endl;
        cout<<"|     trips list        |"<<endl;
        cout<<" ======================="<<endl<<endl;

        this->tripDescrition();
        cout<<endl;
        cout<<"#==================================#"<<endl<<endl;
        cout<<"Please Enter Trip id :";
        cin>>tripID;
        
        while (!isTripExist(tripID)) {
            cout<<"Enter valid trip id :";
            cin>>tripID;
        }
        cout<<"Please Enter Your id :";
        cin>>userID;
        cout<<"#==================================#"<<endl;

        if(!IsUserExist(userID)){
            cout<<endl<<endl;
            cout<<"|---------------|"<<endl;
            cout<<"|               |"<<endl;
            cout<<"| SignUp user   |"<<endl;
            cout<<"|               |"<<endl;
            cout<<"|_______________|"<<endl<<endl;

            cout<<"Please Enter your name :";
            cin>>username;
            cout<<"Please Enter your id :";
            cin>>userID;
            while (!cin) {
                cout<<"Enter valid id :";
                cin>>userID;
            }
            cout<<"Enter your phoneNo :";
            cin>>phoneNo;
            while (!cin) {
                cout<<"Enter valid phoneNo :";
                cin>>phoneNo;
            }
            paymentMethod = "cash";
            newUser.setID(userID);
            newUser.setName(username);
            newUser.setPhoneNo(phoneNo);
            users.insert(userID, newUser);

        }else {
            
            User targetUser = users.search(userID)->data;
                                    
            cout<<endl<<endl;
            cout<<"Select payment method [cash/card] :";
            cin>>paymentMethod;
            while (paymentMethod!="cash"&&paymentMethod!="card") {
            cout<<"Select payment method [cash/card] :";
            cin>>paymentMethod;
            }
            if(paymentMethod=="card"){
                if(targetUser.userCardDescription().length()!=0){
                    cout<<"Your cards :"<<endl;
                    cout<<targetUser.userCardDescription();
                    cout<<endl;
                }
                cout<<"Please enter card id : ";
                cin>>cardID;
                                
                if(!targetUser.useCard(users.search(userID)->data.getCard(cardID), trips.search(tripID)->data.getPrice())){
                    cout<<"This card not valid "<<endl<<endl;
                }
            }
        }
        
        Trip targetTrip = trips.search(tripID)->data;
        string userAnswer;
        cout<<"Trip selected Price is "<<targetTrip.getPrice()<<" confirm [yes/no] :";
        cin>>userAnswer;
        if(userAnswer=="yes"){

            Request newRequest(userID,tripID,paymentMethod=="card"?'x':'c',0,0);
            trips.search(tripID)->data.addRequest(newRequest);
            
        }else{
            return;
        }
      }
    
    void refundRequest(){
        long tripID,ticketID,userID;
        cout<<endl<<endl;
        cout<<"Enter your id :";
        cin>>userID;
        while(!IsUserExist(userID)){
            cout<<"User isn't exist"<<endl;
            cout<<"Enter your id :";
            cin>>userID;
            
        }
        cout<<endl;
        cout<<"^=========================================^"<<endl<<endl;
        cout<<"Please enter your trip id :";
        cin>>tripID;
        cout<<"Please enter your ticket id :";
        cin>>ticketID;
        
        trips.search(tripID)->data.deleteRequest(ticketID);
        
    }
    
    bool isTripExist(long tripID){
        return trips.find(tripID);
    }
    
    bool IsUserExist(long userID){
        return users.find(userID);
    }
    
    void tripDescrition(){
        trips.inorder();
    }
    
    long generateId(){
        long id=0;
        char digit[] =  "0123456789";
        for(int i=1;i<=10;i++){id+=digit[rand()%10+1]*pow(10, i);}
        return id;
    }
    
    void testSpeed(long *tripsID){
        using std::chrono::duration_cast;
        using std::chrono::duration;
        using std::chrono::milliseconds;
        
        
        auto timeBegin1 = std::chrono::high_resolution_clock::now();
        
          for(int j=0;j<DAT_BUY_IN_ADVANCE*ONE_DAY_TRIPS;j++){
             Trip targetTrip = trips.search(tripsID[j])->data;
                for(int i=0;i<476190;i++){
                    Request newRequest(343,tripsID[j],'x',0,0);
                    targetTrip.addRequest(newRequest);
                    }
                }
        
        auto timeEnd1 = std::chrono::high_resolution_clock::now();
        auto ms_double_1 = duration_cast<milliseconds>(timeEnd1 - timeBegin1);
        
        
        string time = to_string(ms_double_1.count());
        if(time.length()>3){
        time.insert(time.length()-3, ".");
        cout<<"To insert 10M tickets to Bus system need : "<<time<<"sec"<<endl;
        }else{
        cout<<"To insert 10M tickets to Bus system need : "<<time<<"msec"<<endl;
        }
        
    }
};
   
