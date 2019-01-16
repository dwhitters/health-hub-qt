/**
    @author David Whitters
    @date 12/23/18

    @description Starts the application.
*/
#include <QtWidgets/QApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller controller;

    return a.exec();
}
