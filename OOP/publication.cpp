//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ ASSIGNMENT III _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
 
#include "iostream"
using namespace std;
class publication{//Abstract Class
    public:
        string title;
        float price;
        publication(): title(""), price(0.0){}
        virtual int Set(){ //Function for Reading Title and Price
            int ch=1;
            while(ch==1){
            try{ //Exception Handling
                cout<<"Enter Title : ";
                cin.ignore();
                getline(cin, title);
                if(title==" "){
                    throw title;
                }
                cout<<"Enter Price : ";
                cin>>price;
                if(price<=0.0){
                    throw price;
                }
                ch=2;
            }
            catch(string t){
                cout<<"Invlaid Title, Press 1 to try again or another key to exit\n = ";
                cin>>ch;
                if(ch!=1){
                    return -1;
                }
            }
            catch(float p){
                price= 0.0; //reseting price to zero
                cout<<"Invlaid Price, Press 1 to try again or another key to exit\n = ";
                cin>>ch;
                if(ch!=1){
                    return -1;
            }
            }       
            }
        }
        virtual void Get() = 0;//pure virtual function
};
//Subclass 1
class book: public publication{
    int pages;
    public:
        book(): pages(0){}
        int Set(){
            int r = publication::Set(); //Calling base class's Set function
            if(r!=-1){
                int ch = 1;
                while(ch==1){
                try{
                        cout<<"Enter Number of Pages : ";
                        cin>>pages;
                        if(pages<=0){
                            throw pages;
                        }
                        ch=2;
                }
                catch(int p){
                    pages = 0;//Resetting pages to zero
                    cout<<"Invlaid Number of Pages, Press 1 to try again or another key to exit\n = ";
                    cin>>ch;
                    if(ch!=1){
                        return -1;
                    }
                }
                }
            }else{
                    return -1;
            }
        }
        void Get(){
            cout<<"\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
            cout<<"\nTitle                            : "<<title<<endl;
            cout<<"Price                            : "<<price<<endl; 
            cout<<"Number of Pages                  : "<<pages<<endl;
        }
};
class tape: public publication{ //Subclass 2
    float mins;
    public:
        tape(): mins(0){}
        int Set(){
            int r = publication::Set();
            if(r!=-1){
                int ch = 1;
                while(ch==1){
                try{
                    cout<<"Enter Play Time : ";
                    cin>>mins;
                    if(mins<=0){
                        throw mins;
                    }
                    ch=2;
                    return 1;
                }
                catch(float x){
                    mins = 0;
                    cout<<"Invlaid Playtime, Press 1 to try again or another key to exit\n = ";
                    cin>>ch;
                    if(ch!=1){
                        return -1;
                    }
                }
                }
            }else{
                return -1;
                
            }
        }
        void Get(){
            cout<<"\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
            cout<<"\nTitle                            : "<<title<<endl;
            cout<<"Price                            : "<<price<<endl;;
            cout<<"PLaytime of Tape                 : "<<mins<<endl;
        }
};

int main(){
    cout<<"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ WELCOME -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
    int ch=1,opt,count = 0,b_count = 0,t_count=0, i = 0, j = 0,r;
    publication* items[10];
    float total = 0;
    do{
        cout<<"\nShop For\n1)Book.\n2)Cassette.\n3)Exit.\nEnter Your Choice = ";
        cin>>opt;
        switch(opt){
            case 1:
                items[i] = new book;
                r = items[i]->Set();
                if(r==-1){
                    break;
                }
                i++;
                count++;
                b_count++;
                break;
            case 2:
                items[i] = new tape;
                r = items[i]->Set();
                if(r==-1){
                    break;
                }
                count++;
                t_count++;
                break;
            case 3:
                ch = 2;
                break;
        }
    }while(ch==1);
    if(count!=0){
        for(int i=0;i<count;i++){
            items[i]->Get();
            total += items[i]->price;
        }
    }
    cout<<"\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ BILL -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n"<<endl;
    cout<<"Books = "<<b_count<<endl;
    cout<<"Cassettes = "<<t_count<<endl;
    cout<<"Total = "<<total<<endl;
    return 0;
}