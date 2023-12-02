#include"iostream"
using namespace std;
#define MAX 50

class prQueue{
		int front=-1,rear=-1;
		int data[MAX];
		int pr[MAX];
	public:

		void enqueue(int d, int priority){
			if(rear==MAX-1){
				cout<<"OVERFLOW"<<endl;
				return;
			}
			else if(front==-1 && rear==-1){
				front = rear = 0;
				data[rear] = d;
				pr[rear] = priority;
				return;
			}
			else{
                int i =rear;
				for(i=rear;i>=front;i--){
					if(priority<=pr[i]){
						data[i+1] = data[i];
						pr[i+1] = pr[i];
					}
                    else break;
                }
				data[i+1] = d;
				pr[i+1] = priority;
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
					x = data[front];
					y = pr[front];
					front = rear = -1;
					return x,y;
				}
				else{
					x = data[front];
					y = pr[front];
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
                cout<<data[front]<<" with priority "<<pr[front]<<" is next one "<<endl;
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
					cout<<"  "<<data[i]<<"                    "<<pr[i]<<endl;
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