#include <iostream>
#include <vector>
#include "graph.h"
#include <math.h>

#ifdef _WIN64 // fine whatever windows you dickhead
#include <windows.h>

void sleepytime(unsigned milliseconds) { Sleep(milliseconds); }


#else
#include <unistd.h>
void sleepytime(unsigned milliseconds) {
  usleep(milliseconds * 1000); // takes microseconds
}
#endif

using namespace std;

int begin(int offset, int peakToPeak, int windowSize, int readingSize, int iterations, int delay) {
  vector<float> x, y, xWindow, yWindow;
  plot p;
  x.reserve(readingSize);
  y.reserve(readingSize);
  xWindow.reserve(windowSize*readingSize);
  yWindow.reserve(windowSize*readingSize);

  bool initialised = 0;
  for (int a = 0 ; a < iterations ; a++) {
    x.clear();
    y.clear();

    for (float j = 0; j < readingSize; j++) {
      x.push_back(a + j / readingSize);
      y.push_back((peakToPeak * sin(a + j / readingSize)) + offset);
    }

    if (a == windowSize)
      initialised = 1;

    xWindow.insert(xWindow.end(), x.begin(), x.end());
    yWindow.insert(yWindow.end(), y.begin(), y.end());

    if (initialised) {
      xWindow.erase(xWindow.begin(), xWindow.begin() + readingSize);
      yWindow.erase(yWindow.begin(), yWindow.begin() + readingSize);
    }

    p.plot_data(xWindow, yWindow);
    sleepytime(delay);
  }
  return 0;
}

int main(int argc, char **argv) {
  int offset = 1000;
  int peakToPeak = 1000;
  int windowSize = 10;
  int readingSize = 1000;
  int iterations = 50;
  int delay = 0;

  begin(offset, peakToPeak, windowSize, readingSize, iterations, delay);

  return 0;
}
