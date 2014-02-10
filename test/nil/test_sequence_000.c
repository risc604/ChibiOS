/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "hal.h"
#include "ch_test.h"
#include "test_root.h"

/**
 * @page test_sequence_000 Threads Functionality
 *
 * File: @ref test_sequence_000.c
 *
 * <h2>Description</h2>
 * This sequence tests the ChibiOS/Nil functionalities related to threading.
 *
 * <h2>Test Cases</h2>
 * - @subpage test_000_000
 * .
 */

/****************************************************************************
 * Shared code.
 ****************************************************************************/


/****************************************************************************
 * Test cases.
 ****************************************************************************/

#if TRUE || defined(__DOXYGEN__)
/**
 * @page test_000_000 System Tick Counter functionality
 *
 * <h2>Description</h2>
 * The functionality of the API @p chVTGetSystemTimeX() is tested.
 *
 * <h2>Conditions</h2>
 * None.
 *
 * <h2>Test Steps</h2>
 * - A System Tick Counter increment is expected, the test simply hangs if
 *   it does not happen.
 * .
 */

static void test_000_000_execute(void) {
  systime_t time;

  /* A System Tick Counter increment is expected, the test simply hangs if
     it does not happen.*/
  test_set_step(1);
  {
    time = chVTGetSystemTimeX();
    while (time == chVTGetSystemTimeX()) {
    }
  }
}

static const testcase_t test_000_000 = {
  "Brief description",
  NULL,
  NULL,
  test_000_000_execute
};
#endif /* TEST_000_000_CONDITION */

#if TRUE || defined(__DOXYGEN__)
/**
 * @page test_000_001 Thread Sleep functionality
 *
 * <h2>Description</h2>
 * The functionality of the API @p chThdSleep() and derivatives is tested.
 *
 * <h2>Conditions</h2>
 * None.
 *
 * <h2>Test Steps</h2>
 * - The current system time is read then a sleep is performed for 100 system
 *   ticks and on exit the system time is verified again.
 * - The current system time is read then a sleep is performed for 100000
 *   microseconds and on exit the system time is verified again.
 * - The current system time is read then a sleep is performed for 100
 *   milliseconds and on exit the system time is verified again.
 * - The current system time is read then a sleep is performed for 1
 *   second and on exit the system time is verified again.
 * .
 */

static void test_000_001_execute(void) {
  systime_t time;

  /* The current system time is read then a sleep is performed for 100 system
     ticks and on exit the system time is verified again.*/
  test_set_step(1);
  {
    time = chVTGetSystemTimeX();
    chThdSleep(100);
    test_assert_time_window(time + 100,
                            time + 101,
                            "out of time window");
  }

  /* The current system time is read then a sleep is performed for 100000
     microseconds and on exit the system time is verified again.*/
  test_set_step(2);
  {
    time = chVTGetSystemTimeX();
    chThdSleepMicroseconds(100);
    test_assert_time_window(time + US2ST(100),
                            time + US2ST(100) + 1,
                            "out of time window");
  }

  /* The current system time is read then a sleep is performed for 100
     milliseconds and on exit the system time is verified again.*/
  test_set_step(3);
  {
    time = chVTGetSystemTimeX();
    chThdSleepMilliseconds(100);
    test_assert_time_window(time + MS2ST(100),
                            time + MS2ST(100) + 1,
                            "out of time window");
  }

  /* The current system time is read then a sleep is performed for 1
     second and on exit the system time is verified again.*/
  test_set_step(4);
  {
    time = chVTGetSystemTimeX();
    chThdSleepSeconds(1);
    test_assert_time_window(time + S2ST(1),
                            time + S2ST(1) + 1,
                            "out of time window");
  }
}

static const testcase_t test_000_001 = {
  "Brief description",
  NULL,
  NULL,
  test_000_001_execute
};
#endif /* TEST_000_001_CONDITION */

 /****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
 * @brief   Sequence brief description.
 */
const testcase_t * const test_sequence_000[] = {
#if 1 || defined(__DOXYGEN__)
  &test_000_000,
#endif
#if 1 || defined(__DOXYGEN__)
  &test_000_001,
#endif
  NULL
};