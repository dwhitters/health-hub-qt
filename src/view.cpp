/**
    @author David Whitters
    @date 12/25/18

    @description This is the view of the application.
*/
#include "view.h"

// Constructor.
View::View()
{
    setupChart();
    setupWindow();
}

/**
    Sets the chart series to the passed in series.

    @param series
        Reference to the series that the chart must display
*/
void View::setChartData(QLineSeries * series)
{
    chart->removeAllSeries();
    chart->addSeries(series);
    chart->createDefaultAxes(); // Must be called after adding a series to a chart.
}

// Sets up the chart and binds the data in the model to it.
void View::setupChart()
{
    chart = new QChart(); // Initialize the chart and configure it.
    chart->legend()->hide();
    chart->setTitle("ECG");

    // Initialize the chart view and store the chart in it.
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

// Sets up the window and displays the chart view.
void View::setupWindow()
{
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}
