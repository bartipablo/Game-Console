#ifndef OUTPUT_MEMORY_STREAM_H
#define OUTPUT_MEMORY_STREAM_H

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <algorithm>

namespace streams {

/**
 * @brief The InputMemoryStream class is used to write data to memory buffer.
 * 
 * This class provides functionality for managing an output memory stream,
 * allowing data to be written to a dynamically allocated buffer.
 */
class OutputMemoryStream {
public:
    OutputMemoryStream():
        mBuffer(nullptr), mHead(0), mCapacity(0) {
            reallocBuffer(32);
}

    ~OutputMemoryStream() {
        std::free(mBuffer);
    }

    const char* getBufferPtr() {
        return mBuffer;
    }

    uint32_t getLength() {
        return mHead;
    }

    void write(const void* inData, size_t inByteCount);

private:
/**
 * @brief Reallocates the memory buffer with a new length.
 *
 * This method reallocates the memory buffer to accommodate a new length specified by
 * the parameter `inNewLength`.
 * 
 * @param inNewLength The new length for the memory buffer.
 */
    void reallocBuffer(uint32_t inNewLength);

    char* mBuffer;

    uint32_t mHead;

    uint32_t mCapacity;
};

}

#endif // OUTPUT_MEMORY_STREAM_H