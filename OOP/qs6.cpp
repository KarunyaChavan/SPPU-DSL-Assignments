#include"iostream"
#include"fstream"
using namespace std;

class Employee{
        int ecode,ch; 
        string name, pos, date, department;
        fstream f;
        string line;
    public:
        void login(){ 
            ch=1;
            f.open("empData.txt", ios::app);
            if(!f){
                cout<<"File Creation Failed"<<endl;
            }
            while(ch==1){
                try{
                    cout<<"\n_-_-_-_-_-_-_ LOGIN  _-_-_-_-_-_-_-_"<<endl;
                    cout<<"Enter Today's Date (DD/MM/YYYY) = ";
                    cin.ignore();
                    getline(cin, date);
                    if(date==" "){
                        throw date;
                    }
                    cout<<"Enter Name = ";
                    getline(cin, name);
                    if(name==" " || name==""){
                        throw name;
                    }
                    cout<<"Enter E-Code = ";
                    cin>>(ecode);
                    if(ecode<=0){
                        throw ecode;
                    }
                    cout<<"Enter Your Deprartment = ";
                    cin.ignore();
                    getline(cin, department);
                    if(department==" "){
                        throw department;
                    }
                    cout<<"Enter Your Position = ";
                    getline(cin,pos);
                    if(pos==" "){
                        throw pos;
                    }
                    f<<"----------------------------------------------------------"<<endl;
                    f<<"Date                                      :  "<<date<<endl;
                    f<<"Name                                      :  "<<name<<endl;
                    f<<"Employee - Code                           :  "<<(ecode)<<endl;
                    f<<"Department                                :  "<<department<<endl;
                    f<<"Position                                  :  "<<pos<<endl;
                    f<<"----------------------------------------------------------"<<endl;
                    f.close();
                    cout<<"Logged in Successfully"<<endl;
                    ch=2;
                    return;
                }
                catch(string x){
                    cout<<"Invalid Entry\nPress 1 to try again : ";
                    cin>>ch;
                    if(ch!=1){
                        return;
                    }
                }
                catch(int y){
                    cout<<"Invalid ecode, press 1 to try again, else login page will exit : ";
                    cin>>ch;
                    if(ch!=1){
                        return;
                    }
                }
            }
        }
        void show(){ 
            f.open("empData.txt", ios::in);
            if(!f){
                cout<<"Such File Doesn't Exists"<<endl;
            }
            f.seekg(0);
            while(getline(f,line)){
                cout<<line<<endl;
            }
            f.close();
        }
};

int main(){
    Employee e;
    int opt;
    do{
        cout<<"\n1)Login.\n2)Retreive Today's Login Data.\n3)Exit.\n Choice = ";
        cin>>opt;
        switch(opt){
            case 1:
                e.login();
                break;
            case 2:
                e.show();
                break;
            case 3:
                break;
        }
    }while(opt!=3);
    return 0;
}
