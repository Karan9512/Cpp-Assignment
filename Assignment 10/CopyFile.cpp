#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main( int arg , char *argv[] ){
	

	if(arg!=3){
		cout<<"Invalid Format : Use ./mycp sourceFile destFile "<<endl;
	
	}

	ifstream fin = ifstream(argv[1]);
        ofstream fout = ofstream(argv[2]);
	string str;

	if(!fin){
		cout<<"Error Reading File ";
	}

	if(!fout){
		cout<<"Error Writing in File ";
	}


	while(fin){
	
		getline(fin,str);
		fout<<str<<endl;
	
	}

	fin.close();
	fout.close();
}
