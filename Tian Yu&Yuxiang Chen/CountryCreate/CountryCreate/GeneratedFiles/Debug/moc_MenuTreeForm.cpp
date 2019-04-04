/****************************************************************************
** Meta object code from reading C++ file 'MenuTreeForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MenuTreeForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuTreeForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuTreeForm_t {
    QByteArrayData data[16];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuTreeForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuTreeForm_t qt_meta_stringdata_MenuTreeForm = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MenuTreeForm"
QT_MOC_LITERAL(1, 13, 17), // "pictureViewCliked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "logViewCliked"
QT_MOC_LITERAL(4, 46, 29), // "violateInformationViewClicked"
QT_MOC_LITERAL(5, 76, 25), // "backGroundColorSetClicked"
QT_MOC_LITERAL(6, 102, 17), // "listFontSetCliked"
QT_MOC_LITERAL(7, 120, 22), // "listFontColorSetCliked"
QT_MOC_LITERAL(8, 143, 15), // "copyrightCliked"
QT_MOC_LITERAL(9, 159, 16), // "helpButtonCliked"
QT_MOC_LITERAL(10, 176, 20), // "aboutUSButtonClicked"
QT_MOC_LITERAL(11, 197, 20), // "closeSoftwareClicked"
QT_MOC_LITERAL(12, 218, 18), // "mixSoftwareClicked"
QT_MOC_LITERAL(13, 237, 25), // "screenStatusChangeClicked"
QT_MOC_LITERAL(14, 263, 17), // "createClickSignal"
QT_MOC_LITERAL(15, 281, 16) // "QTreeWidgetItem*"

    },
    "MenuTreeForm\0pictureViewCliked\0\0"
    "logViewCliked\0violateInformationViewClicked\0"
    "backGroundColorSetClicked\0listFontSetCliked\0"
    "listFontColorSetCliked\0copyrightCliked\0"
    "helpButtonCliked\0aboutUSButtonClicked\0"
    "closeSoftwareClicked\0mixSoftwareClicked\0"
    "screenStatusChangeClicked\0createClickSignal\0"
    "QTreeWidgetItem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuTreeForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,
       8,    0,   85,    2, 0x06 /* Public */,
       9,    0,   86,    2, 0x06 /* Public */,
      10,    0,   87,    2, 0x06 /* Public */,
      11,    0,   88,    2, 0x06 /* Public */,
      12,    0,   89,    2, 0x06 /* Public */,
      13,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,   91,    2, 0x0a /* Public */,

 // signals: parameters
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

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,    2,    2,

       0        // eod
};

void MenuTreeForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MenuTreeForm *_t = static_cast<MenuTreeForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pictureViewCliked(); break;
        case 1: _t->logViewCliked(); break;
        case 2: _t->violateInformationViewClicked(); break;
        case 3: _t->backGroundColorSetClicked(); break;
        case 4: _t->listFontSetCliked(); break;
        case 5: _t->listFontColorSetCliked(); break;
        case 6: _t->copyrightCliked(); break;
        case 7: _t->helpButtonCliked(); break;
        case 8: _t->aboutUSButtonClicked(); break;
        case 9: _t->closeSoftwareClicked(); break;
        case 10: _t->mixSoftwareClicked(); break;
        case 11: _t->screenStatusChangeClicked(); break;
        case 12: _t->createClickSignal((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::pictureViewCliked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::logViewCliked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::violateInformationViewClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::backGroundColorSetClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::listFontSetCliked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::listFontColorSetCliked)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::copyrightCliked)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::helpButtonCliked)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::aboutUSButtonClicked)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::closeSoftwareClicked)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::mixSoftwareClicked)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MenuTreeForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuTreeForm::screenStatusChangeClicked)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MenuTreeForm::staticMetaObject = {
    { &CFWidget::staticMetaObject, qt_meta_stringdata_MenuTreeForm.data,
      qt_meta_data_MenuTreeForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MenuTreeForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuTreeForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuTreeForm.stringdata0))
        return static_cast<void*>(this);
    return CFWidget::qt_metacast(_clname);
}

int MenuTreeForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CFWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MenuTreeForm::pictureViewCliked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MenuTreeForm::logViewCliked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MenuTreeForm::violateInformationViewClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MenuTreeForm::backGroundColorSetClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MenuTreeForm::listFontSetCliked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MenuTreeForm::listFontColorSetCliked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MenuTreeForm::copyrightCliked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MenuTreeForm::helpButtonCliked()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MenuTreeForm::aboutUSButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MenuTreeForm::closeSoftwareClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MenuTreeForm::mixSoftwareClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void MenuTreeForm::screenStatusChangeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
