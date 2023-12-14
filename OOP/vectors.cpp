#include <iostream>   
#include <algorithm>    
#include <vector>    
using namespace std;

class Item { //class created for writing into vector for storing purpose
      public:   
        char name[10];
        int quantity;
        int cost;
        int code;

        //Overloading comparison operators for searching & sorting purposes
        bool operator==(const Item& i1){
        if(code==i1.code)
        	return 1;
        return 0;
    }

    bool operator < (const Item& i1){
        if(cost<i1.cost) 
        	return 1;
        return 0;
    }
};

vector<Item> o1; //Creating vector of type Item. / Vector of Objects of type Item.

bool compare(const Item &i1, const Item &i2)
{
   return i1.cost < i2.cost;
}

void insert() //Creating function for reading values from user
{
    Item i1;
    cout<<"Enter Item Name:";
    cin>>i1.name;
    cout<<"Enter Item Quantity:";
    cin>>i1.quantity;
    cout<<"Enter Item Cost:";
    cin>>i1.cost;
    cout<<"Enter Item Code:";
    cin>>i1.code;
    o1.push_back(i1); //appending
}

void print(Item &i1) //Formatting output for Item object
{
     cout<<"\n";
     cout<<"Item Name       :"<<i1.name<<endl;
     cout<<"Item Quantity   :"<<i1.quantity<<endl;
     cout<<"Item Cost       :"<<i1.cost<<endl;
     cout<<"Item Code       :"<<i1.code<<endl;
}

void display() //Applying above defined print function to each of the element in vector
{
    for_each(o1.begin(),o1.end(),print);
}

void search()
{
    vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter Item Code to search:";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1); //Traverses the vector until key is found and returns as soon key is found
    if(p==o1.end()) //When key ain't present in vector, iterator will traverse whole and reach to end
    {
         cout<<"\nNot found.";
    }
    else
    {
         cout<<"\nFound.";
    }
}

void dlt()
{
     vector<Item>::iterator p;
    Item i1;
    cout<<"\nEnter Item Code to delete:";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);
    if(p==o1.end())
    {
         cout<<"\nNot found.";
    }
    else
    {
         o1.erase(p);
         cout<<"\nDeleted.";
    }
}

int main()
{
    int ch;
      do
    {  
        cout<<"\n***** Menu *****";
        cout<<"\n1.Insert";
        cout<<"\n2.Display";
        cout<<"\n3.Search";
        cout<<"\n4.Sort";
        cout<<"\n5.Delete";
        cout<<"\n6.Exit";
        cout<<"\nEnter your Choice : ";
        cin>>ch;
		cout<<endl;
        switch(ch)
        {
               case 1:
                          insert();
                          break;
                    
               case 2:
                          display();
                          break;
                   
               case 3:
                         search();
                         break;
                              
               case 4:
                        sort(o1.begin(),o1.end(),compare);
                        cout<<"\n\n Sorted on Cost";
                        display();
                        break;
                  
               case 5:
                       dlt();
                        break;
                     
               case 6:
                        exit(0);
        }
   
    }while(ch!=7);

      return 0;
}
