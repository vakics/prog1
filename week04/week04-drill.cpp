#include "std_lib_facilities.h"

//1
class B1{
public:
		virtual void vf()
		{
			cout<<"B1::vf"<<endl;
		};
		void f()
		{
			cout<<"B1::f"<<endl;
		};
		//5
		virtual void pvf()=0;
	
};

//2
class D1: public B1
{
public:
	virtual void vf() override
	{
		cout<<"D1::vf"<<endl;
	};
	//4
	void f()
	{
		cout<<"D1::f"<<endl;
	};
};

//6
class D2: public D1
{
public:
	virtual void pvf() override
	{
		cout<<"D2::pvf"<<endl;
	};
};

//7
class B2
{
public:
	virtual void pvf()=0;	
};

class D21: public B2
{
public:
	virtual void pvf() override
	{
		cout<<data<<endl;
	};
private:
	string data="titok";
};

class D22: public B2
{
public:
	virtual void pvf() override
	{
		cout<<num<<endl;
	};
private:
	int num=420;
	
};

void f(B2& b2ref)
{
	b2ref.pvf();
}

int main()
{
	//1
	B1 b1;
	b1.vf();
	b1.f();
	cout<<endl;

	//2
	D1 d1;
	d1.vf();
	d1.f();
	cout<<endl;

	//3
	B1& b1ref=d1;
	b1ref.vf();
	b1ref.f();
	cout<<endl;

	//6
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();
	cout<<endl;

	//7
	D21 d21;
	D22 d22;
	f(d21);
	f(d22);
	return 0;
}