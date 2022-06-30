//Method Override 
//overloading ile eşit değil 
//taban sınıfta özellikte , tekrar bir özellik çağırdığımızda veya   methodu , türetilmiş sınıfta tanımadığımız çağıracaktır
using namespace std;
//private olma durumunda hata verecektir 
#include <iostream>
class Base {
public : 
    int data[100];
    int size;
    int x;

    Base() :size(0),x(0){}
    
        void add(int value)
        {
            data[size] = value;
            size++;

        }
        void print()const {
            cout << "base" << endl;
            for (int i = 0; i < size; i++)
                cout << data[i] << " ";
       

        }
    

};

class derived :public Base{ //türetilmiş sınıf  belirtilmesi gereken 
    
public:
    float data[100];
    int size;
    derived() :size(0) {}

    void add(float value)
    {
        data[size] = value;
        size++;

    }
    void x() {
        cout << "hello" << endl;

     }
    void print()const { //hem tavan sınıftaki hem de kendi sınıf metodu çağırıyoruz . 
        //
        //tavan  sınıftaki özelliği çağırmak istersek kalıtım aldığımız print metodu çağır 
        Base::print();
        cout << endl;
        cout << "derived" << endl;
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
    }
    void addInt(int value) {
        Base::add(value);

    }

};
int main()
{
    Base b;
    b.add(35);
    b.add(5);
    b.add(3);
    b.print();
    cout << endl;

    derived d;
    d.addInt(5);
    d.addInt(8);
    d.add(3.5);
    d.add(5.1);
    d.add(3.2);
    d.print();
    d.x(); //metod şeklinde çağırılması gerek 
    //base sınıftan bir pointer oluşturuldu ve türetilmiş sınıftan oluturduğum nesneye at
    Base* ptr = &d;
    //dönüşüm işlemi 
    cout << endl;
    cout << ptr-> x;
    
    return 0;

 
}

