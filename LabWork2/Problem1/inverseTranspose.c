#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* enc;
char* enc1 ;
int* arr1 ;
int p,q,r,x,y,f,v;

void encryption();
void decryption();

int main()
{
	int w=0;
	size_t s =0;
	FILE *filePointer;
    char ch;
	filePointer = fopen("outputfile.txt", "r");
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
	//printf("%d", v);
	printf("Enter the n ,a and b which were used to encrypt the file.\n");
	scanf("%d", &p);
	scanf("%d", &q);
	scanf("%d", &r);	

	//j = p - (v%p);

	for(int m=0;m<p;m++)
	{
		if((q*m)%p==1)
			{f = m;
			 break;}
	}
	x = f;
	y = -1*((x*r)%p);
	decryption(p,x,y);
	//printf("%s\n" , enc1);
	printf("Decrypted successfully. \n");

 	FILE *fptr;
    fptr = fopen("decryptedOutputfile.txt","w");
    if(fptr == NULL)
    {
       printf("Error!");   
       exit(1);             
    }
    for(int a=0;a<v;a++)
		fprintf(fptr,"%c",enc1[a]);
    fclose(fptr);
    printf("Decrypted text has been stored in decryptedOutputfile.txt \n");

}

void decryption(int n, int a, int b)
{
	int u;
	enc1 = (char*)malloc(v*sizeof(char));
	arr1 = (int*)malloc(v*sizeof(int));
	for(int h=0,l=-1;h<v;h++)
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