/*Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed cannot be cancelled. Write C++ program to simulate the system using circular queue using array. */

#include"iostream"
using namespace std;
#define MAX 3
string menu[5] = {"Cheese", "Veggie", "Pepperoni", "Margherita", "Hawaiian"};

class CircularQueue{
        int front = -1, rear = -1;
        int queue[MAX];
    public:

        void enqueue_order(int val){
            if((front==0 && rear==MAX-1)||(rear==front-1)){
                cout<<"Sorry, we are out of stock"<<endl;//Overflow
                return;
            }
            else if(front==-1 && rear==-1){//Empty Queue Condition
                front = rear = 0;
                queue[rear] = val;
            }
            else if(front!=0 && rear==MAX-1){//Circular queue condition
                    rear = 0;//Joiining rear to the start
                    queue[rear] = val;
                }
            else{//Normal Condition
                    rear++;
                    queue[rear] = val;
                }
        }

        int dequeue_order(){
            int val;
            if(front==-1 && rear==-1){//Underflow
                cout<<"All pizzas has been delivered"<<endl;//Underflow
                return -1;
            }
            val = queue[front];

            if(front==rear){//Only one element was present in the queue
                front=rear=-1;
            }
            else{
                if(front==MAX-1){//Circular Condition
                    front = 0;//Joining front to the start
                }
                else{
                    front++;//Normal (In-Between) Condition
                }
            }
            return val;
        }

        int peek(){
            if(front==-1 && rear==-1){
                cout<<"Nothing to Deliver"<<endl;
                return -1;
            }
            else{
                return queue[front];
            }
        }

        void display(){
            if(front==-1 && rear==-1){
                cout<<"QUEUE IS EMPTY"<<endl;
            }
            else{
                if(front<rear){//Normal Condition - Linear Queue Wali
                    for(int i=front;i<=rear;i++){
                            cout<<menu[queue[i]-1]<<" -> ";
                    }cout<<endl;
                }

                else if(front==rear){//Single element prsence only
                        cout<<menu[(queue[front])-1]<<endl;
                }

                else{//front > rear
                    for(int i=front;i<MAX;i++)//from front to max - 1 //Part P1
                        cout<<menu[(queue[i])-1]<<" -> ";

                    for(int i=0;i<=rear;i++)//from 0 to rear //Part P2
                        cout<<menu[(queue[i])-1]<<" -> ";
                }
                cout<<endl;
            }
        }
};

int main(){
    CircularQueue kitchen;
    int opt,id,val;
    string menu[5] = {"Cheese", "Veggie", "Pepperoni", "Margherita", "Hawaiian"};
    do{
        cout<<"\5_-_-_-_-_-_-_-_-_-_-_-_ STARDOLLARS _-_-_-_-_-_-_-_-_-_-_-_\5\n1)Accept an Order.\n2)Display Order Queue.\n3)View Next Order.\n4)Deliver an Order.\n\5)Exit\n : ";
        cin>>opt;
        switch(opt){
            case 1:
                cout<<"\4_-_-_-_-_-_-_-_-_-_-_-_ MENU _-_-_-_-_-_-_-_-_-_-_-_\4\nPlease enter id refering below\n1)Cheese Pizza.\n2)Veggie Pizza.\n3)Pepperoni Pizza.\n4)Margherita Pizza.\n5)Hawaiian Pizza.\n : ";
                cin>>id;
                kitchen.enqueue_order(id);
                break;

            case 2:
                cout<<"Current Status : "<<endl;
                kitchen.display();
                break;

            case 3:
                val = kitchen.peek();
                cout<<menu[val-1]<<" is the next one in the queue"<<endl;
                break;

            case 4:
                val = kitchen.dequeue_order();
                if(val!=-1)
                    cout<<menu[val-1]<<" Pizza - Order has been Delivered"<<endl;
                break;

            case 5:
                break;

            default:
                cout<<"Invalid Option"<<endl;
        }
    }while(opt!=5);
    return 0;
}