# Tractive_compression
FW assignment from tractive

# Firmware Assignment
* Our device stores activity data of the user’s pet which is an average acceleration over the last minute. The values ranges from 0-254.

* The maximum size of stored records in the flash is 50400 bytes.
This data is stored on the device and uploaded on demand to our server so we can visualize it
to the user in terms of “How active was your pet.”

* The data is currently stored in a NAND flash and transmitted in the following format:
● 4 byte timestamp
● 1 byte data

This pattern repeats and looks like this:
4 Byte timestamp 1 Byte Data
4 Byte timestamp 1 Byte Data
....

In order to save GSM Data you should come up with an idea for compression of the transmitted Data.
Please prepare the following:
● Study the case
● Investigate an idea to compress the data before sending.
● Also think about edge cases and possible problems.
● You should present your idea/solution and be prepared to get challenged in the interview.
● After the architecture is defined, please also create the necessary file structure and
provide some high level code (methods/functions).

# Approach
1. First, we will include 3 lossless compression techniques we can use for this task, using the provided frame structure:

	1.1. Run-Length Encoding (RLE)
	1.2. Delta Encoding (ΔE)
	1.3. Huffman Encoding (HE)

2. Once introduced, we will create the file structure. It will consist on:
	2.1. Random data generator module
	2.2. RLE module
	2.3. ΔE module
	2.4. Test module
	
3. The development will be done using PlatformIO IDE, running on GCC for WinOS (MinGW), although it can easily be ported to arm-gcc to run on target if needed.

4. Finally, we will dive into how modifying the initial given frame structure could result in higher data density.