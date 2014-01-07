#include<stdio.h>

#include<string.h>

int main ()
{

  int j = 0;

  char *str[5];

  char text1[100], text2[100];

  printf ("\n enter the text \n");

  scanf ("%s", text1);

  str[0] = text1;

  printf ("\n enter the text \n");

  scanf ("%s", text2);

  str[1] = text2;

  printf ("\n the text is %s\n", str[0]);

  printf ("\n the text is %s\n", str[1]);

  return 0;

}
