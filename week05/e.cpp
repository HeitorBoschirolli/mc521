#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {

    double p, q, r, s, t, u;

    while (true) {

        cin >> p >> q >> r >> s >> t >> u;

        if (cin.eof()) {
            break;
        }

        bool solved = false;
        double x_low = 0;
        double x_high = 1;
        double funct_low = p * exp(-x_low) + q * sin(x_low) + r * cos(x_low) + s * tan(x_low) + t * pow(x_low, 2) + u;
        double funct_high =
                p * exp(-x_high) + q * sin(x_high) + r * cos(x_high) + s * tan(x_high) + t * pow(x_high, 2) + u;

        if (fabs(funct_high) < 0.000000001) {
            printf("%.4f\n", x_high);
            solved = true;

        }
        else if (fabs(funct_low) < 0.000000001) {
            printf("%.4f\n", x_low);
            solved = true;
        }
        else if ((funct_high > -0.000000001) && (funct_low > -0.000000001)) {
            cout << "No solution" << endl;
            solved = true;
        }
        else if ((funct_high < +0.000000001) && (funct_low < +0.000000001)) {
            cout << "No solution" << endl;
            solved = true;
        }

        double funct;
        double x;
        if (!solved) {
            do {
                x = (x_high + x_low) / 2;
                funct = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;

                if (funct > 0.000000001) {
                    x_low = x;
                } else if (funct < -0.000000001) {
                    x_high = x;
                }

            } while (fabs(funct) > 0.000000001);
            printf("%.4f\n", x);
        }
    }
    return 0;
}