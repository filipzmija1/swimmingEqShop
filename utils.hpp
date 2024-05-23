bool checkPhoneLength(string phoneNumber){
    string numbers = {"0123456789"};
    int numbersCount = 0;
    for(int i = 0; phoneNumber[i] != '\0'; i++){
        for(int j = 0; numbers[j] != '\0'; j++){
            if(phoneNumber[i] == numbers[j]){
                numbersCount = numbersCount + 1;
            }
        }   
    }
    if(numbersCount == 9 && phoneNumber.length() == 9){
        return true;
    }
    else{
        return false;
    }
}

bool checkEmailValidation(string email){
    int i;
    int atIndex = 0;
    int dotIndex = 0;
    for (i = 0; email[i] != '\0'; i++){
        if(email[i] == '@' && i != 0){
            atIndex = i;
        }
        if(email[i] == '.'){
            dotIndex = i;
        }
    }
    if(atIndex > 0 && email[atIndex+1] != '\0' && atIndex < dotIndex && email[dotIndex+1] != '\0'){
        return true;
    }
    else{
        return false;
    }
}

bool checkNameValidation(string firstName= "", string lastName = ""){
    string Name;
    bool checkIfChar;
    Name = firstName.append(lastName);
    if(lastName.size() > 0 && firstName.size() > 0){
        if(firstName.length() <= 20 && lastName.length() <= 20 && firstName.length() > 0 && lastName.length() > 0){
            for(int i=0; Name[i] != '\0'; i++){
                checkIfChar = regex_match(Name, regex("^[a-zA-Z]+$"));
                if(checkIfChar){
                    return true;
                }
            }
    }
    }else if(firstName == "" || lastName == ""){
        if(firstName.length() <= 20 && firstName.length() > 0){
            for(int i=0; firstName[i] != '\0'; i++){
                checkIfChar = regex_match(firstName, regex("^[a-zA-Z]+$"));
                if(checkIfChar){
                    return true;
                }
            }   
        }
        else if(lastName.length() <= 20 && lastName.length() > 0) {
            for(int i=0; lastName[i] != '\0'; i++){
                checkIfChar = regex_match(lastName, regex("^[a-zA-Z]+$"));
                if(checkIfChar){
                    return true;
                }
            }  
        }
    }
    return false;
}

bool equipmentValidator(string quantity){
    string numbers = {"0123456789"};
    int accessoriesNumber = 0;
    for(int i = 0; quantity[i] != '\0'; i++){
        for(int j = 0; numbers[j] != '\0'; j++){
            if(quantity[i] == numbers[j]){
                accessoriesNumber = accessoriesNumber + 1;
            }
        }
    }
    if(quantity.length() > accessoriesNumber){
        return false;
    }
    else{
        return true;
    }
}


Client newClient(){

    string firstName;
    string lastName;
    string email;
    string phoneNumber;

    cout << endl;
    cout << "Podaj imie: ";
    cin >> firstName;
    cout << "Podaj nazwisko: ";
    cin >> lastName;
    checkNameValidation(firstName, lastName);
    while(checkNameValidation(firstName, lastName) != true){
        cout << "Imie i nazwisko moga miec maksymalnie po 20 liter. Cyfry i znaki specjalne sa niedozwolone."<< endl;
        cout << "Podaj imie: ";
        cin >> firstName;
        cout << "Podaj nazwisko: ";
        cin >> lastName;
        checkNameValidation(firstName, lastName);
    }
    cout << "Podaj numer telefonu: ";
    cin >> phoneNumber;
    checkPhoneLength(phoneNumber);
    while(checkPhoneLength(phoneNumber) != true){
        cout << "Numer telefonu powinien sie skladac z 9 cyfr. Powtorz jeszcze raz: " << endl;
        cin >> phoneNumber;
        checkPhoneLength(phoneNumber);
    }

    cout << "Podaj adres email: ";
    cin >> email;
    checkEmailValidation(email);
    
    while(checkEmailValidation(email) != true){
        cout << "Email powinien zawierac @ i w czesci po 'maplpie' powinna znajdowac sie kropka. Podaj jeszcze raz: ";
        cin >> email;
        checkEmailValidation(email);
    }
    cout << "Client has been added" << endl;

    return Client(firstName, lastName, phoneNumber, email, true);

}


Equipment newEquipment(){
    string Name;
    string quantity;
    cout << "Podaj nazwe sprzetu: ";
    cin >> Name;
    cout << "Podaj ilosc dostepnych egzemplarzy: ";
    cin >> quantity;
    equipmentValidator(quantity);
    while(equipmentValidator(quantity) != true){
        cout << "Ilosc powinna byc podana tylko w cyfrach. Podaj jeszcze raz: ";
        cin >> quantity;
        equipmentValidator(quantity);
    }
    cout << "New accessorie has beed added" << endl;

    return Equipment(Name, stoi(quantity), true);
}


