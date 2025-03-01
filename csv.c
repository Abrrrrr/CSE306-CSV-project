#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

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
			if(strcmp(data,field)==0){
				return ret;
			}
			ret++;
			data=strtok(NULL,",");
	}		
		return -1;
	
}



	void min(char* filename, char *field){

		FILE *file = fopen(filename,"r");
		char header[4096];
		int min=INT_MAX;

		int fieldIndex=atoi(field);
		if (fgets(header, sizeof(header), file)) {
		if(h_is){
			fgets(header,sizeof(header),file);
			fieldIndex= fieldTranslate(header,field);
			if(fieldIndex==-1){
				exit(EXIT_FAILURE);
			}else{
				fieldIndex=atoi(field);
			}
		}
		}
		while(fgets(header,sizeof(header),file)){
			char *data=strtok(header,",");
			for(int i=0; i<fieldIndex;i++){
				data = strtok(NULL,",");
			}
		
		if (data!= NULL){
			if(atoi(data)<min){
				min = atoi(data);
			}
		}

		}
		printf("%d\n",min);

		fclose(file);
	}





	void max(char* filename, char *field){
		int max=INT_MIN;
		
		FILE *file = fopen(filename,"r");
		char header[4096];

		int fieldIndex=atoi(field);
		if (fgets(header, sizeof(header), file)) {
		if(h_is){
			fgets(header,sizeof(header),file);
			fieldIndex= fieldTranslate(header,field);
			if(fieldIndex==-1){
				exit(EXIT_FAILURE);
			}else{
				fieldIndex=atoi(field);
			}
		}
		}
		while(fgets(header,sizeof(header),file)){
			char *data=strtok(header,",");
			for(int i=0; i<fieldIndex;i++){
				data = strtok(NULL,",");
			}
		
		if (data!= NULL){
			if(atoi(data)>max){
				max = atoi(data);
			}
		}

		}
		printf("%d\n",max);

		fclose(file);
	}

	void mean(char* filename, char* argv[]){
		int sum=0;
		int count=0;
			char*p="dog function, wave the white flag :(";
	printf("%s",p);

	}

	void records(char* filename, char* argv[]){
	char*p="doodoo function, wave the white flag :(";
	printf("%s",p);
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

		}else if(strcmp(argv[i],"-min")==0 && i + 1 < argc - 1){
			// run -min function
			int j=i+1;
			min(filename,argv[j]);
		}else if(strcmp(argv[i],"-max" )==0&& i + 1 < argc - 1){
			// run -max function
			int j=i+1;
			max(filename,argv[j]);
		}else if(strcmp(argv[i],"-mean" )==0){
			// run -mean function
			mean(filename,argv);
		}else if(strcmp(argv[i],"-records")==0){
			// run -records function
			records(filename,argv);
		}else{
			return EXIT_FAILURE;
		}
	}	return EXIT_SUCCESS;


	fclose(file);


	return 0;
}



