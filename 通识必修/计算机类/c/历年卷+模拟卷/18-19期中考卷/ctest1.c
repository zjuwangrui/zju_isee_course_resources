 #include <stdio.h>
 int main ()
 {
 	int i=0,num=0,voc=0,k=0,j=0;
 	char c[1000],d[1000];
 	do 
 	{
 		c[i]=getchar();
 		if ('c[i]'>=48&&'c[i]'<=57)
 			num++;
 		if ('c[i]'>=97&&'c[i]'<=122)
		 {
 			voc++; 
			d[j]=c[i];
			j++;
		 }
 		if ('c[i]'>=65&&'c[i]'<=90)
		 {
 			voc++; 
			d[j]=c[i];
			j++;
		 }	
	}while ('c'!=35);
	
	printf("%d %d\n",voc,num);
	
	for(k=0;k<=j;k++)
	{
		printf("%c",d[k]);
	}
 	
 }
