#include<bits/stdc++.h>
using namespace std;

int bill = 0;

class Product
{
    string name;
    long barcode;
    public:
        Product()
        {
            name = " ";
            barcode = 0;

}

Product(string n, long bc)
{
    name = n;
    barcode = bc;
    
}


void setName(string n)
{
    name = n;

}

string getName()
{
    return name;

}
void setBarcode(long bc)
{
    barcode = bc;
}
long getBarcode()
{
    return barcode;
}

virtual void scanner()
{
    cout << "Please Enter The Product Name: " << endl;
    cin >> name;
    
    cout << " Please Enter The Barcode: " << endl;
    cin >> barcode;
}

virtual void printer()
{
    cout << "\nName : "<< name << "\nBarcode : "<< barcode;
}

};

class PrepackedFood : public Product
{
    double unitPrice;
    public:
        PrepackedFood()
{
    unitPrice = 0;
}

PrepackedFood(string n, long bc, double up) : Product(n, bc)
{
    unitPrice = up;

}

void setUnitPrice(double up)
{
    unitPrice = up;

}

double getUnitPrice()
{
    return unitPrice;
}

void scanner()
{
    string n;
    int bc;
    double up;
    cout<<"Name : "; cin >> n;
    cout<<"\nBarcode : "; cin >> bc;
    cout<<"Price per piece : "; cin >> up;
    setName(n);
    setBarcode(bc);
    setUnitPrice(up);
    bill += up;
}

void printer()
{
    cout<< "\nName : "<<getName()<< "\nBarcode : "
    << getBarcode() 
    << "\nPrice per piece : "<<unitPrice<<endl;
}

};

class FreshFood : public Product
{
    double weight;
    double pricePerKilo;
    public:
        FreshFood()
{
    weight = 0;
    pricePerKilo = 0;
}

FreshFood(string n, long bc, double w, double ppk) : Product(n, bc)
{
    weight = w;
    pricePerKilo = ppk;
}

void setWeight(double w)
{
    weight = w;
}

void setPricePerKilo(double ppk)
{
    pricePerKilo = ppk;
}

double getWeight()
{
    return weight;
}

double getPricePerKilo()
{
    return pricePerKilo;
}

void scanner()
{
    string n;
    int bc;
    double w;
    double ppk;
    cout<<"Name : "; cin >> n;
    cout<<"\nBarcode : "; cin >> bc;
    cout<<"Weight(lbs) : "; cin >> w;
    cout<<"Price/lbs : "; cin >> ppk;
    setName(n);
    setBarcode(bc);
    setWeight(w);
    setPricePerKilo(ppk);
    bill += (w*ppk);
}

void printer()
{
    cout<< "\nName : "<<getName()<< "\nBarcode : "<<getBarcode() 
    << "\nWeight(lbs) : "<< weight
    <<"\nPrice/lbs : "<<pricePerKilo
    <<"\nTotal : "<<weight*pricePerKilo<<endl;
}

};

void show()
{
    cout<<"Next Option?" << endl;
    cout << endl;
    cout << "0 = None, more item \n1 = Fresh food item \n2 = Prepacked item?" << endl;
}
void record()
{
    Product *ptr[100];
    int n, count = 0;
    show();
    FreshFood ff[100];
    PrepackedFood ppk[100];
    int i = 0, j = 0;
    cin >> n;
    while(n != 0)
{
switch(n)
{
    case 1 : 
    {
        ff[i].scanner();
        ptr[count++] = &ff[i];
        i++;
        break;
}
case 2 : 
{
    ppk[j].scanner();
    ptr[count++] = &ppk[j];
    j++;
    break;
}

default :
cout<<"Please enter a valid choice!"<<endl;
}
show();
cin >> n;
}
double total;
for(int i = 0; i < count; i++)
{
cout<<"••••••••••••••••••"<<endl;
ptr[i]->printer();
}
cout << endl;
cout<<"••••••••••••••••••"<<endl;
cout<<"Total Price : "<< bill << endl;
}

int main()
{
    cout<<"\nCheckout Here: "<< endl;
    char c;
    while(true)
{

cin.sync();
cout<<"\nAnother customer (y/n)?";
cin>>c;

if(c == 'y' || c =='Y')
record();
else
break;
}
return 0;
}
