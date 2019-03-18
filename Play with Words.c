#include<stdio.h>
#include<string.h>
#include<ctype.h>
int determain(char in[])
{
	char a[]="insert",b[]="delete";
	if(strlen(in)==1){
		if(isalpha(in[0])){return 0;} //english word
		if(isdigit(in[0])){return 1;} //number
	}if(strlen(in)==4){  //left
		return 2;
	}if(strlen(in)==5){ //right
		return 3;
	}if(strlen(in)==6){
		if(strcmp(a,in)==0){return 4;} //insert
		if(strcmp(b,in)==0){return 5;} //delete
	}
}
void do_main(int i,char main[],int situation[],char input[], int count)
{
	char copy[100000]={0};
	switch (i){
		case 3:
		if(situation[1]==1){
			for(int j = 0; j <(input[1]-'0') ; j++){
				copy[j]= main[j];
			}
			copy[(input[1]-'0')]=input[2];
			for(int j = (input[1]-'0'); j < count; j++){
				copy[j+1]=main[j];
			}
		}if(situation[1]==4){
			copy[0]=input[2];
			for(int j=0; j < count;j++){
				copy[j+1]=main[j];
			}
		}if(situation[1]==5){
			for(int j = 0;j < count; j++)
				copy[j]=main[j];
			copy[count]=input[2];
		}
		for(int j = 0; j < count; j++)
			main[j]=0;
		count++;
		for(int j = 0; j < count; j++)
			main[j]=copy[j];
		break;

		case 2:
		if(situation[1] == 1){
			for(int j = 0; j < (input[1]-'0'); j++)
				copy[j]= main[j];
			for(int j=(input[1]-'0')+1;j < count;j++)
				copy[j-1]=main[j];
		}if(situation[1]==4){
			for(int j = 1; j < count; j++)
				copy[j-1]=main[j];
		}if(situation[1]==5){
			for(int j = 0; j < count-1; j++)
				copy[j]=main[j];
		}
		for(int j = 0; j < count; j++)
			main[j]=0;
		count--;
		for(int j = 0; j < count; j++)
			main[j]=copy[j];
		break;
	}
	return;

}
int main(void)
{
	char print_what[28], number[100];
	char main[100000]={0}, input[5][15];
	int i = 0, situation[5],count=0;
	while(scanf("%s",input[i])!=EOF){
            for(int j = 0; j < count;j++)
             printf("%c",main[j]);

		situation[i]=determain(input[i]);
     printf("%d\n",situation[i]);
		if(i>0){
			if(situation[i]==4 || situation[i]==5){
                    printf("%d\n",i);
				do_main(i,main,situation,input[i],count);
				situation[0]=situation[i];
				i = 1;
				continue;
			}
		}
		i++;
	}
}
