#include<stdio.h>
#include<string.h>
typedef struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
  int sub[32];
  int count_sub;
  int sup[32];
  int count_sup;
}Employee;
Employee a[32];
int n;

int search(int id)
{
	for(int i = 0; i < n; i++)
		if(a[i].id==id)
			return i;
}
int find_name(char c[32],char b[32], Employee a[])
{
	for(int i = 0; i < n; i++){
		//printf("%s\n",a[i].first_name );
		if(strcmp(a[i].first_name,c)==0 && strcmp(a[i].last_name,b)==0)
			return i;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i].id);
		scanf("%s",a[i].first_name);
		scanf("%s",a[i].last_name);
		scanf("%d",&a[i].boss_id);
		a[i].count_sup=0;
		a[i].count_sub=0;
	}
	for(int i = 0; i < n; i++){
		if(a[i].boss_id != a[i].id){
			a[i].sup[a[i].count_sup++]=a[i].boss_id;
			int s=search(a[i].boss_id);
			a[s].sub[a[s].count_sub++]=a[i].id;
		}
	}
	for(int i = 0; i < n; i++){
		if(a[i].count_sub>0 && a[i].count_sup>0){
			for(int j = 0; j < a[i].count_sup; j++){
				int s=search(a[i].sup[j]);
				for(int k = 0; k < a[i].count_sub; k++){
					int t=search(a[i].sub[k]);
					a[s].sub[a[s].count_sub++]=a[i].sub[k];
					a[t].sup[a[t].count_sup++]=a[i].sup[j];
				}
			}
		}
	}
	/*for(int i = 0; i < n; i++){
		printf("%d\n",a[i].id );
		for(int j=0;j<a[i].count_sub;j++)
			printf("%d ",a[i].sub[j]);
		printf("\n");
		for(int j=0;j<a[i].count_sup;j++)
			printf("%d ",a[i].sup[j]);
		printf("\n");
		printf("\n");
	}*/
	
	int request;
	scanf("%d",&request);
	for(int i = 0; i <request;i++){
		char first1[32],first2[32],last1[32],last2[32];
		scanf("%s%s%s%s",first1,last1,first2,last2);
		int t1=find_name(first1,last1,a);
		int t2=find_name(first2,last2,a);
		//printf("%d %d\n",t1,t2);
		int relation=0;
		for(int j = 0; j < a[t1].count_sub && !relation;j++){
			//printf("1\n");
			//printf("%d\n",a[t1].sub[j]);
			//printf("%d\n",a[t2].id);
			if(a[t1].sub[j]==a[t2].id){printf("supervisor\n");relation=1;}
		}
		for(int j = 0; j < a[t1].count_sup && !relation;j++){
			if(a[t1].sup[j]==a[t2].id){printf("subordinate\n");relation=1;}
		}
		for(int j = 0; j < a[t1].count_sup && !relation;j++){
			for(int k=0; k < a[t2].count_sup && !relation;k++){
				if(a[t1].sup[j]==a[t2].sup[k]){printf("colleague\n");relation=1;}
			}
		}
		if(!relation)printf("unrelated\n");
	}
}