void DisplayEquipmentList(list<Equipment> eqList){
    if (eqList.size() > 0){
        for (auto element: eqList) {
            cout << "\nId: " << element.get_id() << endl;
            cout << "Nazwa: " << element.Name << endl;
            cout << "Dostepna ilosc: " << element.quantity << endl;
            if(element.isAvailable){
                cout << "Dostepnosc: w magazynie" << endl;
            }
            else{
                cout << "Dostepnosc: brak" << endl;
            }
        }

    }
    cout << endl;
}


void DisplayClientsList(list<Client> clientList){
    for (auto client: clientList){
        client.dispName();
    }
    cout << endl;
}


void GetEqFromFile(list<Equipment> &eq){
    ifstream fin("equipment.dat", ios::in | ios::binary);
    char ch;
    string name;
    string quantity;
    int indexes[2];
    int separator = 0;
    string component;
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
            }
            name = component.substr(0, indexes[0]);
            quantity = component.substr(indexes[0] + 1, indexes[1] - indexes[0]);

            eq.push_back(Equipment(name, stoi(quantity), false));
            component.clear();
            separator = 0;
        }
        else{
            component += ch;
        }
    }
    cout << "Equipments data load from file successfully" << endl;
}

string RemoveColonFromString(string data){
    string output;
    string numbersString = "1234567890";
    for(int i = 0; i < data.size(); i++){
        if(data[i] == ':'){
            for(int j = 0; numbersString[j] != '\0'; j++){
                if(data[i - 1] == numbersString[j]){
                    output = data.substr(i + 1, data.size() - 1);
                }
            }
        }
    }
    return output;
}

void GetClientsFromFile(list<Client> &clients){
    const char *clientsFile = "clients.dat";
    ifstream fin(clientsFile, ios::in |ios::binary);
    char ch;
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
    string component;
    int indexes[3];
    int separator = 0;
    char previous;
    while (fin.get(ch)) {
        if (ch == '\n') {
            for(int j = 0; j < component.size(); j++){
                if(component[j] == 32 && separator == 0){
                    indexes[0] = j;
                    separator = separator + 1;
                }
                else if(component[j] == 32 && separator == 1){
                    indexes[1] = j;

                    separator = separator + 1;
                }
                else if(component[j] == 32 && separator == 2){
                    indexes[2] = j;
                    separator = separator + 1;
                }
            }
            cout << component << endl;
            
            firstName = RemoveColonFromString(component.substr(0, indexes[0]));
            lastName = RemoveColonFromString(component.substr(indexes[0] + 1, indexes[1] - indexes[0]));
            email = RemoveColonFromString(component.substr(indexes[1] + 1, indexes[2] - indexes[1]));
            phoneNumber = RemoveColonFromString(component.substr(indexes[2] + 1, component.size() - 1));
            
            clients.push_back(Client(firstName, lastName, phoneNumber, email, false));
            component.clear();
            separator = 0;

        } 
        else if(fin.eof()){
            break;
        }
        else{
            component += ch;
        }
    }
    fin.close();
}


void displayClients() {
        ifstream fin("clients.dat", ios::in | ios::binary);
        char ch;
        while (fin.get(ch)) {
            if (ch == '\n') {
                cout << endl;
            } else {
                cout << ch;
            }
        }

        fin.close();
    }

