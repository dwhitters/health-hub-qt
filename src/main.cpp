/**
    @author David Whitters
    @date 12/23/18

    @description Starts the application.
*/
#include <QtWidgets/QApplication>
#include "model.h"
#include "view.h"
#include "ads1015.h"
#include <iostream>

int main(int argc, char *argv[])
{
    ADS1015 ads1015;

    ads1015.SetRegister(ADS1015_CONVERSION_REG);
    int val = ads1015.GetConversion();
    std::cout<<"Val: "<< val << std::endl;


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
