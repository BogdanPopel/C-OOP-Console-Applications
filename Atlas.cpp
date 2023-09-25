#include <iostream>
#include<list>
using namespace std;

/***
Lista temelor, cu toate cerințele pentru a treia lucrare practica.

    • Cerințe comune tuturor temelor:

    1. utilizarea sabloanelor (functii, clase)
    2. utilizarea STL
    3. utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const
    4. utilizarea conceptelor de RTTI raportat la templat-uri (ex: upcast & dynamic_cast)
    5. citirea informațiilor complete a n obiecte, memorarea și afișarea acestora

Obs. Se pot considera și probleme din fișierul Tema 2 adaptate la cerințele actuale.

    • cerințe generale aplicate fiecărei teme din acest fișier:
- să se identifice și să se implementeze ierarhia de clase;
- clasele să conțină constructori, destructori, =, supraincarcare pe >> si << pentru citire si afisare;
- clasa de baza sa conțină funcție virtuala de afisare si citire, rescrisa în clasele derivate, iar operatorul de citire si afisare să fie implementat
ca funcție prieten (în clasele derivate să se facă referire la implementarea acestuia în clasa de baza).


Tema 2. La ora de Biologie, copiii din ciclul gimnazial învață că regnul animal se împarte în 2 grupuri: nevertebrate și vertebrate. La rândul lor,
vertebratele se împart în pești, păsări, mamifere și reptile.

Cerința suplimentară:
- Să se adauge toate campurile relevante pentru modelarea acestei probleme.
- Să se construiască clasa template AtlasZoologic care sa conțină un număr de animale (incrementat automat la adaugarea unei noi file) și structura de obiecte
de tipul regnurilor implementate, alocata dinamic. Sa se supraincarce operatorul += pentru inserarea unei fișe de observație a unui animal în structura.
- Să se construiască o specializare pentru tipul Pești care sa adapteze operatorii menționați și care sa afiseze, în plus, cati pesti rapitori de lungime
mai mare de 1m s-au citit.

Structura de date: list<animal de un anumit tip *>
*/
class Animal{
    protected:
string nume;
bool rapitor;
float lungime;
    public:
virtual void read(istream&);
virtual void write(ostream&) const;
Animal() = default;
Animal(string, bool, float);
Animal(const Animal&);
Animal& operator = (const Animal& a);
virtual void setName(string) = 0;
virtual void setType(bool) = 0;
virtual void setLength(float) = 0;
virtual string getName() = 0;
virtual bool getType() = 0;
virtual float getLength() = 0;
    friend istream& operator>> (istream& in, Animal& A) {
    A.read(in);
    return in;
}
    friend ostream& operator<< (ostream& out, const Animal& A) {
    A.write(out);
    return out;
}
virtual ~Animal(){};
};
Animal::Animal(string name, bool rap, float len): nume(name), rapitor(rap), lungime(len)
{
}
Animal::Animal(const Animal& a)
{
this->nume = a.nume;
this->rapitor = a.rapitor;
this->lungime = a.lungime;
}
Animal& Animal::operator=(const Animal& a)
{
    if(this != &a)
    {
        this->nume = a.nume;
        this->rapitor = a.rapitor;
        this->lungime = a.lungime;
    }
    return *this;
}

void Animal::read(istream& in) {
    string k, l;
    cout<<"\nNume:    ";
    in.ignore();
    getline(in, this->nume);
    cout<<"Este rapitor? (1/0)    ";
    in >> k;
    while(k.find_first_not_of("01") != string::npos)
    {   cout<<"Valoarea transmisa poate fi doar 0 sau 1.\n1 = este rapitor;\n0 = nu este rapitor;\nReincercati: ";
        in>>k;
    }
    if(k == "1")
        this->rapitor = 1;
    else
        this->rapitor = 0;
    cout<<"Ce lungime are?(cm)    ";
    in >> l;
    while(l.find_first_not_of("1234567890.") != string::npos )
    {
        cout<<"Datele introduse trebuie sa fie de tip float, lungimile fiind masurate in cm.\nEXEMPLU: 1.5 sau 100.231 sau 98766543 etc. Zecimalele sunt despartite prin punct.\nReincercati: ";
        in>>l;
    }
    this->lungime = stof(l);

}

