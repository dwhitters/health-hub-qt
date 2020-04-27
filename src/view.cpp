/**
    @author David Whitters
    @date 12/25/18

    @description This is the view of the application.
*/
#include "view.h"
#include "model.h"

// Constructor.
View::View()
{
    x_axis = new QValueAxis(); // Axes must be created as the default axes can't be modified.
    y_axis = new QValueAxis();

    x_axis->setRange(0, DATA_SERIES_SIZE);
    y_axis->setRange(0, 4096);

    setupChart();
    setupWindow();

    chart->addAxis(x_axis, Qt::AlignBottom);
    chart->addAxis(y_axis, Qt::AlignLeft);
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
    series->attachAxis(x_axis);
    series->attachAxis(y_axis);
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
    window.resize(800, 300);
    window.show();
}
