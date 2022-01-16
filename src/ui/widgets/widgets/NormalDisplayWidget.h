#ifndef NORMALDISPLAYWIDGET_H
#define NORMALDISPLAYWIDGET_H

#include <QWidget>

namespace Ui {
class NormalDisplayWidget;
}

class NormalDisplayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NormalDisplayWidget(QWidget *parent = nullptr);
    ~NormalDisplayWidget();

private:
    Ui::NormalDisplayWidget *ui;
};

#endif // NORMALDISPLAYWIDGET_H
