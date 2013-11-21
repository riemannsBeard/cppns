#include <iostream>
#include "step1/lin1d.h"
#include "step2/nonlinear-1d.h"

using namespace std;

int main()
{
    int selection;

    for (;;) {
        cout << "Please select a program (either 1 or 2): ";
        if ((cin >> selection) && (selection > 0) && (selection < 3)) {
            switch (selection) {
                case 1:
                    lin1d();
                break;

                case 2:
                    nonlinear1d();
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
