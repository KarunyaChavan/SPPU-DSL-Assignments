#include "iostream"
#include "cstring"
using namespace std;
const int maximum = 50;

class Stack{
    int top=-1;
    string expr;
    char st[maximum];
    char a;
    public:
        void push(char val){
            if(top==maximum-1){
                cout<<"Overflow"<<endl;
                return;
            }else{
                top++;
                st[top] = val;
            }
        }
        
        int pop(){
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
        
        int peek(){
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
        int isEmpty(){
            if(top==-1){
                return -1;
            }else{
                return 1;
            }
        }
        int isParaBal();
};

int Stack::isParaBal(){
	cout<<"Enter Expression = ";
	cin>>expr;
	for(int i=0;i<expr.length();i++){
		if(expr[i]=='{' || expr[i]=='[' || expr[i]=='('){
			push(expr[i]);
		}
		switch(expr[i]){
			case ')':
				a = pop();
				if(a!='('){
                    return -1;
				}
				break;

			case ']':
				a = pop();
				if(a!='['){
                    return -1;
				}
				break;

			case '}':
				a = pop();
				if(a!='{'){
                    return -1;
				}
				break;
		}
	}
    if(top!=-1){
        return -1;
    }else{
        return 1;
    }
}

int main(){
    Stack s;
    int r;
    r = s.isParaBal();
    if(r!=-1){
    	cout<<"Well Parenthesised"<<endl;
    }else{
    	cout<<"Bad Parenthesised"<<endl;
    }
    return 0;
}