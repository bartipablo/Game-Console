#ifndef INPUT_MEMORY_STREAM_H
#define INPUT_MEMORY_STREAM_H

#include <cstdint>
#include <cstdlib>
#include <cstring>

/**
 * @brief The InputMemoryStream class is used to read data from a memory buffer.
 * 
 * Objects of this class allow reading data from a memory buffer
 * using the read() method.
 */
class InputMemoryStream {

public:
/**
* @brief The constructor of the InputMemoryStream class.
* 
* Creates an InputMemoryStream object based on the provided data buffer
* and its size.
* 
* @param inBuffer A pointer to the input data buffer.
* @param inByteCount The number of bytes in the input data buffer.
*/
    InputMemoryStream(const char* inBuffer, uint32_t inByteCount);

    ~InputMemoryStream() {
        std::free(mBuffer);
    }

    uint32_t getRemainingDataSize() {
        return mCapacity - mHead;
    }

    /**
     * @brief Reads data from the buffer into the specified memory location.
     * 
     * The method reads the specified number of bytes from the buffer
     * and writes them to the specified memory location.
     * 
     * @param outData A pointer to the location where the read data should be written.
     * @param inByteCount The number of bytes to read and write.
     */
    void read(void* outData, size_t inByteCount);

private:
    char* mBuffer;
    uint32_t mHead;
    uint32_t mCapacity;

};


#endif