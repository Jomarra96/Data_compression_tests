#include "run_length_encoding.h"

uint8_t run_length_encode(const uint8_t *raw_data, uint8_t *run_time_encoded_data, uint16_t *encoded_size)
{
	if((raw_data == NULL) || (run_time_encoded_data == NULL) || (encoded_size == NULL)){
		return ERR_RUN_LENGTH_NULL_PTR;
	}
	
	int8_t current_byte = raw_data[0];
	uint8_t run_length = 1;
	uint16_t encoded_index = 0;
	uint8_t status = 0;

	for (uint16_t i = 1; i < PAGE_SIZE; i++) {
		if ((raw_data[i] == current_byte) && (run_length < 255)) {
			run_length++;
		} else {
			run_time_encoded_data[encoded_index] = current_byte;	//number
			encoded_index++;
			run_time_encoded_data[encoded_index] = run_length;	//repetitions
			encoded_index++;
			current_byte = raw_data[i];				//next new number
			run_length = 1;
		}
	}

	/* When end of array is reached, force last element update */
	run_time_encoded_data[encoded_index] = current_byte;	 
	encoded_index++;
	run_time_encoded_data[encoded_index] = run_length;
	encoded_index++;

	*encoded_size = encoded_index;

	if (run_length >= MAX_RUN_LENGTH)
	{
		status = ERR_RUN_LENGTH_EXCEEDED;
	}

	return status;
}

/* Check every element pair and copy the element as many times as the run length indicates */
uint8_t run_length_decode(uint8_t *run_time_decoded_data, const uint8_t *run_time_encoded_data, const uint16_t encoded_size)
{
	uint16_t decoded_index = 0;
	uint8_t status = 0;
	uint8_t decoded_byte = 0;
	uint8_t run_length = 0;

	for (uint16_t i = 0; i < encoded_size; i = i + 2) {
        	decoded_byte = run_time_encoded_data[i];
        	run_length = run_time_encoded_data[i+1];

        	for (uint8_t k = 0; k < run_length; k++) {
            		run_time_decoded_data[decoded_index] = decoded_byte;
			decoded_index++;
        	}
    	}
	
	if (decoded_index > PAGE_SIZE) {
		status = ERR_RUN_LENGTH_DECODE_OVERFLOW;
	}

	return status;
}