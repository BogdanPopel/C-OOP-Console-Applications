 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/***
Cerinte comune tuturor temelor:

    • implementare in C++ folosind clase
    • datele membre private
    • constructori de initializare (cu si fara parametrii), constructor de copiere
    • get, set pentru toate datele membre
    • ATENTIE: functiile pe care le-am numit mai jos metode (fie ca sunt supraincarcari de operatori, fie altfel de functii), pot fi implementate ca functii prieten in loc de metode ale claselor respective, daca se considera ca aceasta alegere este mai naturala;
    • supraincarcarea operatorilor << si >> pentru iesiri si intrari de obiecte, dupa indicatiile de mai jos, astfel incat sa fie permise (si ilustrate in program):
    • sa existe o metoda publica prin care se realizeaza citirea informațiilor complete a n obiecte, memorarea și afisarea acestora.
    • programul sa aiba un meniu interactiv

Necesar: programul sa nu contina erori de compilare si sa ruleze in CodeBlocks

Tema 3. Clasa ”Vector” (vector de numere întregi)
	- membri privati pentru vectorul propriu zis si numarul de elemente;
    	- constructor pentru initializarea cu un numar dat pe toate componentele
(primeste ca parametru numarul respectiv si numarul componentelor);
    	- constructori pentru initializare si copiere;
    	- destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero, iar în cazul alocarii dinamice, se dezaloca zona de memorie utilizata);
    	- metoda-operator public de atribuire =;
	- metoda publica pentru reactualizarea numarului de componente si initializarea componentelor cu un numar dat (primeste ca parametru numarul respectiv si numarul componentelor);
	- metoda publica pentru calculul sumei tuturor elementelor vectorului;
	- metoda publica pentru găsirea maximului și a pozitiei lui;
	- metoda publica pentru sortarea crescătoare a vectorului;
*/
//vector<Vector> vec;

class Vector
{
    int nr_componente = 0;
    vector<int> Vec;

public:

void set_nr_componente(int n) {nr_componente = n; Vec.resize(nr_componente);}
void set_componente(int n) {for(unsigned int i = 0; i < Vec.size(); i++) {cin>>n; Vec.push_back(n);}}
int get_nr_componente(){return nr_componente;}
void get_componente(){for(unsigned int i = 0; i < Vec.size(); i++) cout<<Vec[i]<<" "; cout<<endl;}
void Actualizare(int val, int lungime);
Vector operator=(Vector);
void GetMax();
void OrderCresc();
void SumOfElements();
Vector(int lungime = 0, int continut = 0);
Vector(const Vector&);
~Vector();
friend ostream& operator<<(ostream& out, Vector& v);
friend istream& operator>>(istream& in, Vector& v);
};

void Vector::Actualizare(int val, int lungime)
{
    nr_componente = lungime;
    Vec.assign(nr_componente, val);
}

Vector Vector::operator=(Vector ob)
{
        if(this != &ob)
        {
            this->nr_componente = ob.nr_componente;
            this->Vec.assign(ob.Vec.begin(), ob.Vec.end());
        }
        return *this;
}

void Vector::GetMax()
{   int Maxim = *max_element(this->Vec.begin(), this->Vec.end());
    int Pos_Maxim = distance(this->Vec.begin(), max_element(this->Vec.begin(), this->Vec.end()));
    cout<<"Maxim: "<<Maxim<<" Pozitia: "<<Pos_Maxim + 1<<" sau Vec["<<Pos_Maxim<<"]"<<endl;
}
void Vector::OrderCresc()
{
    bool swapped = true;

    while(swapped)
    { swapped = false;
        for(unsigned int i = 0; i<this->Vec.size()-1;i++)
        {
            if (this->Vec[i] > this->Vec[i+1])
            {
                this->Vec[i] += this->Vec[i+1];
                this->Vec[i+1] = this->Vec[i] - this->Vec[i+1];
                this->Vec[i] -= this->Vec[i+1];
                swapped = true;
            }
        }

    }
}
void Vector::SumOfElements()
{   int Sum = 0;
    for(unsigned int i = 0; i < this->Vec.size(); i++)
        Sum += Vec[i];
    cout<<Sum<<endl;
}

Vector::Vector(int lungime, int continut)
{
    this->nr_componente = lungime;
    Vec.resize(nr_componente, continut);
}


Vector::Vector(const Vector& ob)
{
    nr_componente = ob.nr_componente;
    Vec.assign(ob.Vec.begin(), ob.Vec.end());
}

Vector::~Vector()
{
    vector<int>().swap(Vec);

}

ostream& operator<<(ostream& out, Vector& v)
{
    out<<"Numar de componente: "<<v.nr_componente<<" Componente: "<<endl;
    for(unsigned int i = 0; i < v.nr_componente; i++)
        out<<v.Vec[i]<<" ";
    out<<endl;
    out<<"--------------------"<<endl;
    return out;


}
istream& operator>>(istream& in, Vector& v)
{   v.Vec.clear();
    int k;
    cout<<"Numar de componente: ";
    in >> v.nr_componente;
    cout<<"Componente: "<<endl;
    for(unsigned int i = 0; i<v.nr_componente; i++)
    {   in>>k;
        v.Vec.push_back(k);
    }
    return in;
}

