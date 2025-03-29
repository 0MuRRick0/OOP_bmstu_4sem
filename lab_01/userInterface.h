/********************************************************************************
** Form generated from reading UI file 'oopbNOsOQ.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef OOPBNOSOQ_H
#define OOPBNOSOQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel* pixmap_label;
    QWidget* horizontalLayoutWidget;
    QHBoxLayout* horizontalLayout;
    QLabel* label_3;
    QLineEdit* offsetX;
    QLabel* label_4;
    QLineEdit* offsetY;
    QLabel* label_5;
    QLineEdit* offsetZ;
    QLabel* label_2;
    QLabel* label_6;
    QWidget* horizontalLayoutWidget_2;
    QHBoxLayout* horizontalLayout_2;
    QLabel* label_7;
    QLineEdit* rotCenterX;
    QLabel* label_8;
    QLineEdit* rotCenterY;
    QLabel* label_9;
    QLineEdit* rotCenterZ;
    QWidget* horizontalLayoutWidget_3;
    QHBoxLayout* horizontalLayout_3;
    QLabel* label_10;
    QLineEdit* rotX;
    QLabel* label_11;
    QLineEdit* rotY;
    QLabel* label_12;
    QLineEdit* rotZ;
    QLabel* label_13;
    QLabel* label_14;
    QWidget* horizontalLayoutWidget_4;
    QHBoxLayout* horizontalLayout_4;
    QLineEdit* scale;
    QPushButton* scaleButton;
    QPushButton* rotateButton;
    QPushButton* moveButton;
    QPushButton* openButton;

    void setupUi(QWidget* Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(819, 557);
        pixmap_label = new QLabel(Form);
        pixmap_label->setObjectName("pixmap_label");
        pixmap_label->setGeometry(QRect(10, 50, 571, 501));
        horizontalLayoutWidget = new QWidget(Form);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(590, 50, 181, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        offsetX = new QLineEdit(horizontalLayoutWidget);
        offsetX->setObjectName("offsetX");

        horizontalLayout->addWidget(offsetX);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        offsetY = new QLineEdit(horizontalLayoutWidget);
        offsetY->setObjectName("offsetY");

        horizontalLayout->addWidget(offsetY);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        offsetZ = new QLineEdit(horizontalLayoutWidget);
        offsetZ->setObjectName("offsetZ");

        horizontalLayout->addWidget(offsetZ);

        label_2 = new QLabel(Form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(590, 10, 321, 41));
        label_6 = new QLabel(Form);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(590, 160, 121, 16));
        horizontalLayoutWidget_2 = new QWidget(Form);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(590, 260, 191, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName("label_7");

        horizontalLayout_2->addWidget(label_7);

        rotCenterX = new QLineEdit(horizontalLayoutWidget_2);
        rotCenterX->setObjectName("rotCenterX");

        horizontalLayout_2->addWidget(rotCenterX);

        label_8 = new QLabel(horizontalLayoutWidget_2);
        label_8->setObjectName("label_8");

        horizontalLayout_2->addWidget(label_8);

        rotCenterY = new QLineEdit(horizontalLayoutWidget_2);
        rotCenterY->setObjectName("rotCenterY");

        horizontalLayout_2->addWidget(rotCenterY);

        label_9 = new QLabel(horizontalLayoutWidget_2);
        label_9->setObjectName("label_9");

        horizontalLayout_2->addWidget(label_9);

        rotCenterZ = new QLineEdit(horizontalLayoutWidget_2);
        rotCenterZ->setObjectName("rotCenterZ");

        horizontalLayout_2->addWidget(rotCenterZ);

        horizontalLayoutWidget_3 = new QWidget(Form);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(590, 180, 191, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget_3);
        label_10->setObjectName("label_10");

        horizontalLayout_3->addWidget(label_10);

        rotX = new QLineEdit(horizontalLayoutWidget_3);
        rotX->setObjectName("rotX");

        horizontalLayout_3->addWidget(rotX);

        label_11 = new QLabel(horizontalLayoutWidget_3);
        label_11->setObjectName("label_11");

        horizontalLayout_3->addWidget(label_11);

        rotY = new QLineEdit(horizontalLayoutWidget_3);
        rotY->setObjectName("rotY");

        horizontalLayout_3->addWidget(rotY);

        label_12 = new QLabel(horizontalLayoutWidget_3);
        label_12->setObjectName("label_12");

        horizontalLayout_3->addWidget(label_12);

        rotZ = new QLineEdit(horizontalLayoutWidget_3);
        rotZ->setObjectName("rotZ");

        horizontalLayout_3->addWidget(rotZ);

        label_13 = new QLabel(Form);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(590, 240, 121, 16));
        label_14 = new QLabel(Form);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(590, 360, 131, 21));
        horizontalLayoutWidget_4 = new QWidget(Form);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(590, 390, 131, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        scale = new QLineEdit(horizontalLayoutWidget_4);
        scale->setObjectName("scale");

        horizontalLayout_4->addWidget(scale);

        scaleButton = new QPushButton(Form);
        scaleButton->setObjectName("scaleButton");
        scaleButton->setGeometry(QRect(590, 430, 131, 31));
        rotateButton = new QPushButton(Form);
        rotateButton->setObjectName("rotateButton");
        rotateButton->setGeometry(QRect(590, 320, 131, 31));
        moveButton = new QPushButton(Form);
        moveButton->setObjectName("moveButton");
        moveButton->setGeometry(QRect(590, 110, 131, 31));
        openButton = new QPushButton(Form);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(0, 0, 121, 31));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget* Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pixmap_label->setText(QString());
        label_3->setText(QCoreApplication::translate("Form", "X:", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Y:", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "Z:", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "\320\241\320\274\320\265\321\201\321\202\320\270\321\202\321\214 \321\206\320\265\320\275\321\202\321\200 \321\204\320\270\320\263\321\203\321\200\321\213:", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 (\320\262 \320\263\321\200\320\260\320\264\321\203\321\201\320\260\321\205):", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "X:", nullptr));
        label_8->setText(QCoreApplication::translate("Form", "Y:", nullptr));
        label_9->setText(QCoreApplication::translate("Form", "Z:", nullptr));
        label_10->setText(QCoreApplication::translate("Form", "X:", nullptr));
        label_11->setText(QCoreApplication::translate("Form", "Y:", nullptr));
        label_12->setText(QCoreApplication::translate("Form", "Z:", nullptr));
        label_13->setText(QCoreApplication::translate("Form", "\320\246\320\265\320\275\321\202\321\200 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260:", nullptr));
        label_14->setText(QCoreApplication::translate("Form", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261 \320\276\321\202 0.05 \320\264\320\276 20", nullptr));
        scaleButton->setText(QCoreApplication::translate("Form", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        rotateButton->setText(QCoreApplication::translate("Form", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        moveButton->setText(QCoreApplication::translate("Form", "\320\241\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        openButton->setText(QCoreApplication::translate("Form", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form : public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // OOPBNOSOQ_H
