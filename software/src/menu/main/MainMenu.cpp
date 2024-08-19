#include "MainMenu.h"

MainMenu::MainMenu() {

    std::vector<std::shared_ptr<App>> apps;
    apps.push_back(std::make_shared<TetrisApplication>());
    apps.push_back(std::make_shared<PaintApplication>());
    apps.push_back(std::make_shared<NotepadApplication>());
    apps.push_back(std::make_shared<WiFiApplication>());
    apps.push_back(std::make_shared<PongApplication>());
    apps.push_back(std::make_shared<SnakeApplication>());

    appMenu = my_std::make_unique<AppMenu>(apps);
    appMenu->setBlockExit(true);
    appMenu->setLoopedMenu(true);
}

void MainMenu::start() {
    appMenu->start();
}