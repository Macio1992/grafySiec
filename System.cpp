#include "System.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

System::System(int x){
	
	size = x;
		
	system = new int*[size];
	for(int i = 0; i < size; i++)
		system[i] = new int[size];
	
	stackTab = new int[size];
	
	zeroSystem(system);
	
}

System::~System(){
	
	for (int i = 0; i < size ; i++)
		delete [] system[i];
	delete [] system;
	
	delete [] stackTab;
	
}

void System::wypisz(){
	
	cout<<"  0 1 2 3 4 5"<<endl<<endl;
	for(int i = 0; i < size; i++){
		cout<<i<<" ";
		for(int j = 0; j < size; j++){
			cout << system[i][j]<<" ";
		}
		cout <<"\n";
	}
	cout <<"\n";
	
}

void System::zeroSystem(int **tab){
	
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			tab[i][j] = 0;
	
}

void System::fillTheMatrix(){
	ifstream ifile;
	ifile.open("data.txt");
	
	if(!ifile){
		cout<<"Blad podczas otwierania pliku"<<endl;
	}
	
	int a, b, c;
	string line;
	while(getline(ifile, line)){
		stringstream ss;
		ss << line;
		ss >> a >> b >> c;
		//system[a][b] = (-c);
		system[a][b] = c;
//		system[b][a] = c;
	}
	ifile.close();
}

bool checkIfSystemEmpty(int **tab, int n){
	
	int licznik = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(tab[i][j] == 0){
				licznik++;
			}
		}	
	}
		
	
	if(licznik == (n*n)) return true;
	else return false;
	
}

void wypiszTab(int *tab, int n){
	for(int i = 0; i < n; i++)
		cout<<tab[i]<<" ";
	cout<<endl;
}

void wypiszBoole(bool *tab, int n){
	for(int i = 0; i < n; i++)
		if(tab[i] == true) cout<<i<<". == TRUE"<<endl;
		else cout<<i<<". == FALSE"<<endl;
}

bool sprawdzCzyMaSasiadow(int wierzcholek, int n, int **system){
	int l = 0;
	for(int i = 0; i < n; i++)
		if(system[wierzcholek][i] == 0)
			l++;
		
	if(l == n) return false;
	else return true;
}

void System::getCycle2(int beg){	
	
	for(int i = 0; i < size; i++) stackTab[i] = 0;
	
	int suma = 0, x = beg;
	
	Stack stack(size);
	
	while(!checkIfSystemEmpty(system, size)){
	
	stack.push(beg);
	for(int i = 0; i < size; i++)
		if((system[i][stack.getStackTop()] == stack.getStackTop()) && system[i][stack.getStackTop()] < suma){
			stackTab[stack.getStackTop()] = system[i][stack.getStackTop()];
			system[i][stack.getStackTop()] = 0;
		}
		while(!sprawdzCzyMaSasiadow(beg, size, system)){
			stack.pop();
			beg = stack.getStackTop();
		}
		for(int i = 0; i < size; i++){
			if(system[stack.getStackTop()][i] != 0){
				beg = i;
				suma = stackTab[stack.getStackTop()] + system[stack.getStackTop()][beg];
			}
		}
		system[stack.getStackTop()][beg] = 0;
		if(stackTab[beg] != 0){
			if(suma < stackTab[beg])
				stackTab[beg] = suma;
		}else {
			stackTab[beg] = suma;
		}
	}
	wypiszTab(stackTab, size);
	
}

int System::getCzasRealizacjiPrzedsiewziecia(int start, int end){
	
	start = -(stackTab[start]);
	end = -(stackTab[end]);
	
	return end - start;
	
}

void System::wypiszMinimalne(){
	
	fillTheMatrix();
	cout<<"Najwczesniejsze momenty zaczecia: "<<endl;
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			if(system[i][j] != 0)
				cout<<"i: "<<i<<", j: "<<j<<" = "<<getCzasRealizacjiPrzedsiewziecia(0, i)<<endl;
	
}

void System::wypiszMaksymalne(){
	cout<<"Najpozniejszy momenty zaczecia: "<<endl;
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			if(system[i][j] != 0){
				cout<<"i: "<<i<<", j: "<<j<<" = "<<getCzasRealizacjiPrzedsiewziecia(0, size-1) - getCzasRealizacjiPrzedsiewziecia(j, size-1) - (system[i][j])*(-1)<<endl;
			}
}
