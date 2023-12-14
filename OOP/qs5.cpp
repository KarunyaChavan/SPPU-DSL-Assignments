#include <iostream>
#include<stdlib.h>
using namespace std;
class node
{ 
	public:
		node* next;
		node* prev;
		int lot;
		string id;
		int status;
};

class ParkingLot
{
	public:
		node* head,* tail ,* temp;
	ParkingLot()
	{
		head=NULL;
	}
	void create_list();
	void display();
	void book();
	void cancel();
};

void ParkingLot::create_list()
{
	int i=1;
	temp=new node;
	temp->lot=1;
	temp->status=0;
	temp->id="null";
	tail=head=temp;
	for(int i=2;i<=70;i++)
	{
		node *p;
		p= new node;
		p->lot=i;
		p->status=0;
		p->id="null";
		tail->next=p;
		p->prev=tail;
		tail=p;
		tail->next=head;
		head->prev=tail;
	}
}

void ParkingLot::display()
{
	int r=1;
	node* temp;
	temp=head;
	int count=0;
	cout<<"\n------------------------------------------------------------------------------------\n";
	cout<<" Gate this Way \n";
	cout<<"------------------------------------------------------------------------------------\n";
	while(temp->next!=head)
	{
		if(temp->lot/10==0)
			cout<<"S0"<<temp->lot<<" :";
		else
			cout<<"S"<<temp->lot<<" :";

		if(temp->status==0)
			cout<<"|___| ";
		else
			cout<<"|_B_| ";
		count++;
		if(count%7==0)
		{
			cout<<endl;
			r++;
		}
		temp=temp->next;
	}
	cout<<"S"<<temp->lot<<" :";
	if(temp->status==0)
		cout<<"|___| ";
	else
		cout<<"|_B_| ";
}

void ParkingLot::book()
{ 
	int x;
	string y;
	label:
	cout<<"\n\n\nEnter lot number to be booked\n";
	cin>>x;
	cout<<"Enter your ID number\n";
	cin>>y;
	if(x<1||x>70)
	{
		cout<<"Enter correct lot number to book (1-70)\n";
		goto label;
	}
	node *temp;
	temp=new node;
	temp=head;
	while(temp->lot!=x)
	{
		temp=temp->next;
	}

	if(temp->status==1)
		cout<<"Lot already booked!\n";
	else
	{
		temp->status=1;
		temp->id=y;
		cout<<"Lot "<<x<<" booked!\n";
	}
}

void ParkingLot::cancel()
{
	int x;
	string y;
    label1:
	cout<<"Enter lot number to cancel booking\n";
	cin>>x;
	cout<<"Enter you ID\n";
	cin>>y;
	if(x<1||x>70)
	{
		cout<<"Enter correct seat number to cancel (1-70)\n";
		goto label1;
	}
	node *temp;
	temp=new node;
	temp=head;
	while(temp->lot!=x)
	{
		temp=temp->next;
	}
	if(temp->status==0)
	{
		cout<<"Lot not booked yet!!\n";
	}
	else
	{
		if(temp->id==y)
		{
			temp->status=0;
			cout<<"Lot Cancelled!\n";
		}
		else
			cout<<"Wrong User ID !!! Lot cannot be cancelled!!!\n";
	}
}

int main()
{ 
	ParkingLot obj;
	obj.create_list();
	int ch;
	char c='y';
	while(c=='y')
	{ 
		cout<<"\n*********************************************\n";
		cout<<" CITY PLAZA PARKING LOT\n";
		cout<<"*********************************************\n";
		cout<<"\nEnter Choice\n1.Current Lot Status\n2.Book Lot \n3.Cancel Lot\n";
		cin>>ch;
		switch(ch)
		{
			case 1:obj.display();
			break;
			case 2: obj.book();
			break;
			case 3: obj.cancel();
			break;
			default: cout<<"Wrong choice input\n";
		}
		cout<<"\nDo you want to perform any other operation : (y/n) \n";
		cin>>c;
	}
	return 0;
}
