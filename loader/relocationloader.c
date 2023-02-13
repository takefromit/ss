#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char add[6],length[10],input[10],binary[12],bitmask[12],relocbit,ch[72],name[6];
int start,inp,len,i,address,opcode,addr,actualadd;
FILE *fp1,*fp2;
  printf("\n the content of the Input fiel:\n\n");
  // fp2=fopen("inputRelLoader.txt","r");

  // ch=fgetc(fp2);
  // while(ch!=EOF)
  //   {
  //     printf("%c",ch);
  //     ch=
  //   }
// fscanf(fp2,"%s",)

  printf("\n\n Enter the actual starting address:");
  scanf("%d",&start);
  fp1=fopen("inputRecl.txt","r");
  printf("\n\n Program loaded in memeory\n");
  printf("\n\nADDRESS\tOBJECT CODE\n");
  fscanf(fp1,"%s",input);
   printf("%s",input);
  
  while(strcmp(input,"E")!=0)
    {
      if(strcmp(input,"H")==0)
      {
        fscanf(fp1,"%s",name);
        fscanf(fp1,"%s",add);
        fscanf(fp1,"%s",length);
        fscanf(fp1,"%s",input);
        printf("name:%s,add:%s,lenght:%s,input:%s\n\n",name,add,length,input);
      }
      if(strcmp(input,"T")==0)
      {
        fscanf(fp1,"%d",&address);
        fscanf(fp1,"%s",bitmask);
        address+=start;
        len=strlen(bitmask);
        for(int i=0;i<len;i++)
          {
             fscanf(fp1,"%d",&opcode);
            addr=opcode%10000;
            opcode=opcode/10000;
            relocbit=bitmask[i];
            if(relocbit=='0')
              actualadd=addr;
            else
              actualadd=addr+start;
            printf("%d\t\t%d%d\n",address,opcode,actualadd);
          address+=3;    
          }
     }
      fscanf(fp1,"%s",input);
    }
  fclose(fp1);
  return 0;
  
}