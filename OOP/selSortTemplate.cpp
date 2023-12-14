#include <iostream>
using namespace std;

template <class T> //Function Template for Selection Sort
void selSort(int n, T *arr){
    for (int i = 0;i<(n-1);i++){
        int min_index = i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        if (min_index != i){
            swap(arr[i],arr[min_index]);
        }
    }
    return;
}

template<class T> //Function Template for Display
void display(int n,T* arr){
    for (int i= 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    int n,opt,ch=1;
    while(ch==1){
        cout<<"Select Type of Array\n1)Integer Array.\n2)Float Array.\n3)Exit.\n = ";
        cin>>opt;
        if(opt==1){
            cout<<"Enter Number of Elements = ";
            cin>>n;
            int Int_arr[n];
            cout<<"Enter elements of array "<<endl;
            for (int i= 0;i<n;i++){
                cin>>Int_arr[i]; //Calling for Integer Array
            }
            selSort(n,Int_arr);
            display(n,Int_arr);
        }
        
        else if(opt==2){
            cout<<"Enter Number of Elements = ";
            cin>>n;
            float Float_arr[n];
            cout<<"Enter elements of array "<<endl;
            for (int i= 0;i<n;i++){
                cin>>Float_arr[i]; //Calling for Float Array.
            }
            selSort(n,Float_arr);
            display(n,Float_arr);
        }
        else{
            break;
        }
    }
    return 0;
}