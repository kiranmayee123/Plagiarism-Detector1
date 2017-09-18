#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include<math.h>
#include "files.h"/*importing multiple files from files.h header*/
struct freq
{
	char word[50];
	int count;
};
/*to remove the duplicates in an array*/
int	 duplicate(char a[1000][50],int l,struct freq dic[])
{
	//char b[1000][50];
	int i,j,c=0,q=0;
	for(i=0;i<l;i++)
	{	

		int flag=0,count1=0;
		for(j=0;j<i;j++)
		{
			int k;
			k=strcmp(dic[j].word,a[i]);
			if(k==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{	
			int d=0;
			while(d<strlen(a[i]))
			{
			dic[q].word[d]=a[i][d];
			d++;}
			dic[q].word[d]='\0';
			
			
			for(j=0;j<l;j++)
			{	
				if(strcmp(a[i],a[j])==0)
					count1++;
			}
			dic[q].count=count1;
			printf("\nword:%s count:%d",dic[q].word,dic[q].count);
			q++;
		}
			
	}
	return q;
}
/*this function is used to remove spaces and special characters */
int chararray(char s[],char arr[1000][50])
{
	//printf("hi");
	int i=0,k=0,count=0;
	strlwr(s);
	printf("\nstring:%s",s);
	while(i<strlen(s))
	{	int j=0;
		if(s[i]!=' ')
		{
			//printf("\ns[i]:%c",s[i]);
			while(s[i]!=' '&&i<strlen(s))
			{
			//int asc=(int)s[i];
				if(isalpha(s[i])||isdigit(s[i]))
				{
					//printf("%c",s[i]);
					count++;
					arr[k][j]=s[i];
					j++;
					i++;
				}
			}
		arr[k][j]='\0';
		k++;
		
	}
	else
	{
		i++;
	}

	}
	for(int x=0;x<k;x++)
	{
		printf("\n%s   ",arr[x]);
	}
	return k;
}
/*find the count and finding plagarism by using euclidian form*/
float plagcal(struct freq str1[],int len1,struct freq str2[],int len2)
{
	int i,j,count2=0;
	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
			if(strcmp(str1[i].word,str2[j].word)==0)
			{
				count2+=(str1[i].count)*(str2[j].count);
				break;
			}
		}
	}
	printf("\n%d",count2);
	float denom1=0,denom2=0;
	int sum=0;
	for(i=0;i<len1;i++)
	{
		sum=sum+(str1[i].count*str1[i].count);
	}
	denom1=sqrt(sum);
	printf("\n%f",denom1);
	sum=0;
	printf("\n%d",sum);
	for(i=0;i<len2;i++)
	{
		sum=sum+(str2[i].count*str2[i].count);
		printf("\nsum%d",sum);
	}
	printf("\n%d",sum);
	denom2=sqrt(sum);
	printf("\ndenom:%f",denom2);
	double denom=denom1*denom2;
	if(denom==0)
	{
		printf("File is empty");
	}
	else
	{
		double plag=count2*100.0/(denom);
		return plag;
	}
	
}

int main()
{
	
	long long int i=0,j=0;
    char files[100][100];
    long long int len=openfile(files);
    double ans[100][100];
    printf("\nlen:%d",len);
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
    	{
    		char s[10000];
	        FILE *fp;
	        fp = fopen(files[i],"r");
	        fgets(s,1000,(FILE*)fp);
   		    char s1[10000];
		    FILE *fp2;
		    fp2 = fopen(files[j],"r");
		    fgets(s1,1000,(FILE*)fp2);
		    char arr1[1000][50];
			char arr2[1000][50];
			//char a[1000][50];
			long long int k=chararray(s,arr1);
			long long int k1=chararray(s1,arr2);
			//printf("%d\n",k );
			//printf("%d\n",k1 ); 
			struct freq dic1[k],dic2[k1];
			long long int len1=duplicate(arr1,k,dic1);
			//printf("\nlen1:%d",len1);
			long long int len2=duplicate(arr2,k1,dic2);
			//printf("\nlen2:%d",len2);
			float plag=plagcal(dic1,len1,dic2,len2);
			ans[i][j]=plag;
		}
	}
    printf("\n");
    printf("\t   ");
    for(i=0;i<len;i++)
    {
        printf("  %s    ",files[i]);
    }
    printf("\n");
    for(i=0;i<len;i++)
    {
        printf("%s 		",files[i]);
        for(j=0;j<len;j++)
        {
        printf("	%.2f\t",ans[i][j]);
        }
        printf("\n");
	}
	return 0;
}