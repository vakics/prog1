#include "std_lib_facilities.h"
//#include <vector>

template<typename T>
struct S
{
private:
	T val;
public:
	S(T v): val(v) {};
	T get();
	T const get() const;
	void set(T v) { val=v;};
	S operator=(const T&);
	void read_val(T& v);
};

template<typename T>
T const S<T>::get() const
{
	return val;
}

template<typename T>
S<T> S<T>::operator=(const T& s)
{
	val=s;
	return val;
}

template<typename T>
T S<T>::get()
{
	return val;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& vec)
{
	char c=0;
	is>>c;
	if(c!='{')
	{
		is.unget();
		return is;
	}
	for(T val;is>>val;)
	{
		vec.push_back(val);
		is>>c;
		if(c!=',') break;
	}
	return is;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
	os<<"{";
	for(int i=0;i<vec.size();i++)
	{
		if(i<vec.size()-1) os<<vec[i]<<", ";
		else os<<vec[i]<<"}\n";
	}
	return os;
}

template<typename T>
void read_val(T& v)
{
	cin>>v;
}

int main()
{
	int n;
	cout<<"int: ";
	cin>>n;
	S<int> num {n};
	char c;
	cout<<"char: ";
	read_val(c);
	S<char> ch {c};
	double d;
	cout<<"double: ";
	read_val(d);
	S<double> db {d};
	string s;
	cout<<"string: ";
	cin>>s;
	S<string> st {s};
	vector<int> v;
	cout<<"vector: ";
	while(cin>>n) v.push_back(n);
	S<vector<int>> vc {v};
	cout<<endl;

	cout<<"int: "<<num.get()<<endl;
	cout<<"char: "<<ch.get()<<endl;
	cout<<"double: "<<db.get()<<endl;
	cout<<"string: "<<st.get()<<endl;
	cout<<"vector: ";
	for(auto a:vc.get())
	{
		cout<<a<<" ";
	}
	cout<<endl<<endl;

	num.set(54004);
	cout<<"int megváltoztatva: "<<num.get()<<endl;

	st="megváltoztam";
	cout<<"string megváltoztatva: "<<st.get()<<endl;

	return 0;
}