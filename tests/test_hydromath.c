#include <check.h>
#include "hydromath.h"

START_TEST(test_nse_perfect)
{
    double data[5] = {1.,2.,3.,4.,5.};
    double s = nse_c(data, data, 5);
    ck_assert(s == 1.0);
}
END_TEST
