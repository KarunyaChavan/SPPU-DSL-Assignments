#include "iostream"
using namespace std;
//----------------------------------------------------------------------------------------------------------------//
//Defining Student Class
class Student{
        int *rollNum; //Pointer for dynamic binding
        string name, div, dob, bld_grp, addrs, year, cnt;//private data
    public:
        Student(){ //Default Constructor
            rollNum = new int;
            *rollNum = 0;
            name = dob = div = bld_grp = addrs = year = cnt = "";
        }
        friend class Faculty; //Declaring Friend Class
        static void header(){ //Static Method
            cout<<"\n_-_-_-_-_-_-_ STUDENT DATABASE _-_-_-_-_-_-_"<<endl;
        }
        void admit(){ //Function for accepting input
            cout<<"\n_-_-_-_-_-_-_ Enter Student Data _-_-_-_-_-_-_"<<endl;
            cout<<"Enter Name = ";
            cin.ignore();
            getline(cin, name);
            cout<<"Enter Roll Number = ";
            cin>> (*rollNum);
            cout<<"Enter Your Class = ";
            cin>>year;
            cout<<"Enter Your Division = ";
            cin>>div;
            cout<<"Enter Your Birth Date (DD/MM/YYYY) = ";
            cin>>dob;
            cout<<"Enter Your Blood Group = ";
            cin>>bld_grp;
            cout<<"Enter Your Contact Number = ";
            cin>>cnt;
            cout<<"Enter Your Address = ";
            cin.ignore();
            getline(cin, addrs);
        }
        void show(){ //Function for displaying entered data
            cout<<"\n------------------------------------------------------------"<<endl;
            cout<<"Name                                      :  "<<name<<endl;
            cout<<"Roll Number                               :  "<<(*rollNum)<<endl;
            cout<<"Class                                     :  "<<year<<endl;
            cout<<"Division                                  :  "<<div<<endl;
            cout<<"Birth Date                                :  "<<dob<<endl;
            cout<<"Blood Group                               :  "<<bld_grp<<endl;
            cout<<"Contact Number                            :  "<<cnt<<endl;
            cout<<"Address                                   :  "<<addrs<<endl;
        }
        ~Student(){ //Destructor
            delete rollNum;
        }
};
//--------------------------------------------------------------------------------------------------------------------------------------------//
//Defining Faculty Class
class Faculty{
        int ID;
    public:
        Faculty(): ID(000){} //Default Constructor
        Faculty(const Faculty &f){ //Copy Constructor
            ID = f.ID;
        }
        void div_info(Student &S, string F){
            try{
                if (S.div==F){
                    S.show();
                }else{
                    throw(S.div); //If F.div != S.div
                }
            }
            catch(string x){
                cout<<"\nSorry, You aren't assigned to this class"<<endl;
            }
        }
};
//--------------------------------------------------------------------------------------------------------------------------------------------//
//Driver Code
int main(){
    Student S[100]; //Array of Student Objects with max accomodation of 100
    Faculty F;
    int count = 0, opt;
    string Fdiv;
    do{
        cout<<"\nSTUDENT DATABASE WELCOMES YOU!!"<<endl;
        cout<<"_-_-_-_-_-_-_ MENU _-_-_-_-_-_-_"<<endl;
        cout<<"1)Add Information.\n2)Display Information.\n3)As Per Respective Faculty Information.\n4)Exit.\nEnter Your Choice  = ";
        cin>>opt;
        switch (opt)
        {
        case 1:
            S[count].admit();
            count++;
            break;
        
        case 2:
            Student::header();
            for (int i=0; i<count ; i++){
                S[i].show();
            }
            break;
            
        case 3:
            cout<<"\nEnter Division of Required Faculty = ";
            cin>>Fdiv;
            for (int i=0;i<count;i++){
                cout<<endl;
                F.div_info(S[i], Fdiv);
            }
            break;
            
        case 4:
            exit(0);

        default:
            cout<<"Invalid Option."<<endl;
            break;
        }
    }while(opt!=4);
    return 0;
}