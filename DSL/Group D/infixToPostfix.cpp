/*Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions:
Operands and operator, both must be single character.
Input Postfix expression must be in a desired format.
Only '+', '-', '*' and '/ ' operators are expected.
*/

#include "iostream"
#include "string.h"
using namespace std;
#define max 100

class Stack{
    int top=-1;
    int st[max];
    public:
        //necessary
        void push(char val){
            if(top==max-1){
                cout<<"Overflow"<<endl;
                return;
            }else{
                top++;
                st[top] = val;
            }
        }
        //necessary
        char pop(){
            char val;
            if(top==-1){
                cout<<"Underflow"<<endl;
                return -1;
            }else{
                val = st[top];
                top--;
                return val;
            }
        }
        char peek(){
            if(top==-1){
                cout<<"Underflow"<<endl;
                return -1;
            }else{
                return st[top];
            }
        }
        int size(){
            return (top+1);
        }

        void display(){
            int i;
            if(top == -1)
                cout<<"STACK IS EMPTY"<<endl;
            else{
                for(i=top;i>=0;i--){
                    cout<<st[i]<<"  ";
            }cout<<endl;
        }
        }

        int getPrior(char c);//For getting precedence

        string infixToPostfix(string infix);//for conversion
};

//For getting precedence of character to be popped.
//Precedence :- ^ > * or / > - or + (P E MD AS)
int Stack::getPrior(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string Stack::infixToPostfix(string infix){
    string postfix; //Declaring a string to store postfix expression
    //Phase 1:- Iterating infix expression
    for(int i=0;i<infix.length();i++){
        //Case 1 - Checking for a operand by checking range lies between ASCII values or not
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z') || (infix[i]>='0' && infix[i]<='9')){
            //Adding operands directly to the postfix
            postfix += infix[i];
        }
        //Case 2 - Opening braces encountered
        else if(infix[i]=='('){
            //Add directly to the postfix
            push(infix[i]);
        }
        //Case 2.2 - Closing braces encountered
        else if(infix[i]==')'){
            //Pop unitl opening bracket is encountered
            while((top!=-1) && (st[top]!='(')){
                postfix += st[top]; //Add the element at top to the postfix
                pop();
            }
            //Discard opening bracket wihtout adding it to postfix
            pop();
        }
        //Case 3 - Operators
        else{
            while((top!=-1) && ((getPrior(st[top])) >= (getPrior(infix[i])))){ //infix[i] = incoming and st[top] = top
                postfix += st[top];
                pop();
            }
            push(infix[i]);
        }
    }
    //Phase 2: If stack is not empty
    while((top!=-1)){
        postfix += st[top];
        pop();
    }
    
    return postfix;
}

int main(){
    Stack s;//Creating Stack object so that we can use its getPrior and conversion function
    string exp, res; //String for infix and postfix expression
    int ch = 1;
    while(ch==1){
        cout<<"\nEnter Infix Expression = ";
        cin>>exp;
        res = s.infixToPostfix(exp);
        cout<<"Postfix Expression : "<<res<<endl;
        cout<<"Press 1 to try again : ";
        cin>>ch;
    }
    return 0;
}