#include <iostream>
#include <vector>

using namespace std;


class Person
{
protected:
    int id;
    string nume;
    static int nr_ord;
public:
    Person(string = "");
    Person(const Person&);
    Person& operator = (const Person&);
    virtual int getID() = 0;
    virtual string getName() = 0;
    virtual string getNumber() = 0;
    virtual string getSkypeID() = 0;
    virtual string getMail() = 0;
    virtual string getCountry() = 0;
    virtual void setData() = 0;
    virtual void setName(string) = 0;
    virtual void setNumber(string) = 0;
    virtual void setSkypeID(string) = 0;
    virtual void setMail(string) = 0;
    virtual void setCountry(string) = 0;
    virtual void print() = 0;

    static void Describe(){cout<<"Programul permite crearea unei agende de abonati, de diferite tipuri, in care se pot salva si accesa datele lor personale, cautarea putand fi facuta dupa nume. Introduceti optiunea dorita, apoi apasati tasta ENTER pentru a confirma.\nOption 1: Adaugati un numar ales de abonati. Se va cere numarul de abonati pe care doriti sa il adaugati, apoi datele fiecaruia.\nOption 2: Se va cere tipul abonatului pe care doriti sa il adaugati si datele acestuia.\nOption 3: Se va cere numele abonatului ale carui date doriti sa le afisati. exemplu: Popel --> Se va cauta in agenda abonatul cu numele < Popel > si i se vor afisa datele personale din agenda.\n\n";};
friend ostream& operator << (ostream& out, const Person &p) {
        out << "ID: " << p.id << "; Nume: "<< p.nume << "\n";
        return out;
    }

friend istream& operator >> (istream& in, Person &p) {
        cout << "Dati numele persoanei:\n";
        in >> p.nume;
        return in;
    }

~Person(){};
};

int Person::nr_ord = -1;

Person::Person(string n): nume(n){
nr_ord++;
this->id = nr_ord;
}
Person::Person(const Person& old)
{
    this->id = old.id;
    this->nume = old.nume;
}
Person& Person::operator=(const Person& ob)
{
    if(this !=&ob)
    {
        this->id = ob.id;
        this->nume = ob.nume;
    }
    return *this;
}

class Abonat: public Person{
    protected:
    string nr_telefon;
public:
    Abonat(string = "", string = "");
    Abonat(const Abonat&);
    Abonat& operator = (const Abonat&);
    int getID(){return this->id;};
    string getName(){return this->nume;};
    string getNumber(){return this->nr_telefon;};
    string getSkypeID(){cout<<"Acest tip de abonat nu contine un ID de skype.\n";};
    string getMail(){cout<<"Acest tip de abonat nu contine o adresa de mail.\n";};
    string getCountry(){cout<<"Acest tip de abonat nu contine o tara.\n";};
    void setName(string s){this->nume = s;};
    void setNumber(string s){this->nr_telefon = s;};
    void setSkypeID(string){};
    void setMail(string){};
    void setCountry(string){};
    void setData();
    void print();
    friend ostream& operator << (ostream& out, const Abonat &a) {
        out << "ID: " << a.id << "; Nume: "<< a.nume <<" ;Nr. telefon: "<<a.nr_telefon <<"\n";
        return out;
    }

    friend istream& operator >> (istream& in, Abonat &a) {
        cout << "Dati numele persoanei si numarul de telefon:\n";
        in>>a.nume >> a.nr_telefon;
        return in;
}
~Abonat(){};
};
Abonat::Abonat(string n, string nr): Person(n), nr_telefon(nr){}
Abonat::Abonat(const Abonat& ab)
{
this->id = ab.id;
this->nume = ab.nume;
this->nr_telefon = ab.nr_telefon;
}
Abonat& Abonat::operator=(const Abonat& ob)
{
     if(this !=&ob)
     {
        this->id = ob.id;
        this->nume = ob.nume;
        this->nr_telefon = ob.nr_telefon;
     }
     return *this;
}

void Abonat::setData()
{   string n, nr;
    cout<<"Nume: ";cin>>n;cout<<"Nr. telefon: ";cin>>nr;
    this->setName(n);
    this->nr_telefon = nr;
}
void Abonat::print()
{
    cout<<"ID: "<<this->id<<"; Nume: "<<this->nume<<"; Nr. telefon: "<<this->nr_telefon<<"\n";
}


