/*Queues are frequently used in computer programming and a typical example is the   creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue. */

#include"iostream"
using namespace std;
#define MAX 4

class Queue{
        string queue[MAX];
        int front,rear;
    public:
        Queue():front(-1),rear(-1){}

        void enqueue(string val){
            if(rear==MAX-1){//Full Queue condition
                cout<<"OVERFLOW"<<endl;
                return;
            }
            else if(front==-1 && rear==-1){ //Empty Queue condition
                front=rear=0;
            }
            else{
                rear++;
            }
            queue[rear] = val;
            return;
        }

        string dequeue(){
            if(front==-1 || (front>rear)){
                cout<<"UNDERFLOW"<<endl;
                return "-1";
            }else{
                string val = queue[front];//storing the element at front
                front++;

                if(front>rear){//Single element condition
                    front = rear = -1;
                }

                return val;
            }
        }

        string peek(){
            if(front==-1 || front>rear){
                cout<<"Queue is Empty";
                return "-1";
            }else{
                return (queue[front]);
            }
        }

        void display(){
            if(front==-1 || front>rear){
                cout<<"Queue is Empty"<<endl;
            }else{
                for(int i=front;i<=rear;i++){
                    if(i!=rear)
                        cout<<queue[i]<<" -> ";
                        
                    else cout<<queue[i]<<endl;
                }
            }
        }
};

int main(){
    Queue q;
    int opt;
    string job;
    do{
        cout<<"_-_-_-_-_-_-_-_-_-_-_ WELCOME TO MENU _-_-_-_-_-_-_-_-_-_-_"<<endl;
        cout<<"1)Add Job.\n2)Delete Job.\n3)Display Job Queue.\n4)View Next Job.\n5)Exit.\n : ";
        cin>>opt;
        switch (opt)
        {
        case 1:
            cout<<"Enter Desired Job : ";
            cin.ignore();
            getline(cin,job);
            q.enqueue(job);
            break;

        case 2:
            job = q.dequeue();
            cout<<job<<" Dequeued from queue and Performed"<<endl;
            break;

        case 3:
            cout<<"-_-_-_-_-_-_-_-_-_-_JOB QUEUE-_-_-_-_-_-_-_-_-_-_"<<endl;    
            q.display();
            break;
        
        case 4:
            job = q.peek();
            cout<<job<<" is upcoming job"<<endl;
            break;

        case 5:
            break;
            
        default:
            cout<<"Invalid Option"<<endl;
            break;
        }
    }while(opt!=5);
    return 0;
}