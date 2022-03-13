#include <bits/stdc++.h>

using namespace std;

int cid = 1;

class CSet
{
	
public:
	int n,*data,rn;
	int id;
	
public:
	CSet(int n)
	{
		this->id=cid++;
		printf("create: %d\n", this->id);
		this->n=n;
		data=new int[n];
	}
	~CSet()
	{
		printf("delete: %d,%d ", this->id, this->data);
		this->display(); 
		//delete [] data;
	}
	void ini()
	{
		for(int i=0;i<n;i++)
		{
			cin>>data[i];
			//printf("read: %d\n",data[i]);
		}
		rn=n;
		//this->display();
	}
	void display()
	{
		for(int i=0;i<rn-1;i++)
			printf("%d ",data[i]);
		printf("%d\n",data[rn-1]);
	}
	
	CSet operator+(const CSet &s2)
	{
		CSet tmp(this->rn+s2.rn);
		for(int i=0;i<this->rn;i++)
			tmp.data[i]=this->data[i];
		int cnt=this->rn;
		for(int i=0;i<s2.rn;i++)
		{
			bool fl=0;
			for(int j=0;j<this->rn;j++)
				if(s2.data[i]==this->data[j])
					fl=1;
			if(!fl)
				tmp.data[cnt++]=s2.data[i];
		}
		tmp.rn=cnt;
		printf("tmp data: %d, tmp addr: %d\n",tmp.data, &tmp);
		return tmp;
	}
//	CSet operator-(CSet &s1,CSet &s2)
//	{
//		CSet tmp(s1.n);
//		int cnt=0;
//		for(int i=0;i<s1.n;i++)
//		{
//			bool fl=0;
//			for(int j=0;j<s2.n;j++)
//				if(s2.data[j]==s1.data[i])
//					fl=1;
//			if(!fl)
//				tmp.data[cnt++]=s1.data[i];
//		}
//		tmp.rn=cnt;
//		return tmp;
//	}
//	CSet operator*(CSet &s1,CSet &s2)
//	{
//		CSet tmp(min(s1.n,s2.n));
//		int cnt=0;
//		for(int i=0;i<s1.n;i++)
//		{
//			bool fl=0;
//			for(int j=0;j<s2.n;j++)
//				if(s2.data[j]==s1.data[i])
//					fl=1;
//			if(fl)
//				tmp.data[cnt++]=s1.data[i];
//		}
//		tmp.rn=cnt;
//		return tmp;
//	}
};

int main()
{
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		CSet A(tmp);
		A.ini();
		cin>>tmp;
		CSet B(tmp);
		B.ini();
		printf("A:");A.display();
		printf("B:");B.display();
		CSet C = (A+B);
		printf("C data: %d, C addr: %d\n",C.data, &C);
		printf("A+B:");C.display();
//		printf("A*B:");(A*B).display();
//		printf("(A-B)+(B-A):");((A-B)+(B-A)).display();
		printf("\n");
	}
	printf("end");
	return 0;
} 
















