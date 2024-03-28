#ifndef UserInput_H
#define UserInput_H

#include "Arduino.h"
#include <stdexcept>

/**
 * @brief Class for handling user input such as buttons and joystick.
 * 
 * The UserInput class enables handling various types of user input, 
 * such as buttons and joystick, on the Arduino platform.
 * The class uses the "Singleton" design pattern
 */
class UserInput
{
public:        
    UserInput(const UserInput&) = delete;

    void operator=(const UserInput&) = delete;
    
	 /**
     * @brief Initializes the UserInput object.
     * 
     * The init method initializes the UserInput object by setting the GPIO pins 
     * for buttons and joystick.
     * 
     * @param leftButtonPin GPIO pin number for the left button.
     * @param rightButtonPin GPIO pin number for the right button.
     * @param joysticXPin GPIO pin number for the X axis of the joystick.
     * @param joysticYPin GPIO pin number for the Y axis of the joystick.
     * @param joysticButtonPin GPIO pin number for the joystick button.
     */
    static void init(int leftButtonPin, int rightButtonPin, int joysticXPin, int joysticYPin, int joysticButtonPin);

    /**
     * @brief Returns a pointer to the instance of the UserInput class.
     * 
     * The getInstance method returns a pointer to the single instance 
     * of the UserInput class.
     * 
     * @return A pointer to the instance of the UserInput class.
     */
    static UserInput* getInstance();

    /**
     * @brief Checks if the left button is pressed.
     * 
     * @return true if the left button is pressed, false otherwise.
     */
    bool isPressedLeftButton();

    /**
     * @brief Checks if the right button is pressed.
     *
     * @return true if the right button is pressed, false otherwise.
     */
    bool isPressedRightButton();

    /**
     * @brief Checks if the joystick is pushed up.
     * 
     * @return true if the joystick is pushed up, false otherwise.
     */
    bool isPressedJoysticUp();

    /**
     * @brief Checks if the joystick is pushed down.
     * 
     * @return true if the joystick is pushed down, false otherwise.
     */
    bool isPressedJoysticDown();

    /**
     * @brief Checks if the joystick is pushed left.
	 *
     * @return true if the joystick is pushed left, false otherwise.
     */
    bool isPressedJoysticLeft();

    /**
     * @brief Checks if the joystick is pushed right.
     * 
     * @return true if the joystick is pushed right, false otherwise.
     */
    bool isPressedJoysticRight();

    /**
     * @brief Checks if the joystick button is pressed.
     * 
     * @return true if the joystick button is pressed, false otherwise.
     */
    bool isPressedJoysticButton();

    /**
     * @brief Gets the X-axis analog value of the joystick.
     * 
     * @return The X-axis value of the joystick.
     */
    int getXJoysticVal();

    /**
     * @brief Gets the Y-axis analog value of the joystick.
     * 
     * @return The Y-axis value of the joystick.
     */
    int getYJoysticVal();

private:
    /**
     * @brief Private constructor of the UserInput class.
     * 
     * The private constructor of the UserInput class to prevent 
     * creating additional instances of the class from outside.
     */
	UserInput(int leftButtonPin, int rightButtonPin, int joysticXPin, int joysticYPin, int joysticButtonPin);

    /**
     * @brief Pointer to the instance of the UserInput class.
     * 
     * Static member variable that holds the single instance of the UserInput class.
     */
	static UserInput* userInput_;

	int leftButtonPin_;

	int rightButtonPin_;

	int joysticXPin_;

	int joysticYPin_;

	int joysticButtonPin_;
};

#endif