/****************************************************************************
** Meta object code from reading C++ file 'vencicode.h'
**
** Created: Mon Apr 30 23:38:17 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../vencicode.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vencicode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VenciCode[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   11,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VenciCode[] = {
    "VenciCode\0\0,\0DrawCardAnimation(Card*,int)\0"
};

const QMetaObject VenciCode::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VenciCode,
      qt_meta_data_VenciCode, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VenciCode::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VenciCode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VenciCode::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VenciCode))
        return static_cast<void*>(const_cast< VenciCode*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VenciCode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: DrawCardAnimation((*reinterpret_cast< Card*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
