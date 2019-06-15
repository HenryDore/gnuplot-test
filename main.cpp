#include <iostream>
#include <vector>
#include "graph.h"
#include <math.h>
using namespace std;


#ifdef _WIN32
    #include <windows.h>

    void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>

    void sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif

int main(int argc,char **argv) {
	vector<float> x,y,xWindow,yWindow;
	plot p;
	x.reserve(100);
	y.reserve(100);
	xWindow.reserve(500);
	yWindow.reserve(500);

	bool initialised = 0;
	for(int a=0 ; a < 100 ; a++) {
		x.clear();
		y.clear();

		for(float j = 0 ; j < 100 ; j++) {
			x.push_back(a+j/100);
			y.push_back((100*sin(a+j/100))+100);
		}


	if (a==5) initialised = 1;

		xWindow.insert(xWindow.end(), x.begin(), x.end());
		yWindow.insert(yWindow.end(), y.begin(), y.end());

	if (initialised) {
		xWindow.erase(xWindow.begin(),xWindow.begin()+100);
		yWindow.erase(yWindow.begin(),yWindow.begin()+100);
		xWindow.resize(500);
		yWindow.resize(500);
		}


	p.plot_data(xWindow,yWindow);

	sleep(1);

	}

/*
	for (unsigned int i = 0 ; i < 500 ; i++) {
		cout << xWindow[i] << ", " << yWindow[i] << endl;
	}
*/

	return 0;

}