void updateEqFile(list<Equipment>eqList){
    string line;
    ofstream fout("equipment.dat", ios::out | ios::trunc | ios::binary);
    ofstream temp("temp.dat", ios::out | ios::trunc | ios::binary);
    string availabilityString;
    for(auto eq: eqList){
        if(eq.isAvailable){
            availabilityString = "true";
        }
        else{
            availabilityString = "false";
        }
        temp.write(eq.Name.c_str(), eq.Name.size());
        temp.put(' ');
        temp.write(to_string(eq.quantity).c_str(), to_string(eq.quantity).size());
        temp.put(' ');
        temp.write(availabilityString.c_str(), availabilityString.size());
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

void updateClientFile(list<Client>clientList){
    string line;
    string tempName = "temp.dat";
    ofstream fout("clients.dat", ios::out | ios::binary | ios::trunc);
    ofstream temp("temp.dat", ios::out | ios::trunc | ios::binary);
    for(auto client: clientList){
        temp.write(to_string(client.firstName.size()).c_str(), to_string(client.firstName.size()).size());
        temp.put(':');
        temp.write(client.firstName.c_str(), client.firstName.size());
        temp.put(' ');
        temp.write(to_string(client.lastName.size()).c_str(), to_string(client.lastName.size()).size());
        temp.put(':');
        temp.write(client.lastName.c_str(), client.lastName.size());
        temp.put(' ');
        temp.write(to_string(client.email.size()).c_str(), to_string(client.email.size()).size());
        temp.put(':');
        temp.write(client.email.c_str(), client.email.size());
        temp.put(' ');
        temp.write(to_string(client.phoneNumber.size()).c_str(), to_string(client.phoneNumber.size()).size());
        temp.put(':');
        temp.write(client.phoneNumber.c_str(), client.phoneNumber.size());
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



int clientDetailsManagement(list<Client> &clients){
    Client *client;
    string clientId;
    char option;
    string newData;

    cout << "Podaj id klienta, ktorego szukasz: ";
    cin >> clientId;
    int returner = 0;

    for(auto &clientobj: clients){
        if(clientId == to_string(clientobj.id)){
            client = &clientobj;
        }
    }
    cout << "Imie: " << client->firstName << endl;
    cout << "Nazwisko: " << client->lastName << endl;
    cout << "Email: " << client->email << endl;
    cout << "Numer komorkowy: " << client->phoneNumber << endl;
    cout << endl;
    while(option != '0'){
        cout << "1. Zmien imie" << endl;
        cout << "2. Zmien nazwisko" << endl;
        cout << "3. Zmien email" << endl;
        cout << "4. Zmien numer" << endl;
        cout << "5. Usun klienta" << endl;
        cout << "0. Powrot do menu" << endl;

        cin >> option;
        if(option == '1'){
            cout << "Podaj nowe imie: ";
            cin >> newData;
            checkNameValidation(newData, "");
            while(checkNameValidation(newData, "") != true){
                cout << "Imie moze skladac sie wylacznie z liter i nie moze byc dluzsze od 20 znakow. Wpisz ponownie: ";
                cin >> newData;
                checkNameValidation(newData, "");
            }
            client->firstName = newData;
        }
        if(option == '2'){
            cout << "Podaj nowe nazwisko: ";
            cin >> newData;
            checkNameValidation("", newData);
            while(checkNameValidation("", newData) != true){
                cout << "Nazwisko moze skladac sie wylacznie z liter i nie moze byc dluzsze od 20 znakow. Wpisz ponownie: ";
                cin >> newData;
                checkNameValidation("", newData);
            }
            client->lastName = newData;
        }
        if(option == '3'){
            cout << "Podaj nowy email: ";
            cin >> newData;
            checkEmailValidation(newData);
            while(checkEmailValidation(newData) != true){
                cout << "Email powinien zawierac @ i w czesci po 'maplpie' powinna znajdowac sie kropka. Podaj jeszcze raz: ";
                cin >> newData;
                checkEmailValidation(newData);
            }
            client->email = newData;
        }
        if(option == '4'){
            cout << "Podaj nowy numer telefonu: ";
            cin >> newData;
            checkPhoneLength(newData);
            while(checkPhoneLength(newData) != true){
                cout << "Numer telefonu powinien sie skladac z 9 cyfr. Powtorz jeszcze raz: " << endl;
                cin >> newData;
                checkPhoneLength(newData);
            }
            client->phoneNumber = newData;
        }
        if(option == '5'){
            return client->id;
        }
        updateClientFile(clients);
    }
    return returner;
}


int equipmentDetailsManagement(list<Equipment> &accesories){
    Equipment *equipment;
    string eqId;
    char option;
    string newData;
    cout << "Podaj id rzeczy ktora zmieniasz: ";
    cin >> eqId;

    for(auto &eqObj: accesories){
        if(eqId == to_string(eqObj.id)){
            equipment = &eqObj;
        }
    }
    cout << "Nazwa: " << equipment->Name << endl;
    cout << "Ilosc dostepnych: " << equipment->quantity << endl;
    cout << "Czy sa dostepne: ";
    (equipment->quantity > 0)? cout << "Sa dostepne": cout << "Nie ma na magazynie";
    cout << endl;
    while(option != '0'){
        cout << "1. Zmien nazwe sprzetu" << endl;
        cout << "2. Zmien ilosc dostepnych egzemplarzy" << endl;
        cout << "3. Usun calkowicie wybrany produkt z oferty" << endl;
        cout << "0. Powrot do menu" << endl;

        cin >> option;
        if(option == '1'){
            cout << "Podaj nowa nazwe: ";
            cin >> newData;
            equipment->Name = newData;
        }
        if(option == '2'){
            cout << "Podaj ilosc dostepnych egzemplarzy" << endl;
            cin >> newData;
            equipmentValidator(newData);
            while(equipmentValidator(newData) != true){
                cout << "Ilosc powinna byc podana tylko w cyfrach. Podaj jeszcze raz: ";
                cin >> newData;
                equipmentValidator(newData);
            }
            equipment->quantity = stoi(newData);
            (equipment->quantity > 0) ? equipment->isAvailable = true: equipment->isAvailable = false;
        }
        if(option == '3'){
            return equipment->id;
        }
        updateEqFile(accesories);
    }
    return 0;
}