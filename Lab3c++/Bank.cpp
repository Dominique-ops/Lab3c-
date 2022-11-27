#include "Bank.h"

int Bank::counter = 0;

Bank::Bank() {
    FIO();
    id = 1;
    sum = 100;

}

Bank::Bank (int x, int deposid, FIO d) {
    id = counter;
    sum = deposid;
    client = d;

}

int Bank::Getid() {
    return id;
}

double Bank::Getsum() {
    return sum;
}

char* Bank::Getname() {
    return client.name;
}


char* Bank::Getsurname() {
    return client.surname;
}

char* Bank::Getoname() {
    return client.oname;
}

void addsum(Bank mas[])
{
    int id,value;
    cout << "введите число" << endl;
    cin >> value;
    cout << "введите id" << endl;
    cin >> id;
    mas[id] + value;
    
}



/*Bank::Bank(Bank& other) {
    this->account = other.account;
    strcpy(this->fam, other.fam);
    strcpy(this->name, other.name);
    this->sum = other.sum;
}*/


void Bank::addperson(Bank mas[]) {
    char* surname = new char[50];
    char* name = new char[50];
    char* oname = new char[50];
    cout << "¬ведите номер счета: ";
    cin >> mas[counter].id;

    cout << "¬ведите фамилию клиента: ";
    cin >> surname;

    cout << "¬ведите им€ клиента: ";
    cin >> name;

    cout << "¬ведите отчество клиента: ";
    cin >> oname;

    cout << "¬ведите депозит: ";
    cin >> mas[counter].sum;

    FIO human(name, surname, oname);
    mas[counter].client = human;

    counter++;
}

void Bank::saveperson(Bank mas[]) {
    ofstream file("DataBase.txt");
    file << counter << endl;
    for (int i = 0; i < counter; i++) {
        file << mas[i].id << endl;
        file << mas[i].client.name << endl;;
        file << mas[i].client.surname << endl;
        file << mas[i].client.oname << endl;
        file << mas[i].sum << endl;
    }
    delete[] mas;
    file.close();
    exit(0);
}

void Bank::loadperson(Bank mas[]) {
    ifstream file("DataBase.txt");
    if (file.is_open() && file.peek() != EOF) {
        char* n = new char[20];
        char* s = new char[20];
        char* o = new char[20];
        int d, y;
        file >> counter;
        for (int i = 0; i < counter; i++) {
            file >> mas[i].id;
            file >> n;
            file >> s;
            file >> o;
            FIO human(n, s, o);
            mas[i].client = human;
        }
    }
    /* else {

         cout << "—оздание новой DB" << endl;
         addperson(mas);
     }*/
    file.close();

}
ostream& operator <<(ostream& out, Bank& obj) {


    out << obj.Getid() << endl;
    out << obj.Getname() << endl;;
    out << obj.Getsurname() << endl;
    out << obj.Getoname() << endl;
    out << obj.Getsum() << endl;

    return out;
}

void Bank::display(Bank mas[]) {
    cout << "¬ведите id" << endl;
    int m;
    cin >> m;
    bool flag = false;
    for (int i = 0; i < counter; i++) {
        if (mas[i].id == m) {
            //cout << "Owner's id: " << mas[i].id << endl;
            //cout << "Surname: " << mas[i].client.surname << endl;
            //cout << "Name: " << mas[i].client.name << endl;
            //cout << "Oname: " << mas[i].client.oname << endl;
            //cout << "Deposid: " << mas[i].sum << endl;
            cout << mas[i];
            flag = true;
            break;
        }
    }
    if (flag == false) {
        cout << "id отсутствует " << endl;
    }

}

Bank:: ~Bank() {
    // delete fam;
     //delete name;

}




void sort(Bank mas[]) {
    Bank test;
    for (int i = 0; i < Bank::counter - 1; ++i) {
        for (int j = 0; j < Bank::counter - 1; ++j) {
            if (mas[j].sum < mas[j+1].sum) {
                test = mas[j + 1];
                mas[j + 1] = mas[j];
                mas[j] = test;
            }
        }
    }

}



