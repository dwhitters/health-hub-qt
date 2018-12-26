/**
    @author David Whitters
    @date 12/25/18

    @description This is the model of the application.
*/

#ifndef MODEL_H
#define MODEL_H

#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

class Model
{
    // The current data in the model.
    QLineSeries * series;

public:
    Model();
    QLineSeries * getSeries();
};

#endif // MODEL_H
