#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>

#define TAILLE_MAX 50


void clean(const char *buffer, FILE *fp);
void encryptDecrypt(char *input, char *output);



int main(int argc, char *argv[]){

	
	DIR *dir = NULL;
	struct dirent *envelopDir = NULL;

	dir = opendir("/media/external/");
	if(dir == NULL){
		printf("Error. Cannot open /media/external.\n");
		exit(1);
	}
	printf("The directory /media/external has been properly opened.\n\n");
	

	int fr = open("/media/external/test.txt",O_RDONLY);
	int fw = open ("/media/external/encryptedFile.xor",O_WRONLY | O_CREAT);
	if (fr<0){
		printf("Error. Cannot open test.txt.\n");
		exit(1);
	}
	if (fw<0){
		printf("Error. Cannot write encryptedFile.xor \n");
		exit(1);
	}

	char buffer_in[TAILLE_MAX]="";
	char buffer_out[TAILLE_MAX]="";
	read(fr, buffer_in, TAILLE_MAX);
	encryptDecrypt(buffer_in, buffer_out);
	printf("%s\n",buffer_out);
	write(fw,buffer_out,TAILLE_MAX);
	close(fr);
	close(fw);
	close(dir);


	
	
	return 0;
}




void clean(const char *buffer, FILE *fp){
    char *p = strchr(buffer,'\n');

    if (p != NULL)
        *p = 0;
    else{
        int c;

        while ((c = fgetc(fp)) != '\n' && c != EOF);

    }
}



void encryptDecrypt(char *input, char *output){
	char key[] = {'K','A','D'}; //Can be any chars, and any size array
	
	int i;
	for(i = 0; i < strlen(input); i++) {
		output[i] = input[i] ^ key[i % (sizeof(key)/sizeof(char))];
	}
}




