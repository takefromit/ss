#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void) {
  printf("Enter the name of the program");
  char n[10];
  scanf("%s",n);
  FILE *fp;
  fp=fopen("inputAbs.txt","r");
  char line[50],name[20],strAddr[30];
int i,currAddr;
  fscanf(fp,"%s",line);
if(line[0]=='H'){
  for(i=0;i<6;i++)
    {
      name[i]=line[i+2];
    }
  name[i]='\0';
  printf("name :%s\n",name);
  if(strcmp(name,n)==0)
  {
    
  i=i+3;
  for(int j=0;j<6;j++)
    {
      strAddr[j]=line[j+i];
    }
  printf("strAddr: %s\n",strAddr);
  while(!feof(fp))
    {
      i=2;int j;
      fscanf(fp,"%s",line);
      if(line[0]=='T')
      {
          for( j=0;j<6;j++)
    {
      strAddr[j]=line[j+i];
    }
        currAddr=atoi(strAddr);
        i=i+j+3;
     while(line[i]!='$')   
       {
         if(line[i]!='^')
         {
      printf("%i : %c%c\n",currAddr++,line[i],line[i+1]);
       i=i+2;
         }
         else{
           i++;
         }
       }
      }
      
    }
  
  
}
 else{
    printf("wrong program\n");
  }
  }
  else{
    printf("wrong input\n");
  }
  
  return 0;
}