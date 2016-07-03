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

/*
    Kling-Gupta efficiency.

    References:
        * Gupta, Hoshin V., Harald Kling, Koray K. Yilmaz, and Guillermo F. Martinez. "Decomposition of the Mean Squared Error and NSE Performance Criteria: Implications for Improving Hydrological Modelling." Journal of Hydrology 377, no. 1–2 (October 20, 2009): 80–91. doi:10.1016/j.jhydrol.2009.08.003.
*/
double kge_c(double * obs, double * sim, int n) {

    double obs_mean = mean(obs, n);
    double sim_mean = mean(sim, n);
    double obs_std = standard_dev_mean(obs, obs_mean, n);
    double sim_std = standard_dev_mean(sim, sim_mean, n);

    double beta = (sim_mean / obs_mean);
    double cov_so = covariance(sim, obs, n);

    // Default to zero, we set later if sim_std != 0
    double alpha = 0;
    double r = 0;
    if (sim_std != 0) {
        alpha = sim_std / obs_std;
        r = cov_so / (sim_std * obs_std);
    }

    return 1 - sqrt(pow(r - 1, 2) + pow(alpha - 1, 2) + pow(beta - 1, 2));
}

/*
    Heaviside step function

    References:
        * https://en.wikipedia.org/wiki/Heaviside_step_function
        * Hersbach, H. (2000). Decomposition of the Continuous Ranked Probability Score for Ensemble Prediction Systems. Weather and Forecasting, 15(5), 559–570. http://doi.org/10.1175/1520-0434(2000)015<0559:DOTCRP>2.0.CO;2

 */
void heaviside(double * input_data, double * output_data, double x, int n) {
    int i;
    for(i = 0; i < n; i++) {
        if (input_data[i] < x) {
            output_data[i] = 0;
        }
        else {
            output_data[i] = 1;
        }
    }
}
