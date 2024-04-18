#include "MainMenu.h"

MainMenu::MainMenu() {
    menuDisplay = new MainMenuDisplay();

    std::vector<App*> apps;
    apps.push_back(new TetrisApplication(menuDisplay));
    apps.push_back(new PaintApplication(menuDisplay));
    apps.push_back(new NotepadApplication(menuDisplay));

    appMenu = new AppMenu(apps);
    appMenu->setBlockExit(true);
    appMenu->setLoopedMenu(true);
}

MainMenu::~MainMenu() {
    delete appMenu;
    delete menuDisplay;
}

void MainMenu::start() {
    appMenu->start();
}