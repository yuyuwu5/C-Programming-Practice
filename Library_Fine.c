#include<stdio.h>

#ifndef BOOK_H
#define BOOK_H
 
enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK};
 
struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};
 
#endif
#ifndef DATE_H
#define DATE_H
 
struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};
 
#endif
int count_binary(int a)
{
	int g[2];
    int countnum = 0;
    for(int i = 0; i < 32; i++){
        if(a & ((unsigned int)1 << i)){
            g[countnum] = i;
            countnum++;
        }
        if(countnum == 2){
            break;
        }
    }
    int z = g[1] - g[0] - 1;
    return z;
} 
int leap_year(int a)
{
  if((a%4==0 && a%100!=0) || a%400==0)
    return 1;
  return 0;
}
int calendar(int month,int if_leap)
{
  if(month==1)
    return 31;
  if(month==2 && if_leap)
    return 29;
  if(month==2 && !if_leap)
    return 28;
  if(month==3)
    return 31;
  if(month==4)
    return 30;
  if(month==5)
    return 31;
  if(month==6)
    return 30;
  if(month==7)
    return 31;
  if(month==8)
    return 31;
  if(month==9)
    return 30;
  if(month==10)
    return 31;
  if(month==11)
    return 30;
  if(month==12)
    return 31;
}
int day_count(struct Date start,struct Date end)
{
  int day=0;
  if(end.year-start.year==0){
    int if_Leap=leap_year(start.year);
    if(end.month-start.month==0){
      day=end.day-start.day+1;
    }else{
      int temp=0;
      for(int i = start.month+1; i < end.month; i++){
        //printf("aaaaaaaaa\n");
        temp += calendar(i,if_Leap);
      }
      day=calendar(start.month,if_Leap)-start.day+1+end.day+temp;
    }
  }else{
    int if_Leap1=leap_year(start.year);
    int if_Leap2=leap_year(end.year);
    int temp=0;
    for(int i = start.month+1; i <=12; i++)
      temp += calendar(i,if_Leap1);
    for(int i = 1; i < end.month; i++)
      temp += calendar(i,if_Leap2);
    for(int i = start.year+1; i < end.year; i++){
      if(leap_year(i))
        temp+=366;
      else
        temp+=365;
    }
    day=calendar(start.month,if_Leap1)-start.day+1+end.day+temp;
  }
  return day;
}
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
	char d[10];
	int fine_base=count_binary(book.importance);
	int available_time;
	if(book.type==0)
		available_time=90;
	if(book.type==1)
		available_time=10;
	if(book.type==2)
		available_time=100;
	if(book.type==3)
		available_time=5;
	int x=day_count(date_borrowed,date_returned);
	return (x-available_time)>0? (x-available_time)*fine_base : 0;

}
 
int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 2007;
    date_borrowed.month = 11;
    date_borrowed.day   = 14;
    date_returned.year  = 2007;
    date_returned.month = 12;
    date_returned.day   = 3;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
}