#include <iostream>
using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------//
//Defining a class
class Length{
        int l; //private data member
    public:
        Length(): l(0){} //Default Constructor
        
        void set(){ //Method for reading number
            cout<<"Enter Desired Number = ";
            cin>>l;
        }
        Length operator - (){ //Overloading '-' operator
            Length temp;
            temp.l = -l;
            return temp;
        }
        Length operator ++ (){//Overloading '++' operator
            Length temp;
            temp.l = ++l;
            return temp;
        }

        Length operator --(){ //Overloading '--' operator
            Length temp;
            temp.l = --l;
            return temp;
        }

        void show(){
            cout<<l<<endl;
        }
        void operator ! (){
            int temp = l;
            l = !l;
            if(l){
                cout<<"Number is zero"<<endl;
            }else{
                cout<<"Number is non-zero"<<endl;
            }
            l = temp;
        }
};
//--------------------------------------------------------------------------------------------------------------------------------------------//
//Driver Code
int main(){
    Length L; //Instaniating a object 
    L.set();
    !L;
    char ch='y';
    int opt;
    do{
        cout<<"UNARY OPERATORS\n1)Minus(-)\n2)Increment(++)\n3)Decrement(--)\nEnter Your Choice = ";
        cin>>opt;
        switch(opt){
            case 1:
                cout<<"Value of L after applying - operator"<<endl;
                (-L).show();
                break;
            case 2:
                cout<<"Value of L after applying ++ operator"<<endl;
                
                (++L).show();
                break;
            case 3:
                cout<<"Value of L after applying -- operator"<<endl;
                (--L).show();
                break;
            default:
                cout<<"Invalid Option"<<endl;
        }
        cout<<"Press y to continue, else any other key = ";
        cin>>ch;
    }while(ch=='y');
}