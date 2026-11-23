#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Double_Window.H>

int main()
{
	Fl::screen_count();
	Fl::screen_scale(0, 1.25f);

	Fl_Double_Window window(240, 80);
	window.color(FL_WHITE);
	Fl_Box box(20, 19, 200, 42);
	box.box(FL_FLAT_BOX);
	box.color(FL_BLACK);
	window.end();

	window.show();

	Fl::add_timeout(
		1,
		[](void* p) {
			auto* box = static_cast<Fl_Box*>(p);
			box->color(FL_WHITE);
			box->redraw();
		},
		&box);

	return Fl::run();
}
