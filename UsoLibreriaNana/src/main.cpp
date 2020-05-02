/*#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

int main()
{
	using namespace nana;

	//Define a form.
	form fm;

	//Define a label and display a text.
	label lab{ fm, "Hello, <bold blue size=16>Nana C++ Library</>" };
	lab.format(true);

	//Define a button and answer the click event.
	button btn{ fm, "Quit" };
	btn.events().click([&fm] 
	{
		fm.close();
	});

	//Layout management
	fm.div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
	fm["text"] << lab;
	fm["button"] << btn;
	fm.collocate();

	//Show the form
	fm.show();

	//Start to event loop process, it blocks until the form is closed.
	exec();
}*/

// ---------------------------------------------------------------------

#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

int main()
{
	using namespace nana;

	form fm;
	fm.caption("Calculator");

	fm.div("vert<proc weight=10%><result weight=15%>"
		"<weight=2>"
		"<keys margin=2 grid=[4, 5] gap=2 collapse(0,4,2,1)>");

	label procedure(fm, "(1 + 7) X 9 +"), result(fm, "72");

	//Make the label right aligned.
	procedure.text_align(align::right);
	result.text_align(align::right);
	result.typeface(paint::font("", 14, true));

	fm["proc"] << procedure;
	fm["result"] << result;

	std::vector<std::unique_ptr<button>> keys;

	paint::font keyfont("", 10, true);

	wchar_t keys_char[] = L"C\261%/789X456-123+0.=";
	for (auto kchar : keys_char)
	{
		keys.emplace_back(std::make_unique<button>(fm,
			to_utf8(std::wstring(1, kchar))));	//C++14
		auto& key = *keys.back();
		key.typeface(keyfont);

		if ('=' == kchar)
		{
			key.bgcolor(color_rgb(0x7ACC));
			key.fgcolor(colors::white);
		}
		fm["keys"] << key;
	}

	fm.collocate();
	fm.show();
	exec();
}