#include <stdio.h>
#include <string.h>
#include "files.h"
/*finding the plagarism percentage*/
int lcs(char *a,char *b)
{
	int n=strlen(a)+strlen(b);
	int c,cmax=0,temp;
	for (int i = 0; i < strlen(a); ++i)
	{
		c=0;
		temp=i;
		for (int j = 0; j < strlen(b); ++j)
		{
			if (a[temp]==b[j])
			{
				while (((temp<(strlen(a))) && (j<(strlen(b)))) && (a[temp]==b[j]))
				{
					printf("%c %c\n",a[temp],b[j] );
					c+=sizeof(a[temp]);
					temp+=1;
					j+=1;
				}
			}
			if(c>cmax)
			{
				cmax=c;
			}
			
		}
	}
	float percent=((cmax)*200)/n;
	return percent;
}
int rmandcon(char s[],char s1[])
{
	char s2[50]={'\0'};
	char s3[50]={'\0'};
	/*removing special characters*/
	char *p=strtok(s," ");
	while (p != NULL)
	{
		strcat(s2,p);
		p = strtok(NULL," ");
	}
	//printf("%s\n",s2 );
	char *p1=strtok(s1," ");
	while (p1 != NULL)
	{
	 	strcat(s3,p1);
	    p1 = strtok(NULL," ");
	}
	//printf("%s\n",s3 );
	/*converting into lower case*/
	strlwr(s2);
	strlwr(s3);
	return (lcs(s2,s3));
}

int main()
{
	long long int i=0,j=0;
	char files[100][100];
	double res[100][100];
	long long int len=openfile(files);
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
	    {
	    	char s[1000];
		    FILE *fp;
	        fp = fopen(files[i],"r");
	        fgets(s,1000,fp);
	        printf("%s\n",s );
	        long l=ftell(fp);
	        long n=strlen(s);
            char s1[10000];
		    FILE *fp2=fopen(files[j],"r");
		    fgets(s1,1000,(FILE*)fp2);
		    printf("s:%s\n",s );
		    printf("s1:%s\n",s1 );
		    long l1=ftell(fp2);
		    float plag=rmandcon(s,s1);
		    res[i][j]=plag;
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
        printf("%s    ",files[i]);
        for(j=0;j<len;j++)
        {
       		 printf("	%.2f\t",res[i][j]);
        }
        printf("\n");
	}
	return 0;
}
