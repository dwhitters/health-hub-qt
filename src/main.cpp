/**
    @author David Whitters
    @date 12/23/18

    @description Starts the application.
*/
#include <QtWidgets/QApplication>
#include "model.h"
#include "view.h"
#include "i2c.h"

int main(int argc, char *argv[])
{
    i2cInit();

//    QApplication a(argc, argv);
//
//    // Create a series of data to display on the chart.
//    Model * model = new Model();
//    View * view = new View();
//    view->setChartData(model->getSeries());
//
//    // Pass control to QT and return here when done.
//    return a.exec();
}
