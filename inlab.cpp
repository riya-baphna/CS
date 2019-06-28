
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
class Sport{
    public:
    	int score=5;

     
      virtual void getScore(){
      	cout<< "The score is: "<< score <<endl;
      }
      virtual void gameOver(){
      	if (score == 20){
      		cout<< "Game over"<<endl;
      	}
      }

 
};


class Basketball : public Sport{
public:
	virtual void getScore(){
		cout  << "The Score is : "<<score*2<<endl;

	};B
	virtual int basket(){
		score+=2;
		return score;

	}

};


int main(){
	Sport *b = new Basketball();
	b -> getScore();
	b -> gameOver();
}
