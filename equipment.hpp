#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Equipment{
    public:
        int id;
        int static eqId;
        string Name;
        int quantity;
        bool isAvailable;
        bool saveToFile;
        string availability;

    Equipment(string aName, int aQuantity, bool saveintoBinary){
        setName(aName);
        setQuantity(aQuantity);
        saveToBinaryFile(saveintoBinary);
        if(quantity > 0){
            setAvailability(true);
        }
        else{
            setAvailability(false);
        }
        setAvailabilityString(isAvailable);
        if(saveintoBinary){
            saveToBinary();
        }
        id = eqId++;
    }

    int get_id(){
        return id;
    }

    void setName(string aName){
        Name = aName;
    }

    void setAvailability(bool aIsAvailable){
        isAvailable = aIsAvailable;
    }

    void setQuantity(int aQuantity){
        quantity = aQuantity;
    }

    void saveToBinaryFile(bool isTrue){
        saveToFile = isTrue;
    }

    void setAvailabilityString(bool available){
        if(available){
            availability = "true";
        }
        else{
            availability = "false";
        }
    }

    void saveToBinary(){
        ofstream fout("equipment.dat", ios::out | ios::app | ios::binary);
        fout.write(Name.c_str(), Name.size());
        fout.put(' ');
        fout.write(to_string(quantity).c_str(), to_string(quantity).size());
        fout.put(' ');
        fout.write(availability.c_str(), availability.size());
        fout.put('\n');
        fout.close();
    }
    
    void dispData(){
        cout << "\nId: " << '\t' << get_id() << endl;
        cout << "Nazwa: " << '\t' << Name << endl; 
        cout << "Ilosc egzemplarzy: " << '\t' << quantity << endl;
        if(isAvailable){
            cout << "Dostepnosc: w magazynie" << endl; 
        }
        else{
            cout << "Dostepnosc: brak" << endl;
        }   
    }

    // void showEquipmentList(list<Equipment> eqList){
    //     for_each(eqList.begin(), eqList.end(), dispData);
    // }

};

int Equipment::eqId = 1;
