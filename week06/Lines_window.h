#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

struct Lines_window:Graph_lib::Window
{
	Lines_window(Point xy,int w,int h,const string& title);
	Open_polyline lines;
	Menu color_menu;
	Menu style_menu;

private:
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Button color_button;
	Button style_button;

	void next();
	void quit();
	void color_change(Color c);
	void red_pressed();
	void blue_pressed();
	void black_pressed();
	void cmenu_pressed();
	void smenu_pressed();
	void dash_pressed();
	void style_change(Line_style s);
	void dot_pressed();
	void solid_pressed();
};