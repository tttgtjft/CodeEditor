#ifndef THEMECHANGER_H
#define THEMECHANGER_H

#include <QRadioButton>

class ThemeChanger : public QRadioButton
{
    Q_OBJECT

public:
    ThemeChanger(QWidget* parent = nullptr);

signals:
    bool is_checked();

private slots:
    void on_radioButton_clicked();
};

#endif // THEMECHANGER_H
