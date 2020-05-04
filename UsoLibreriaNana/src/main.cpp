#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

//#include <ScoreControl.h>
#include <Score.h>

using namespace std;
using namespace nana;
using namespace API;

int main()
{
	const int max = 10;

	//Define a form.
	form window(make_center(400, 500), appearance());
	window.caption(L"High Score - Nana");

	//Define the HighScore library
	HighScore* scores[max];

	scores[0] = new HighScore("TOM", 100);
	scores[1] = new HighScore("FRA", 90);
	scores[2] = new HighScore("MIG", 80);
	scores[3] = new HighScore("JOS", 70);
	scores[4] = new HighScore("MAT", 60);
	scores[5] = new HighScore("FER", 50);
	scores[6] = new HighScore("SEB", 40);
	scores[7] = new HighScore("HEC", 30);
	scores[8] = new HighScore("AIL", 20);
	scores[9] = new HighScore("MIC", 10);

	//Define a label and display a text.
	label* players[max];
	
	for (int i = 0; i < max; i++) {
		players[i] = NULL;
	}
	
	int yPos = 50;
	
	for (int i = 0; i < max; i++) {
		players[i] = new label(window, rectangle(20, yPos, 150, 30));
		players[i]->format(true);
		yPos += 40;
	}

	label tittle(window, rectangle(125, 10, 200, 35));
	tittle.format(true);
	tittle.caption("<bold blue size=18> High Scores </>");

	//Draw labels
	for (int i = 0; i < max; i++)
	{
		if (i == 9) {
			players[i]->caption("<bold=true size=12>" + to_string(i + 1) + " -  " + scores[i]->getName() + "  -  " + to_string(static_cast<int>(scores[i]->getSco())) + "</>");
		}
		else{
			players[i]->caption("<bold=true size=12>" + to_string(i + 1) + "   -  " + scores[i]->getName() + "  -  " + to_string(static_cast<int>(scores[i]->getSco())) + "</>");
		}
	}

	//Define a button and answer the click event.
	button btn(window, rectangle{ 100, 450, 200, 40 });
	btn.caption(L"Quit");
	btn.events().click(API::exit);

	//Show the form
	window.show();

	//Start to event loop process, it blocks until the form is closed.
	exec();

	//delete scores;
	for (int i = 0; i < max; i++) {
		if (scores[i] != NULL)
			delete scores[i];
	}
	for (int i = 0; i < max; i++) {
		if (players[i] != NULL)
			delete players[i];
	}

	return 0;
}