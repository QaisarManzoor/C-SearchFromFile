#include<fstream>
#include<iostream>
#include<cstdlib>
using namespace std;
ifstream fin;//file object
string temp = "";
bool matchName(string nameSearch);
int main()
{
	
	fin.open("test.txt");
	if(fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	string nameSearch;
	cout << "Please enter a name you want to Search from file : ";
	cin  >> nameSearch;
	//function calling to Search name form file
	bool isFound=matchName(nameSearch);

	if(isFound)
		{
			cout<<"Record Found::";
			cout << "\nName is "<<temp;
			fin>>temp;
			cout<<"\nAge is "<<temp;
			fin>>temp;
			cout<<"\nDepartment is "<<temp;
		}

	if(fin.eof()&&(!isFound))
	{
		cout << "Name not found!\n";
	}

	fin.close();

	return 0;
}
bool matchName(string nameSearch)
{
	bool isFound=0;
	while(!fin.eof())
	{
		
		getline(fin,temp);
		for(int i=0;i<nameSearch.size();i++)
		{
			if(temp[i]==nameSearch[i])
				isFound = 1;
			else
			{
				isFound =0;
				break;
			}
		}
		if(isFound)
		{
			return 1;
		}
	}
}

