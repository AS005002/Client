#ifndef MY_LABEL_H
#define MY_LABEL_H

#include<QLabel>
#include<QLabel>
#include<QEvent>
class my_label : public QLabel
{
    Q_OBJECT
public:
    explicit my_label(QWidget *parent=0);
    void mousePressEvent(QMouseEvent *ev);
signals:
    void Mouse_Pressed();
public slots:
};

#endif // MY_LABEL_H
