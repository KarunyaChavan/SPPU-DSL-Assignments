#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int main()
{
	string name;
	int pop;
	string states[] = { "Maharashtra", "Punjab", "Gujarat","Kerala", "Rajasthan", "Bengal"};
	int pops[] = { 125, 78, 32, 38, 32, 39 };
	map<string, int, less<string> > mapStates; //map
	map<string, int, less<string> >::iterator iter; //iterator
	for(int j=0; j<6; j++)
	{
	name = states[j]; //get data from arrays
	pop = pops[j];
	mapStates[name] = pop; //put it in map
	}
	//Method 1: For Searching 
	cout << "Enter state: "; //get state from user
	cin >> name;
	pop = mapStates[name]; //find population
	cout << "Population:  "<< pop << ",00,000\n";
	cout << endl; //display entire map

	for(iter = mapStates.begin(); iter != mapStates.end(); iter++)
		cout << (*iter).first << " " << (*iter).second << ",000\n";

	char ch = 'y'; 
	do{
		//Method 2: For Searching
		string state;
		cout<<"\nEnter Name of State : ";
		cin>>state;
		iter = mapStates.find(state);
		if(iter!=mapStates.end()){
			cout<<state<<"\'s population is "<<iter->second<<" million"<<endl;
		}else{
			cout<<state<<" is not in the list"<<endl;
		}
		cout<<"Do you want to continue ? : (y/n) ";
		cin>>ch;
	}while(ch=='y' || ch== 'Y');
	mapStates.clear();
	return 0;
}