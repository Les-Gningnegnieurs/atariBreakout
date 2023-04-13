

#include "GameLoop.h"

GameLoop::GameLoop(QApplication* app, QObject* parent) : QObject(parent) {
    _canevas = new Canevas();
    _window = new MainWindow(app, nullptr, _canevas->getScene());
}