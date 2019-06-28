// mathfun.cpp
//riya baphna
//rb4nk
//3/25/19

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product(int x, int y);

extern "C" int power(int x, int y);



int  main () {

    // delcare the local variables
    int x;
    int y;
    int products;
    int powers;

 
    cout << "Please enter a variable ";
    cin >> x;

     cout << "Please enter a second variable ";
    cin >> y;



    products = product(x, y);
    cout << "The product is " << products << endl;

    powers= power(x,y);
    cout<< x << " to the power of "<< y << " is: " << powers <<endl;





    return 0;
}
