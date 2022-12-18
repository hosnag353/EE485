#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
long int StrToLong(const char *nptr, char **endptr, int base)
{
  /* handle only when base is 10 */
  if (base != 10) return 0;

  /* TODO: fill this function */
  int temp=0;
  long int x=0;
  int checkMinus=0;
  int checkOverflow=0;
  int checkUnderflow=0;

  while(*nptr&&isspace(*nptr)){
    nptr++;
  }
  if (*nptr=='-'){
    checkMinus++;
    nptr++;
  }
  if(checkMinus){
    while(*nptr&&isdigit(*nptr)){
    temp=*nptr-'0';
    if(((LONG_MIN/10)>x)||(((LONG_MAX/10)==x)&&(temp>8))){
      checkUnderflow++;
    }
    x=10*x-temp;
    nptr++;
    }
    if(checkUnderflow){
      x=LONG_MIN;
    }
  }
  else{
    while(*nptr&&isdigit(*nptr)){
    temp=*nptr-'0';
    if((LONG_MAX/10<x)||((LONG_MAX/10==x)&&(temp>7))){
      checkOverflow++;
    }
    x=10*x+temp;
    nptr++;
    }
    if(checkOverflow){
      x=LONG_MAX;
    }
  }
  *endptr=(char*)nptr;
  return x;
}
/*void inc(){
	static int sum;
	i=1;
	sum++;
	sum=0;
	printf("%d\n", sum);
}*/
int main(void){
//	inc();
//	inc();
	char *date2= "June 14";
	date2++;
	printf("%s \n", date2);
	char date1[8]="June14";
	//date1++;
//	printf("%d \n", i);
	int N=3;
	int a[3]={};
	//printf("%d", a[2]);
	char b[]="2022";
  	char *stop1, *stop2;
	long int result11;
  	long int result12;
	result11=strtol(b,&stop1,10);
	result12=StrToLong(b,&stop2,10);
	printf("%ld,%s\n", result11, stop1);
	printf("%ld,%s\n",result12, stop2);
	
	return 0;
	
	
	
}