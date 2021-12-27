//  Trip.cpp
//  BusReservationSystem
//  Created by admin on 2021/11/16.
#include "iostream"
#include "iomanip"
#include "string"
#include "algorithm"
#include "Date.cpp"
#include "Request.cpp"
#include "Bus.cpp"
#include "BinaryTree.cpp"
#include "vector"
#define DEAD_LINE 15
using namespace std;
class Trip{
private:
    long id;
    int deadline;
    int income;
    int price;
    Date time;
    vector<Request> request;
    Bus bus;
    vector<Bus>buses;
public:
    
    //default constrctor for using container
    Trip(){}
    
    // full constractor to intial the object variables through the parameters value
    Trip(long id ,int price,Date time){
        this->id = id;
        this->deadline = DEAD_LINE;
        this->price = price;
        this->time.assign(time);;
        this->income = 0;
        Bus intialBus('s');
        this->buses.push_back(intialBus);
    }
    

    //getter and setter
    void setDate(Date newDate){this->time=newDate;}
    Date getDate(){return this->time;}
    void setID(long id){this->id = id;}
    long getID(){return this->id;}
    int getPrice(){return this->price;}
    void setPrice(int price){this->price=price;}
    int getIncome(){
        return this->price;
    }
    void setIncome(int income){this->income = income;}
    
    // this function calculate the deadline by subtract N minutes from the time of this trip to get the deadline for this trip <used to buy ticket or drop ticket>
    Date getDeadline(){
        Date temp;
        temp.assign(time);
        return temp.decreaseByMinute(DEAD_LINE);
    }
    int getDL(){return this->deadline;}
    void setDL(int deadline){this->deadline=deadline;}
    void setDeadline(int deadline){this->deadline=deadline;}
    vector<Request> getAllRequest(){return this->request;}
    void setAllRequest(vector<Request>newRequest){for(Request r:newRequest)this->request.push_back(r);}
    vector<Bus> getAllBuses(){return this->buses;}
    void setAllBuses(vector<Bus>newBuses){for(Bus b:newBuses)this->buses.push_back(b);}
    
    
    unsigned long getAllIncome(){
        return request.size()*price;
    }
    
    long getAllExpenses(){
        long result=0;
        for(Bus b:buses)result+=b.getExpenses();
        return result;
    }

    // override == operator to check whether two object are equals or not
    bool operator == (Trip otherTrip){
        if(this->id != otherTrip.id)return false;
        else if(this->deadline != otherTrip.deadline)return false;
        else if(this->income != otherTrip.income)return false;
        else if(this->price != otherTrip.price)return false;
        else if(this->time != otherTrip.time)return false;
        else return true;
         
     }
    
    //this function take bus id and give if the bus is full or not
    // this function work by first finding the target id , then call the function isBusFull from bus class
    bool isBusFull(long busID){
        for(Bus b : buses)if(b.getID()==busID)return b.isBusFull();
        return false;
    }
    
    
    void addRequest(Request newRequest){
        if(!bus.isBusFull()){
            bus.bookSeat(newRequest.getUserID(), newRequest.getID());
        }else{
            buses.push_back(bus);
            bus = Bus('s');
        }
        request.push_back(newRequest);
    }
    
    void deleteRequest(long requestID){
        auto it = request.begin();
        for (int i=0; it != request.end(); ++it,i++)if(request.at(i).getID()==requestID)
        {
            request.erase(it);
            cout<<"ticket refund successfully"<<endl;
            return;
        }
        
    }
    
    Request getRequest(long requestID){
        for (int i=0; i<request.size();i++)
             if(request.at(i).getID()==requestID)
                 return request.at(i);
        return Request();
    }
    
    void assign(Trip otherTrip){
        this->setID(otherTrip.getID());
        this->setDL(otherTrip.getDL());
        this->setIncome(otherTrip.getIncome());
        this->setPrice(otherTrip.getPrice());
        this->setDate(otherTrip.getDate());
        this->setAllRequest(otherTrip.getAllRequest());
        this->setAllBuses(otherTrip.getAllBuses());
    }
    
    // descrition function which give us short intro for specific object
    string description(){
        return "trip at "+(this->time.description())+" with price "+to_string(this->price)+" and id "+to_string(this->id)+" Requests: \n"+requestsDescription();
    }
    
    string requestsDescription(){
        string result = "";
        for(Request r:request)result+=r.description()+"\n";
        return result;
    }
    
};
