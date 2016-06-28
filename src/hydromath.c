#include <stdio.h>
#include <math.h>
#include "stats.h"

/*
    Mean Square Error
*/
double mse_c(double * obs, double * sim, int n) {
    int t;
    double sum_y = 0;
    for (t = 0; t < n; t++) {
        sum_y += pow(sim[t] - obs[t], 2);
    }

    return sum_y / n;
}

/*
    Root Mean Square Error
*/
double rmse_c(double * obs, double * sim, int n) {
    return sqrt(mse_c(obs, sim, n));
}

/*
    Nash-Sutcliffe efficiency.

    References:
        * Nash, Jea, and J. V. Sutcliffe. 1970. "River Flow Forecasting through Conceptual Models Part I-A Discussion of Principles." Journal of Hydrology 10 (3): 282-90.
*/
double nse_c(double * obs, double * sim, int n) {

    double m = mean(obs, n);

    int t;
    double e1 = 0;
    double e2 = 0;
    for (t = 0; t < n; t++) {
        e1 += pow(obs[t] - sim[t], 2);
        e2 += pow(obs[t] - m, 2);
    }

    if (e1 == 0) {
        return 1;
    }
    else {
        return 1 - e1 / e2;
    }
}
