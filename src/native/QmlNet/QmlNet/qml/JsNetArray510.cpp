#include <QmlNet/qml/JsNetArray.h>
#include <QmlNet/types/NetMethodInfo.h>
#include <QmlNet/types/Callbacks.h>
#include <QmlNet/types/NetTypeArrayFacade.h>
#include <QVariant>
#include <private/qv4qobjectwrapper_p.h>

QT_BEGIN_NAMESPACE

using namespace QV4;

DEFINE_OBJECT_VTABLE(NetArray);

void Heap::NetArray::init()
{
    Object::init();
    QV4::Scope scope(internalClass->engine);
    QV4::ScopedObject o(scope, this);
    o->setArrayType(Heap::ArrayData::Custom);
    o->defineAccessorProperty(QStringLiteral("length"), QV4::NetArray::method_length, nullptr);
    o->defineDefaultProperty(QStringLiteral("push"), QV4::NetArray::method_push);
    o->defineDefaultProperty(QStringLiteral("pop"), QV4::NetArray::method_pop);
    o->defineDefaultProperty(QStringLiteral("forEach"), QV4::NetArray::method_forEach);
    object = scope.engine->memoryManager->m_persistentValues->allocate();
}

void Heap::NetArray::destroy()
{
    QV4::PersistentValueStorage::free(object);
    Object::destroy();
}

ReturnedValue NetArray::create(ExecutionEngine *engine, NetValue* netValue)
{
    Scope scope(engine);
    Scoped<NetArray> r(scope, engine->memoryManager->allocObject<NetArray>());
    *r->d()->object = QObjectWrapper::wrap(scope.engine, netValue);
    return r.asReturnedValue();
}

void NetArray::method_length(const BuiltinFunction *, Scope &scope, CallData *callData)
{
    scope.result = Encode(4);
}

void NetArray::method_push(const BuiltinFunction *, Scope &scope, CallData *callData)
{

}

void NetArray::method_pop(const BuiltinFunction *, Scope &scope, CallData *callData)
{

}

void NetArray::method_forEach(const BuiltinFunction *, Scope &scope, CallData *callData)
{

}

ReturnedValue NetArray::getIndexed(const Managed *m, uint index, bool *hasProperty)
{
    return 0;
}

bool NetArray::putIndexed(Managed *m, uint index, const Value &value)
{
    return false;
}