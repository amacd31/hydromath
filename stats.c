#include <stdio.h>
#include <math.h>

double sum(double * data, int n) {
    double sum = 0;

    for(int i = 0; i < n; i++) {
        sum += data[i];
    }

    return sum;
}

double mean(double * data, int n) {
    double sum = 0;

    for(int i = 0; i < n; i++) {
        sum += data[i];
    }

    return sum / n;
}

double variance_mean(double * data, double mean, int n) {
    double sum = 0;

    double z = 0;
    for(int i = 0; i < n; i++) {
        sum += pow(data[i] - mean, 2);
    }

    return sum / n;
}

double standard_dev_mean(double * data, double mean, int n) {
    return sqrt(variance_mean(data, mean, n));
}
