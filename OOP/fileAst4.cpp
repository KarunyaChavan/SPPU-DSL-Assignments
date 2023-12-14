#include"iostream"
#include"fstream"
using namespace std;

class Student{
        int rollNum; 
        string name, div, date, year;
        fstream f;
        string line;
    public:
        void admit(){ 
            f.open("studentData.txt", ios::app);
            if(!f){
                cout<<"File Creation Failed"<<endl;
            }
            cout<<"\n_-_-_-_-_-_-_ Enter Student Data _-_-_-_-_-_-_"<<endl;
            cout<<"Enter Date (DD/MM/YYYY) = ";
            cin>>date;
            cout<<"Enter Name = ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter Roll Number = ";
            cin>>(rollNum);
            cout<<"Enter Your Class = ";
            cin>>year;
            cout<<"Enter Your Division = ";
            cin>>div;

            f<<"----------------------------------------------------------"<<endl;
            f<<"Date                                      :  "<<date<<endl;
            f<<"Name                                      :  "<<name<<endl;
            f<<"Roll Number                               :  "<<(rollNum)<<endl;
            f<<"Class                                     :  "<<year<<endl;
            f<<"Division                                  :  "<<div<<endl;
            f<<"----------------------------------------------------------"<<endl;
            f.close();
        }
        void show(){ 
            f.open("studentData.txt", ios::in);
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
    Student s;
    int opt;
    do{
        cout<<"\n1)Add Data.\n2)Retreive Data.\n3)Exit.\n Choice = ";
        cin>>opt;
        switch(opt){
            case 1:
                s.admit();
                break;
            case 2:
                s.show();
                break;
            case 3:
                break;
        }
    }while(opt!=3);
    return 0;
}
