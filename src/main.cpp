#include <iostream>
#include "lin1d.h"
#include "nonlin1d.h"
#include "diffusion1d.h"

using namespace std;

int main()
{
    int selection;

    for (;;) {
        cout << "Please select a program (int between 1-3 inclusive): ";
        if ((cin >> selection) && (selection > 0) && (selection < 4)) {
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

                default:
                    cout << "Something went horribly wrong.";
            }

            break;
        } else {
            cout << "Please enter a valid integer, either 1 or 2:"  << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

}
