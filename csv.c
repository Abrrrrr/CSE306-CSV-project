#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){

	//grabs filename from end of command line arguments
	char *filename = argv[strlen(argv)-1];
	char * frh = argv[1];

	//opems file
	FILE *fptr;
	fptr = fopen(filename, "r");


	//dealing with each command line case -f -r -h -max -min -mean -records
	
	for(int i=1; i<strlen(argv)-1;i++){
		if(strcmp(argv[i]),"-f"==0){
			//run -f function
		}else if(strcmp(argv[i], "-r") ==0){
			// run -r function
		}else if(strcmp(argv[i],"-h")==0){
			// run -h function
		}else if(strcmp(argv[i],"-min")==0){
			// run -min function
		}else if(strcmp(argv[i],"-max")==0){
			// run -max function
		}else if(strcmp(argv[i],"-mean")==0){
			// run -mean function
		}else if(strcmp(argv[i],"-records")==0){
			// run -records function
		}
	}
	




	return 0;
}