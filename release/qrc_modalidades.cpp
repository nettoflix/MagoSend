/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.9.6
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // /home/mago/4SDigisend4/modalidades.dmo
  0x0,0x0,0x0,0xe,
  0x69,
  0x61,0x61,0x61,0x6f,0x62,0x61,0x73,0x61,0x64,0x61,0x73,0x64,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // modalidades.dmo
  0x0,0xf,
  0xf,0xc2,0x6e,0xbf,
  0x0,0x6d,
  0x0,0x6f,0x0,0x64,0x0,0x61,0x0,0x6c,0x0,0x69,0x0,0x64,0x0,0x61,0x0,0x64,0x0,0x65,0x0,0x73,0x0,0x2e,0x0,0x64,0x0,0x6d,0x0,0x6f,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/modalidades.dmo
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x90,0xa3,0x7a,0xb1,0x16,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_modalidades)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_modalidades)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_modalidades)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_modalidades)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_modalidades)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_modalidades)(); }
   } dummy;
}
