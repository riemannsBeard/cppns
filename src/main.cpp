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
#include "channelns.h"


using namespace std;

int main()
{
    int selection;

    for (;;) {
        cout << "Please select a program (number between 1-13 inclusive) or 99 for help: ";
        if ((cin >> selection) && (((selection > 0) && (selection < 14)))||(selection == 99)) {
	  
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
		
		case 13:
		    channelns();
		break;
		
		case 99:
		    std::cout << "1: Step1 Linear 1D \t2: Step2 Nonlinear 1D \t3: Step3 Diffusion 1D";
		    std::cout << "\n4: Step4 Burgers 1D \t5: ArrayOps Test \t6: Step5 Linear 2D";
		    std::cout << "\n7: Step6 Nonlinear 2D \t8: Step7 Diffusion 2D \t9: Step8 Burgers 2D";
		    std::cout << "\n10: Step9 Laplace 2D \t11: Step10 Poisson 2D \t12: Step11 Cavity Flow";
		    std::cout << "\n13: Step12 Channel Flow" << std::endl;
		break;

                default:
                    cout << "Something went horribly wrong.";
            }

            break;
        } else {
            cout << "Please enter a valid integer betwen 1 and 13 inclusive:"  << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

}