class Abonat_Skype: public Abonat{
    protected:
    string id_skype;
public:
    Abonat_Skype(string="", string="", string = "");
    Abonat_Skype(const Abonat_Skype&);
    int getID(){return this->id;};
    string getName(){return this->nume;};
    string getNumber(){return this->nr_telefon;};
    string getSkypeID(){return this->id_skype;};
    string getMail(){cout<<"Acest tip de abonat nu contine o adresa de mail.\n";};
    string getCountry(){cout<<"Acest tip de abonat nu contine o tara.\n";};
    void setName(string s){this->nume = s;};
    void setNumber(string s){this->nr_telefon = s;};
    void setSkypeID(string s){this->id_skype = s;};
    void setMail(string){};
    void setCountry(string){};
    void setData();
    void print();
    Abonat_Skype& operator=(const Abonat_Skype&);

    friend ostream& operator << (ostream& out, const Abonat_Skype &a) {
        out << "ID: " << a.id << "; Nume: "<< a.nume <<" ;Nr. telefon: "<<a.nr_telefon << ": Skype ID: "<< a.id_skype<<"\n";
        return out;
    }

    friend istream& operator >> (istream& in, Abonat_Skype &a) {
        cout << "Dati numele persoanei, numarul de telefon si id-ul de skype:\n";
        in >> a.nume >> a.nr_telefon >> a.id_skype;
        return in;
}
    ~Abonat_Skype(){};
};
Abonat_Skype::Abonat_Skype(string n, string nr,string id): Abonat(n, nr), id_skype(id){}
Abonat_Skype::Abonat_Skype(const Abonat_Skype& ob)
{
    this->id = ob.id;
    this->nume = ob.nume;
    this->nr_telefon = ob.nr_telefon;
    this->id_skype = ob.id_skype;
}
Abonat_Skype& Abonat_Skype::operator=(const Abonat_Skype& ob)
{
    if(this != &ob)
    {
    this->id = ob.id;
    this->nume = ob.nume;
    this->nr_telefon = ob.nr_telefon;
    this->id_skype = ob.id_skype;
    }
    return *this;
}

void Abonat_Skype::setData()
{
    string n, nr, id_sk;
    cout<<"Nume: ";cin>>n;cout<<"Nr. telefon: ";cin>>nr; cout<<"ID Skype: ";cin>>id_sk;
    this->setName(n);
    this->nr_telefon = nr;
    this->id_skype = id_sk;
}
void Abonat_Skype::print()
{
    cout<<"ID: "<<this->id<<"; Nume: "<<this->nume<<"; Nr. telefon: "<<this->nr_telefon<<"ID Skype: "<<this->id_skype<<"\n";
}
class Abonat_Skype_Romania: public Abonat_Skype{
    protected:
    string adresa_mail;
public:
    Abonat_Skype_Romania(string = "", string ="", string = "", string = "");
    Abonat_Skype_Romania(const Abonat_Skype_Romania& ar);
    int getID(){return this->id;};
    string getName(){return this->nume;};
    string getNumber(){return this->nr_telefon;};
    string getSkypeID(){return this->id_skype;};
    string getMail(){return this->adresa_mail;};
    string getCountry(){cout<<"Acest tip de abonat nu contine o tara.\n";};
    void setName(string s){this->nume =s; };
    void setNumber(string s){this->nr_telefon = s;};
    void setSkypeID(string s){this->id_skype = s;};
    void setMail(string s){this->adresa_mail = s;};
    void setCountry(string s){};
    void setData();
    void print();
    Abonat_Skype_Romania& operator=(const Abonat_Skype_Romania&);

    friend ostream& operator << (ostream& out, const Abonat_Skype_Romania &a) {
        out << "ID: " << a.id << "; Nume: "<< a.nume <<" ;Nr. telefon: "<<a.nr_telefon << ": Skype ID: "<< a.id_skype<< "; Mail: "<<a.adresa_mail<<"\n";
        return out;
    }

    friend istream& operator >> (istream& in, Abonat_Skype_Romania &a) {
        cout << "Dati numele persoanei, numarul de telefon, id-ul de skype si adresa de mail:\n";
        in >> a.nume >> a.nr_telefon >> a.id_skype >> a.adresa_mail;
        return in;
}
    ~Abonat_Skype_Romania(){};
};

