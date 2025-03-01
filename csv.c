#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool h_is=false;
char *field;

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
		//calulate how many data records in file
		FILE *file = fopen(filename, "r");
		char header[4096];
		int ret=0;
		while(fgets(header,sizeof(header),file)){
			ret++;
		}

		fclose(file);
		printf("%d\n",ret);
	}


	int fieldTranslate(char *header, char *field){
		int ret=0;
		char *data =strtok(header,",");
		while(data!=NULL){
			if(strmp(data,field)==0){
				return ret;
			}
			ret++;
			data=strtok(NULL,",");
		return INT_MIN;
	}



	void min(char* filename, char* argv[]){

		FILE *file = fopen(filename,"r");
		char header[4096];
		int min=INT_MAX;

		if(h_is){
			fgets(header,sizeof(header),file);
		}
		while(fget(header,sizeof(header),file)){
			char *data=strtok(header,",");
			for(int i=0; i<)
		}


	}


	void max(char* filename, char* argv[]){
		int max=INT_MIN;
		return 0;

	}

	void mean(char* filename, char* argv[]){
		int sum=0;
		int count=0;

		return 0;
	}



int main(int argc, char *argv[]){
	char *filename=argv[argc-1];
	char header[4096];
    int field_index = -1;

	FILE *file=fopen(filename,"r");
	if(file==NULL){

		return EXIT_FAILURE;
	}
	//dealing with each command line case -f -r -h -max -min -mean -records


	for(int i=1; i<argc-1;i++){
		if(strcmp(argv[i],"-f")==0){
			//run -f function
			f(filename);

		}else if(strcmp(argv[i], "-r") ==0){
			// run -r function
			r(filename);

		}else if(strcmp(argv[i],"-h")==0){
			// run -h function
			h_is= true;
			fieldTranslate(header,)

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


	fclose(file);


	return 0;
}



	int records(char* filename, char* argv[]){

		return 0;
	}


