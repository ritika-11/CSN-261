#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* enc;
char* enc1 ;
int* arr1 ;

int p,q,r,f,v,j;
size_t s =0;

void encryption();
//void decryption();

int main()
{
	
	int w=0;
	FILE *filePointer;
    char ch;
    filePointer = fopen("Sample_testcase_1.txt", "r");
    if (filePointer == NULL)
    {
		printf("File is not available \n");
    }
    else
    {
		fseek(filePointer, 0, SEEK_END);
		s = ftell(filePointer);
		rewind(filePointer);
		enc = (char*)malloc(sizeof(char)*s);
		while ((ch = fgetc(filePointer)) != EOF)
		{
		    //printf("%c", ch);
		    enc[w] = ch; w++;
		}
    }
    fclose(filePointer);
	v = strlen(enc);
	//printf("%d  ", v);
	printf("Enter n ,a and b such that n and a are coprime.\n");
	scanf("%d", &p);
	scanf("%d", &q);
	scanf("%d", &r);

	j = p - (v%p);
	//printf("%d", j);
	for(int a=0;a<j;a++)
		strcat(enc , " ");
	
	encryption(p,q,r);
	//printf("%s\n" , enc1);
	printf("Encrypted successfully. \n");

 	FILE *fptr;
    fptr = fopen("outputfile.txt","w");
    if(fptr == NULL)
    {
       printf("Error!");   
       exit(1);             
    }

    for(int a=0;a<v+j;a++)
	fprintf(fptr,"%c",enc1[a]);
    fclose(fptr);
    printf("Encrypted text has been stored in outputfile.txt \n");
}

void encryption(int n, int a, int b)
{
	int u;
	enc1 = (char*)malloc((v+j)*sizeof(char));
	arr1 = (int*)malloc((v+j)*sizeof(int));
	for(int h=0,l=-1;h<(v+j);h++)
	{
		if(h%n==0)
			l++;
		if((a*h+b)<0)
			{u = n - ((-1*(a*h+b))%n);
			 arr1[h] = u + l*n;}
		else
			arr1[h] = (a*h + b)%n + l*n;
		enc1[h] = enc[arr1[h]];
	}
}