/**
    @author David Whitters
    @date 1/10/19

    @description This is the controller of the application.
*/
#include "controller.h"
#include <iostream>

/** The delay in ms between data points being updated on the GUI. */
#define UPDATE_DELAY_MS 2

/**
    Constructor for the controller. Initializes the model, view, and the ADC.
    Sets up a timer to trigger an event every UPDATE_DELAY_MS ms.
*/
Controller::Controller() {
    model = new Model();
    view.setChartData(model->getSeries());

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Update()));
    timer->start(UPDATE_DELAY_MS); 
}

/**
    Called every UPDATE_DELAY_MS ms. This updates the data at each data
    point in the model series.
*/
void Controller::Update() {
    static int data_point = 0;
    static int val = 1;

    model->getSeries()->replace(data_point, data_point, ads1015.GetConversion());

    data_point = (data_point == DATA_SERIES_SIZE) ? 0 : data_point + 1; // Increment the data then roll over at the max.
    if(data_point == 0)
    {
        val *= -1;
    }
}
