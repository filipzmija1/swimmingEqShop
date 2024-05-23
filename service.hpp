#include <iostream>
#include <string>
#include <ctime>
#include "client.hpp"
#include "equipment.hpp"

using namespace std;


class Service{
    public:
        Client *client;
        Equipment *equipment;
        char rentalDate[80];
        char returnDate[80];
        int rentalHoursNumber;


    Service(Client *aclient, Equipment *aequipment, int arentalHoursNumber){
        setClient(aclient);
        setEquipment(aequipment);
        setrentalHoursNumber(arentalHoursNumber);
        setReturnDate(arentalHoursNumber);
        cout << "Utworzono zamownienie" << endl;
    }
    
    void setDefaultDate(){
        time_t result = time(nullptr);
        strftime(rentalDate, 80, "%d-%m-%Y %H:%M:%S", localtime(&result));
    }

    void setClient(Client *aclient){
        client = aclient;
    }

    void setEquipment(Equipment *aequipment){
        equipment = aequipment;
    }

    void setrentalHoursNumber(int hours){
        rentalHoursNumber = hours;
    }

    void setReturnDate(int hours){
        string changeReturnHours;
        int hoursUpdator;
        for(int i=0; rentalDate[i] != '\0'; i++){
            if(i == 11 || i == 12){
                changeReturnHours = changeReturnHours + rentalDate[i];
                hoursUpdator = stoi(changeReturnHours);
            }
        }
        returnDate[11] = to_string(hoursUpdator)[0];
        returnDate[12] = to_string(hoursUpdator)[1]; 
    }

    void dispService(){
        // cout << "Klient: " << client->dispName() << << endl;
        // cout << "Sprzet: " << equipment->dispData() << endl;
        cout << "Data wynajecia: " << rentalDate << endl;
        cout << "Data oddania: " << returnDate << endl; 
    }

};