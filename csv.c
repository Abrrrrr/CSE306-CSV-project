#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	void f(char* filename){
		//calculate how many fields in first record
		FILE *file = fopen(filename,"r");

		char header[4096];
		fgets(header,sizeof(header),file);
		int ret=0;
		char *data=strtok(header,",");
		while(data!=NULL){
			ret++;
			data=strtok(NULL, ",");
		}
		fclose(file);
		printf("%d\n",ret);
	}


	void r(char *filename){
		//calulate how many data records in file, if -h is also attached -1 from it
		FILE *file = fopen(filename, "r");
		char header[4096];
		int ret=0;
		while(fgets(header,sizeof(header),file)){
			ret++;
		}

		fclose(file);
		printf("%d\n",ret);
	}



int main(int argc, char *argv[]){
	char *filename=argv[argc-1];

	FILE *file=fopen(filename,"r");
	if(file==NULL){

		return EXIT_FAILURE;
	}
	//dealing with each command line case -f -r -h -max -min -mean -records
	bool h_is;

	for(int i=1; i<argc-1;i++){
		if(strcmp(argv[i],"-f")==0){
			//run -f function
			f(filename);
		}else if(strcmp(argv[i], "-r") ==0){
			// run -r function
			r(filename);
		}else if(strcmp(argv[i],"-h")==0){
			// run -h function
			h_is= TRUE;
		}else if(strcmp(argv[i],"-min")==0){
			// run -min function
		}else if(strcmp(argv[i],"-max")==0){
			// run -max function
		}else if(strcmp(argv[i],"-mean")==0){
			// run -mean function
		}else if(strcmp(argv[i],"-records")==0){
			// run -records function
		}else{
			return EXIT_FAILURE;
		}
	}	return EXIT_SUCCESS;





	return 0;
}



	int min(char* filename, char* argv[]){

		return 0;
	}

	int max(char* filename, char* argv[]){

		return 0;

	}

	int mean(char* filename, char* argv[]){

		return 0;
	}

	int records(char* filename, char* argv[]){

		return 0;
	}


