#include "random_data_generator.h"

/* Follow the provided structure: 4B ts, 1B data */
uint8_t populate_page_with_random_data(uint8_t *mem_page){
	
	if( mem_page == NULL)
	{
		return RDG_ERR_NULL_PTR;
	}

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
		timestamp += TS_INCREMENT_SEC;
	}	
	return 0;
}