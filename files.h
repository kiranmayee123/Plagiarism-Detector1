#include<stdio.h>
#include<dirent.h>
#include<string.h>
int openfile(char files[100][100])
{
	char s[100];
	printf("enter the path");
	scanf("%[^\n]",s);
	chdir(s);
	int i=0;
	DIR *d;
	int j;
	//i=0;
	struct dirent *dir;
	d=opendir(s);
	{
	while((dir=readdir(d))!=NULL)
	{
	int k=strlen(dir->d_name);
	if(dir->d_name[k-1]=='t'&&dir->d_name[k-2]=='x'&&dir->d_name[k-3]=='t')
	{
		j=0;
		while(j<k)
		{
			files[i][j]=dir->d_name[j];
			j++;
		}
		i++;
	}
	}
	closedir(d);
	}
	return i;

}