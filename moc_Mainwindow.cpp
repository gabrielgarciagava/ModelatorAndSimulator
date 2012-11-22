/****************************************************************************
** Meta object code from reading C++ file 'Mainwindow.h'
**
** Created: Thu Nov 22 14:53:38 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      48,   11,   11,   11, 0x08,
      83,   11,   11,   11, 0x08,
     119,   11,   11,   11, 0x08,
     156,   11,   11,   11, 0x08,
     191,   11,   11,   11, 0x08,
     225,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,
     296,   11,   11,   11, 0x08,
     331,   11,   11,   11, 0x08,
     367,   11,   11,   11, 0x08,
     409,  403,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_botao_inicio_simulacao_clicked()\0"
    "on_botao_parar_simulacao_clicked()\0"
    "on_botao_pausar_simulacao_clicked()\0"
    "on_botao_avancar_simulacao_clicked()\0"
    "on_edit_serv_local_returnPressed()\0"
    "on_edit_suc_local_returnPressed()\0"
    "on_edit_frac_local_returnPressed()\0"
    "on_edit_serv_remoto_returnPressed()\0"
    "on_edit_suc_remoto_returnPressed()\0"
    "on_edit_frac_remoto_returnPressed()\0"
    "on_tamanho_passo_tela_textChanged()\0"
    "value\0on_tamanho_passo_valueChanged(int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_botao_inicio_simulacao_clicked(); break;
        case 1: on_botao_parar_simulacao_clicked(); break;
        case 2: on_botao_pausar_simulacao_clicked(); break;
        case 3: on_botao_avancar_simulacao_clicked(); break;
        case 4: on_edit_serv_local_returnPressed(); break;
        case 5: on_edit_suc_local_returnPressed(); break;
        case 6: on_edit_frac_local_returnPressed(); break;
        case 7: on_edit_serv_remoto_returnPressed(); break;
        case 8: on_edit_suc_remoto_returnPressed(); break;
        case 9: on_edit_frac_remoto_returnPressed(); break;
        case 10: on_tamanho_passo_tela_textChanged(); break;
        case 11: on_tamanho_passo_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
