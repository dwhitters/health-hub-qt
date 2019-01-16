/**
    @author David Whitters
    @date 12/25/18

    @description This is the model of the application.
*/

#ifndef MODEL_H
#define MODEL_H

#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

/** The number of data points in the series. */
#define DATA_SERIES_SIZE 10

class Model
{
    // The current data in the model.
    QLineSeries * series;

public:
    Model();
    QLineSeries * getSeries();
};

#endif // MODEL_H
