/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Game_t {
    QByteArrayData data[21];
    char stringdata[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 9),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 10),
QT_MOC_LITERAL(4, 27, 6),
QT_MOC_LITERAL(5, 34, 8),
QT_MOC_LITERAL(6, 43, 12),
QT_MOC_LITERAL(7, 56, 5),
QT_MOC_LITERAL(8, 62, 5),
QT_MOC_LITERAL(9, 68, 8),
QT_MOC_LITERAL(10, 77, 6),
QT_MOC_LITERAL(11, 84, 17),
QT_MOC_LITERAL(12, 102, 13),
QT_MOC_LITERAL(13, 116, 5),
QT_MOC_LITERAL(14, 122, 14),
QT_MOC_LITERAL(15, 137, 14),
QT_MOC_LITERAL(16, 152, 15),
QT_MOC_LITERAL(17, 168, 15),
QT_MOC_LITERAL(18, 184, 9),
QT_MOC_LITERAL(19, 194, 18),
QT_MOC_LITERAL(20, 213, 10)
    },
    "Game\0turnTaken\0\0CELL_STATE\0byWhom\0"
    "nextTurn\0scoreChanged\0white\0black\0"
    "gameOver\0winner\0handleCellClicked\0"
    "BoardPosition\0where\0getPlayerName1\0"
    "getPlayerName2\0getPlayersToken\0"
    "handleTurnTaken\0_gameOver\0handleScoreChanged\0"
    "makeAIMove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       6,    2,   74,    2, 0x06 /* Public */,
       9,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   82,    2, 0x0a /* Public */,
      14,    0,   85,    2, 0x0a /* Public */,
      15,    0,   86,    2, 0x0a /* Public */,
      16,    0,   87,    2, 0x0a /* Public */,
      17,    2,   88,    2, 0x08 /* Private */,
      18,    1,   93,    2, 0x08 /* Private */,
      19,    2,   96,    2, 0x08 /* Private */,
      20,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 3,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::QString,
    QMetaType::QString,
    0x80000000 | 3,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Game *_t = static_cast<Game *>(_o);
        switch (_id) {
        case 0: _t->turnTaken((*reinterpret_cast< CELL_STATE(*)>(_a[1])),(*reinterpret_cast< CELL_STATE(*)>(_a[2]))); break;
        case 1: _t->scoreChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->gameOver((*reinterpret_cast< CELL_STATE(*)>(_a[1]))); break;
        case 3: _t->handleCellClicked((*reinterpret_cast< BoardPosition(*)>(_a[1]))); break;
        case 4: { QString _r = _t->getPlayerName1();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->getPlayerName2();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { CELL_STATE _r = _t->getPlayersToken();
            if (_a[0]) *reinterpret_cast< CELL_STATE*>(_a[0]) = _r; }  break;
        case 7: _t->handleTurnTaken((*reinterpret_cast< CELL_STATE(*)>(_a[1])),(*reinterpret_cast< CELL_STATE(*)>(_a[2]))); break;
        case 8: _t->_gameOver((*reinterpret_cast< CELL_STATE(*)>(_a[1]))); break;
        case 9: _t->handleScoreChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->makeAIMove(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Game::*_t)(CELL_STATE , CELL_STATE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::turnTaken)) {
                *result = 0;
            }
        }
        {
            typedef void (Game::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::scoreChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Game::*_t)(CELL_STATE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Game::gameOver)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Game::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Game.data,
      qt_meta_data_Game,  qt_static_metacall, 0, 0}
};


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata))
        return static_cast<void*>(const_cast< Game*>(this));
    return QObject::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Game::turnTaken(CELL_STATE _t1, CELL_STATE _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Game::scoreChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Game::gameOver(CELL_STATE _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
