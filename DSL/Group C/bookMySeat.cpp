#include "iostream"
using namespace std;

//Phase 1 :- Creation of nodes, (seats)
class seat{
    public:
        int num, status;
        string id;
        seat* prev;
        seat* next;
};

//Phase 2 : Linked List class creation.
class Theatre{
        seat* head;
        seat* tail;
    public:
        Theatre(){       //No arg constructor (always in public)
            head = NULL; //Initialising to NULL
            tail = NULL;
        }

        //Phase 2.1 : Creation of 70 seats (nodes)
        void createSeats(){
            //Phase 2.1.1 : Creating 1st seat only.
            int i =1;
            seat* temp = new seat;
            temp->num = 1;
            temp->id = "NULL";
            temp->status = 0;
            tail = head = temp; //As temp is our 1st seat

            //Phase 2.1.2 : Creation of remaining 69 seats, travsing from 2nd seat to 70th seat.
            for(int i=2;i<=70;i++){
                seat* s = new seat;
                s->num = i;
                s->id = "NULL";
                s->status = 0;
                //appending new node to list
                tail->next = s;
                s->prev = tail;
                tail = s;
                tail->next = head;
                head->prev = tail;
            }
        }

        //Phase 2.2 : Displaying Seats Status
        void display(){
            //Phase 2.2.1 :- Displaying Screen and initialising row_count r and seats count , count.
            int r = 1, count = 0;
            seat* temp = head;
            cout<<"___________________________________________________________________________________"<<endl;
            cout<<"                                     Screen This Way                               "<<endl;
            cout<<"___________________________________________________________________________________\n"<<endl;

            //Phase 2.2.2 : Displaying Real Time seats status
            do{
                //Case 1 :  If seat number lies between 1 to 10.
                if(temp->num/10==0){ //Every number less 10 will have quotient 0.something when division is performed.
                    cout<<"S0"<<temp->num<<" : ";
                    //For n<10 we are sticking 0 to S in order to maintain uniformity.
                }
                else{
                    //For every double digits. (n>10)
                    cout<<"S"<<temp->num<<" : ";
                }
                
                //Case 2 : Displaying whether the seat is avail or not
                if(temp->status==0){ //status is 0 when seat is empty , else 1.
                    cout<<"|   |  ";
                }else{
                    cout<<"| \3 |  ";
                }
                if(temp->num==14 || temp->num==35){
                    cout<<"\n\n-----------------------------------------------------------------------------------------"<<endl;
                }
                count++; //incrementing seats count
                if(count%7==0) //As we have 7 seats in each row, then incrementing row count by 1.
                {
                    cout<<endl;
                    r++;
                }
                temp=temp->next;
            }while(temp!=head);
        }

        //Phase 2.3 : Defining a book() function
        void book(int n, string v){
            seat* temp = new seat;
            temp = head;
            while(temp->num!=n){ //Traversing until nth arg
                temp = temp->next;
            }
            if(temp->status==1){    //if seat is already booked
                cout<<"Already Booked, choose another. "<<endl;
                return;
            }
            else{
                temp->status = 1; 
                temp->id = v;
                cout<<"Seat "<<temp->num<<" booked sucessfully"<<endl;
            }
        }

        void cancel(int n, string v){
            seat* temp = new seat;
            temp = head;
            while(temp->num!=n){
                temp = temp -> next;
            }
            if(temp->id == v){
            if(temp->status==0){
                cout<<"Seat not booked yet"<<endl;
            }
            else{
                temp->status = 0;
                cout<<"Seat Cancelled."<<endl;
            }
            }
            else{
                cout<<"Wrong User ID"<<endl;
            }
        }
};

int main(){
    Theatre cinepolis;
    cinepolis.createSeats();
    cinepolis.display();
    int opt,n;
    string v;
    do{
        cout<<"\n\5_-_-_-_-_-_-_-_-_-_-_-_ CINEPOLIS _-_-_-_-_-_-_-_-_-_-_-_\5\n1)Book Seat.\n2)Cancel Seat.\n3)Display Current Status.\n4)EXIT.\n : ";
        cin>>opt;
        switch(opt){
            case 1:
                cout<<"Enter Seat Number : ";
                cin>>n;
                cout<<"Enter ID : ";
                cin>>v;
                if(n<1||n>70)
                {
                    cout<<"No such seat number\n";
                    break;
                }
                cinepolis.book(n,v);
                break;

            case 2:
                cout<<"Enter Seat Number : ";
                cin>>n;
                cout<<"Enter ID : ";
                cin>>v;
                if(n<1||n>70)
                {
                    cout<<"No such seat number\n";
                    break;
                }
                cinepolis.cancel(n,v);
                break;

            case 3:
                cinepolis.display();
                break;
        }
    }while(opt!=4);
    return 0;
}