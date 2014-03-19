#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Student {
         int idn;
         string name;
         double mark; // The mark is a value between 0 and 10, or -1 that represents NP
         bool repeater;
};

void information(const vector<Student>& stu, double& min, double& max, double& avg) {
        int avgcounter = 0; //Number of numbers added for the avg
        min = -1.0;
        max = -1.0;
        avg = 0.0;
        int size = stu.size();
        for (int i = 0; i < size; ++i) {
                if (not stu[i].repeater) {
                        if (stu[i].mark > -1) {
                                avg = avg + stu[i].mark;
                                ++avgcounter;
                                if (stu[i].mark < min or min == -1.0) min = stu[i].mark;
                                if (stu[i].mark > max) max = stu[i].mark;
                        }
                }
        }
        if (avgcounter > 0) {
                avg = avg/avgcounter;
                return;
        }
        else avg = -1.0;
}

int main () {}
