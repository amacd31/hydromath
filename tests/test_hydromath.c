#include <check.h>
#include <math.h>
#include "hydromath.h"

/** START KGE TESTS **/

START_TEST(test_kge_perfect)
{
    double data[7] = {1.,2.,3.,4.,5.,6.,7.};
    double s = kge_c(data, data, 7);
    ck_assert(round(s * 15) / 15 == 1.0);
}
END_TEST

START_TEST(test_kge_climatology)
{
    double obs_data[5] = {1.,2.,3.,4.,5.};
    double sim_data[5] = {3.,3.,3.,3.,3.};
    double s = kge_c(obs_data, sim_data, 5);
    ck_assert(s == 1 - sqrt(2.0));
}
END_TEST

START_TEST(test_kge_biased_climatology)
{
    double obs_data[5] = {1.,2.,3.,4.,5.};
    double sim_data[5] = {6.,6.,6.,6.,6.};
    double s = kge_c(obs_data, sim_data, 5);
    ck_assert(s == 1 - sqrt(3.0));
}
END_TEST

START_TEST(test_kge)
{
    double obs_data[13] = {1,2,3,4,5,6,7,6,5,4,3,2,1};
    double sim_data[13] = {1,2,3,4,5,6,6,6,5,4,3,2,1};
    double s = kge_c(obs_data, sim_data, 13);
    ck_assert(s == 0.93444263181747966307000297092599794268608093261719);
}
END_TEST

/** END KGE TESTS **/

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

/** START MSE TESTS **/
START_TEST(test_mse_perfect)
{
    double data[5] = {1.,2.,3.,4.,5.};
    double s = mse_c(data, data, 5);
    ck_assert(s == 0.0);
}
END_TEST

START_TEST(test_mse_bad)
{
    double obs_data[5] = {1.,2.,3.,4.,5.};
    double sim_data[5] = {3.,3.,3.,3.,3.};
    double s = mse_c(obs_data, sim_data, 5);
    ck_assert(s == 2.0);
}
END_TEST

START_TEST(test_mse)
{
    double obs_data[5] = {13.,17.,18.,20.,24.};
    double sim_data[5] = {12.,15.,20.,22.,24.};
    double s = mse_c(obs_data, sim_data, 5);
    ck_assert(s == 2.6);
}
END_TEST
/** END MSE TESTS **/

/** START RMSE TESTS **/
START_TEST(test_rmse_perfect)
{
    double data[5] = {1.,2.,3.,4.,5.};
    double s = rmse_c(data, data, 5);
    ck_assert(s == 0.0);
}
END_TEST

START_TEST(test_rmse_bad)
{
    double obs_data[5] = {1.,2.,3.,4.,5.};
    double sim_data[5] = {3.,3.,3.,3.,3.};
    double s = rmse_c(obs_data, sim_data, 5);
    ck_assert(s == sqrt(2.0));
}
END_TEST

START_TEST(test_rmse)
{
    double obs_data[5] = {13.,17.,18.,20.,24.};
    double sim_data[5] = {12.,15.,20.,22.,24.};
    double s = rmse_c(obs_data, sim_data, 5);
    ck_assert(s == sqrt(2.6));
}
END_TEST
/** END RMSE TESTS **/
