#include "main.h"

int main(void)
{
	uint8_t mem_page[PAGE_SIZE] = {0};
	uint8_t raw_data[PAGE_SIZE] = {0};
	uint8_t delta_encoded_data[PAGE_SIZE] = {0};
	uint8_t run_time_encoded_data[2*PAGE_SIZE] = {0}; //Worst case scenario
	uint16_t encoded_size = 0;
	uint8_t status = 0;

	populate_page_with_random_data(mem_page);

#if 0
	status = run_length_encode(mem_page, run_time_encoded_data, &encoded_size);
	printf("Status: %d. Encoded size: %d\r\n", status, encoded_size);
	status = run_length_decode(raw_data, run_time_encoded_data, encoded_size);
	printf("Status: %d. Decoded.\r\n", status);

	status = delta_encode(mem_page, delta_encoded_data, &encoded_size);
	printf("Status: %d. Encoded size: %d\r\n", status, encoded_size);
	status = delta_decode(raw_data, delta_encoded_data, encoded_size);
	printf("Status: %d. Decoded.\r\n", status);
#endif
}