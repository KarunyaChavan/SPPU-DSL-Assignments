#include "iostream"
#include "string.h"
using namespace std;
#define max 100

class Stack{
    int top=-1;
    int st[max];
    public:
        void push(char val){
            if(top==max-1){
                cout<<"Overflow"<<endl;
                return;
            }else{
                top++;
                st[top] = val;
            }
        }
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

        int getPrior(char c);

        string infixToPostfix(string infix);
};

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
    string postfix;
    for(int i=0;i<infix.length();i++){
        //Case 1 - Checking for a operand
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z') || (infix[i]>='0' && infix[i]<='9')){
            postfix += infix[i];
        }
        //Case 2 - Opening braces encountered
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while((top!=-1) && (st[top]!='(')){
                postfix += st[top];
                pop();
            }
            pop();
        }
        //Case 3 - Operators
        else{
            while((top!=-1) && ((getPrior(st[top])) >= (getPrior(infix[i])))){
                postfix += st[top];
                pop();
            }
            push(infix[i]);
        }
    }
    while((top!=-1)){
        postfix += st[top];
        pop();
    }
    
    return postfix;
}

int main(){
    Stack s;
    string exp, res;
    cout<<"Enter Infix Expression = ";
    cin>>exp;
    res = s.infixToPostfix(exp);
    cout<<res<<endl;
    return 0;
}