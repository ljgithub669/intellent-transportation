/********************************************************************************
** Form generated from reading UI file 'CountryCreate.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTRYCREATE_H
#define UI_COUNTRYCREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CountryCreateClass
{
public:

    void setupUi(QWidget *CountryCreateClass)
    {
        if (CountryCreateClass->objectName().isEmpty())
            CountryCreateClass->setObjectName(QStringLiteral("CountryCreateClass"));
        CountryCreateClass->resize(600, 400);

        retranslateUi(CountryCreateClass);

        QMetaObject::connectSlotsByName(CountryCreateClass);
    } // setupUi

    void retranslateUi(QWidget *CountryCreateClass)
    {
        CountryCreateClass->setWindowTitle(QApplication::translate("CountryCreateClass", "CountryCreate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CountryCreateClass: public Ui_CountryCreateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTRYCREATE_H


