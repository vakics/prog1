#include "std_lib_facilities.h"

template<typename Iter1,typename Iter2>
Iter2 tcopy(Iter1 f1,Iter1 e1,Iter2 f2)
{
	if(f1==e1)
	{
		cout<<"There is nothing to copy.\n";
		return f2;
	}
	else
	{
		for(Iter1 p=f1;p!=e1;p++)
		{
			*f2++=*p;
			return f2;
		}
	}
}

int main()
{
	array<int,10> a1={0,1,2,3,4,5,6,7,8,9};
	vector<int> v1={0,1,2,3,4,5,6,7,8,9};
	list<int> l1={0,1,2,3,4,5,6,7,8,9};

	array<int,10> a2=a1;
	for(auto& i:a2)
	{
		i=i+2;
	}
	vector<int> v2=v1;
	for(auto& i:v2)
	{
		i=i+3;
	}
	list<int> l2=l1;
	for(auto& i:l2)
	{
		i=i+5;
	}

	tcopy(a2.begin(),a2.end(),v2.begin());
	tcopy(l2.begin(),l2.end(),a2.begin());
	//for(auto i:a2) cout<<i<<endl;

	int to_find=3;
	auto f=find(v2.begin(),v2.end(),to_find);
	if(f==v2.end()) cout<<"Oops! We couldn't find the number you are looking for in the vector.\n";
	else cout<<"Found it! It's in the "<<distance(v2.begin(),f)<<". place in the vector.\n";
	to_find=27;
	auto f2=find(l2.begin(),l2.end(),to_find);
	if(f2==l2.end()) cout<<"Oops! We couldn't find the number you are looking for in the list.\n";
	else cout<<"Found it! It's in the "<<distance(l2.begin(),f2)<<". place in the list.\n";
	return 0;
}