#include <vector>
#include "graph.h"
#include <unistd.h>
#include <math.h>
using namespace std;

int main(int argc,char **argv) {
	vector<float> x,y;
	plot p;

	for(float a=0 ; a < 1000 ; a++) {
		x.push_back(a);
		y.push_back(100*sin(a/10));

/*
		for(int k=a ; k<a+200 ; k++) {
			x.push_back(k);
			y.push_back(100*sin(k));
			usleep(100);
		}
*/
		p.plot_data(x,y);
	}
	return 0;
}
