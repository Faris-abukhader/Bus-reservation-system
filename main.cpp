//  main.cpp
//  BusReservationSystem
//  Created by admin on 2021/11/16.
#include <iostream>
#include "string"
#include "BusSystem.cpp"
using namespace std;
int main(int argc, const char * argv[]) {

    Date currentDate(2021,1,1,1,1,1);
    int tripTime[] = {8,10,17};
    BusSystem busSystem(currentDate,tripTime);

    return 0;
}
