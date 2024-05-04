#include "InputMemoryStream.h"

void InputMemoryStream::read(void* outData, size_t inByteCount) {
    std::memcpy(outData, mBuffer + mHead, inByteCount);
    mHead += inByteCount;
}

InputMemoryStream::InputMemoryStream(const char* inBuffer, uint32_t inByteCount):
    mCapacity(inByteCount), mHead(0) {
    mBuffer = static_cast<char*>(std::malloc(inByteCount));
    std::memcpy(const_cast<char*>(mBuffer), inBuffer, inByteCount);
}