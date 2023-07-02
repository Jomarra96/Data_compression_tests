#ifndef DELTA_ENCODING_H
#define DELTA_ENCODING_H

#include "stdint.h"
#include "tractive_config.h"

#define MAX_DELTA 255
#define ERR_DELTA_EXCEEDED 1
#define ERR_DELTA_ENCODE_OVERFLOW 2
#define ERR_DELTA_DECODE_OVERFLOW 3
#define ERR_DELTA_TEST_FAILED 4
#define ERR_DELTA_NULL_PTR 5

/*
Note that delta encoding is not a form of compression.
In fact, the size of the output data is the same as the size of the input data.
However, delta encoding can make the data more compressible by reducing the range of values, 
which can be beneficial if you apply a compression algorithm after delta encoding. 
*/

uint8_t delta_encode(const uint8_t *raw_data, uint8_t *delta_encoded_data, uint16_t *encoded_size);
uint8_t delta_decode(uint8_t *decoded_data, const uint8_t *delta_encoded_data, const uint16_t encoded_size);

#endif // DELTA_ENCODING_H