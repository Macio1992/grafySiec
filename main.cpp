#include <iostream>
#include "Stack.h"
#include "System.h"

using namespace std;

int main() {
	
	System system(5);
	system.fillTheMatrix();
	system.wypisz();

	system.getCycle2(0);
	
	//cout<<"Minimalny czas realizacji przedsiewziecia: "<<system.getCzasRealizacjiPrzedsiewziecia(0,5)<<endl;
	
	//system.wypiszMinimalne();
	//system.wypiszMaksymalne();
	
	
	return 0;
}
