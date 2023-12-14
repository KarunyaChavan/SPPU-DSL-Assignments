#include <iostream>
#include "fstream"
using namespace std;
//Defining a class whose data is to be stored in the file,
class Shop{
        string item;
        float price;
    public:
        Shop(): item(""), price(0.0){}//2-Arguement Constructor
        void putdata(){ //Function for reading data
            cout<<"--------------------------------"<<endl;
            cout<<"Enter Item Name : ";
            cin>>item;
            cout<<"Enter Its Price : ";
            cin>>price;
        }
        void show(){ //Function for displaying data
            cout<<"================================"<<endl;
            cout<<"Item Name : "<<item<<endl;
            cout<<"Price     : "<<price<<endl;
        }
};
//Driver Code.
int main(){
    int n;
    fstream f; //Creating File Object.
    f.open("shop.txt",ios::out); //Opening File for Writing
    cout<<"_-_-_-_-_-_-_-_-_-_ WELCOME_-_-_-_-_-_-_-_-_-_ "<<endl;
    cout<<"Enter Number of Items Purchased = ";
    cin>>n;
    Shop s[n]; //Array of objects
    cout<<"Writing to the File"<<endl;
    for(int i=0;i<n;i++){
        s[i].putdata();
        f.write((char*) &s[i], sizeof(s[i])); //Writing Object Data to file.
    }
    f.close();//Closing the current file.
    f.open("shop.txt",ios::in);//Opening File for Reading
    cout<<"\nReading Content of File"<<endl;
    for(int i=0;i<n;i++){
        f.read((char*)&s[i], sizeof(s[i])); //Reading Data
        s[i].show();
    }
    f.close();
    return 0;
}