/****************************************************************************
** Meta object code from reading C++ file 'dynamicline.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dynamicline.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dynamicline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DynamicLine_t {
    QByteArrayData data[23];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DynamicLine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DynamicLine_t qt_meta_stringdata_DynamicLine = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DynamicLine"
QT_MOC_LITERAL(1, 12, 15), // "setSeriesValues"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "index"
QT_MOC_LITERAL(4, 35, 5), // "value"
QT_MOC_LITERAL(5, 41, 16), // "setSeriesVisible"
QT_MOC_LITERAL(6, 58, 7), // "visible"
QT_MOC_LITERAL(7, 66, 13), // "setChartTitle"
QT_MOC_LITERAL(8, 80, 5), // "title"
QT_MOC_LITERAL(9, 86, 20), // "setTimeAxisXSpanSecs"
QT_MOC_LITERAL(10, 107, 4), // "secs"
QT_MOC_LITERAL(11, 112, 18), // "setTimeAxisXFormat"
QT_MOC_LITERAL(12, 131, 6), // "format"
QT_MOC_LITERAL(13, 138, 21), // "setTimeAxisXTickCount"
QT_MOC_LITERAL(14, 160, 9), // "tickCount"
QT_MOC_LITERAL(15, 170, 13), // "setAxisYRange"
QT_MOC_LITERAL(16, 184, 3), // "min"
QT_MOC_LITERAL(17, 188, 3), // "max"
QT_MOC_LITERAL(18, 192, 18), // "setpAxisYTickCount"
QT_MOC_LITERAL(19, 211, 5), // "count"
QT_MOC_LITERAL(20, 217, 19), // "setAxisYLabelFormat"
QT_MOC_LITERAL(21, 237, 11), // "updateChart"
QT_MOC_LITERAL(22, 249, 22) // "on_LegendMarkerClicked"

    },
    "DynamicLine\0setSeriesValues\0\0index\0"
    "value\0setSeriesVisible\0visible\0"
    "setChartTitle\0title\0setTimeAxisXSpanSecs\0"
    "secs\0setTimeAxisXFormat\0format\0"
    "setTimeAxisXTickCount\0tickCount\0"
    "setAxisYRange\0min\0max\0setpAxisYTickCount\0"
    "count\0setAxisYLabelFormat\0updateChart\0"
    "on_LegendMarkerClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DynamicLine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x0a /* Public */,
       5,    2,   79,    2, 0x0a /* Public */,
       7,    1,   84,    2, 0x0a /* Public */,
       9,    1,   87,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x2a /* Public | MethodCloned */,
      13,    1,   94,    2, 0x0a /* Public */,
      15,    2,   97,    2, 0x0a /* Public */,
      18,    1,  102,    2, 0x0a /* Public */,
      20,    1,  105,    2, 0x0a /* Public */,
      21,    0,  108,    2, 0x08 /* Private */,
      22,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,   16,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DynamicLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DynamicLine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSeriesValues((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setSeriesVisible((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->setChartTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setTimeAxisXSpanSecs((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->setTimeAxisXFormat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setTimeAxisXFormat(); break;
        case 6: _t->setTimeAxisXTickCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setAxisYRange((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 8: _t->setpAxisYTickCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setAxisYLabelFormat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->updateChart(); break;
        case 11: _t->on_LegendMarkerClicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DynamicLine::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DynamicLine.data,
    qt_meta_data_DynamicLine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DynamicLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DynamicLine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DynamicLine.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DynamicLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
