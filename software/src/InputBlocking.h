#ifndef InputBlocking_H
#define InputBlocking_H


/**
 * @brief Class representing a mechanism for blocking input for a certain number of frames.
 *   
 * Solves the problem of reading too many values from an external input at high refresh rates.
 */
class InputBlocking {

public:
    InputBlocking();

    /**
     * @brief Checks if input is currently blocked.
     * 
     * @return True if input is blocked, false otherwise.
     */
    bool isBlocked();

    /**
     * @brief Starts blocking input for a specified number of frames.
     * 
     * @param blockedFramesNo The number of frames for which input will be blocked.
     */
    void startBlocking(int blockedFramesNo);

    /**
     * @brief Decrements the blocking counter.
     * 
     * If the counter reaches zero, input is no longer considered blocked.
     */
    void decrement();

private:
    int counter; ///< Counter representing the remaining number of frames for which input is blocked.
};


#endif
