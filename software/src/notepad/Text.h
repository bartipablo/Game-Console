#ifndef Text_H
#define Text_H

#include <string>

class Text {

public:
    Text(int maxRowLength, int maxRowsQuantity);

    ~Text();

    void appendCharacter(char character);

    void backspace();

    std::string* getText();

    int getActualRow();
    
private:
    int actualRow;

    int maxRowLength;

    int maxRowsQuantity;

    std::string* text;

    
};


#endif