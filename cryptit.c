#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define TAILLE_MAX 1000


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



	FILE *f1 = NULL;
	FILE *f2 = NULL;
	
	char baseStr[TAILLE_MAX] = "";
	char encryptedString[TAILLE_MAX] = "";
	
	
	f1 = fopen("/media/external/test.txt", "r");
	if(f1 == NULL)
		printf("Error. Failed to oppen f1.\n");
	else{
		f2 = fopen("/media/external/encryptedFile.xor", "w");
		if(f2 == NULL)
			printf("Error. Failed to open f2.\n");		
		
		while(fgets(baseStr, TAILLE_MAX, f1) != NULL){
			encryptDecrypt(baseStr, encryptedString);
			fputs(encryptedString, f2);
		}
		
		fclose(f1);
		fclose(f2);
	}
	
	close(dir);



/*
	while(keepRunning){
		while((envelopDir = readdir(dir)) != NULL){
			printf("The directory barj contains : %s\n", envelopDir->d_name);
		}
		
		printf("\nIs there a directory that you would like to encrypt? (n for no, y for yes)\n");
		
		
		choice1 = getchar();
		while(getchar() != '\n');
		
		switch(choice1){
			case 'n':
				keepRunning = 0;
				break;
			
			case 'y':
	
				printf("\nType down the name of the directory that you want to encrypt: ");
					
				fgets(filesName, sizeof(filesName), stdin);
				clean(filesName, stdin);
					
				FILE *f1 = NULL;
				FILE *f2 = NULL;
	
				char baseStr[TAILLE_MAX] = "";
				char encryptedString[TAILLE_MAX] = "";
	
	
				//f1 = fopen(filesName, "r");
				if(f1 == NULL)
					printf("Error. Failed to oppen f1.\n");
				else{
					f2 = fopen("blablaPasClair", "w");
					if(f2 == NULL)
						printf("Error. Failed to open f2.\n");		
		
					while(fgets(baseStr, TAILLE_MAX, f1) != NULL){
						encryptDecrypt(baseStr, encryptedString);
						fputs(encryptedString, f2);
					}
		
					fclose(f1);
					fclose(f2);
				}
				break;
			
			default:
				printf("Please type a n for no or a y for yes");
		}
		
		
		
		//fgets(filesName, sizeof(filesName), stdin);
	
	}



	if(closedir(dir) != 0){
		printf("Error. Cannot close barj.\n");
		exit(1);
	}

	printf("Succesful closing of barj.\n");*/
	
	
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
	char key[] = {'K', 'C', 'Q'}; //Can be any chars, and any size array
	
	int i;
	for(i = 0; i < strlen(input); i++) {
		output[i] = input[i] ^ key[i % (sizeof(key)/sizeof(char))];
	}
}




