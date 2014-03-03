#include <iostream>
#include "lin1d.h"
#include "nonlin1d.h"
#include "diffusion1d.h"
#include "burgers.h"

using namespace std;

int main()
{
    int selection;

    for (;;) {
        cout << "Please select a program (int between 1-4 inclusive): ";
        if ((cin >> selection) && (selection > 0) && (selection < 5)) {
            switch (selection) {
                case 1:
                    lin1d();
                break;

                case 2:
                    nonlin1d();
                break;

                case 3:
                    diffusion1d();
                break;
		
		case 4:
		    burgers();
		break;

                default:
                    cout << "Something went horribly wrong.";
            }

            break;
        } else {
            cout << "Please enter a valid integer betwen 1 and 4 inclusive:"  << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

}
