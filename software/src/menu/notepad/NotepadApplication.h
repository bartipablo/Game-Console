#ifndef NotepadApplication_H
#define NotepadApplication_H

#include "../Application.h" 
#include "NotepadIcon.h"
#include "../../notepad/NotepadEngine.h"

class NotepadApplication : public Application {
public:
    NotepadApplication() {
        title = "Notepad";
    }

    void start() override {
        NotepadEngine* notepadEngine = new NotepadEngine();
        notepadEngine->run();
        delete notepadEngine;
    }

    Icon* getIcon() override {
        return new NotepadIcon();
    }

private:

};

#endif
