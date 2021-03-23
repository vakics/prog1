#include "Graph.h"
#include "GUI.h"
#include "Lines_window.h"

Lines_window::Lines_window(Point xy,int w,int h,const string& title)
:Window{xy,w,h,title},
next_button{Point{x_max()-150,0},70,20,"Next point",
[](Address,Address pw){reference_to<Lines_window>(pw).next();}},
quit_button{Point{x_max()-70,0},70,20,"Quit",
[](Address,Address pw){reference_to<Lines_window>(pw).quit();}},
next_x{Point{x_max()-310,0},50,20,"next x:"},
next_y{Point{x_max()-210,0},50,20,"next y:"},
xy_out{Point{100,0},100,20,"current (x,y):"},
color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
color_button{Point{x_max()-80,30},"color menu",
[](Address,Address pw){reference_to<Lines_window>(pw).cmenu_pressed();}},
style_menu(Point{x_max()-70,120},70,20,Menu::vertical,"style"),
style_button{Point{x_max()-80,50},"style menu",
[](Address,Address pw){reference_to<Lines_window>(pw).smenu_pressed();}}

{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	attach(lines);
	color_menu.attach(new Button{Point{0,0},0,0,"red",
	[](Address,Address pw){reference_to<Lines_window>(pw).red_pressed();}});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",
	[](Address,Address pw){reference_to<Lines_window>(pw).blue_pressed();}});
	color_menu.attach(new Button{Point{0,0},0,0,"black",
	[](Address,Address pw){reference_to<Lines_window>(pw).black_pressed();}});
	attach(color_menu);
	color_menu.hide();
	attach(color_button);
	style_menu.attach(new Button{Point{0,0},0,0,"dash",
	[](Address,Address pw){reference_to<Lines_window>(pw).dash_pressed();}});
	style_menu.attach(new Button{Point{0,0},0,0,"dot",
	[](Address,Address pw){reference_to<Lines_window>(pw).dot_pressed();}});
	style_menu.attach(new Button{Point{0,0},0,0,"solid",
	[](Address,Address pw){reference_to<Lines_window>(pw).solid_pressed();}});
	attach(style_menu);
	style_menu.hide();
	attach(style_button);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x=next_x.get_int();
	int y=next_y.get_int();
	lines.add(Point{x,y});

	ostringstream ss;
	ss<<'('<<x<<':'<<y<<')';
	xy_out.put(ss.str());
	redraw();
}

void Lines_window::color_change(Color c)
{
	lines.set_color(c);
}

void Lines_window::red_pressed()
{
	color_change(Color::red);
	color_menu.hide();
	color_button.show();
	redraw();
}

void Lines_window::blue_pressed()
{
	color_change(Color::blue);
	color_menu.hide();
	color_button.show();
	redraw();
}

void Lines_window::cmenu_pressed()
{
	color_button.hide();
	color_menu.show();
}

void Lines_window::black_pressed()
{
	color_change(Color::black);
	color_menu.hide();
	color_button.show();
	redraw();
}

void Lines_window::smenu_pressed()
{
	style_button.hide();
	style_menu.show();
}

void Lines_window::style_change(Line_style s)
{
	lines.set_style(s);
}

void Lines_window::dash_pressed()
{
	style_change(Line_style::dash);
	style_menu.hide();
	style_button.show();
	redraw();
}

void Lines_window::dot_pressed()
{
	style_change(Line_style::dot);
	style_menu.hide();
	style_button.show();
	redraw();
}

void Lines_window::solid_pressed()
{
	style_change(Line_style::solid);
	style_menu.hide();
	style_button.show();
	redraw();
}