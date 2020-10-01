#include <stdio.h>
#include <stdlib.h>

#include"Menu.h"
#include"Instructions.h"
#include"Cache.h"
#include"Cpu.h"


int main(){
	int HD_block = 100000;
	FILE* hardDisk = fopen("HD.bin","w+b");
	create_hardDisk_bin(hardDisk, HD_block);
	srand(time(NULL));
	Menu(hardDisk);
	fclose(hardDisk);
	free(hardDisk);
	return 0;
}
