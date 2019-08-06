    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<string.h>

    int l = 0;
    int size,k;
    int **red;
    int **arr;

    struct node
    {
        struct node *sonNW;
        struct node *sonNE;
        struct node *sonSW;
        struct node *sonSE;
        int nodetype;
    };

    
    void quadmatrix();

    int main(){ 

        FILE *fp = fopen("quadtree.txt", "r");
    
        char ch; int num;
        int count_lines=0;
        int blank_lines=0;
        ch = getc(fp);
        
        while ((ch = fgetc(fp))!= EOF)
        {
            if (ch  ==  '\n')
            {
                count_lines++;
            }
            if (ch  ==  '\n')
            {
                if ((ch = fgetc(fp))  ==  '\n')
                {
                    fseek(fp, -1, 1);
                    blank_lines++;
                }
            }
         }
         if(blank_lines==0)
            count_lines=count_lines+1;
         else
            count_lines=count_lines-blank_lines;
         fclose(fp);
         int i=0;
         int j;
         FILE *f1 = fopen("quadtree.txt", "r");
         int array[count_lines][count_lines];
         char buffer[1024];
         while((fgets(buffer,1024,f1) != NULL))
         {
            char *token = strtok(buffer, " ");
            j = 0;
              while(token!=NULL)
              {
                  int value=atoi(token);
                  array[i][j]=value;
                  token = strtok(NULL, " ");
                  j++;
              }
              i++;
         }     
    
        size = (int) pow(2, ceil(log(count_lines)/log(2)));
        //printf("%d " , size);

        arr = (int**)malloc(size*sizeof(int*));
        for(int m = 0;m<size;m++)
            arr[m] = (int*)malloc(size*sizeof(int));

        for(int i=0;i<size;i++)
        {    
            for(int j=0;j<size;j++)
            {   
                if((i<size-count_lines)||(j<size-count_lines))
                    arr[i][j] = 0;
                else
                    arr[i][j] = array[i+count_lines-size][j+count_lines-size];
                //printf("%d " , arr[i][j]);
            } 
            //printf("\n");  
        } 


        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        ptr->nodetype = -1;

        red = (int**)malloc(size*sizeof(int*));
        for(int m = 0;m<size;m++)
            red[m] = (int*)malloc(size*sizeof(int));

        printf("Node number, their corresponding bit values and their levels in quadtree are as follows : \n \n");

        quadmatrix(0, size, 0, size, ptr); 

        printf("\n");
        printf("Maximal square array is as follows : \n\n");
        
        for(int i=0;i<size;i++)
        {    
            for(int j=0;j<size;j++)
            { 
                if(red[i][j]/10==0)
                    printf(" ");  
                printf("%d ", red[i][j]);
            }  
            printf("\n"); 
        }

        return 0;  
    }    

    void quadmatrix(int start1, int end1, int start2, int end2, struct node *ptrr)
    {
        for(int i=start1;i<end1;i++)
        {    
            for(int j=start2;j<end2;j++)
            {   
                k=0; 
                if(arr[i][j]!=arr[start1][start2])
                {
                    k++;
                    break;
                }
                else 
                    continue;    
            }
            if(k>0)
                break;    
        } 
        if(k>0)
        {
            struct node *temp1, *temp2,*temp3,*temp4;

            temp1=(struct node*)malloc(sizeof(struct node));
            temp2=(struct node*)malloc(sizeof(struct node));
            temp3=(struct node*)malloc(sizeof(struct node));
            temp4=(struct node*)malloc(sizeof(struct node));
           
            ptrr->sonNW=temp1;
            ptrr->sonNE=temp2;
            ptrr->sonSW=temp3;
            ptrr->sonSE=temp4;
            
            quadmatrix(start1, (end1+start1)/2, start2, (end2+start2)/2, temp1);
            quadmatrix(start1, (end1+start1)/2, (end2+start2)/2, end2, temp2);
            quadmatrix((end1+start1)/2, end1, start2, (end2+start2)/2, temp3);
            quadmatrix((end1+start1)/2, end1, (end2+start2)/2, end2, temp4);
        }  
        else
        {
            l++;
            int y = size/(end1-start1);
            int s = (int) (log(y)/log(2));
            for(int i=start1;i<end1;i++)
            {    
                for(int j=start2;j<end2;j++)
                {   
                    red[i][j] = l;
                }   
            } 
            ptrr->nodetype = arr[start1][start2];
            printf("%d , %d , %d \n", l, ptrr->nodetype, s);
        }
    }