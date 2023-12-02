#include"iostream"
using namespace std;
#define MAX 5
string menu[5] = {"Cheese", "Veggie", "Pepperoni", "Margherita", "Hawaiian"};

class CircularQueue{
        int front = -1, rear = -1;
        int queue[MAX];
    public:
        void enqueue_order(int val){
            if(front==0 && rear==MAX-1){
                cout<<"Sorry, we are out of stock"<<endl;
                return;
            }
            else if(front==-1 && rear==-1){
                front = rear = 0;
                queue[rear] = val;
            }
            else{
                rear++;
                queue[rear] = val;
            }
        }

        int dequeue_order(){
            if(front==-1 && rear==-1){
                cout<<"All pizzas has been delivered"<<endl;
                return -1;
            }
            int val = queue[front];
            if(front==rear){
                front=rear=-1;
            }else{
                if(front==MAX-1){
                    front = 0;
                }else{
                    front++;
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
            if(front==-1 || rear==-1){
                cout<<"QUEUE IS EMPTY"<<endl;
            }else{
                if(front<rear){
                    for(int i=front;i<=rear;i++){
                            cout<<menu[queue[i]-1]<<" -> ";
                    }cout<<endl;
                }
                else if(front==rear){
                        cout<<menu[(queue[front])-1]<<endl;
                }
                else{
                    for(int i=front;i<MAX;i++)
                        cout<<menu[(queue[i])-1]<<" -> ";
                    for(int i=0;i<=rear;i++)
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
                cout<<menu[val-1]<<" Pizza - Order has been Delivered"<<endl;
                break;

            default:
                cout<<"Invalid Option"<<endl;
        }
    }while(opt!=6);
    return 0;
}