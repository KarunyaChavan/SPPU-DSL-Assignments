/*In any language program mostly syntax error occurs due to unbalancing delimiter such as (), {}, []. Write C++ program using stack to check whether given expression is well parenthesized or not.*/

#include "iostream"
#include "cstring"
using namespace std;
const int maximum = 50;

class Stack{
    int top=-1;
    string expr;
    char st[maximum];//Stack Array
    char a;//Required for storing element at top
    public:

        void push(char val){
            if(top==maximum-1){
                cout<<"Overflow"<<endl;
                return;
            }else{
                top++;
                st[top] = val;
                return;
            }
        }
        
        char pop(){
            char val;
            if(top==-1){
                cout<<"Underflow"<<endl;
                return -1;
            }else{
                val = st[top];//stroing element at top of stack 
                top--;//decrement 
                return val;
            }
        }
        
        int peek(){
            if(top==-1){
                cout<<"Underflow"<<endl;
                return -1;
            }else{
                return (st[top]);
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
	cout<<"Enter Expression = ";//Reading expression
	cin>>expr;

	for(int i=0;i<expr.length();i++){//Traversing Expression 
		if(expr[i]=='{' || expr[i]=='[' || expr[i]=='('){//If Opening Bracket Found
			push(expr[i]); //Inserting them into stack
		}
        //Checking Proper Matching for closing bracket
		switch(expr[i]){
			case ')':
				a = pop();
				if(a!='('){
                    return -1;//returning false and ending the function
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
    //Sometimes if not well-parenthesised entered. then some bracket(opening) may remain in stack only

    if(top!=-1){//if stack ain't empty
        return -1;
    }
    else{
        return 1;
    }
}

int main(){
    Stack s;//creating object of class stack to access member funcs
    int r;
    r = s.isParaBal();

    if(r==1){
        cout<<"Well Parenthesised"<<endl;
    }
    else{
        cout<<"Bad Parenthesised"<<endl;
    }

    return 0;
}