#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char line[5072];

void removeGreen();
void removeRed();
void removeBlue();
void preserveGreen();
void preserveRed();
void preserveBlue();
void GetPixel();

int main()
{
	int **red = (int**)malloc(953*sizeof(int*));
	for(int m = 0;m<1268;m++)
		red[m] = (int*)malloc(1268*sizeof(int));
	int **green = (int**)malloc(953*sizeof(int*));
	for(int m = 0;m<1268;m++)
		green[m] = (int*)malloc(1268*sizeof(int));
	int **blue = (int**)malloc(953*sizeof(int*));
	for(int m = 0;m<1268;m++)
		blue[m] = (int*)malloc(1268*sizeof(int));

	FILE *f = fopen("./Q3_ip_Blue.dat","r");
	if(f == NULL)
	{
	printf("\n File opening failed");
	return -1;
	}
	for(int i=0; i<953; i++)
	{
		fgets(line, 5072, f);
		char* token = strtok (line, ",");
		int j=0;
		while(token != NULL)
		{
			int m;
			sscanf(token, "%d" , &m);
			blue[i][j] = m;
			token = strtok (NULL, ",");
			j++;
		}
	}	

	fclose(f);

	FILE *f1 = fopen("./Q3_ip_Red.dat","r");
	if(f1 == NULL)
	{
	printf("\n File opening failed");
	return -1;
	}
	for(int i=0; i<953; i++)
	{
		fgets(line, 5072, f1);
		char* token = strtok (line, ",");
		int j=0;
		while(token != NULL)
		{
			int m;
			sscanf(token, "%d" , &m);
			red[i][j] = m;
			token = strtok (NULL, ",");
			j++;
		}
	}

	fclose(f1);

	FILE *f2 = fopen("./Q3_ip_Green.dat","r");
	if(f2 == NULL)
	{
	printf("\n File opening failed");
	return -1;
	}
	for(int i=0; i<953; i++)
	{
		fgets(line, 5072, f2);
		char* token = strtok (line, ",");
		int j=0;
		while(token != NULL)
		{
			int m;
			sscanf(token, "%d" , &m);
			green[i][j] = m;
			token = strtok (NULL, ",");
			j++;
		}
	}

	fclose(f2);

	int choice;

		printf("1.removeGreen\n");
		printf("2.removeRed\n");
		printf("3.removeBlue\n");
		printf("4.preserveGreen\n");
		printf("5.preserveRed\n");
		printf("6.preserveBlue\n");
		printf("7.Get pixel value\n");
		printf("8.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			removeGreen(red,green,blue);
			break;
		 case 2:
			removeRed(red,green,blue);
			break;
		 case 3:
			removeBlue(red,green,blue);
			break;
		 case 4:
			preserveGreen(red, green, blue);
			break;
		 case 5:
			preserveRed(red, green, blue);
			break;
		 case 6:
			preserveBlue(red, green, blue);
			break;
		 case 7:
		 	GetPixel(red,green,blue);
            break;
            case 8:
            break;
		 default:
			printf("Wrong choice\n");
		}


    FILE *fptr;
    fptr = fopen("C:\\Q3_op_Red.dat","w");
    if(fptr == NULL)
    {
       printf("Error!");   
       exit(1);             
    }

    for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			fprintf(fptr," %d,",red[i][j]);
		}
	}
    fclose(fptr);

    FILE *fptr1;
    fptr1 = fopen("C:\\Q3_op_Green.dat","w");
    if(fptr1 == NULL)
    {
       printf("Error!");   
       exit(1);             
    }

    for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			fprintf(fptr1," %d,",green[i][j]);
		}
	}
    fclose(fptr1);

    FILE *fptr2;
    fptr2 = fopen("C:\\Q3_op_Blue.dat","w");
    if(fptr2 == NULL)
    {
       printf("Error!");   
       exit(1);             
    }

    for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			fprintf(fptr2," %d,",blue[i][j]);
		}
	}
    fclose(fptr2);
	
	return 0;
}

void GetPixel(int **Red, int **Green, int **Blue)
{
	int x,y;
	printf("Enter x coordinate : ");
	scanf("%d",&x);
	printf("Enter y coordinate : ");
	scanf("%d",&y);
	printf("Red component is %d \n" ,Red[x][y]);
	printf("Green component is %d \n" ,Green[x][y]);
	printf("Blue component is %d " ,Blue[x][y]);

}

void removeGreen(int **Red, int **Green, int **Blue)
{
	for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			if(Green[i][j]>Red[i][j]&&Green[i][j]>Blue[i][j])
				Green[i][j] = 0;
		}
	}
	GetPixel(Red,Green,Blue);
}

void removeRed(int **Red, int **Green, int **Blue)
{
	for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			if(Red[i][j]>Green[i][j]&&Red[i][j]>Blue[i][j])
				Red[i][j] = 0;
		}
	}
	GetPixel(Red,Green,Blue);
}

void removeBlue(int **Red, int **Green, int **Blue)
{
	for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			if(Blue[i][j]>Red[i][j]&&Blue[i][j]>Green[i][j])
				Blue[i][j] = 0;
		}
	}
	GetPixel(Red,Green,Blue);
}


void preserveGreen(int **Red, int **Green, int **Blue)
{
	for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			if(Blue[i][j]>Red[i][j]&&Blue[i][j]>Green[i][j])
				Blue[i][j] = 0;
		}
	}
	for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			if(Red[i][j]>Green[i][j]&&Red[i][j]>Blue[i][j])
				Red[i][j] = 0;
		}
	}
	GetPixel(Red,Green,Blue);
}

void preserveBlue(int **Red, int **Green, int **Blue)
{
	for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			if(Green[i][j]>Red[i][j]&&Green[i][j]>Blue[i][j])
				Green[i][j] = 0;
		}
	}
	for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			if(Red[i][j]>Green[i][j]&&Red[i][j]>Blue[i][j])
				Red[i][j] = 0;
		}
	}
	GetPixel(Red,Green,Blue);
}

void preserveRed(int **Red, int **Green, int **Blue)
{
	for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			if(Blue[i][j]>Red[i][j]&&Blue[i][j]>Green[i][j])
				Blue[i][j] = 0;
		}
	}
	for(int i=0;i<953;i++)
	{
		for(int j=0;j<1268;j++)
		{
			if(Green[i][j]>Red[i][j]&&Green[i][j]>Blue[i][j])
				Green[i][j] = 0;
		}
	}
	GetPixel(Red,Green,Blue);
}
