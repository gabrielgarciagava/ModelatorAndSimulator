/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created: Thu Nov 22 17:23:59 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
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
    QPushButton *botao_pausar_simulacao;
    QPushButton *botao_parar_simulacao;
    QPushButton *botao_avancar_simulacao;
    QFrame *frame_parametros;
    QFrame *frame_local;
    QLabel *label_2;
    QLineEdit *edit_serv_local;
    QLineEdit *edit_suc_local;
    QLineEdit *edit_frac_local;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *frame_local_2;
    QLabel *label_3;
    QLineEdit *edit_serv_remoto;
    QLineEdit *edit_suc_remoto;
    QLineEdit *edit_frac_remoto;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_parametros;
    QFrame *frame;
    QLineEdit *tamanho_passo_tela;
    QLabel *label;
    QSlider *tamanho_passo;
    QLabel *label_10;
    QLineEdit *tamanhoDaSimulacao;
    QTabWidget *tabWidget;
    QWidget *tab_logs;
    QTextBrowser *caixa_logs;
    QWidget *tab_estatistica;
    QTextBrowser *caixa_estatistica;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(820, 638);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_opcoes = new QFrame(centralWidget);
        frame_opcoes->setObjectName(QString::fromUtf8("frame_opcoes"));
        frame_opcoes->setGeometry(QRect(20, 20, 301, 541));
        frame_opcoes->setFrameShape(QFrame::StyledPanel);
        frame_opcoes->setFrameShadow(QFrame::Raised);
        botao_inicio_simulacao = new QPushButton(frame_opcoes);
        botao_inicio_simulacao->setObjectName(QString::fromUtf8("botao_inicio_simulacao"));
        botao_inicio_simulacao->setGeometry(QRect(90, 460, 131, 27));
        botao_pausar_simulacao = new QPushButton(frame_opcoes);
        botao_pausar_simulacao->setObjectName(QString::fromUtf8("botao_pausar_simulacao"));
        botao_pausar_simulacao->setEnabled(false);
        botao_pausar_simulacao->setGeometry(QRect(40, 500, 71, 27));
        botao_parar_simulacao = new QPushButton(frame_opcoes);
        botao_parar_simulacao->setObjectName(QString::fromUtf8("botao_parar_simulacao"));
        botao_parar_simulacao->setEnabled(false);
        botao_parar_simulacao->setGeometry(QRect(120, 500, 71, 27));
        botao_avancar_simulacao = new QPushButton(frame_opcoes);
        botao_avancar_simulacao->setObjectName(QString::fromUtf8("botao_avancar_simulacao"));
        botao_avancar_simulacao->setEnabled(false);
        botao_avancar_simulacao->setGeometry(QRect(200, 500, 71, 27));
        frame_parametros = new QFrame(frame_opcoes);
        frame_parametros->setObjectName(QString::fromUtf8("frame_parametros"));
        frame_parametros->setGeometry(QRect(20, 20, 261, 331));
        frame_parametros->setFrameShape(QFrame::StyledPanel);
        frame_parametros->setFrameShadow(QFrame::Raised);
        frame_local = new QFrame(frame_parametros);
        frame_local->setObjectName(QString::fromUtf8("frame_local"));
        frame_local->setGeometry(QRect(10, 20, 241, 141));
        frame_local->setFrameShape(QFrame::StyledPanel);
        frame_local->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_local);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 0, 62, 17));
        edit_serv_local = new QLineEdit(frame_local);
        edit_serv_local->setObjectName(QString::fromUtf8("edit_serv_local"));
        edit_serv_local->setGeometry(QRect(100, 20, 41, 27));
        edit_serv_local->setLayoutDirection(Qt::LeftToRight);
        edit_serv_local->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_suc_local = new QLineEdit(frame_local);
        edit_suc_local->setObjectName(QString::fromUtf8("edit_suc_local"));
        edit_suc_local->setGeometry(QRect(110, 60, 31, 27));
        edit_suc_local->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_frac_local = new QLineEdit(frame_local);
        edit_frac_local->setObjectName(QString::fromUtf8("edit_frac_local"));
        edit_frac_local->setGeometry(QRect(110, 100, 31, 27));
        edit_frac_local->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(frame_local);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 81, 31));
        label_8 = new QLabel(frame_local);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 60, 91, 31));
        label_9 = new QLabel(frame_local);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 100, 91, 31));
        frame_local_2 = new QFrame(frame_parametros);
        frame_local_2->setObjectName(QString::fromUtf8("frame_local_2"));
        frame_local_2->setGeometry(QRect(10, 180, 241, 141));
        frame_local_2->setFrameShape(QFrame::StyledPanel);
        frame_local_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_local_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 62, 17));
        edit_serv_remoto = new QLineEdit(frame_local_2);
        edit_serv_remoto->setObjectName(QString::fromUtf8("edit_serv_remoto"));
        edit_serv_remoto->setGeometry(QRect(100, 20, 41, 27));
        edit_serv_remoto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_suc_remoto = new QLineEdit(frame_local_2);
        edit_suc_remoto->setObjectName(QString::fromUtf8("edit_suc_remoto"));
        edit_suc_remoto->setGeometry(QRect(110, 60, 31, 27));
        edit_suc_remoto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        edit_frac_remoto = new QLineEdit(frame_local_2);
        edit_frac_remoto->setObjectName(QString::fromUtf8("edit_frac_remoto"));
        edit_frac_remoto->setGeometry(QRect(110, 100, 31, 27));
        edit_frac_remoto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(frame_local_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 81, 31));
        label_6 = new QLabel(frame_local_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 60, 91, 31));
        label_7 = new QLabel(frame_local_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 100, 91, 31));
        label_parametros = new QLabel(frame_opcoes);
        label_parametros->setObjectName(QString::fromUtf8("label_parametros"));
        label_parametros->setGeometry(QRect(30, 15, 78, 17));
        label_parametros->setAutoFillBackground(true);
        frame = new QFrame(frame_opcoes);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 360, 261, 91));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tamanho_passo_tela = new QLineEdit(frame);
        tamanho_passo_tela->setObjectName(QString::fromUtf8("tamanho_passo_tela"));
        tamanho_passo_tela->setGeometry(QRect(150, 60, 41, 21));
        tamanho_passo_tela->setAlignment(Qt::AlignCenter);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 60, 81, 21));
        tamanho_passo = new QSlider(frame);
        tamanho_passo->setObjectName(QString::fromUtf8("tamanho_passo"));
        tamanho_passo->setGeometry(QRect(10, 40, 241, 19));
        tamanho_passo->setMinimum(1);
        tamanho_passo->setMaximum(500);
        tamanho_passo->setSingleStep(5);
        tamanho_passo->setPageStep(25);
        tamanho_passo->setSliderPosition(10);
        tamanho_passo->setOrientation(Qt::Horizontal);
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(15, 10, 171, 16));
        tamanhoDaSimulacao = new QLineEdit(frame);
        tamanhoDaSimulacao->setObjectName(QString::fromUtf8("tamanhoDaSimulacao"));
        tamanhoDaSimulacao->setGeometry(QRect(185, 5, 51, 27));
        tamanhoDaSimulacao->setAlignment(Qt::AlignCenter);
        frame->raise();
        botao_inicio_simulacao->raise();
        botao_pausar_simulacao->raise();
        botao_parar_simulacao->raise();
        botao_avancar_simulacao->raise();
        frame_parametros->raise();
        label_parametros->raise();
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(340, 20, 461, 541));
        tab_logs = new QWidget();
        tab_logs->setObjectName(QString::fromUtf8("tab_logs"));
        caixa_logs = new QTextBrowser(tab_logs);
        caixa_logs->setObjectName(QString::fromUtf8("caixa_logs"));
        caixa_logs->setGeometry(QRect(20, 20, 441, 471));
        tabWidget->addTab(tab_logs, QString());
        tab_estatistica = new QWidget();
        tab_estatistica->setObjectName(QString::fromUtf8("tab_estatistica"));
        caixa_estatistica = new QTextBrowser(tab_estatistica);
        caixa_estatistica->setObjectName(QString::fromUtf8("caixa_estatistica"));
        caixa_estatistica->setGeometry(QRect(10, 10, 441, 491));
        tabWidget->addTab(tab_estatistica, QString());
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

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        botao_inicio_simulacao->setText(QApplication::translate("MainWindow", "Iniciar Simula\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        botao_pausar_simulacao->setText(QApplication::translate("MainWindow", "Travar", 0, QApplication::UnicodeUTF8));
        botao_parar_simulacao->setText(QApplication::translate("MainWindow", "Parar", 0, QApplication::UnicodeUTF8));
        botao_avancar_simulacao->setText(QApplication::translate("MainWindow", "Avan\303\247ar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Local", 0, QApplication::UnicodeUTF8));
        edit_serv_local->setText(QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8));
        edit_suc_local->setText(QApplication::translate("MainWindow", "60", 0, QApplication::UnicodeUTF8));
        edit_frac_local->setText(QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Servidores :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Sucesso(%) :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Fracasso(%) :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Remoto", 0, QApplication::UnicodeUTF8));
        edit_serv_remoto->setText(QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8));
        edit_suc_remoto->setText(QApplication::translate("MainWindow", "50", 0, QApplication::UnicodeUTF8));
        edit_frac_remoto->setText(QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Servidores :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Sucesso(%) :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Fracasso(%) :", 0, QApplication::UnicodeUTF8));
        label_parametros->setText(QApplication::translate("MainWindow", "Par\303\242metros", 0, QApplication::UnicodeUTF8));
        tamanho_passo_tela->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Passos/seg :", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Tempo de Simula\303\247\303\243o(s) : ", 0, QApplication::UnicodeUTF8));
        tamanhoDaSimulacao->setText(QApplication::translate("MainWindow", "3600", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_logs), QApplication::translate("MainWindow", "Logs", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_estatistica), QApplication::translate("MainWindow", "Estat\303\255stica", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
