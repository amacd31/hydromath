#include "stats.h"
#include "hydromath.h"
#include <stdio.h>

int main(void)
{
    double data[8] = {2, 4, 4, 4, 5, 5, 7, 9};

    double x = sum(data, 8);
    printf("%f\n", x);

    double m = mean(data, 8);
    printf("%f\n", m);

    double v = variance_mean(data, m, 8);
    printf("%f\n", v);

    double sd = standard_dev_mean(data, m, 8);
    printf("%f\n", sd);

    double obs[5] = {13,17,18,20,24};
    double sim[5] = {12,15,20,22,24};

    double mean_square_error = mse_c(obs, sim, 5);
    printf("%f\n", mean_square_error);

    double pobs[5] = {1,2,3,4,5};
    double psim[5] = {1,2,3,4,5};
    double ns = nse_c(pobs, psim, 5);
    printf("%f\n", ns);

    return 0;
}
