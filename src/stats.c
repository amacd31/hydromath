#include <stdio.h>
#include <math.h>

double sum(double * data, int n) {
    double sum = 0;

    int i;
    for(i = 0; i < n; i++) {
        sum += data[i];
    }

    return sum;
}

double mean(double * data, int n) {
    double sum = 0;

    int i;
    for(i = 0; i < n; i++) {
        sum += data[i];
    }

    return sum / n;
}

double covariance(double * data_a, double * data_b, int n) {
    double mean_a = mean(data_a, n);
    double mean_b = mean(data_b, n);

    double variance_a;
    double variance_b;
    double covariance = 0;
    int i;
    for(i = 0; i < n; i++) {
        variance_a = data_a[i] - mean_a;
        variance_b = data_b[i] - mean_b;
        covariance += variance_a * variance_b / n;
    }

    return covariance;
}

double variance_mean(double * data, double mean, int n) {
    double sum = 0;

    double z = 0;
    int i;
    for(i = 0; i < n; i++) {
        sum += pow(data[i] - mean, 2);
    }

    return sum / n;
}

double standard_dev_mean(double * data, double mean, int n) {
    return sqrt(variance_mean(data, mean, n));
}
