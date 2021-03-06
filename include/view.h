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
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

class View
{

    // The chart the data will be in.
    QChart * chart;
    // The view that the chart will be in.
    QChartView * chartView;
    // The window.
    QMainWindow window;
    // The vertical axis
    QValueAxis * y_axis;
    // The horizontal axis
    QValueAxis * x_axis;

public:
    View();
    void setChartData(QLineSeries * series);

private:
    void setupChart();
    void setupWindow();

};

#endif // VIEW_H

