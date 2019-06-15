#include <iostream>
#include <vector>
#include "graph.h"
#include <unistd.h>
#include <math.h>
using namespace std;

int main(int argc,char **argv) {
	vector<float> x,y,xWindow,yWindow;
	plot p;
	x.reserve(1000);
	y.reserve(1000);
	xWindow.reserve(5000);
	yWindow.reserve(5000);

	bool initialised = 0;
	for(int a=0 ; a < 10 ; a++) {
		x.clear();
		y.clear();

		for(float k=a ; k<a+1 ; k=k+0.001) {
			x.push_back(k);
			y.push_back(100*sin(k));
		}


	if (a==5) initialised = 1;

	if (initialised) {
		xWindow.erase(xWindow.begin(),xWindow.begin()+1000);
		yWindow.erase(yWindow.begin(),yWindow.begin()+1000);
		}

	xWindow.insert(xWindow.end(), x.begin(), x.end());
	yWindow.insert(yWindow.end(), y.begin(), y.end());

	p.plot_data(xWindow,yWindow);
	usleep(100000);

	}
	for (unsigned int i = 0 ; i < 1000 ; i++) {
		cout << xWindow[i] << ", " << yWindow[i] << endl;
	}
	return 0;

}
