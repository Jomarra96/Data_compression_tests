#include <unity.h>
#include "tractive_config.h"
#include "random_data_generator.h"
#include "run_length_encoding.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_randomly_generated_page_data() {
    
    uint8_t mem_page[PAGE_SIZE] = {0};
    uint32_t previous_timestamp = 0;
    uint32_t timestamp = 0;
	
    populate_page_with_random_data(mem_page);
    
    for (int i = 0; i < DATAPOINTS; i++) {
        
        // Retrieve timestamp
        timestamp = 0;
        for (int j = 0; j < 4; j++) {
            timestamp |= (mem_page[i*5 + 3 - j]) << (j*8);
        }

        // Check timestamp is incrementing by a minute
        if (i > 0) {
            TEST_ASSERT_EQUAL(timestamp - previous_timestamp, TS_INCREMENT_SEC);
        }

        previous_timestamp = timestamp;

        // Check acceleration data is in range
        TEST_ASSERT_TRUE(mem_page[i*5 + 4] >= 0 && mem_page[i*5 + 4] <= 254);
    }
}

void test_run_length_encoding() {
    
    uint16_t encoded_size = 0;
    uint8_t mem_page[PAGE_SIZE] = {0};
    uint8_t run_time_encoded_data[PAGE_SIZE * 2]; // Worst case scenario
    uint8_t raw_data[PAGE_SIZE] = {0};
    uint8_t status = 0;
	
    populate_page_with_random_data(mem_page);
    
    status = run_length_encode(mem_page, run_time_encoded_data, &encoded_size);
    TEST_ASSERT_EQUAL(status, 0);

    status = run_length_decode(raw_data, run_time_encoded_data, encoded_size);
    TEST_ASSERT_EQUAL(status, 0);

    /* Could make [PAGE_SIZE] asserts here, but unnecessary */
    for (uint16_t i = 0; i < PAGE_SIZE; i++) {
        if(mem_page[i] != raw_data[i])
        {
            status = RLE_TEST_FAILED;
        }
    }

    TEST_ASSERT_EQUAL(status, 0);
}

int main() {
    
    UNITY_BEGIN();
    
    RUN_TEST(test_randomly_generated_page_data);
    RUN_TEST(test_run_length_encoding);

    UNITY_END();
}