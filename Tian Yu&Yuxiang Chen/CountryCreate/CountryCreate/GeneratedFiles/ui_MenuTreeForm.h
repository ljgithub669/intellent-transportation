/********************************************************************************
** Form generated from reading UI file 'MenuTreeForm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUTREEFORM_H
#define UI_MENUTREEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class ui_MenuTreeForm
{
public:

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(400, 300);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuTreeFormClass: public ui_MenuTreeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUTREEFORM_H
