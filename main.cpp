#include "world.h"
#include "Commentator.h"

int Commentator::height = 0;
int main()
{
	bool isActive = true;
	int control;
	World world(XSIZE, YSIZE);
	while (isActive) {
		control = _getch();
		if (control == 27) isActive = false; 
		if (control == ARROW_DOWN || control == ARROW_LEFT || control == ARROW_RIGHT || control == ARROW_UP || 
				control == SPECIAL_ABILITY || control == SAVE || control == LOAD) {
			world.makeTurn(control, &isActive);
		}
	}
}