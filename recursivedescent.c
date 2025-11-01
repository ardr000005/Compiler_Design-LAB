#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCESS 1
#define FAILURE 0

int E();
int Edash();
int T();
int Tdash();
int F();
int N();

char *cursor;
char string[100];

int main()
{
  printf("Enter the String to Parse\n");
  scanf("%s",string);
  
  cursor = string;
  if(E() && *cursor == '\0')
  { 
     printf("String Parsed Sucessfully\n");
  }
  else
  {
     printf("String cant be parsed\n");
  }
  return 0;
}

int E()
{
  printf("String in %s E -> TE'\n",cursor);
  if(T())
  {
   if(Edash())
   return SUCESS;
  }
  return FAILURE;
}

int Edash()
{
 if(*cursor == '+')
 {
  cursor++;
  printf("String in %s E' -> +TE'\n",cursor);
  if(T())
  {
   if(Edash())
   return SUCESS;
  }
  return FAILURE;
 }
 printf("String in %s E' -> €'\n",cursor);
 return SUCESS;
}

int T()
{
printf("String in %s T -> FT'\n",cursor);
 if(F())
 {
  if(Tdash())
  return SUCESS;
 }
 return FAILURE;
}

int Tdash()
{
 if(*cursor == '*')
 {
  cursor++;
  printf("String in %s T' -> *FT'\n",cursor);
  if(F())
  {
   if(Tdash())
   return SUCESS;
  }
  return FAILURE;
 }
 printf("String in %s T' -> €'\n",cursor);
 return SUCESS;
}

int F()
{
if(*cursor == '(')
 {
  cursor++;
  printf("String in %s F -> (E)\n",cursor);
  if(E())
  {
  if(*cursor == ')')
  {
  cursor++;
  return SUCESS;
  }
  }
  return FAILURE;
}
else
{
 printf("String in %s F -> N\n",cursor);
 return N();
 }
}

int N()
{
  if(*cursor>='a' && *cursor <= 'z')
  {
    printf("String in %s N -> %c\n",cursor,*cursor);
    cursor++;
    return SUCESS;
  }
  return FAILURE;
}