#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void generateMap() {
    int w = 0, k = 0;
    bool function_expression;

    /***********************************
        Parameters (variables, map_size)
    ************************************/
    bool a, b, c, d;
    const int numOfVariables = 4, Cols = 4, Rows = 4;

    if (static_cast<double>(Cols * Rows) != pow(2, numOfVariables)) throw exception("The multiplication of Cols and Rows should be equal to 2^(Number_Of_Variables)");

    bool map[Rows][Cols];

    for (unsigned int i = 0; i < pow(2, numOfVariables); i++) {
        a = i bitand 8;
        b = i bitand 4;
        c = i bitand 2;
        d = i bitand 1;

        /***********************************
           Change function expression here
        ************************************/

        function_expression = a bitor (not(b) bitand not(c)) bitor (not(b) bitand not(d));

        map[w][k] = function_expression;

        k = (k + 1) % Cols;
        if (k % Cols == 0) w++;
    }

    for (int i = 0; i < Cols; i++) {
        swap(map[i][Cols - 2], map[i][Cols - 1]);
    }
    for (int i = 0; i < Rows; i++) {
        swap(map[Rows - 2][i], map[Rows - 1][i]);
    }

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << map[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    try {
        generateMap();
    }
    catch (exception & e) {
        cerr << e.what();
    }
}