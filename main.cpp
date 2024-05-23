#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP
#ifndef UTILS_HPP
#define UTILS_HPP
#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <typeinfo>
#include <list>
#include <iterator>
#include <fstream>
#include <vector>
#include <cstdio>
#include <filesystem>
#include <cstring>

#include "client.hpp"
#include "equipment.hpp"
#include "utils.hpp"
#endif
#endif
#endif

using namespace std;

class Service{
    public:
        int id;
        Client *client;
        Equipment *equipment;
        int rentalHoursNumber;
        string returnDate;
        float pricePerHour;
        static int serviceId;
        int accesoriesAmount;
        bool saveToFile;
        string dateOfOrder;

    Service(Client *aclient, Equipment *aequipment, int arentalHoursNumber, float apricePerHour, int borrowedAmmount, bool asaveTofile, string dateFromFile="random"){
        setClient(aclient);
        setEquipment(aequipment);
        countBorrowedThings(borrowedAmmount);
        setrentalHoursNumber(arentalHoursNumber);
        setPricePerHour(apricePerHour, arentalHoursNumber, borrowedAmmount);
        saveTofile(asaveTofile);
        cout << "Utworzono zamownienie" << endl;
        cout << "Cena zamowienia: " << getServicePrice(pricePerHour) << endl;
        id = serviceId++;
        if(saveToFile){
            saveToBinary();
            setOrderDate(getDefaultDate());
            cout << "Data planowanego oddania: " << getReturnDate(arentalHoursNumber, setCorrectDate(arentalHoursNumber, getDefaultDate())) << endl;
        }
        else{
            setOrderDate(dateFromFile);
            cout << "Data planowanego oddania: " << getReturnDate(arentalHoursNumber, setCorrectDate(arentalHoursNumber, dateFromFile)) << endl;
        }
    }
    
    string getDefaultDate(){
        string formattedTime;
        char date[80];
        time_t result = time(nullptr);
        strftime(date, 80, "%d-%m-%Y %H:%M:%S", localtime(&result));
        formattedTime = date;
        return formattedTime;
    }

    int get_id(){
        return id;
    }

    void saveTofile(bool isTrue){
        saveToFile = isTrue;
    }

    void setOrderDate(string date){
        dateOfOrder = date;
    }

    void saveToBinary(){
        ofstream fout("services.dat", ios::out | ios::app | ios::binary);
        fout.write(to_string(client->id).c_str(), to_string(client->id).size());
        fout.put(' ');
        fout.write(getDefaultDate().c_str(), getDefaultDate().size());
        fout.put(' ');
        fout.write(to_string(equipment->id).c_str(), to_string(equipment->id).size());
        fout.put(' ');
        fout.write(equipment->Name.c_str(), equipment->Name.size());
        fout.put(' ');
        fout.write(to_string(rentalHoursNumber).c_str(), to_string(rentalHoursNumber).size());
        fout.put(' ');
        fout.write(to_string(accesoriesAmount).c_str(), to_string(accesoriesAmount).size());
        fout.put(' ');
        fout.write(to_string(pricePerHour).c_str(), to_string(pricePerHour).size());
        fout.put('\n');
        fout.close();
    }

