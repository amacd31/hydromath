#include <check.h>
#include "test_stats.c"
#include "test_hydromath.c"

Suite * stats_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Hydromath");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_sum);
    tcase_add_test(tc_core, test_sum_complex);
    tcase_add_test(tc_core, test_mean);

    tcase_add_test(tc_core, test_nse_perfect);
    tcase_add_test(tc_core, test_nse_bad);
    tcase_add_test(tc_core, test_nse);

    tcase_add_test(tc_core, test_mse_perfect);
    tcase_add_test(tc_core, test_mse_bad);
    tcase_add_test(tc_core, test_mse);

    tcase_add_test(tc_core, test_rmse_perfect);
    tcase_add_test(tc_core, test_rmse_bad);
    tcase_add_test(tc_core, test_rmse);


    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = stats_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}
