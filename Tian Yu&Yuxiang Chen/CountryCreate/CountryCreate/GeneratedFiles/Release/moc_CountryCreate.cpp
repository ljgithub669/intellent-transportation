/****************************************************************************
** Meta object code from reading C++ file 'CountryCreate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CountryCreate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CountryCreate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CountryCreate_t {
    QByteArrayData data[14];
    char stringdata0[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CountryCreate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CountryCreate_t qt_meta_stringdata_CountryCreate = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CountryCreate"
QT_MOC_LITERAL(1, 14, 11), // "pictureView"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "logView"
QT_MOC_LITERAL(4, 35, 22), // "violateInformationView"
QT_MOC_LITERAL(5, 58, 18), // "backGroundColorSet"
QT_MOC_LITERAL(6, 77, 11), // "listFontSet"
QT_MOC_LITERAL(7, 89, 16), // "listFontColorSet"
QT_MOC_LITERAL(8, 106, 9), // "copyright"
QT_MOC_LITERAL(9, 116, 10), // "helpButton"
QT_MOC_LITERAL(10, 127, 13), // "aboutUSButton"
QT_MOC_LITERAL(11, 141, 13), // "closeSoftware"
QT_MOC_LITERAL(12, 155, 11), // "mixSoftware"
QT_MOC_LITERAL(13, 167, 18) // "screenStatusChange"

    },
    "CountryCreate\0pictureView\0\0logView\0"
    "violateInformationView\0backGroundColorSet\0"
    "listFontSet\0listFontColorSet\0copyright\0"
    "helpButton\0aboutUSButton\0closeSoftware\0"
    "mixSoftware\0screenStatusChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CountryCreate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CountryCreate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CountryCreate *_t = static_cast<CountryCreate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pictureView(); break;
        case 1: _t->logView(); break;
        case 2: _t->violateInformationView(); break;
        case 3: _t->backGroundColorSet(); break;
        case 4: _t->listFontSet(); break;
        case 5: _t->listFontColorSet(); break;
        case 6: _t->copyright(); break;
        case 7: _t->helpButton(); break;
        case 8: _t->aboutUSButton(); break;
        case 9: _t->closeSoftware(); break;
        case 10: _t->mixSoftware(); break;
        case 11: _t->screenStatusChange(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CountryCreate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CountryCreate.data,
      qt_meta_data_CountryCreate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CountryCreate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CountryCreate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CountryCreate.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CountryCreate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE