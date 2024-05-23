#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <string>
#endif

using namespace std;

class Client{
    public:
        int id;
        static int unique_id;
        string firstName;
        string lastName;
        string email;
        string phoneNumber;
        bool saveTofile;

    Client(string aFirstName, string aLastName, string aphoneNumber, string aemail, bool asaveTofile){
        setFirstName(aFirstName);
        setLastName(aLastName);
        setPhoneNumber(aphoneNumber);
        setEmail(aemail);
        saveToFile(asaveTofile);
        id = unique_id++;
        if(saveTofile){
            saveToBinary();
        }
    }

    int get_id(){
        return id;
    }
    
    void setFirstName(string aFirstName){
        firstName = aFirstName;
    }

    void setLastName(string aLastName){
        lastName = aLastName;
    }

    void setPhoneNumber(string aphoneNumber){
        phoneNumber = aphoneNumber;
    }

    void setEmail(string aemail){
        email = aemail;
    }

    void saveToFile(bool isTrue){
        saveTofile = isTrue;
    }

    void saveToBinary(){
        ofstream fout("clients.dat", ios::out | ios::app | ios::binary);
        fout.write(to_string(firstName.size()).c_str(), to_string(firstName.size()).size());
        fout.put(':');
        fout.write(firstName.c_str(), firstName.size());
        fout.put(' ');
        fout.write(to_string(lastName.size()).c_str(), to_string(lastName.size()).size());
        fout.put(':');
        fout.write(lastName.c_str(), lastName.size());
        fout.put(' ');
        fout.write(to_string(email.size()).c_str(), to_string(email.size()).size());
        fout.put(':');
        fout.write(email.c_str(), email.size());
        fout.put(' ');
        fout.write(to_string(phoneNumber.size()).c_str(), to_string(phoneNumber.size()).size());
        fout.put(':');
        fout.write(phoneNumber.c_str(), phoneNumber.size());
        fout.put('\n');
        fout.close();
    }

    void dispName(){
        cout << "Id: " << get_id() << endl;
        cout << "Imie: " << firstName << endl;
        cout << "Nazwisko: " << lastName << endl;
        cout << "Email: " << email << endl;
        cout << "Numer: " << phoneNumber << endl;
        cout << endl;
    }

};

int Client::unique_id = 1;