void Animal::write (ostream& out) const {
    out << "-----------------------------" << endl;
    out << "Nume: " << this->nume << endl;
    if(this->rapitor){
        out<< "Rapitor: DA";
    }
    else{
        out<<"Rapitor: NU";
    }
    out << "\nLungime: " << this->lungime << endl;
}

class Nevertebrate: public Animal
{
    public:
Nevertebrate() = default;
Nevertebrate(string n, bool b, float l): Animal(n,b,l){};
Nevertebrate(const Nevertebrate&);
Nevertebrate& operator = (const Nevertebrate&);
void setName(string s) {this->nume = s;};
void setType(bool b) {this->rapitor = b;};
void setLength(float l) {this->lungime = l;};
string getName(){return this->nume;};
bool getType() {return this->rapitor;};
float getLength() {return this->lungime;};
~Nevertebrate(){};
void read(istream& in)
{
    Animal::read(in);
}
void write(ostream& out) const
{
    Animal::write(out);
}

};

Nevertebrate::Nevertebrate(const Nevertebrate& N)
{
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
}
Nevertebrate& Nevertebrate::operator = (const Nevertebrate& N)
{
       if(this != &N)
    {
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
    }
}
class Vertebrate: public Animal
{
public:
    Vertebrate() = default;
    Vertebrate(string n, bool b, float l): Animal(n,b,l){};
    Vertebrate(const Vertebrate&);
    Vertebrate& operator = (const Vertebrate&);
    void setName(string s) {this->nume = s;};
    void setType(bool b) {this->rapitor = b;};
    void setLength(float l) {this->lungime = l;};
    string getName(){return this->nume;};
    bool getType() {return this->rapitor;};
    float getLength() {return this->lungime;};
    ~Vertebrate(){};
    void read(istream& in)
    {
        Animal::read(in);
    }
    void write(ostream& out) const
    {
        Animal::write(out);
    }
};

Vertebrate::Vertebrate(const Vertebrate& N)
{
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
}
Vertebrate& Vertebrate::operator = (const Vertebrate& N)
{
       if(this != &N)
    {
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
    }
}

class Mamifere: public Vertebrate{

public:
    Mamifere() = default;
    Mamifere(string n, bool b, float l): Vertebrate(n,b,l){};
    Mamifere(const Mamifere&);
    Mamifere& operator = (const Mamifere&);
    void setName(string s) {this->nume = s;};
    void setType(bool b) {this->rapitor = b;};
    void setLength(float l) {this->lungime = l;};
    string getName(){return this->nume;};
    bool getType() {return this->rapitor;};
    float getLength() {return this->lungime;};
    ~Mamifere(){};
    void read(istream& in)
    {
        Vertebrate::read(in);
    }
    void write(ostream& out) const
    {
        Vertebrate::write(out);
    }
};

Mamifere::Mamifere(const Mamifere& N)
{
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
}
Mamifere& Mamifere::operator = (const Mamifere& N)
{
       if(this != &N)
    {
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
    }
}
class Reptile: public Vertebrate{

public:

    Reptile() = default;
    Reptile(string n, bool b, float l): Vertebrate(n,b,l){};
    Reptile(const Reptile&);
    Reptile& operator = (const Reptile&);
    void setName(string s) {this->nume = s;};
    void setType(bool b) {this->rapitor = b;};
    void setLength(float l) {this->lungime = l;};
    string getName(){return this->nume;};
    bool getType() {return this->rapitor;};
    float getLength() {return this->lungime;};
    ~Reptile(){};
    void read(istream& in)
    {
        Vertebrate::read(in);
    }
    void write(ostream& out) const
    {
        Vertebrate::write(out);
    }
};

Reptile::Reptile(const Reptile& N)
{
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
}
Reptile& Reptile::operator = (const Reptile& N)
{
       if(this != &N)
    {
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
    }
}

class Pasari: public Vertebrate{

public:
    Pasari() = default;
    Pasari(string n, bool b, float l): Vertebrate(n,b,l){};
    Pasari(const Pasari&);
    Pasari& operator = (const Pasari&);
    void setName(string s) {this->nume = s;};
    void setType(bool b) {this->rapitor = b;};
    void setLength(float l) {this->lungime = l;};
    string getName(){return this->nume;};
    bool getType() {return this->rapitor;};
    float getLength() {return this->lungime;};
    ~Pasari(){};
    void read(istream& in)
    {
        Vertebrate::read(in);
    }
    void write(ostream& out) const
    {
        Vertebrate::write(out);
    }
};

