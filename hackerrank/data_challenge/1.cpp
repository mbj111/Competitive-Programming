
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double normal_dist_90(double mean, double stddev){
    double z_score = 1.28l;
    double x =  z_score*stddev + mean;
    return x;
}

int main() {
    double mean = 2000.00l, stddev = 200.00l;
    printf("%.2f" ,normal_dist_90(mean, stddev));
    return 0;
}
