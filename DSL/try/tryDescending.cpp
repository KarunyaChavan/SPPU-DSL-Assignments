/*Write program to implement a priority queue in C++ using an inorder list to store the items in the queue. Create a class that includes the data items (which should be template) and the priority (which should be int). The inorder list should contain these objects, with operator <= overloaded so that the items with highest priority appear at the start of the list (which will make it relatively easy to retrieve the highest item.)*/

#include"iostream"
using namespace std;
#define MAX 50

template<class T>
class Data{ //will be used as data type of queue
	public:
		T val;
		int priority;
		bool operator >= (int v){
			if(v<=priority){
				return true;
			}
			else return false;
		}
};

template<class T>
class prQueue{
		int front=-1,rear=-1;
		Data<T> queue[MAX];
	public:
		void enqueue(T d, int priority){
			Data<T> D;
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
					if(priority >= ((queue[i]).priority)){
						queue[i+1] = queue[i];
					}
                    else break;
                }
				queue[i+1] = D;
				rear++;
				return;
			}
		}
		
		Data<T> dequeue(){
			if(front==-1 && rear==-1){
				cout<<"UNDERFLOW"<<endl;
			}
			else{
				Data<T> gar;
				if(front==rear){
					gar = queue[front];
					front = rear = -1;
					return gar;;
				}
				else{
					gar = queue[front];
					front++;
					return gar;
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
	prQueue<char> p;
    int opt,pr;
	char val;
    Data<char> G;
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
                G = p.dequeue();
                cout<<G.val<<" with priority "<<G.priority<<" has been dequeued "<<endl;
                break;

            case 3:
                cout<<"ELEMENT ----------- PRIORITY "<<endl;
                p.display();
                break;

            case 4:
                p.peek();
                break;

			case 5:
				break;

            default:
                cout<<"Invalid Option"<<endl;
        }
    }while(opt!=5);
	
	return 0;
}