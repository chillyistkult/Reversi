#ifndef LOGICCLASS_H
#define LOGICCLASS_H

#include <QObject>

class LogicClass : public QObject
{
    Q_OBJECT
public:
    explicit LogicClass(QObject *parent = 0);
    int max(){ return 100; }
    int min(){ return 0; }
    void emit50(){ emit signalProgress(50); }

 signals:
     void signalProgress(int);

public slots:

};

#endif // LOGICCLASS_H
