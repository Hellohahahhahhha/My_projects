#include<iostream>
#include<string>
using namespace std;

void t(int &a,int &b){int c=a;a=b;b=c;}

struct student
{
	string namee;
	int name;
	string school;
	float fsl;
};

void B_sort(int* arr,int size)
{
	int idx;
	do
	{
		idx=0;
		size--;//                 4  1  3  2  7 
		for(int j=0;j<size;j++)// 1  2  3  4  7             3,1,
		{
			if(arr[j]>arr[j+1])
			{
				idx++;
				t(arr[j],arr[j+1]);
				if(arr[j]<arr[j-1])idx++;//whether arr[j-1] greater than arr[j] (sorted)
			}
		}
		cout<<idx<<endl;
	}while(idx>1);
}

void F_sort(int* arr,int _b,int _e)// 2  3  1  4                    5  9  6  7  8 
{//                                          b                    m  e              
	int b=_b,e=_e;
	if(e-b==0)return;
	int m=(b+e)/2;
	while(e-b>0)
	{
		while(arr[b]<arr[m] && b<m)
		{
			b++;
		}
		while(arr[e]>arr[m] && e>m)
		{
			e--;
		}
		t(arr[b],arr[e]);
	}
	F_sort(arr,_b,m);
	F_sort(arr,m+1,_e);
}

int main()
{//                                              13  4  55  21  10  54  6  67  44  34 
	int arr[10]={13,4,55,21,10,54,6,67,44,34};// 13  4  34  21  10  6                 44  67  54  55                4,2,1,end
	for(int i=0;i<10;i++)//                      b       m          e                                   
	{
		printf("%d ",arr[i]);
	}
	cout<<endl;
	F_sort(arr,0,sizeof(arr)/sizeof(int)-1);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

/*
int main()
{
	string ss="???";
	char s[10]="123456789";
	return 0;
}
*/


/*
if(arr[b]>arr[m] && arr[e]<arr[m])
		{
			t(arr[b],arr[e]);
			b++;
			e--;
		}
		else if(arr[b]<arr[m])
		{
			b++;
		}
		else if(arr[e]>arr[m])
		{
			e--;
		}
		*/




/*
int main()
{//                                              13  4  55  21  10 
	int arr[10]={13,4,55,21,10,54,6,67,44,34};// 4  10  13  21  55                4,2,1,end
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	cout<<endl;
	B_sort(arr,sizeof(arr)/sizeof(int));
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}*/