    void setPricePerHour(float price, int hours, int accesoriesAmount){
        pricePerHour = price * hours * accesoriesAmount ;
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

    void countBorrowedThings(int counter){
        accesoriesAmount = counter;
    }

    float getServicePrice(float price){
        return price;
    }

    string setCorrectDate(int hours, string returnDate){
        int daysToAdd;
        int hoursToSubtract;
        int daysMonths31[7] = {1, 3, 5, 7, 8, 10, 12};
        int daysMonths30[5] = {2, 4, 6, 9, 11};
        string dateString;
        string formattedDate;
        string converter;
        int daysNumber;
        int monthsNumber;
        int year;
        int hoursNumber;
        formattedDate = returnDate;
        for(int i=0; returnDate[i] != '\0'; i++){
            if(i == 0 || i == 1){
                dateString = dateString + returnDate[i];
                daysNumber = stoi(dateString);
            }
            if(i == 3 || i == 4){
                dateString = dateString + returnDate[i];
                monthsNumber = stoi(dateString);
            }
            if(i >= 6 && i < 10){
                dateString = dateString + returnDate[i];
                year = stoi(dateString);
            }
            if(i == 11 || i == 12){
                dateString = dateString + returnDate[i];
                
            }
            if(i == 14 || i == 15 || i == 17 || i == 18){
                dateString = dateString + returnDate[i];
            }

        }

    daysToAdd = hours / 24;
    string hoursConvert;
    string numbers = "0123456789";
    hoursNumber = dateString[8] + dateString[9];
    int firstHourPart;
    int secondHourPart;
    int firstInterate = 0;

    return dateString;
    }


    string getReturnDate(int hours, string dateToFormat){
        string output = "0123456789111111111";
        char hoursChar[2] = {dateToFormat[8], dateToFormat[9]};
        char monthNumbers[2] = {dateToFormat[3], dateToFormat[4]};
        char day[2] = {dateToFormat[0], dateToFormat[1]};
        string convert = to_string(hours);
        int allHours;
        int daysMonths31[7] = {1, 3, 5, 7, 8, 10, 12};
        int daysMonths30[5] = {2, 4, 6, 9, 11};
        string decimalHour = to_string(hoursChar[1]);
        string numbers = "0123456789";
        int hourFirstNumber;
        int daysToAdd;
        int daysNumber;
        int monthsQuantity;
        int year;
        int hoursNumber;
        int dayHours;

        for(int i = 0; monthNumbers[i] != '\0'; i++){
            for(int j = 0; numbers[j] != '\0'; j++){
                if(monthNumbers[1] == numbers[j]){
                    monthsQuantity = monthsQuantity + j;
                }
            }
        }

        for(int i = 0; convert[i] != '\0'; i++){
            for(int z = 0; hoursChar[z] != '\0'; z++){
                if(z == 0){
                    for(int j = 0; numbers[j] != '\0'; j++){
                        if(numbers[j] == hoursChar[z]){
                            hourFirstNumber = j * 10;
                        }
                        }
                    }
                if( z == 1){
                    for(int j = 0; numbers[j] != '\0'; j++){
                        if(numbers[j] == hoursChar[z]){
                           hourFirstNumber = hourFirstNumber + j; 
                        }
                        
                    }
                }
            }
        }
            allHours = hourFirstNumber + hours;
            daysToAdd = allHours / 24;
            dayHours = allHours % 24;
            if(allHours > 24){
                for(int j = 0; j < 2; j++){
                    for(int i = 0; numbers[i] != '\0'; i++){
                        if(day[0] != '0' && numbers[i] == day[0]){
                            daysNumber = i * 10;
                        }
                        if(day[1] == numbers[i]){
                            daysNumber = daysNumber + i;

                        }
                    }
                }
                daysNumber = daysNumber + daysToAdd;

                    for(int i=0; i < 5; i++){
                        if(daysNumber == 30 && monthsQuantity == daysMonths30[i]){
                            daysNumber = daysToAdd;
                            monthsQuantity = monthsQuantity + 1;
                            if(daysToAdd < 10){
                                dateToFormat[0] = '0';
                                dateToFormat[1] = to_string(daysNumber)[0];
                            }
                            else{
                                dateToFormat[0] = to_string(daysNumber)[0];
                                dateToFormat[1] = to_string(daysNumber)[1];
                            }
                            if(monthsQuantity < 10){
                                dateToFormat[2] = '0';
                                dateToFormat[3] = monthNumbers[0];
                            }
                            else{
                                dateToFormat[3] = monthNumbers[0];
                                dateToFormat[3] = monthNumbers[1];
                            }
                            
                        }
                        else{
                            dateToFormat[0] = to_string(daysNumber)[0];
                            dateToFormat[1] = to_string(daysNumber)[1];
                        }
                    }
                    for(int i=0; i < 7; i++){
                        if(daysNumber == 31 && monthsQuantity == daysMonths31[i]){
                            if(monthsQuantity == 12){
                                monthsQuantity = 1;
                                year = year + 1;
                                daysNumber = daysToAdd;
                                dateToFormat[4] = to_string(year)[0];
                                dateToFormat[5] = to_string(year)[1];
                                dateToFormat[6] = to_string(year)[2];
                                dateToFormat[7] = to_string(year)[3];
                                dateToFormat[2] = '0';
                                dateToFormat[3] = monthNumbers[0];
                                if(daysNumber < 10){
                                    dateToFormat[0] = '0';
                                    dateToFormat[1] = to_string(daysNumber)[0];
                                }
                                else{
                                    dateToFormat[0] = to_string(daysNumber)[0];
                                    dateToFormat[1] = to_string(daysNumber)[1];
                                }
                            }
                            else{
                                daysNumber = daysNumber + daysToAdd;
                                monthsQuantity = monthsQuantity + 1;
                                dateToFormat[0] = to_string(daysNumber)[0];
                                dateToFormat[1] = to_string(daysNumber)[1];
                                dateToFormat[2] = '0';
                                dateToFormat[3] = monthNumbers[0];
                            }
                        }
                        
                    }
                dateToFormat[8] = to_string(dayHours)[0];
                dateToFormat[9] = to_string(dayHours)[1];     
            }
            else{
                for(int j = 0; j < 2; j++){
                    for(int i = 0; numbers[i] != '\0'; i++){
                        if(day[0] != '0' && numbers[i] == day[0]){
                            daysNumber = i * 10;
                        }
                        if(day[1] == numbers[i]){
                            daysNumber = daysNumber + i;

                        }
                    }
                }
                dateToFormat[8] = to_string(dayHours)[0];
                dateToFormat[9] = to_string(dayHours)[1];  
            }
        

        output[0] = dateToFormat[0];
        output[1] = dateToFormat[1];
        output[2] = '-';
        output[3] = dateToFormat[2];
        output[4] = dateToFormat[3];
        output[5] = '-';
        output[6] = dateToFormat[4];
        output[7] = dateToFormat[5];
        output[8] = dateToFormat[6];
        output[9] = dateToFormat[7];
        output[10] = ' ';
        output[11] = dateToFormat[8];
        output[12] = dateToFormat[9];
        output[13] = ':';
        output[14] = dateToFormat[10];
        output[15] = dateToFormat[11];
        output[16] = ':';
        output[17] = dateToFormat[12];
        output[18] = dateToFormat[13];

        returnDate = output;

        return output;
    }
};


void GetServicesFromFile(list<Client>&clients, list<Equipment>&eq, list<Service>&services){
    ifstream fin("services.dat", ios::in | ios::binary);
    Client *client;
    Equipment *accessorie;
    string clientId;
    string dateOfOrder;
    string hourOfOrder;
    string eqId;
    string eqName;
    string rentalHours;
    string fullprice;
    string borrowedAmmount;
    string component;
    int pricePerHour;
    int indexes[7];
    int separator = 0;
    char ch;
    while(fin.get(ch)){
        if(ch == '\n'){
            for(int i = 0; i < component.size(); i++){
                if(component[i] == 32 && separator == 0){
                    indexes[0] = i;
                    separator = separator + 1;
                }
                else if(component[i] == 32 && separator == 1){
                    indexes[1] = i;

                    separator = separator + 1;
                }
                else if(component[i] == 32 && separator == 2){
                    indexes[2] = i;
                    separator = separator + 1;
                }
                else if(component[i] == 32 && separator == 3){
                    indexes[3] = i;
                    separator = separator + 1;
                }
                else if(component[i] == 32 && separator == 4){
                    indexes[4] = i;
                    separator = separator + 1;
                }
                else if(component[i] == 32 && separator == 5){
                    indexes[5] = i;
                    separator = separator + 1;
                }
                else if(component[i] == 32 && separator == 6){
                    indexes[6] = i;
                    separator = separator + 1;
                }
            }
            clientId = component.substr(0, indexes[0]);
            dateOfOrder = component.substr(indexes[0] + 1, indexes[1] - indexes[0]);
            hourOfOrder = component.substr(indexes[1] + 1, indexes[2] - indexes[1]);
            eqId = component.substr(indexes[2] + 1, indexes[3] - indexes[2]);
            eqName = component.substr(indexes[3] + 1, indexes[4] - indexes[3]);
            rentalHours = component.substr(indexes[4] + 1, indexes[5] - indexes[3]);
            borrowedAmmount = component.substr(indexes[5] + 1, indexes[6] - indexes[3]);
            fullprice = component.substr(indexes[6] + 1, component.size() - 1);
            for(auto &clientObject: clients){
                if(to_string(clientObject.id) == clientId){
                    client = &clientObject;
                }
            }
            for(auto &eqObject: eq){
                if(eqObject.id == stoi(eqId)){
                    accessorie = &eqObject;
                }
            }
            string date = dateOfOrder + hourOfOrder;
            pricePerHour = stoi(fullprice) / stoi(rentalHours) / stoi(borrowedAmmount);
            services.push_back(Service(client, accessorie, stoi(rentalHours), pricePerHour, stoi(borrowedAmmount), false, date));
            component.clear();
            separator = 0;
        }
        else{
            component += ch;
        }
    }
}
    

Service newService(list<Client> &clients, list<Equipment> &eq){
    Client *client;
    Equipment *equipment;
    int accesoriesAmount;
    float pricePerHour;
    int borrowingTime;
    int searchingClientData;
    int searchingEqData;
    cout << clients.size() << " " << eq.size() << endl;
    if(clients.size() == 0 || eq.size() == 0){
        char option;
        while(option != '9'){
            cout << "W bazie danych nie ma zadnego klienta / zadnego akcesoria do wypozyczenia" << endl;
            cout << "0. Jesli chcesz wrocic do glownego menu" << endl;
            cout << "1. Przenies mnie od razu do opcji dodawania klienta" << endl;
            cout << "2. Przenies mnie od razu do opcji dodawania akcesoriow" << endl;
            cout << "9. Zakoncz program" << endl;
            cin >> option;
            if(option == '0'){
                cout << endl;
            }
            if(option == '1'){
                newClient();
            }
            if(option == '2'){
                eq.push_back(newEquipment());
            }
        }
    }
    else{
        cout << "Formularz wypozyczenia (wypelnia pracownik)" << endl;
        DisplayClientsList(clients);
        cout << "Podaj id klienta: ";
        cin >> searchingClientData;
        for(auto &clientObject: clients){
            if(clientObject.id == searchingClientData){
                client = &clientObject;
                break;
            }
        }
        DisplayEquipmentList(eq);
        cout << "Podaj id rzeczy do wypozyczenia: ";
        cin >> searchingEqData;
        for(auto &eqObject: eq){
            if(eqObject.id == searchingEqData){
                equipment = &eqObject;
            }
        }
        while(equipment->quantity <= 0){
            cout << "Nie ma aktualnie akcesoria o ktore prosisz. Wybierz inna rzecz: ";
            cin >> searchingEqData;
            for(auto &eqObject: eq){
                if(eqObject.id == searchingEqData){
                    equipment = &eqObject;
                }
            }
        }
        cout << "Podaj ilosc: ";
        cin >> accesoriesAmount;
        while(equipment->quantity < accesoriesAmount){
            cout << "Niestety nie ma wystarczajaco rzeczy o ktore prosisz. Zmniejsz ilosc: ";
            cin >> accesoriesAmount;
        }
        equipment->quantity = equipment->quantity - accesoriesAmount;
        cout << "Podaj cene wypozyczenia za godzine: ";
        cin >> pricePerHour;
        cout << "Podaj liczbe planowanych godzin wypozyczenia: ";
        cin >> borrowingTime;
    }
    updateEqFile(eq);
    return Service(client, equipment, borrowingTime, pricePerHour, accesoriesAmount, true);

}

void dispServices(list<Service> services){
    for(auto service: services){
        cout << "Id zamowienia: " << service.id << endl;
        cout << "Klient: " << service.client->firstName << " " << service.client->lastName << endl;
        cout << "Rzecz: " << service.equipment->Name << endl;
        cout << "Ilosc: " << service.accesoriesAmount << endl;
        cout << "Data wypozyczenia: " << service.dateOfOrder << endl;
        cout << "Data oddania: " << service.returnDate << endl;
        cout << "Cena zamowienia: " << service.pricePerHour << endl;
        cout << endl;
    }
}


void updateServiceFile(list<Service>servicesList){
    string line;
    ofstream fout("services.dat", ios::out | ios::trunc | ios::binary);
    ofstream temp("temp.dat", ios::out | ios::trunc | ios::binary);
    for(auto service: servicesList){
        temp.write(to_string(service.client->id).c_str(), to_string(service.client->id).size());
        temp.put(' ');
        temp.write(service.dateOfOrder.c_str(), service.dateOfOrder.size());
        temp.put(' ');
        temp.write(to_string(service.equipment->id).c_str(), to_string(service.equipment->id).size());
        temp.put(' ');
        temp.write(service.equipment->Name.c_str(), service.equipment->Name.size());
        temp.put(' ');
        temp.write(to_string(service.rentalHoursNumber).c_str(), to_string(service.rentalHoursNumber).size());
        temp.put(' ');
        temp.write(to_string(service.accesoriesAmount).c_str(), to_string(service.accesoriesAmount).size());
        temp.put(' ');
        temp.write(to_string(service.pricePerHour).c_str(), to_string(service.pricePerHour).size());
        temp.put('\n');
    }
    temp.close();
    ifstream fileData("temp.dat", ios::in | ios::app | ios::binary);
    while(getline(fileData, line)){
        for(int i = 0; i < line.length(); i++){
            if(line[i] == ' ' && line[i + 1] == ' '){
                line.erase(i, 1);
            }
        }
        fout << line << "\n";
    }
    fout.close();
}

int serviceDetailsManagement(list<Client> &clients, list<Equipment> &accesories, list<Service> &services){
    char option;
    string newData;
    Service *service;
    string serviceId;
    int temp;
    int hourPrice;
    bool componentExists = false;
    cout << "Podaj id uslugi ktora chcesz zaktualizowac: ";
    cin >> serviceId;
    for(auto &serviceObj: services){
        if(serviceId == to_string(serviceObj.id)){
            service = &serviceObj;
        }  
    }
    hourPrice = service->pricePerHour / service->accesoriesAmount / service->rentalHoursNumber;
    while(option != '0'){
        cout << "1. Zmien ilosc wypozyczonych rzeczy" << endl;
        cout << "2. Zmien liczbe godzin" << endl;
        cout << "3. Usun zamowienie" << endl;
        cout << "0. Wroc do menu" << endl;
        cin >> option;
        if(option == '1'){
            cout << "Podaj ilosc: ";
            cin >> newData;
            equipmentValidator(newData);
            while(equipmentValidator(newData) != true){
                cout << "Ilosc powinna byc podana tylko w cyfrach. Podaj jeszcze raz: ";
                cin >> newData;
                equipmentValidator(newData);
            }
            temp = service->accesoriesAmount;
            if(service->equipment->quantity + temp - stoi(newData) >= 0){
                service->accesoriesAmount = stoi(newData);
                service->equipment->quantity = service->equipment->quantity + temp - stoi(newData);
                (service->equipment->quantity > 0) ? service->equipment->isAvailable = true: service->equipment->isAvailable = false;
                service->pricePerHour = service->accesoriesAmount * service->rentalHoursNumber * hourPrice;
            }
            else{
                cout << endl;
                cout << "Nie ma wystarczajaco rzeczy na magaazynie. Wprowadz jeszcze raz co chcesz zrobic" << endl;
                cout << endl;
            }
            
        }
        if(option == '2'){
            cout << "Podaj liczbe planowanych godzin zamowienie. Data rozpoczecia zamowienia: " << service->dateOfOrder << endl;
            cin >> newData;
            equipmentValidator(newData);
            cout << service->get_id() << endl;
            while(equipmentValidator(newData) != true){
                cout << "Liczba godzin powinna byc podana tylko w cyfrach. Podaj jeszcze raz: ";
                cin >> newData;
                equipmentValidator(newData);
            }
            service->pricePerHour = service->accesoriesAmount * stoi(newData) * hourPrice;
            service->getReturnDate(stoi(newData), service->setCorrectDate(stoi(newData), service->dateOfOrder));
            cout << "Zmieniono liczbe godzin" << endl;
        }
        if(option == '3'){
            service->equipment->quantity = service->equipment->quantity + service->accesoriesAmount;
            updateEqFile(accesories);
            return service->id;
        }
        updateServiceFile(services);
        updateEqFile(accesories);
    }
    return 0;   
}

int Service::serviceId = 1;

int main(){
    // classes
    Client *client;
    Equipment *equipment;
    Service *service;

    // client attributes
    int clientToChangeId;

    // iterators
    list<Client>::iterator it;
    list<Equipment>::iterator eqIt;
    list<Service>::iterator serviceIt;

    // equipment attributes
    int eqToChangeId;

    // service attributes
    int hours;
    float price;
    int serviceToChangeId;

    // lists
    list<Client> ClientsList;
    list<Equipment> EquipmentList;
    list<Service> ServiceList;

    // Files and program management
    char option;
    char choice;
    GetClientsFromFile(ClientsList);
    GetEqFromFile(EquipmentList);
    GetServicesFromFile(ClientsList, EquipmentList, ServiceList);

    // program flow
    while(option != '0'){
        cout << "\n1. Dodaj nowego klienta" << endl;
        cout << "2. Dodaj nowy sprzet plywacki" << endl;
        cout << "3. Dodaj nowe zamowienie" << endl;
        cout << "4. Zmien dane klienta(tutaj mozna usuwac klienta)" << endl;
        cout << "5. Zmien dane oferty(tutaj mozna usuwac poszczegolne akcesoria)" << endl;
        cout << "6. Wyswietl dane klientow" << endl;
        cout << "7. Wyswietl dane magazynu" << endl;
        cout << "8. Wyswietl dane zamowien" << endl;
        cout << "9. Zmien dane zamowienia" << endl;
        cout << "0. Zakoncz program" << endl;

        cin >> option;
        if(option == '1'){
            ClientsList.push_back(newClient());
        }
        if(option == '2'){
            EquipmentList.push_back(newEquipment());
            cout << EquipmentList.size() << endl;
        }
        if(option == '3'){
            ServiceList.push_back(newService(ClientsList, EquipmentList));
        }
        if(option == '4'){
            DisplayClientsList(ClientsList);
            clientToChangeId = clientDetailsManagement(ClientsList);
            if(clientToChangeId != 0){
                it = find_if(ClientsList.begin(), ClientsList.end(), 
                    [clientToChangeId](const auto &cli)
                    { return cli.id == clientToChangeId; });
                ClientsList.erase(it);
                ServiceList.erase(remove_if(ServiceList.begin(), ServiceList.end(),
                    [clientToChangeId](const Service &sObj){ return sObj.client->id == clientToChangeId; }),
                    ServiceList.end());
                updateClientFile(ClientsList);
                updateServiceFile(ServiceList);
                cout << "Klient i wszystkie przypisane do niego zamowienia zostaly usuniete" << endl;
            }
        }
        if(option == '5'){
            DisplayEquipmentList(EquipmentList);
            eqToChangeId = equipmentDetailsManagement(EquipmentList);
            if(eqToChangeId != 0){
                eqIt = find_if(EquipmentList.begin(), EquipmentList.end(), 
                    [eqToChangeId](const auto &eq)
                    { return eq.id == eqToChangeId; }
                );
                EquipmentList.erase(eqIt);
                ServiceList.erase(remove_if(ServiceList.begin(), ServiceList.end(),
                    [eqToChangeId](const Service &sObj){ return sObj.equipment->id == eqToChangeId; }),
                    ServiceList.end());
                updateEqFile(EquipmentList);
                updateServiceFile(ServiceList);
                cout << "Akcesoria i wsztstkie zamowienia zwiazane z nimi zostaly usuniete" << endl;
            }
        }
        if(option == '6'){
            DisplayClientsList(ClientsList);
            cout << "Posortuj wedlug: " << endl;
            cout << "1. Imienia" << endl;
            cout << "2. Nazwiska" << endl;
            cout << "3. Id" << endl;
            cout << "4. Email" << endl;
            cout << "0. Wroc do menu" << endl;
            cin >> choice;
            if(choice == '0'){
            }
            else{
                if(choice == '1'){
                    ClientsList.sort([](const Client &first, const Client &second){ return first.firstName < second.firstName; });
                }
                else if(choice == '2'){
                    ClientsList.sort([](const Client &first, const Client &second){ return first.lastName < second.lastName; });
                }
                else if(choice == '3'){
                    ClientsList.sort([](const Client &first, const Client &second){ return first.id < second.id; });
                }
                else if(choice == '4'){
                    ClientsList.sort([](const Client &first, const Client &second){ return first.email < second.email; });
                }
                DisplayClientsList(ClientsList);
            }
        }
        if(option == '7'){
            DisplayEquipmentList(EquipmentList);
            cout << "Posortuj wedlug: " << endl;
            cout << "1. Nazwy" << endl;
            cout << "2. Ilosci dostepnych elementow" << endl;
            cout << "3. Id" << endl;
            cout << "4. Dostepny" << endl;
            cout << "0. Wroc do menu" << endl;
            cin >> choice;
            if(choice == '0'){
            }
            else{
                if(choice == '1'){
                    EquipmentList.sort([](const Equipment &first, const Equipment &second){ return first.Name < second.Name; });
                }
                else if(choice == '2'){
                    EquipmentList.sort([](const Equipment &first, const Equipment &second){ return first.quantity < second.quantity; });
                }
                else if(choice == '3'){
                    EquipmentList.sort([](const Equipment &first, const Equipment &second){ return first.id < second.id; });
                }
                else if(choice == '4'){
                    EquipmentList.sort([](const Equipment &first, const Equipment &second){ return first.isAvailable > second.isAvailable; });
                }
                DisplayEquipmentList(EquipmentList);
            }
            
        }
        if(option == '8'){
            dispServices(ServiceList);
            cout << "Posortuj wedlug: " << endl;
            cout << "1. Daty utworzenia" << endl;
            cout << "2. Planowanej daty oddania" << endl;
            cout << "3. Id" << endl;
            cout << "4. Wypozyczonych rzeczy" << endl;
            cout << "5. Calkowitej ceny zamowien" << endl;
            cout << "0. Wroc do menu" << endl;
            cin >> choice;
            if(choice == '0'){
            }
            else{
                if(choice == '1'){
                    ServiceList.sort([](const Service &first, const Service &second){ return first.dateOfOrder < second.dateOfOrder; });
                }
                else if(choice == '2'){
                    ServiceList.sort([](const Service &first, const Service &second){ return first.returnDate < second.returnDate; });
                }
                else if(choice == '3'){
                    ServiceList.sort([](const Service &first, const Service &second){ return first.id < second.id; });
                }
                else if(choice == '4'){
                    ServiceList.sort([](const Service &first, const Service &second){ return first.equipment->Name < second.equipment->Name; });
                }
                else if(choice == '5'){
                    ServiceList.sort([](const Service &first, const Service &second){ return first.pricePerHour < second.pricePerHour; });
                }
                dispServices(ServiceList);
            }
        }
        if(option == '9'){
            dispServices(ServiceList);
            serviceToChangeId = serviceDetailsManagement(ClientsList, EquipmentList, ServiceList);
            if(serviceToChangeId != 0){
                serviceIt = find_if(ServiceList.begin(), ServiceList.end(),
                    [serviceToChangeId](const Service &sObj){ return sObj.id == serviceToChangeId; });
                ServiceList.erase(serviceIt);
                updateServiceFile(ServiceList);
                cout << "Zamowienie zostalo usuniete" << endl;
            }
        }
    }
    return 0;
}