Pasari::Pasari(const Pasari& N)
{
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
}
Pasari& Pasari::operator = (const Pasari& N)
{
       if(this != &N)
    {
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
    }
}

class Pesti: public Vertebrate{


public:
    Pesti() = default;
    Pesti(string n, bool b, float l): Vertebrate(n,b,l){};
    Pesti(const Pesti&);
    Pesti& operator = (const Pesti&);
    void setName(string s) {this->nume = s;};
    void setType(bool b) {this->rapitor = b;};
    void setLength(float l) {this->lungime = l;};
    string getName(){return this->nume;};
    bool getType() {return this->rapitor;};
    float getLength() {return this->lungime;};
    ~Pesti(){};
    void read(istream& in)
    {
        Vertebrate::read(in);
    }
    void write(ostream& out) const
    {
        Vertebrate::write(out);
    }
};
Pesti::Pesti(const Pesti& N)
{
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
}
Pesti& Pesti::operator = (const Pesti& N)
{
       if(this != &N)
    {
        this->nume = N.nume;
        this->rapitor = N.rapitor;
        this->lungime = N.lungime;
    }
}

template <class T>
class AtlasZoologic
{
protected:

static int Size;
list<T*> atlas;

public:
    AtlasZoologic<T>() = default;
    AtlasZoologic<T>(int n){this->Size = n; this->atlas.resize(this->Size);}
    ~AtlasZoologic<T>(){};

    int HowManyFish()
    {
        int contor = 0;
        for(auto it = this->atlas.begin(); it != this->atlas.end(); it++)
        {
            if(IsFish(*it) && (*it)->getType() && (*it)->getLength() >= 100.0)
                    {contor++;}
        }
        return contor;
    }
    bool IsFish(T* t)
    {
        if(dynamic_cast<Pesti*>(t) != nullptr)
            return true;
        return false;
    }
    void introd(T* t)
    {
        this->atlas.push_back(t);
        this->Size += 1;
    }
     void afis()
    {
        for(auto it = atlas.begin(); it!= atlas.end(); it++)
        {
        cout<<(**it)<<"\n";
        }
        cout<<"Dimensiunea listei este: "<<this->Size<<"\n";
    }
    friend ostream& operator >> (istream& in, AtlasZoologic<T>& a)
    {
    string n;
    int opt, nn;
     cout<<"Cate fise de observatie doriti contina atlasul?\n";
     cin>> n;
     while(n.find_first_not_of("1234567890") != string::npos)
     {
         cout<<"Numarul transmis trebuie sa fie natural.\nReincercati: ";
         cin>>n;
     }
    nn = stoi(n);
     while(nn)
     {
    cout<<"1 - Adauga Peste;\n"<<"2 - Adauga Pasare;\n"<<"3 - Adauga Mamifer;\n"<<"4 - Adauga Reptila;\n"<<"5 - Adauga Nevertebrata;\n";
    cin>>opt;
    switch(opt)
    {
        case 1:
            {
            cout<<"1 - Adauga Peste;\n";
            Pesti *p = new Pesti();
            cin>>*p;
            a+= p;
            break;
            }
            case 2:
            {
            cout<<"2 - Adauga Pasare;\n";
            Pasari *o = new Pasari();
            cin>>*o;
            a+=o;
            break;
            }
            case 3:
            {
            cout<<"3 - Adauga Mamifer;\n";
            Mamifere *h = new Mamifere();
            cin>>*h;
            a+=h;
            break;
            }
            case 4:
            {
            cout<<"4 - Adauga Reptila;\n";
            Reptile *z = new Reptile();
            cin>>*z;
            a+=z;
            break;
            }
            case 5:
            {
            cout<<"5 - Adauga Nevertebrata;\n";
            Nevertebrate *u = new Nevertebrate();
            cin>>*u;
            a+=u;
            break;
            }
        }
        nn-=1;
    }
    }
    friend ostream& operator << (ostream& out, const AtlasZoologic<T>& u)
    {
     for(auto it = u.atlas.begin(); it != u.atlas.end(); it++)
        {
            (*it)->write(out);
            if(dynamic_cast<Pesti*>(*it) != nullptr)
                    out<<"Tip: Peste\n";
            if(dynamic_cast<Pasari*>(*it) != nullptr)
                    out<<"Tip: Pasare\n";
            if(dynamic_cast<Mamifere*>(*it) != nullptr)
                    out<<"Tip: Mamifer\n";
            if(dynamic_cast<Reptile*>(*it) != nullptr)
                    out<<"Tip: Reptila\n";
            if(dynamic_cast<Nevertebrate*>(*it) != nullptr)
                    out<<"Tip: Nevertebrata\n";
        }
        out<<"Dimensiunea listei este: "<<Size<<"\n";
        return out;
    }
    AtlasZoologic<T>& operator += (T*);
    AtlasZoologic<T>& operator = (const AtlasZoologic<T>&);
};

