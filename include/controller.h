/**
    @author David Whitters
    @date 1/10/19

    @description This is the controller of the application.
*/
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include "model.h"
#include "view.h"

class Controller : public QObject
{
    Q_OBJECT // Needed to use signals and slots. Used by the meta-object compiler.

    QTimer *timer;
    View view;
    Model * model;

public:
    Controller();

public slots:
    void Update();
};

#endif // CONTROLLER_H
