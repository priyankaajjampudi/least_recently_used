#include<stdio.h>
int d[10];
int search(int ele,int page[10],int n)
{
	int i,flag=0;
	printf("page frame:");
	for(i=0;i<n;i++)
	printf(" %d ",page[i]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(ele==page[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	return 1;
	else
	return 0;
	
}
int max(int fsize)
{
	int i=0,index=0,m;
	m=d[0];
	for(i=1;i<fsize;i++)
	{
		if(m<d[i])
		{
		m=d[i];
		index=i;
	   }
		
	}
	return index;
	
}
void find( int j,int page[10],int a[100],int fsize, int n)
{
	int i,flag=0,temp,k;
	temp=j;
	printf("temp:%d",temp);
	for(i=0;i<fsize;i++)
	{
	for(k=temp;k>=0;k--)
	{
		if(page[i]==a[k])
		{
			d[i]=temp-k;
			break;
		}
	}
	}
	
}
int main()
{
	int a[100],n,page[10],fsize,i,c=0,j=0,k,check,pagefaults=0,l;
	printf("enter nof of requests and frame size");
	scanf("%d%d",&n,&fsize);
	printf("enter request ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<fsize;i++)
	{
		page[j]=a[i];
		j++;
	}
	printf("%d",i);
	for(k=i;k<n;k++)
	{
		find(k,page,a,fsize,n);
		l=max(fsize);
		check=search(a[k],page,fsize);
		if(check!=1)
		{
		 pagefaults++;
		 page[l]=a[k];
		 
	   }
	}
	printf("%d",pagefaults+fsize);
}

