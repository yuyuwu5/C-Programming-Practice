#include<stdio.h>
#include<string.h>
struct person {
    unsigned int id;
    char name[32];
};
struct friends {
    unsigned id1;
    unsigned id2;
};
int p,f;
struct person people[10000];
struct friends fri[10000];
int find_id(char name[]){
	for(int i=0;i<p;i++){
		if(strcmp(people[i].name,name)==0){
			return people[i].id;
		}
	}
}void find_friend(int q1,int q2){
	for(int i = 0; i < f; i++){
		if(fri[i].id1==q1&&fri[i].id2==q2||fri[i].id1==q2&&fri[i].id2==q1){
			printf("yes\n");
			return;
		}
	}printf("no\n");
}
int main(){
	FILE *fp=fopen("friends","rb");
	fread(&p,4,1,fp);
	fread(people,sizeof(struct person),p,fp);
	fread(&f,4,1,fp);
	fread(fri,sizeof(struct friends),f,fp);
	char q1[10000],q2[10000];
	while(scanf("%s",q1)!=EOF&&strcmp(q1,"end")!=0){
		scanf("%s",q2);
		find_friend(find_id(q1),find_id(q2));
	}
}
