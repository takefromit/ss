#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
  FILE *fin,*fopt,*flen,*fsym;
  int op1[10],txtlen,txtlen1,i,j=0,len;
  char add[5],symadd[5],op[5],start[10],temp[30],line[20],label[20],opcode[10],operand[10],symbol[10],opmne[10];

  fin=fopen("input.txt","r");
  flen=fopen("length.txt","r");
  fopt=fopen("optab.txt","r");
  fsym=fopen("symtab.txt","r");
  fscanf(fin,"%s\t%s\t%s\t%s",add,label,opcode,operand);

  if(strcmp(opcode,"START")==0)
  {
    strcpy(start,operand);
    fscanf(flen,"%d",&len);
  }
  printf("\nH^%s^%s^%d\nT^00%s^",label,start,len,start);
  fscanf(fin,"%s\t%s\t%s\t%s",add,label,opcode,operand);
while(strcmp(opcode,"END")!=0)
  {
    fscanf(fopt,"%s%s",opmne,op);
    // printf("\nhere add:%s,label:%s,opcode:%s,operand:%s",add,label,opcode,operand);

    while(!feof(fsym))
      {
       // printf("here opcode:%s,opmne:%s",opcode,opmne);
        if(strcmp(opcode,opmne)==0)
        {
          fclose(fopt);
          fscanf(fsym,"%s%s",symadd,symbol);
          while(!feof(fsym))
            {
              if(strcmp(operand,symbol)==0)
              {
                printf("%s%s",op,symadd);
                break;
              }
              else
                fscanf(fsym,"%s%s",symadd,symbol);
            }
          break;
        }
        else
          fscanf(fsym,"%s%s",symadd,symbol);
        //fscanf(fsym,"%s%s",symadd,symbol);
      }
    if((strcmp(opcode,"BYTE")==0)||(strcmp(opcode,"WORD")==0))
    {
      if(strcmp(opcode,"WORD")==0)
        printf("0000%s^",operand);
      else{
        len=strlen(operand);
          for(i=2;i<len;i++)
           printf("%d",operand[i]);
        printf("^");
      }
    }
    fscanf(fin,"%s%s%s%s",add,label,opcode,operand);
    fopt=fopen("optab.txt","r");
    fseek(fopt,SEEK_SET,0);
  }
  printf("\nE^00%s\n",start);
  fclose(fin);
  fclose(fopt);
  fclose(fsym);
  fclose(flen);
  return  0;
}