#include<iostream>
#include<cstdlib>
using namespace std;

class stack
{
	private:
		int *data;
		int size;
		int i;
	public:
		stack();
		stack(int);
		stack(const stack &);
		~stack();
		stack &operator=(stack &);
		stack &operator<<(int);
		friend ostream &operator<<(ostream &,stack &);
};
stack::stack()
{
  	this->size=0;
 	this->data=NULL;
  	this->i=0;  
}
stack::stack(int n)
{
	this->size=n;
	this->data=new int[n];
	this->i=0;
}
stack::stack(const stack &s)
{
	int _i=0;
	this->size=s.size;
	this->i=s.i;
	this->data=new int[s.size];
	for(_i=0;i<size;_i++)
	{
		this->data[_i]=s.data[_i];
	}
}
stack::~stack()
{

}
stack &stack::operator=(stack &s)
{
	this->i=s.i;
	this->size=s.size;
	delete [] this->data;
	this->data=new int[s.size];
	for(i=0;i<s.size;i++)
	{
		this->data[this->i]=s.data[s.i];
	}
	return *this;
}
stack &stack::operator<<(int n)
{
	if(this->i==this->size)
	{
		return *this;
	}
	this->data[this->i]=n;
	i++;
	return *this;
}
ostream &operator<<(ostream &out,stack &n)
{
	if(n.i==0)
	{
		return out;
	}
	n.i--;
	out<<n.data[n.i];
}

int main()
{
	stack s(5);
	s<<1<<2<<3<<4;
	cout<<s<<s<<endl;
  	return 0;  
}
