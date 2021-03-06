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

    double kge = kge_c(obs, sim, 5);
    printf("KGE: %f\n", kge);

    kge = kge_c(pobs, psim, 5);
    printf("Perfect KGE: %f\n", kge);

    double cv = covariance(obs, sim, 5);
    printf("Covariance: %f\n", cv);

    cv = covariance(pobs, psim, 5);
    printf("Covariance: %f\n", cv);

    double h_data[5] = {-3,-2,-1,1,2};
    double out_data[6] = {0,0,0,0,0,0};
    heaviside(h_data, out_data, 6);

    int i;
    for (i = 0; i < 5; i++) {
        printf("Heaviside %d: %f\n", i, out_data[i]);
    }

    return 0;
}
