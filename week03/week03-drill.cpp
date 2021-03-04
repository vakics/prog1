#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	//1
	Simple_window win(Point(100,100),800,1000,"Canvas #1");
	win.wait_for_button();
	//2
	Vector_ref<Rectangle> grid;
	win.set_label("Canvas #2");
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			grid.push_back(new Rectangle(Point(i*100,j*100),100,100));
			win.attach(grid[grid.size()-1]);
		}
	}
	win.wait_for_button();
	//3
	win.set_label("Canvas #3");
	Vector_ref<Rectangle> piros_atlo;
	for(int i=0;i<8;i++)
	{
		piros_atlo.push_back(new Rectangle(Point(i*100,i*100),100,100));
		piros_atlo[i].set_fill_color(Color::red);
		win.attach(piros_atlo[i]);
	}
	win.wait_for_button();
	//4
	win.set_label("Canvas #4");
	Image nagy1(Point(0,200),"hamster.jpg");
	Image nagy2(Point(0,400),"hamster.jpg");
	Image nagy3(Point(200,400),"hamster.jpg");
	win.attach(nagy1);
	win.attach(nagy2);
	win.attach(nagy3);
	win.wait_for_button();
	//5
	win.set_label("Canvas #5");
	Image kicsi(Point{100,0},"hamster.jpg");
	kicsi.set_mask(Point{50,50},100,100);
	win.attach(kicsi);
	for(int i=0;i<8;i++)
	{
		win.wait_for_button();
		if(i%2==0) kicsi.move(400,200);
		else kicsi.move(600,400);
	}
	win.wait_for_button();
}