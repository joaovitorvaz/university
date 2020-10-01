#include <stdio.h>
#include <stdlib.h>

#include"Menu.h"
#include"Instructions.h"
#include"Cache.h"
#include"Cpu.h"


int main(){
	int x;

	do{
		scanf("%d", &x);
		if(x!=0){
			srand(time(NULL));
			Menu();
		}
		else{}
	}while(x!=0);

	return 0;
}
