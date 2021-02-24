#include "Simple_window.h"
#include "Graph.h"

//g++ week02-drill.cpp Graph.cpp Window.cpp Gui.cpp Simple_window.cpp -o week02-drill `fltk-config --ldflags --use-images`

int main()
{
	using namespace Graph_lib;

	Simple_window win(Point{100,100},600,400,"My Window");
	//2
	Axis xa(Axis::x,Point{20,310},270,10,"x axis");
	win.attach(xa);
	win.set_label("Canvas #2");
	win.wait_for_button();
	//3
	Axis ya(Axis::y,Point{20,310},270,10,"y axis");
	ya.set_color(Color::blue);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button();
	//4
	Function sine(sin,0,100,Point{20,150},1000,50,50);
	sine.set_color(Color::green);
	win.attach(sine);
	win.set_label("Canvas #4");
	win.wait_for_button();
	//5
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dot);
	win.attach(poly);
	win.set_label("Canvas #5");
	win.wait_for_button();
	//6
	Rectangle r(Point{250,250},100,50);
	Closed_polyline polyrect;
	polyrect.add(Point{100,50});
	polyrect.add(Point{200,50});
	polyrect.add(Point{200,100});
	polyrect.add(Point{100,100});
	polyrect.add(Point{50,75});
	win.attach(r);
	win.set_label("Canvas #6");
	win.wait_for_button();
	win.attach(polyrect);
	win.wait_for_button();
	//7
	r.set_fill_color(Color::magenta);
	poly.set_style(Line_style(Line_style::dash,4));
	polyrect.set_style(Line_style(Line_style::dash,2));
	polyrect.set_fill_color(Color::dark_green);
	win.set_label("Canvas #7");
	win.wait_for_button();
	//8
	Text t(Point{150,150},"Hello, graphical world!");
	win.attach(t);
	win.set_label("Canvas #8");
	win.wait_for_button();
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Canvas #9");
	win.wait_for_button();
	//9
	Image ii(Point{100,80},"image.jpg");
	win.attach(ii);
	win.set_label("Canvas #10");
	win.wait_for_button();
	ii.move(100,200);
	win.set_label("Canvas #11");
	win.wait_for_button();
}