template <class B>
int AtlasZoologic<B>::Size = 0;

template<class T>
AtlasZoologic<T>& AtlasZoologic<T>::operator += (T* t)
{
    this->atlas.push_back(t);
    this->Size++;
}

template<class K>
AtlasZoologic<K>& AtlasZoologic<K>::operator = (const AtlasZoologic<K>& ob)
{
    this->Size = ob.Size;
    this->atlas.assign(ob.atlas.begin(), ob.atlas.end());
}
class Menu
{
public:
    Menu() = default;
    ~Menu(){};
    void run()
    {   string opt;
        int OPT = 1;
        AtlasZoologic<Animal> ATLAS;
        while(OPT)
        {
            cout<<"1 - Adauga Vertebrata;\n2 - Adauga Nevertebrata;\n3 - Verifica cati pesti rapitori cu lungimea de peste un metru au fost introdusi;\n4 - Afiseaza intregul Atlas;\n5 - HELP!\n0 - EXIT\n";
            cout<<"Comanda: ";
            cin>>opt;
            while(opt.find_first_not_of("012345") != string::npos)
                {
                    cout<<"Optiunile variaza de la 0 la 5. Alegeti un numar din lista prezentata: 1, 2, 3, 4, 5.\n";
                    cin>>opt;
                }
            OPT = stoi(opt);
            switch(OPT)
            {
            case 1:
            {
                cout<<"1 - Adauga Mamifer;\n2 - Adauga Reptila;\n3 - Adauga Peste\n4 - Adauga Pasare\n";
                cout<<"Comanda: ";
                cin>>opt;
                while(opt.find_first_not_of("1234") != string::npos)
                {
                    cout<<"Optiunile variaza intre 1 si 4. Alegeti un numar din lista prezentata: 1, 2, 3, 4.\n";
                    cin>>opt;
                }
                OPT = stoi(opt);
                switch(OPT)
                {
                    case 1:
                        {
                        Mamifere *m = new Mamifere();
                        cin>>*m;
                        ATLAS += m;
                        break;
                        }
                    case 2:
                        {
                        Reptile *k = new Reptile();
                        cin>>*k;
                        ATLAS += k;
                        break;
                        }
                    case 3:
                        {
                        Pesti *l = new Pesti();
                        cin>>*l;
                        ATLAS += l;
                        break;
                        }
                    case 4:
                        {
                        Pasari *v = new Pasari();
                        cin>>*v;
                        ATLAS += v;
                        break;
                        }
                }
                break;
            }
            case 2:
                {
                Nevertebrate *n = new Nevertebrate();
                cin>>*n;
                ATLAS += n;
                break;
                }
            case 3:
                {
                cout<<"Au fost gasiti "<<ATLAS.HowManyFish()<<" pesti rapitori cu lungimea de peste un metru.\n";
                break;
                }
            case 4:
                {
                cout<<ATLAS;
                break;
                }
            case 5:
            {
                cout<<"Programul urmatorul reprezinta un atlas electronic care permite introducerea mai multor fise de observatie pentru diferite animale. Alegeti daca vreti sa descrieti vertebrate sau nevertebrate, apoi alegeti ce animal doriti sa descrieti. Comenzile sunt transmise de la tastatura, optiunile fiind reprezentate de numerele din stanga optiunilor. Introduceti optiunea dorita si apasati ENTER.\n";
                break;
            }
            }
        }
    cout<<"Multumim pentru timpul acordat!\n";
    }
};


int main()
{
Menu m;
m.run();
}
