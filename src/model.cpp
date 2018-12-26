/**
    @author David Whitters
    @date 12/25/18

    @description This is the model of the application.
*/

#include "model.h"

// Creates a series of data to display on the chart.
Model::Model()
{
    series = new QLineSeries(); // Initialize the series.
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
}

/**
    @return
        The current data in the model.
*/
QLineSeries * Model::getSeries()
{
    return series;
}
