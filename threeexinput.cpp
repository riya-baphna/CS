//RIya Baphna
//rb4nk
//threexinput.cpp
//4/9/12

#include <cstdlib>
#include "timer.h"
#include <string>

using namespace std;

extern "C" int threexplusone(int x);

int main(){
	int x;
	int n;
	int i;
	timer time;

    
    cout << "Please enter a variable ";
    cin >> x;
     cout << "PEnter the number of times the subroutine is called: ";
    cin >> n;


    time.start();
    for(i = 0; i<n; i++){
    	threexplusone(x);
    }
    
    time.stop();

    cout << "The number of steps taken was: " << threexplusone(x) << endl;
    cout << "The average time taken was: "<< time.getTime()/n << endl;

 

}