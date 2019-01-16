/**
    @author David Whitters
    @date 1/10/19

    @description This is the controller of the application.
*/
#include "controller.h"
#include "ads1015.h"
#include <iostream>

/** The delay in ms between data points being updated on the GUI. */
#define UPDATE_DELAY_MS 500

/**
    Initializes the ADS1015 and sets its pointer register to the conversion
    register.
*/
void initAdc() {
    ADS1015 ads1015;

    ads1015.SetRegister(ADS1015_CONVERSION_REG);
    int val = ads1015.GetConversion();
    std::cout<<"Val: "<< val << std::endl;
}

/**
    Constructor for the controller. Initializes the model, view, and the ADC.
    Sets up a timer to trigger an event every UPDATE_DELAY_MS ms.
*/
Controller::Controller() {
    model = new Model();
    view.setChartData(model->getSeries());

    initAdc();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
    timer->start(UPDATE_DELAY_MS); // 500ms timeout.
}

/**
    Called every UPDATE_DELAY_MS ms. This updates the data at each data
    point in the model series.
*/
void Controller::Update() {
    QPointF point = model->getSeries()->at(0);
    model->getSeries()->replace(0, 0, point.ry() + 1);
}
