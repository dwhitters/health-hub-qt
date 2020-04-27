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
    for(int i = 0; i < DATA_SERIES_SIZE; ++i)
    {
        series->append(0,0); // x=0, y=0
    }
}

/**
    @return
        The current data in the model.
*/
QLineSeries * Model::getSeries()
{
    return series;
}
