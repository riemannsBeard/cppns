#include <iostream>
#include "lin1d.h"
#include "nonlin1d.h"
#include "diffusion1d.h"
#include "burgers.h"
#include "arrayops.h"
#include "lin2d.h"
#include "nonlin2d.h"
#include "diffusion2d.h"
#include "burgers2d.h"
#include "laplace2d.h"
#include "poisson2d.h"
#include "cavityns.h"


using namespace std;

int main()
{
    int selection;

    for (;;) {
        cout << "Please select a program (int between 1-12 inclusive): ";
        if ((cin >> selection) && ((selection > 0) && (selection < 13))) {
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
		
		case 5:
		    arrayops();
		break;
		
		case 6:
		    lin2d();
		break;
		
		case 7:
		    nonlin2d();
		break;
		
		case 8:
		    diffusion2d();
		break;
		
		case 9:
		    burgers2d();
		break;
		
		case 10:
		    laplace2d();
		break;
		
		case 11:
		    poisson2d();
		break;
		
		case 12:
		    cavityns();
		break;

                default:
                    cout << "Something went horribly wrong.";
            }

            break;
        } else {
            cout << "Please enter a valid integer betwen 1 and 12 inclusive:"  << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

}
