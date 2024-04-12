#include "Text.h"

Text::Text(int maxRowLength, int maxRowsQuantity) {
    this->maxRowLength = maxRowLength;
    this->maxRowsQuantity = maxRowsQuantity;
    text = new std::string[maxRowsQuantity];
    for (int i = 0; i < maxRowsQuantity; i++) {
        text[i] = "";
    }
    actualRow = 0;
}

Text::~Text() {
    delete[] text;
}

void Text::appendCharacter(char character) {
    if (character == '\n') {
        if (actualRow >= maxRowsQuantity - 1) {
            return;
        }
        text[actualRow] += character;
        actualRow++;
    }
    else if (text[actualRow].length() < maxRowLength) {
            text[actualRow] += character; 
    }
}

void Text::backspace() {
    if (text[actualRow].length() > 0) {
        text[actualRow].pop_back();
    }
    else if (actualRow > 0) {
        actualRow--;
        text[actualRow].pop_back();
    }
}

std::string* Text::getText() {
    return text;
}

int Text::getActualRow() {
    return actualRow;
}