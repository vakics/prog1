#include "GUI.h"
#include "Lines_window.h"

int main()
{
	Lines_window win(Point{100,100},600,400,"lines");
	return gui_main();
}