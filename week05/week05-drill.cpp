#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

//f1
double one (double x) {return 1;}

//f4
double slope(double x) {return x/2;}

//f6
double square(double x) {return x*x;}

//f9
double sloping_cos(double x) {return cos(x)+slope(x);}

//c1
struct Person
{
	//c1,5,9
private:
		string o_firstname;
		string o_secondname;
		int o_age;

public:
		Person(string firstname,string secondname,int age);
		Person(){};

		string get_firstname() const {return o_firstname;}
		string get_secondname()const {return o_secondname;}
		int get_age() const {return o_age;}
		//c7,9
		void set_firstname(string firstname)
		{
			for(int i=0;i<firstname.length();i++)
			{
				if(!isalpha(firstname.at(i))) error("Invalid first name");
			}
			o_firstname=firstname;
		}
		void set_secondname(string secondname)
		{
			for(int i=0;i<secondname.length();i++)
			{
				if(!isalpha(secondname.at(i))) error("Invalid second name");
			}
			o_secondname=secondname;
		}
		void set_age(int age)
		{
			if(age<0 || age>150) error("Age is too big or a negative number");
			else o_age=age;
		}
};

Person::Person(string firstname,string secondname,int age)
{
	set_firstname(firstname);
	set_secondname(secondname);
	set_age(age);
}

//c3,6,9
ostream& operator<<(ostream &o,Person p)
{
	return o<<p.get_firstname()<<" "<<p.get_secondname()<<": "<<p.get_age();
}

istream& operator>>(istream &i, Person &p)
{
	string tmp_firstname;
	string tmp_secondname;
	int tmp_age;
	i>>tmp_firstname>>tmp_secondname>>tmp_age;
	p.set_firstname(tmp_firstname);
	p.set_secondname(tmp_secondname);
	p.set_age(tmp_age);
	return i;
}

int main()
{
	using namespace Graph_lib;

	//graph1
	Simple_window win(Point(100,100),600,600,"Function graphs");
	//win.wait_for_button();

	//graph4
	int xorig=300;
	int yorig=300;
	Axis x(Axis::x,Point{100,yorig},400,400/20,"1==20 pixels");
	Axis y(Axis::y,Point{xorig,400+100},400,400/20,"1==20 pixels");
	win.attach(x);
	win.attach(y);
	//win.wait_for_button();

	//graph5
	x.set_color(Color::red);
	y.set_color(Color::red);
	//win.wait_for_button();

	//f1
	int minrange=-10;
	int maxrange=11;
	Point origo{xorig,yorig};
	Function f_one(one,minrange,maxrange,origo,400);
	win.attach(f_one);
	//win.wait_for_button();

	//f2
	int xscale=20;
	int yscale=20;

	//f4
	Function f_slope(slope,minrange,maxrange,origo,400,xscale,yscale);
	win.attach(f_slope);
	//win.wait_for_button();

	//f5
	Text slope_label(Point{90,390},"x/2");
	win.attach(slope_label);
	//win.wait_for_button();

	//f6
	Function f_square(square,minrange,maxrange,origo,400,xscale,yscale);
	win.attach(f_square);
	//win.wait_for_button();

	//f7
	Function f_cos(cos,minrange,maxrange,origo,400,xscale,yscale);
	win.attach(f_cos);
	//win.wait_for_button();

	//f8
	f_cos.set_color(Color::blue);
	//win.wait_for_button();

	//f9
	Function f_slopingcos(sloping_cos,minrange,maxrange,origo,400,xscale,yscale);
	win.attach(f_slopingcos);
	//win.wait_for_button();

	//c2
	Person goofy;
	cin>>goofy;
	cout<<goofy<<endl;
	
	//c8
	vector<Person> v;
	char quit;
	Person p;
	cout<<"Please enter q to exit!"<<endl;
	while(true)
	{
		cin>>quit;
		if(quit=='q') break;
		else
		{
			cin.putback(quit);
			cin>>p;
			v.push_back(p);
		}
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<v.at(i)<<endl;
	}
}