Abonat_Skype_Romania::Abonat_Skype_Romania(string n, string nr, string id, string m): Abonat_Skype(n, nr, id), adresa_mail(m){}
Abonat_Skype_Romania::Abonat_Skype_Romania(const Abonat_Skype_Romania& ar)
{
    this->id = ar.id;
    this->nume = ar.nume;
    this->nr_telefon = ar.nr_telefon;
    this->id_skype = ar.id_skype;
    this->adresa_mail = ar.adresa_mail;
}
Abonat_Skype_Romania& Abonat_Skype_Romania::operator=(const Abonat_Skype_Romania& ob)
{
    if(this != &ob)
    {
    this->id = ob.id;
    this->nume = ob.nume;
    this->nr_telefon = ob.nr_telefon;
    this->id_skype = ob.id_skype;
    }
    return *this;
}

void Abonat_Skype_Romania::setData()
{
    string n, nr, id_sk, mail;
    cout<<"Nume: ";cin>>n;cout<<"Nr. telefon: ";cin>>nr; cout<<"ID Skype: ";cin>>id_sk; cout<<"Mail: ";cin>>mail;
    this->setName(n);
    this->nr_telefon = nr;
    this->id_skype = id_sk;
    this->adresa_mail = mail;
}
void Abonat_Skype_Romania::print()
{
    cout<<"ID: "<<this->id<<"; Nume: "<<this->nume<<"; Nr. telefon: "<<this->nr_telefon<<"ID Skype: "<<this->id_skype<<"; Mail: "<<this->adresa_mail<<"\n";
}
class Abonat_Skype_Extern: public Abonat_Skype{
    protected:
    string tara;
public:
    Abonat_Skype_Extern(string = "", string ="", string = "", string = "");
    Abonat_Skype_Extern(const Abonat_Skype_Extern&);
    int getID(){return this->id;};
    string getName(){return this->nume;};
    string getNumber(){return this->nr_telefon;};
    string getSkypeID(){return this->id_skype;};
    string getMail(){cout<<"Acest tip de abonat nu contine o adresa de mail.\n";};
    string getCountry(){return this->tara;};
    void setName(string s){this->nume = s;};
    void setNumber(string s){this->nr_telefon = s;};
    void setSkypeID(string s){this->id_skype = s;};
    void setMail(string){};
    void setCountry(string s){this->tara = s;};
    void setData();
    void print();
    Abonat_Skype_Extern& operator=(const Abonat_Skype_Extern&);

    friend ostream& operator << (ostream& out, const Abonat_Skype_Extern &a) {
        out << "ID: " << a.id << "; Nume: "<< a.nume <<" ;Nr. telefon: "<<a.nr_telefon << ": Skype ID: "<< a.id_skype <<"; Tara: "<<a.tara<<"\n";
        return out;
    }

    friend istream& operator >> (istream& in, Abonat_Skype_Extern &a) {
        cout << "Dati numele persoanei scris LEGAT, numarul de telefon, id-ul de skype si tara din care provine:\n";
        in >> a.nume >> a.nr_telefon >> a.id_skype >> a.tara;
        return in;
}
    ~Abonat_Skype_Extern(){};
};
Abonat_Skype_Extern::Abonat_Skype_Extern(string n, string nr, string id, string t): Abonat_Skype(n, nr, id), tara(t){}
Abonat_Skype_Extern::Abonat_Skype_Extern(const Abonat_Skype_Extern& ae)
{
    this->id = ae.id;
    this->nume = ae.nume;
    this->nr_telefon = ae.nr_telefon;
    this->id_skype = ae.id_skype;
    this->tara = ae.tara;
}
Abonat_Skype_Extern& Abonat_Skype_Extern::operator=(const Abonat_Skype_Extern& ob)
{
    if(this != &ob)
    {
    this->id = ob.id;
    this->nume = ob.nume;
    this->nr_telefon = ob.nr_telefon;
    this->id_skype = ob.id_skype;
    }
    return *this;
}

void Abonat_Skype_Extern::setData()
{
    string n, nr, id_sk, t;
    cout<<"Nume: ";cin>>n;cout<<"Nr. telefon: ";cin>>nr; cout<<"ID Skype: ";cin>>id_sk; cout<<"Tara: ";cin>>t;
    this->setName(n);
    this->nr_telefon = nr;
    this->id_skype = id_sk;
    this->tara = t;
}
void Abonat_Skype_Extern::print()
{
    cout<<"ID: "<<this->id<<"; Nume: "<<this->nume<<"; Nr. telefon: "<<this->nr_telefon<<"ID Skype: "<<this->id_skype<<"; Tara: "<<this->tara<<"\n";
}

