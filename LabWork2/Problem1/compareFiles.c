#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* enc;
char* enc1 ;

int main()
{
	int w=0;
	size_t s =0;
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

	int u=0;
	size_t t =0;
	FILE *file;
    char ch1;   
	file = fopen("decryptedOutputfile.txt", "r");
    if (file == NULL)
    {
		printf("File is not available \n");
	}
    else
    {
		fseek(file, 0, SEEK_END);
		t = ftell(file);
		rewind(file);
		enc1 = (char*)malloc(sizeof(char)*t);
		while ((ch1 = fgetc(file)) != EOF)
		{
		    //printf("%c", ch1);
		    enc1[u] = ch1; u++;
		}
	}
	fclose(file);

	int l = 0;
	for(int i=0;i<s;i++)
	{
		if(enc1[i]==enc[i])
			l++;
	}
	if(l==s)
		printf("Decrypted properly. \n");
	else
		printf("Error");
}