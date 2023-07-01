#include "random_data_generator.h"

/* Follow the provided structure: 4B ts, 1B data */
void populate_page_with_random_data(uint8_t *mem_page){
	
	uint32_t timestamp = INITIAL_EPOCH;
	uint32_t reconstructed_ts = 0;
    	int j = 0;

	for (int i = 0; i < DATAPOINTS; i++) {
        	// Store timestamp with MSB first
		for (j = 0; j < 4; j++) {			
			mem_page[i*5 + 3 - j] = (timestamp >> (j*8)) & 0xFF; 
        	}

        	// Store acceleration data
        	mem_page[i*5 + 4] = rand() % 254;
        
		// Increment timestamp by a minute
		timestamp += SECONDS_IN_A_MINUTE;

#if DEBUG_OUTPUT == 1
		reconstructed_ts = mem_page[i*5]<<24 | mem_page[i*5 + 1]<<16 | mem_page[i*5 + 2]<<8 | mem_page[i*5 + 3];
		printf("datapoint %d = [%d, %d]\r\n", i, reconstructed_ts, mem_page[i*5 + 4]);
#endif
	}	

}