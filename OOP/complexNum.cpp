#include <iostream>
using namespace std;
//----------------------------------------------------------------------------------------------------------------//
class Complex{ //Class Declaration
        float a,b; //private data memebers --> a = real part & b = img part
    public:
        Complex(): a(0), b(0) {} //Default Constructor - no args passed

        Complex operator + (Complex C1){
            Complex temp;
            temp.a = C1.a + a;
            temp.b = C1.b + b;
            return temp;
        }
        Complex operator - (Complex C2){ //Overloading for Subtraction
            Complex temp;
            temp.a = a - C2.a;
            temp.b = b - C2.b;
            return temp;
        }
        Complex operator / (Complex C2){ //Overloading for Divison
            Complex temp;
            temp.a = (a*C2.a + b*C2.b)/(C2.a*C2.a + C2.b*C2.b);
            temp.b = (b*C2.a - a*C2.b)/(C2.a*C2.a + C2.b*C2.b);
            return temp;
        }
        Complex operator * (Complex C2){ //Overloading for Multiplication
            Complex temp;
            temp.a = ((a*C2.a)-(b*C2.b));
            temp.b = (b*C2.a + a*C2.b);
            return temp;
        }
        //Declaration of friend functions 
        friend istream &operator >> (istream &in, Complex &c); //Non-member Function, so we even need object of     class complex
        friend ostream &operator << (ostream &out, Complex const c);
        //friend returnType &operator [symbol] (returnType obj1, class obj2);
};
//----------------------------------------------------------------------------------------------------------------//
//Defining friend functions
istream &operator >> (istream &in, Complex &c){
        cout<<"Enter Real Part : ";
        in>>c.a;    //cin>>c.a
        cout<<"Enter Imaginary Part : ";
        in>>c.b;
        return in;
    }

ostream &operator << (ostream &out, Complex const c){
        if(c.b>=0)
            out<<c.a<<" + i"<<c.b<<endl;
        else 
            out<<c.a<<" - i"<<(-c.b)<<endl;
        return out;
    }
//----------------------------------------------------------------------------------------------------------------//
//Driver Code
int main(){
    int opt;
    Complex C1,C2,Sum,Diff,Div,Mul; //Instansiating Objects
    cout<<"Enter First Number "<<endl;
    cin>>C1; //Due to operator overloading now it is possible for us to read the complex objects such like as easy as predefined data types like int , char etc
    cout<<"\nEnter Second Number "<<endl;
    cin>>C2;
    cout<<"\nYou have Entered following two complex numbers :"<<endl;
    cout<<C1<<endl;
    cout<<C2<<endl;   
    do{
    cout<<"\5_-_-_-_-_-_-_-_-_-_-_ MENU _-_-_-_-_-_-_-_-_-_-_ \5\n1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n5)EXIT\n : ";
    cin>>opt;
    switch (opt){
        case 1:
            Sum = C1 + C2; //C1 + C2 will return temp then we have Sum = temp
            cout<<Sum;
            break;
        case 2:
            Diff = C1 - C2;
            cout<<Diff;
            break;
        case 3:
            Mul = C1*C2;
            cout<<Mul;
            break;
        case 4:
            Div = C1/C2;
            cout<<Div;
            break;
        default:
            cout<<"\nKindly choose among the given options only."<<endl;
    }
    }while(opt!=5);
    return 0;
}