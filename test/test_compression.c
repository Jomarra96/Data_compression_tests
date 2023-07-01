#include <unity.h>
#include <time.h>
#include "tractive_config.h"
#include "random_data_generator.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_randomly_generated_page_data() {
    
    uint8_t mem_page[PAGE_SIZE] = {0};
    time_t previous_timestamp = 0;
	
    populate_page_with_random_data(mem_page);
    
    for (int i = 0; i < DATAPOINTS; i++) {

        // Retrieve timestamp
        time_t timestamp = 0;
        for (int j = 0; j < 4; j++) {
            timestamp |= ((time_t)mem_page[i*5 + 3 - j]) << (j*8);
        }

        // Check timestamp is incrementing by a minute
        if (i > 0) {
            TEST_ASSERT_EQUAL(difftime(timestamp, previous_timestamp), SECONDS_IN_A_MINUTE);
        }

        previous_timestamp = timestamp;

        // Check acceleration data is in range
        TEST_ASSERT_TRUE(mem_page[i*5 + 4] >= 0 && mem_page[i*5 + 4] <= 254);
    }
}

int main() {
    
    UNITY_BEGIN();
    
    RUN_TEST(test_randomly_generated_page_data);

    UNITY_END();
}