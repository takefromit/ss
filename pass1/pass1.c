#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int start,locctr,length;
  char opcode[10],operand[10],label[10],code[10],mnemonic[10];
  FILE *fin,*fopt,*fsym,*fout;
  fin=fopen("input.txt","r");
  fopt=fopen("OPTAB.txt","r");
  fsym=fopen("Symtab.txt","w");
  fout=fopen("output.txt","w");

  fscanf(fin,"%s\t%s\t%s",label,opcode,operand);

  if(strcmp(opcode,"START")==0)
  {
    start=atoi(operand);
    locctr=start;
    fprintf(fout,"\t%s\t%s\t%s\n",label,opcode,operand);
    }
    else
      locctr=0;

  while(strcmp(opcode,"END")!=0)
    {
  printf("%s\t%s\t%s",label,opcode,operand);
      fprintf(fout,"%d\t",locctr);
      if(strcmp(label,"**")!=0)
        fprintf(fsym,"%s\t%d\n",label,locctr);
      fscanf(fopt,"%s\t%s",code,mnemonic);
      while(strcmp(code,"END")!=0)
        {
          if(strcmp(opcode,code)==0)
          {
            locctr+=3;
            break;
          }
          fscanf(fopt,"%s\t%s",code,mnemonic);
        }
      if(strcmp(opcode,"WORD")==0)
        locctr+=3;
      else if(strcmp(opcode,"RESW")==0)
        locctr+=3*(atoi(operand));
      else if(strcmp(opcode,"RESB")==0)
        locctr+=atoi(operand);
      else if(strcmp(opcode,"BYTE")==0)
        ++locctr;
      fprintf(fout,"%s\t%s\t%s\t\n",label,opcode,operand);
      fscanf(fin,"%s\t%s\t%s",label,opcode,operand);
    }
  fprintf(fout,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
  length=locctr-start;
  printf("\nLength of the code:%d\n",length);
  fclose(fin);
    fclose(fopt);
    fclose(fsym);
    fclose(fout);
    
    return 0;

  
}