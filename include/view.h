/**
    @author David Whitters
    @date 12/25/18

    @description This is the view of the application.
*/

#ifndef VIEW_H
#define VIEW_H

#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

class View
{

    // The chart the data will be in.
    QChart * chart;
    // The view that the chart will be in.
    QChartView * chartView;
    // The window.
    QMainWindow window;

public:
    View();
    void setChartData(QLineSeries * series);

private:
    void setupChart();
    void setupWindow();

};

#endif // VIEW_H

