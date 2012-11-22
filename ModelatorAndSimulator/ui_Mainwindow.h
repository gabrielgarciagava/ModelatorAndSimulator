/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created: Fri Oct 26 21:56:18 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame_opcoes;
    QPushButton *botao_inicio_simulacao;
    QSlider *tamanho_passo;
    QTextBrowser *tamanho_passo_tela;
    QPushButton *botao_pausar_simulacao;
    QPushButton *botao_parar_simulacao;
    QPushButton *botao_avancar_simulacao;
    QFrame *frame_parametros;
    QLabel *label_parametros;
    QGraphicsView *visao_grafica;
    QTextBrowser *caixa_logs;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(820, 620);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_opcoes = new QFrame(centralWidget);
        frame_opcoes->setObjectName(QString::fromUtf8("frame_opcoes"));
        frame_opcoes->setGeometry(QRect(20, 20, 221, 521));
        frame_opcoes->setFrameShape(QFrame::StyledPanel);
        frame_opcoes->setFrameShadow(QFrame::Raised);
        botao_inicio_simulacao = new QPushButton(frame_opcoes);
        botao_inicio_simulacao->setObjectName(QString::fromUtf8("botao_inicio_simulacao"));
        botao_inicio_simulacao->setGeometry(QRect(40, 430, 131, 27));
        tamanho_passo = new QSlider(frame_opcoes);
        tamanho_passo->setObjectName(QString::fromUtf8("tamanho_passo"));
        tamanho_passo->setGeometry(QRect(20, 310, 171, 19));
        tamanho_passo->setMinimum(1);
        tamanho_passo->setMaximum(200);
        tamanho_passo->setSingleStep(5);
        tamanho_passo->setPageStep(25);
        tamanho_passo->setOrientation(Qt::Horizontal);
        tamanho_passo_tela = new QTextBrowser(frame_opcoes);
        tamanho_passo_tela->setObjectName(QString::fromUtf8("tamanho_passo_tela"));
        tamanho_passo_tela->setGeometry(QRect(60, 330, 91, 31));
        botao_pausar_simulacao = new QPushButton(frame_opcoes);
        botao_pausar_simulacao->setObjectName(QString::fromUtf8("botao_pausar_simulacao"));
        botao_pausar_simulacao->setEnabled(false);
        botao_pausar_simulacao->setGeometry(QRect(40, 470, 71, 27));
        botao_parar_simulacao = new QPushButton(frame_opcoes);
        botao_parar_simulacao->setObjectName(QString::fromUtf8("botao_parar_simulacao"));
        botao_parar_simulacao->setEnabled(false);
        botao_parar_simulacao->setGeometry(QRect(120, 470, 51, 27));
        botao_avancar_simulacao = new QPushButton(frame_opcoes);
        botao_avancar_simulacao->setObjectName(QString::fromUtf8("botao_avancar_simulacao"));
        botao_avancar_simulacao->setEnabled(false);
        botao_avancar_simulacao->setGeometry(QRect(70, 390, 71, 27));
        frame_parametros = new QFrame(frame_opcoes);
        frame_parametros->setObjectName(QString::fromUtf8("frame_parametros"));
        frame_parametros->setGeometry(QRect(20, 20, 181, 271));
        frame_parametros->setFrameShape(QFrame::StyledPanel);
        frame_parametros->setFrameShadow(QFrame::Raised);
        label_parametros = new QLabel(frame_opcoes);
        label_parametros->setObjectName(QString::fromUtf8("label_parametros"));
        label_parametros->setGeometry(QRect(30, 15, 78, 17));
        label_parametros->setAutoFillBackground(true);
        visao_grafica = new QGraphicsView(centralWidget);
        visao_grafica->setObjectName(QString::fromUtf8("visao_grafica"));
        visao_grafica->setGeometry(QRect(260, 20, 541, 371));
        caixa_logs = new QTextBrowser(centralWidget);
        caixa_logs->setObjectName(QString::fromUtf8("caixa_logs"));
        caixa_logs->setGeometry(QRect(260, 410, 541, 131));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 820, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        botao_inicio_simulacao->setText(QApplication::translate("MainWindow", "Iniciar Simula\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        botao_pausar_simulacao->setText(QApplication::translate("MainWindow", "Travar", 0, QApplication::UnicodeUTF8));
        botao_parar_simulacao->setText(QApplication::translate("MainWindow", "Parar", 0, QApplication::UnicodeUTF8));
        botao_avancar_simulacao->setText(QApplication::translate("MainWindow", "Avan\303\247ar", 0, QApplication::UnicodeUTF8));
        label_parametros->setText(QApplication::translate("MainWindow", "Par\303\242metros", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
