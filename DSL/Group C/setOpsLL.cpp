/*Second year Computer Engineering class set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream. Write C/C++ program to store two sets using linked list compute and display
Set of students who like either vanilla or butterscotch or both
Set of students who like both vanilla and butterscotch
Set of students who like only vanilla not butterscotch
Set of students who like only butterscotch not vanilla
Number of students who like neither vanilla nor butterscotch
*/
#include "iostream"
using namespace std;

template<class T>
class Node{
    public:
    T val;
    Node* next;
    Node(T data){
        val = data;
        next = NULL;
    }
};

template<class T>
class LinkedList{
    public:
    Node<T>* head;
    LinkedList(){
        head = NULL;
    }

    void insertAtTail(T val){
        Node<T>* new_node = new Node<T>(val);
        if (head==NULL){ //LinkedList is empty
            head = new_node;
            return;
        }

        Node<T>* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display(){
        Node<T>* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    int count(){
        Node<T>* temp = head;
        int c = 0;
        while(temp!=NULL){
            c++;
            temp = temp->next;
        }
        return c;
    }

    void makeItUnique(){
    Node<T>* current_node = head;
    while(current_node){
        while(current_node->next && current_node->val ==current_node->next->val){
            Node<T>* temp = current_node->next;
            current_node->next = current_node->next->next;
            free(temp);
        }
        current_node = current_node->next;
    }
}
};

template<class T>
Node<T>* intersection(Node<T> *head1, Node<T> *head2){
    LinkedList<T> intersected;
    Node<T>* ptr1 = head1;
    Node<T>* ptr2 = head2;
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            if(ptr1->val == ptr2->val){
                intersected.insertAtTail(ptr1->val);
            }
            ptr2 = ptr2->next;
        }
        ptr2 = head2;
        ptr1 = ptr1->next;
    }
    return intersected.head;
}

template<class T>
Node<T>* uni(Node<T> *head1, Node<T> *head2){
    LinkedList<T> united;
    Node<T>* ptr1 = head1;
    Node<T>* ptr2 = head2;
    int flag;
    while(ptr1!=NULL){
        united.insertAtTail(ptr1->val);
        ptr1 = ptr1->next;
    }
    while(ptr2!=NULL){
        flag = 0;
        ptr1 = head1;
        while(ptr1!=NULL){
            if(ptr1->val == ptr2->val){
                flag = 1;
            }
            ptr1 = ptr1->next;
        }
        if(flag == 0 ){
            united.insertAtTail(ptr2->val);
        }
        ptr2 = ptr2->next;
    }
    return united.head;
}

template<class T>
Node<T>* difference(Node<T> *head1, Node<T> *head2){
    LinkedList<T> diff;
    Node<T>* ptr1 = head1;
    Node<T>* ptr2 = head2;
    int flag;
    while(ptr1!=NULL){
        flag = 0;
        ptr2 = head2;
        while(ptr2!=NULL){
            if(ptr1->val == ptr2->val){
                flag = 1;
            }
            ptr2 = ptr2->next;
        }
        if(flag == 0 ){
            diff.insertAtTail(ptr1->val);
        }
        ptr1 = ptr1->next;
    }
    return diff.head;
}

int main(){
    int n,v,b;
    string name;
    LinkedList<string> total;
    LinkedList<string> vanilla;
    LinkedList<string> butterscotch;

    cout<<"Enter Total Number of Students = ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter Name of Student "<<i+1<<" = ";
        cin>>name;
        total.insertAtTail(name);
        name="";
    }

    cout<<"Enter Number of Students liking Vanilla = ";
    cin>>v;
    for(int i=0;i<v;i++){
        cout<<"Enter Name of Student "<<i+1<<" = ";
        cin>>name;
        vanilla.insertAtTail(name);
        name="";
    }

    cout<<"Enter Number of Students liking Butterscotch = ";
    cin>>b;
    for(int i=0;i<b;i++){
        cout<<"Enter Name of Student "<<i+1<<" = ";
        cin>>name;
        butterscotch.insertAtTail(name);
        name="";
    }

    cout<<"_-_-_-_-_-_-_-_-_ DATA _-_-_-_-_-_-_-_-_"<<endl;
    cout<<"Total Students = ";
    // total.makeItUnique();
    total.display();
    cout<<"\nStudents Liking Vanilla = ";
    vanilla.display();
    cout<<"\nStudents Liking Butterscotch = ";
    butterscotch.display();
    int num;
    LinkedList<string> l1;
    int opt;
    do{
        cout<<"\n1)Set of students who like both vanilla and butterscotch.\n2)Set of students who like either vanilla or butterscotch or not both.\n3)Number of students who like neither vanilla nor butterscotch.\n4)Exit.\n Choose Operation = ";
        cin>>opt;
        switch (opt)
        {
        case 1:
            l1.head = intersection(vanilla.head, butterscotch.head);
            l1.display();
            break;
        
        case 2:
            l1.head = difference(uni(vanilla.head, butterscotch.head),intersection(vanilla.head, butterscotch.head));
            l1.display();
            break;

        case 3:
            l1.head = difference(total.head, uni(vanilla.head, butterscotch.head));
            l1.display();
            num = l1.count();
            cout<<num<<endl;
            break;
        case 4:
            break;
        default:
            cout<<"Invalid Option"<<endl;
        }
    }while(opt!=4);
    return 0;
}