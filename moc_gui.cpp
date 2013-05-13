/****************************************************************************
** Meta object code from reading C++ file 'gui.h'
**
** Created: Mon May 13 15:53:30 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/gui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_swarm_gui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      17,   10,   10,   10, 0x0a,
      24,   10,   10,   10, 0x0a,
      38,   10,   10,   10, 0x0a,
      55,   49,   10,   10, 0x0a,
      67,   49,   10,   10, 0x0a,
      80,   49,   10,   10, 0x0a,
      96,   49,   10,   10, 0x0a,
     114,   49,   10,   10, 0x0a,
     128,   49,   10,   10, 0x0a,
     149,   49,   10,   10, 0x0a,
     164,   49,   10,   10, 0x0a,
     178,   49,   10,   10, 0x0a,
     191,   49,   10,   10, 0x0a,
     218,  210,   10,   10, 0x0a,
     238,  210,   10,   10, 0x0a,
     256,  210,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_swarm_gui[] = {
    "swarm_gui\0\0run()\0step()\0updateSpeed()\0"
    "generate()\0state\0pickUp(int)\0boxDrop(int)\0"
    "robotsDrop(int)\0secondaryBox(int)\0"
    "avoidBot(int)\0congregateColor(int)\0"
    "randomDir(int)\0pileSize(int)\0pileLoc(int)\0"
    "impurityCount(int)\0checked\0"
    "standardPiles(bool)\0sharedPiles(bool)\0"
    "centralPiles(bool)\0"
};

void swarm_gui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        swarm_gui *_t = static_cast<swarm_gui *>(_o);
        switch (_id) {
        case 0: _t->run(); break;
        case 1: _t->step(); break;
        case 2: _t->updateSpeed(); break;
        case 3: _t->generate(); break;
        case 4: _t->pickUp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->boxDrop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->robotsDrop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->secondaryBox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->avoidBot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->congregateColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->randomDir((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->pileSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->pileLoc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->impurityCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->standardPiles((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->sharedPiles((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->centralPiles((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData swarm_gui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject swarm_gui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_swarm_gui,
      qt_meta_data_swarm_gui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &swarm_gui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *swarm_gui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *swarm_gui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_swarm_gui))
        return static_cast<void*>(const_cast< swarm_gui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int swarm_gui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