class Agenda: public Abonat, public std::vector<Person*>
{
    public:
        vector<Person*> Contacte;
    public:

void AddN()
{
    unsigned citiri;
    unsigned opt;
    cout<<"Cate elemente doriti sa adaugati?\n";
    cin>>citiri;
while(citiri)
{
    cout<<"1 - Adauga abonat;\n"<<"2 - Adauga abonat skype;\n"<<"3 - Adauga abonat skype din romania;\n"<<"4 - Adauga abonat skype extern;\n";

    cin>>opt;
    switch(opt) {
  case 1:
    {
    cout<<"1 - Adauga abonat;\n";
    Person *p = new Abonat();
    p->setData();
    this->Contacte.push_back(p);
    citiri--;
    break;
    }
  case 2:
    {
      cout<<"2 - Adauga abonat skype;\n";
    Person *o = new Abonat_Skype();
    o->setData();
    this->Contacte.push_back(o);
    citiri--;
    break;
    }
  case 3:
    {
    cout<<"3 - Adauga abonat skype din romania;\n";
    Person *i = new Abonat_Skype_Romania();
    i->setData();
    this->Contacte.push_back(i);
    citiri--;
    break;
    }
  case 4:
      {
    cout<<"4 - Adauga abonat skype extern;\n";
    Person *u = new Abonat_Skype_Extern();
    u->setData();
    this->Contacte.push_back(u);
    citiri--;
    break;
      }
  default:
    cout<<"Nu exista aceasta optiune. Reincercati!\n";
}

}

}
Person* operator[](int i)
{   if(this->Contacte.size()>0)
        return this->Contacte[i];
    else{cout<<"Agenda nu contine abonati"; return 0;}
}
Person* operator[](string s)
{
if(this->Contacte.size())
    {
    for(int i = 0; i < this->Contacte.size(); i++)
        {
                if(this->Contacte[i]->getName() == s)
                    return this->Contacte[i];
        }
    cout<<"Abonatul cautat nu exista\n"; return 0;
    }
else{cout<<"Agenda nu contine abonati\n"; return 0;}
}
void AddOne()
{
    cout<<"Introduceti tipul abonatului pe care doriti sa il adaugati:\n1 - Adauga abonat;\n"<<"2 - Adauga abonat skype;\n"<<"3 - Adauga abonat skype din romania;\n"<<"4 - Adauga abonat skype din romania;\n";
    unsigned opt;
    cin>>opt;
    switch(opt) {
  case 1:
    {
    cout<<"1 - Adauga abonat;\n";
    Person *p = new Abonat();
    p->setData();
    this->Contacte.push_back(p);
    break;
    }
  case 2:
    {
      cout<<"2 - Adauga abonat skype;\n";
    Person *o = new Abonat_Skype();
    o->setData();
    this->Contacte.push_back(o);
    break;
    }
  case 3:
    {
    cout<<"3 - Adauga abonat skype din romania;\n";
    Person *i = new Abonat_Skype_Romania();
    i->setData();
    this->Contacte.push_back(i);
    break;
    }
  case 4:
      {
    cout<<"4 - Adauga abonat skype din strainatate;\n";
    Person *u = new Abonat_Skype_Extern();
    u->setData();
    this->Contacte.push_back(u);
    break;
      }

  default:
    cout<<"Optiunea nu exista. Reincercati\n";
}
}
};


int main()
{
cout<<"Popel Emil-Bogdan\nGrupa 132\nTema 4\n\n";
unsigned opt;
Agenda agenda;
while(true)
{  cout<<"1 - Citire n elemente;\n2 - Adauga un element;\n3 - Cautare abonat dupa nume;\n4 - Help!;\n0 - Exit\n";
    cin>>opt;
    switch(opt){
    case 0:
        {
            cout<<"Sfarsit de program.\n";
            return 0;
            break;
        }
    case 1:
        {
            agenda.AddN();
            break;
        }
    case 2:
        {
            agenda.AddOne();
            break;
        }
    case 3:
        {
        if(agenda.Contacte.size())
            {string s;
            cout<<"Introduceti numele abonatului ale carui informatii doriti sa le accesati\n";
            cin>>s;
            if(agenda[s])
                {agenda[s]->print();}
            }
        else{cout<<"Agenda nu contine abonati.\n";}

        break;

        }
    case 4:
        {
            Person::Describe();
            break;
        }
    default:
        cout<<"Optiune gresita! Reincercati:\n";
    }
}
}

