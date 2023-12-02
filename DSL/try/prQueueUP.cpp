#include"iostream"
using namespace std;
#define MAX 50

class Data{
	public:
		int val;
		int priority;
		bool operator <= (int v){
			if(v<=priority){
				return true;
			}
			else return false;
		}
};

class prQueue{
		int front=-1,rear=-1;
		Data queue[MAX];
	public:
		void enqueue(int d, int priority){
			Data D;
			if(rear==MAX-1){
				cout<<"OVERFLOW"<<endl;
				return;
			}
			else if(front==-1 && rear==-1){
				front = rear = 0;
				D.val = d;
				D.priority = priority;
				queue[rear] = D;
				return;
			}
			else{
				D.val = d;
				D.priority = priority;
                int i =rear;
				for(i=rear;i>=front;i--){
					if(priority <= ((queue[i]).priority)){
						queue[i+1] = queue[i];
					}
                    else break;
                }
				queue[i+1] = D;
				rear++;
				return;
			}
		}
		
		int dequeue(){
			if(front==-1 && rear==-1){
				cout<<"UNDERFLOW"<<endl;
				return -1;
			}
			else{
				int x,y;
				if(front==rear){
					x = (queue[front]).val;
					y = (queue[front]).priority;
					front = rear = -1;
					return x,y;
				}
				else{
					x = (queue[front]).val;
					y = (queue[front]).priority;
					front++;
					return x,y;
				}
			}
		}	
			
        void peek(){
            if(front==-1 && rear==-1){
				cout<<"Queue is Empty"<<endl;
				return;
			}
            else{
                cout<<(queue[front]).val<<" with priority "<<(queue[front]).priority<<" is next one "<<endl;
                return; 
            }
        }

		void display(){
			if(front==-1 && rear==-1){
				cout<<"Queue is Empty"<<endl;
				return;
			}
			else{
				for(int i=front;i<=rear;i++){
					cout<<"  "<<(queue[i]).val<<"                    "<<(queue[i]).priority<<endl;
				}
			}
		}
};

int main(){
	prQueue p;
    int opt,val,pr;
    
    do{
        cout<<"\5_-_-_-_-_-_-_-_-_-_ MENU _-_-_-_-_-_-_-_-_-_\5\n1)Enqueue.\n2)Dequeue.\n3)Display.\n4)Peek.\n5)EXIT.\n : ";
        cin>>opt;
        switch(opt){
            case 1:
                cout<<"Enter Data Value : ";
                cin>>val;
                cout<<"Enter its Priority : ";
                cin>>pr;
                p.enqueue(val, pr);
                break;

            case 2:
                val,pr = p.dequeue();
                cout<<val<<" with priority "<<pr<<" has been dequeued "<<endl;
                break;

            case 3:
                cout<<"ELEMENT ----------- PRIORITY "<<endl;
                p.display();
                break;

            case 4:
                p.peek();
                break;

            default:
                cout<<"Invalid Option"<<endl;
        }
    }while(opt!=5);
	
	return 0;
}