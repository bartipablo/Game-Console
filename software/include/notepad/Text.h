#ifndef Text_H
#define Text_H

#include <string>

/**
 * Represents a text field.
 * The text is a string array where each element is a row.
 */
class Text {

public:
/**
 * Creates a text object.
 * @param maxRowLength the maximum length (character quantity) of a row.
 * @param maxRowsQuantity the maximum number of rows.
*/
    Text(int maxRowLength, int maxRowsQuantity);

    ~Text();

/**
 * Appends a character to the text.
 * @param character the character to append.
 * If the character is a newline character ('\n'), the text will be split into a new row.
 */
    void appendCharacter(char character);

/**
 * Deletes the last character of the text.
*/
    void backspace();

/**
 * @return the text.
 * The text is a string array where each element is a row.
 */
    std::string* getText();

/**
 * @return the actual row.
 * The actual row is the row where the next character will be appended.
 */
    int getActualRow();
    
private:
    int actualRow;

    int maxRowLength;

    int maxRowsQuantity;

    std::string* text;

    
};


#endif