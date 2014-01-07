#include<stdio.h>

#include<stdlib.h>

#include<sys/types.h>

#include<unistd.h>

#include<string.h>


int flag;



void print(char ** cmd)
{

	
	
	
	{
			printf("%s\n",cmd[0]);
			
			printf("\n");
	}
}

int check_builtin(char **cmd)
{

	//print(cmd);  
	    
	if(!strcmp(cmd[0],"ver") ||!strcmp(cmd[0],"echo") || !strcmp(cmd[0],"path") || !strcmp(cmd[0],"exit"))

	return 1;

	else

	return 0;

}


void execute(char **cmd)

{

		int pid,built,i=0;
        
		//n=strlen(*cmd);

           	built=check_builtin(cmd);

		if(built==0)

		{
			pid=fork();
			
			if(flag==0)
			
			{
		    
				if(pid==0 )

				{
				
				printf("%s\n",*cmd);
		
				execvp(*cmd,cmd);
		
	  			printf("execute failed\n");
				}

				else

				wait();
				
			}
			
			else
			
			{
			
			if(pid==0 )

				{
		
		
				execvp(*cmd,cmd);
		
	  			printf("execute failed\n");
				}

			}
                      
              }
	else

		{

		if(!strcmp(cmd[0],"echo"))

			printf("%s\n",cmd[1]);
		else

		if(!strcmp(cmd[0],"ver"))

			printf("\n the version is 1.6.9.0\n");

		else

		if(!strcmp(cmd[0],"exit"))

			exit(0);

		else 
		  if(!strcmp(cmd[0],"path"))

			printf("\n /bin");
	
		else 
		   if(!strcmp(cmd[0],"help"))

			{

				printf("\n Echo .........print the messag eon the screen");

				printf("\n ver...........display the version of the kernel");

				printf("\n path .........Display the path ");

			}

		}		





}


void parse(char *input,char **cmds)

{
   int i=0,j=0,k=0;
   
   int spcount=0;
   
  char str[100];
  
  char * ptr;

   while(*input)

     {
	 
	if(*(input)==' ' || *(input)=='\t' || *(input)=='\n')

	     {
                  
          	
          	spcount++;
          	
          	if(spcount==1)
          	
          	{	
          	
          		str[k]='\0';
          	   	
          		ptr=(char *) malloc(sizeof(char)*k);
          	
          		strcpy(ptr,str);
          
         		cmds[j]=ptr;
         	
         		while(str[i])
         	
         		str[i++]='\0';
         	
                 
         		 k=0;
          
         		 j++; 	 	 	 
    
	 	 }
	 }
	  
	 else
	 {
	  
	  str[k]=*input;
	  
	  k=k+1;
	 }
	  				
	  input++; 

     }
     
  
  str[k]='\0';
     
   ptr=(char *) malloc(sizeof(char)*k);
          	
	strcpy(ptr,str);
          
    cmds[j]=ptr;
    
    if(strcmp(ptr,"&")==0)
    
    {
    
    	cmds[j]=NULL;
    
    flag=1;
    
    }
         	
   //printf("%p\n",ptr);
    
}


int main()

{

	int i=0;
	char input[100],ch;

	FILE *fp;

	char *cmd[5]={NULL,NULL,NULL,NULL,NULL};

	char * cmds;


	system("clear");

	fp=fopen("source","r");	


	while(1)

	{
		printf("$");

		//while(fgets(input,10,fp)!=NULL)


		gets(input);       

		parse(input,cmd);


		//print(cmd);



		execute(cmd);

		for(i=0;i<5;i++)

			cmd[i]=NULL;


	} 		
	return 0;

}
   
