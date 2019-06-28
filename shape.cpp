




#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
class Shape{
	private:
		string myShape;

    public:
    	Shape (void): myShape (" "){}
    	void setShape (string s){
    		myShape = s;
    	}
    	void print(void) {
        cout << myShape << endl;
    }

 
};


class Square : public Shape{
private:
	int area;
public:
	Square (void){
		area = 0;
	}
	void setArea(int x){
		area = x*4;
	}
	
	void print(void) {
		Shape :: print();
        cout << area << endl;
    }
	

};


int main(void) {
    Square sq;
    sq.setShape("Square");
    sq.setArea(2);
    sq.print();
}