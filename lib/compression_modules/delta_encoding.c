#include "delta_encoding.h"

uint8_t delta_encode(const uint8_t *raw_data, uint8_t *delta_encoded_data, uint16_t *encoded_size)
{
	uint16_t encoded_index = 0;
	uint8_t status = 0;

	// First element is copied as is
	delta_encoded_data[encoded_index++] = raw_data[0];

	for (uint16_t i = 1; i < PAGE_SIZE; i++) {
		// Store the difference from the previous element
		delta_encoded_data[encoded_index++] = raw_data[i] - raw_data[i - 1];
	}

	if (encoded_index > PAGE_SIZE) { // Check for buffer overflow
		status = ERR_DELTA_ENCODE_OVERFLOW;
	}

	*encoded_size = encoded_index;

	return status;
}

uint8_t delta_decode(uint8_t *decoded_data, const uint8_t *delta_encoded_data, const uint16_t encoded_size)
{
    uint16_t decoded_index = 0;
    uint8_t status = 0;

    // First element is copied as is
    decoded_data[decoded_index++] = delta_encoded_data[0];

    for (uint16_t i = 1; i < encoded_size; i++) {
        // Restore the original value by adding the difference to the previous element
        decoded_data[decoded_index++] = decoded_data[i - 1] + delta_encoded_data[i];
    }

    if (decoded_index > PAGE_SIZE) { // Check for buffer overflow
        status = ERR_DELTA_DECODE_OVERFLOW;
    }

    return status;
}






