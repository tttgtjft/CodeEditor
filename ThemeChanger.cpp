#include "ThemeChanger.h"

#include <QGuiApplication>
#include <QStyle>
#include <QDebug>

ThemeChanger::ThemeChanger(QWidget* parent) : QRadioButton(parent)
{
    m_darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    m_darkPalette.setColor(QPalette::WindowText, Qt::white);
    m_darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    m_darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    m_darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    m_darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    m_darkPalette.setColor(QPalette::Text, Qt::white);
    m_darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    m_darkPalette.setColor(QPalette::ButtonText, Qt::white);
    m_darkPalette.setColor(QPalette::BrightText, Qt::red);
    m_darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    m_darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    m_darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    connect(this, SIGNAL(clicked()), this, SLOT(on_radioButton_clicked()));
}

void ThemeChanger::on_radioButton_clicked()
{
    if (emit is_checked())
    {
        qApp->setPalette(m_darkPalette);
    }
    else
    {
        qApp->setPalette(style()->standardPalette());
    }
}
