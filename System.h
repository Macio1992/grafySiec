#ifndef SYSTEM_H
#define SYSTEM_H

class System {
	
	private:
		int **system;
		int size;
		int *tab;
		int *stackTab;
	
	public:
		System(int);
		~System();
		
		void wypisz();
		void zeroSystem(int**);
		void fillTheMatrix();
		void getCycle2(int);
		int getCzasRealizacjiPrzedsiewziecia(int, int);
		void wypiszMinimalne();
		void wypiszMaksymalne();
		
};

#endif
