int tongji(char* str,char ch)
{
	int i=0;
	int count=0;
	while(str[i]!='\0')
	{
		if(str[i]==ch)
		{
			count+=1;
		}
		i++;
	}
	return count;
}
void x2d(char* str)
{
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			str[i]-=32;
		}
		i++;
	}
}
int geshu(char* str)
{
	int i=0;
	int num=0;
	while(str[i]!='\0')
	{
		if(str[i]!=' '&&(str[i+1]==' '||str[i+1]=='\0'))
		{
			num+=1;
		}
		i++;
	}
	return num;
}
void str2word(char *str,char *arr[])
{
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]!=' '&&(i==0||str[i-1]=='\0'))
		{
			*arr=str+i;
			arr++;
		}
		if(str[i]==' ')
		{
			str[i]='\0';
		}	
		i++;
	}
}