int main()
{ vector<Vector> Vectori;

    bool run = 1;
    while(run)
    {   int option;
        cout<<"Introduceti optiunea:"<<endl<<"1 - Initializiare a n elemente"<<endl<<"2 - Intializare vector;"<<endl<<"3 - Afisarea unui anumit vector;"<<endl<<"4 - Afisarea tuturor vectorilor creati"<<endl<<"5 - Afisati suma elementelor unui vector creat"<<endl<<"6 - Ordonati crescator un vector creat"<<endl<<"7 - Afisati maximul si pozitia sa dintr-un vector creat"<<endl<<"8 - Actualizarea continutului unui vector"<<endl<<"9 - Initializare vector cu toate elementele egale"<<endl<<"10 - Copierea unui vector deja creat"<<endl;
        cin>>option;
    switch(option)
    {
    case 1:
        {   Vector x;
            unsigned int n;
            cout<<"Cate elemente doriti sa adaugati?"<<endl<<"n= ";
            cin >> n;
            if(n<1)
            {
                cout<<"n trebuie sa fie cel putin 1!"<<endl;
                break;
            }

            for(unsigned int o = 0; o < n-1; o++)
            {
                cout<<"Elementul "<<o+1<<":"<<endl;
                cin>>x;
                Vectori.push_back(x);
            }

        }
    case 2:
        {
            Vector v;
            cin>>v;
            Vectori.push_back(v);
            break;
        }
    case 3:
        {
            if(Vectori.size()<1)
            {
                cout<<"Nu au fost creati vectori. Reintroduceti optiunea:"<<endl;
                break;
            }

            unsigned int h;
            cout<<"Pana acum au fost creati "<<Vectori.size()<<" vectori. Introduceti numarul de ordine al vectorului pe care doriti sa il afisati: 1-->"<<Vectori.size()<<":"<<endl;

            try
            {
                cin>>h;
                if(h > Vectori.size())
                    throw 1;
            }
            catch(int i)
            {
                cout<<"Au fost creati doar "<<Vectori.size()<<" vectori. Reintroduceti numarul de ordine al vectorului pe care doriti sa-l afisati:"<<endl;
                cin>>h;
                if(h > Vectori.size())
                {
                    cout<<"Au fost creati doar "<<Vectori.size()<<" vectori. Realegeti optiunea."<<endl;
                    break;
                }
                else
                    cout<<Vectori[h-1];

            }
            cout<<Vectori[h-1];
            break;

        }
    case 4:
        {
            if(Vectori.size()<1)
            {
                cout<<"Nu au fost creati vectori. Reintroduceti optiunea:"<<endl;
                break;
            }
            for(unsigned int i = 0; i<Vectori.size();i++)
                cout<<Vectori[i];
            break;
        }
    case 5:
        {
            if(Vectori.size()<1)
            {
                cout<<"Nu au fost creati vectori. Reintroduceti optiunea:"<<endl;
                break;
            }
            unsigned int l;
            cout<<"Introduceti numarul de ordine al vectorului: 1-->"<<Vectori.size()<<"."<<endl;
            cin>>l;
            cout<<"Suma elementelor: ";
            Vectori[l-1].SumOfElements();
            break;
        }
    case 6:
        {
            if(Vectori.size()<1)
            {
                cout<<"Nu au fost creati vectori. Reintroduceti optiunea:"<<endl;
                break;
            }
            unsigned int s;
            cout<<"Introduceti numarul de ordine al vectorului: 1-->"<<Vectori.size()<<"."<<endl;
            cin>>s;
            Vectori[s-1].OrderCresc();
            break;
        }
    case 7:
        {
            if(Vectori.size()<1)
            {
                cout<<"Nu au fost creati vectori. Reintroduceti optiunea:"<<endl;
                break;
            }
            unsigned int g;
            cout<<"Introduceti numarul de ordine al vectorului: 1-->"<<Vectori.size()<<"."<<endl;
            cin>>g;
            Vectori[g-1].GetMax();
            break;
        }
    case 8:
        {
            if(Vectori.size()<1)
            {
                cout<<"Nu au fost creati vectori. Reintroduceti optiunea:"<<endl;
                break;
            }
            unsigned int p;
            int val, lungime;
            cout<<"Introduceti numarul de ordine al vectorului: 1-->"<<Vectori.size()<<"."<<endl;
            cin>>p;
            cout<<"Vectorul "<<p<<" va fi actualizat. Introduceti valoarea cu care va fi ocupat si lungimea dorita."<<endl;
            cout<<"Valoarea: ";
            cin>>val;
            cout<<"Lungime: ";
            cin>>lungime;
            Vectori[p-1].Actualizare(val, lungime);
            break;
        }
    case 9:
        {
            int llungime;
            int vall;
            cout<<"Introduceti valoarea cu care va fi ocupat si lungimea dorita."<<endl;
            cout<<"Valoarea: ";
            cin>>vall;
            cout<<"Lungime: ";
            cin>>llungime;
            if(llungime < 1)
            {
                cout<<"Lungimea trebuie sa fie minim 1";
                break;
            }
            Vector y(llungime, vall);
            Vectori.push_back(y);
            break;
        }
    case 10:
        {
            if(Vectori.size()<1)
            {
                cout<<"Nu au fost creati vectori inca."<<endl;
                break;
            }
            Vector r;
            unsigned int e;
            cout<<"Introduceti numarul de ordine al vectorului pe care doriti sa il copiati: 1-->"<<Vectori.size()<<"."<<endl;
            cin>>e;
            if(e>Vectori.size())
            {
                cout<<"Au fost creati doar "<<Vectori.size()<<" vectori."<<endl;
                break;
            }
            r = Vectori[e-1];
            Vectori.push_back(r);
            break;
        }
    default:
        {
            cout<<"Optiune invalida!"<<endl;
        }
    }

    cout<<"Doriti sa continuati? 0/1"<<endl;
    cin>>run;
    cout<<"--------------------------"<<endl;
    }
    return 0;
}
