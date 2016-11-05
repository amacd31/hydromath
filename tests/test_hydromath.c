#include <check.h>
#include "hydromath.h"

/** START NSE TESTS **/

START_TEST(test_nse_perfect)
{
    double data[5] = {1.,2.,3.,4.,5.};
    double s = nse_c(data, data, 5);
    ck_assert(s == 1.0);
}
END_TEST

START_TEST(test_nse_bad)
{
    double obs_data[5] = {1.,2.,3.,4.,5.};
    double sim_data[5] = {3.,3.,3.,3.,3.};
    double s = nse_c(obs_data, sim_data, 5);
    ck_assert(s == 0.0);
}
END_TEST

START_TEST(test_nse)
{
    double obs_data[12] = {5,4,6,1,3,6,8,1,7,3,4,0.5};
    double sim_data[12] = {3,4.5,4,2,4,5,9,2,8,3,4,0.8};
    double s = nse_c(obs_data, sim_data, 12);
    ck_assert(s == 0.783479081472161);
}
END_TEST

/** END NSE TESTS **/
