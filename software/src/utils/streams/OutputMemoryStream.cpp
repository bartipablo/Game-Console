#include "OutputMemoryStream.h"

namespace streams {

void OutputMemoryStream::reallocBuffer(uint32_t inNewLength) {
    mBuffer = static_cast<char*>(std::realloc(mBuffer, inNewLength));
    mCapacity = inNewLength;
}

void OutputMemoryStream::write(const void* inData, size_t inByteCount) {
    uint32_t resultHead = mHead + static_cast<uint32_t>(inByteCount);
    if (resultHead > mCapacity) {
        reallocBuffer(std::max(mCapacity * 2, resultHead));
    }
    std::memcpy(mBuffer + mHead, inData, inByteCount);
    mHead = resultHead;
}

}