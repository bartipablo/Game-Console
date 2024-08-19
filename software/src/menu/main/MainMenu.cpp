#include "MainMenu.h"

MainMenu::MainMenu() {
    std::vector<App*> apps;
    apps.push_back(new TetrisApplication());
    apps.push_back(new PaintApplication());
    apps.push_back(new NotepadApplication());
    apps.push_back(new WiFiApplication());
    apps.push_back(new PongApplication());
    apps.push_back(new SnakeApplication());

    appMenu = new AppMenu(apps);
    appMenu->setBlockExit(true);
    appMenu->setLoopedMenu(true);
}

MainMenu::~MainMenu() {
    delete appMenu;
}

void MainMenu::start() {
    appMenu->start();
}