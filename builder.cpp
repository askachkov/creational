#include "builder.h"
#include "factory.h"

Director::Director()
{
    m_Builders.push_back( Ptr(new HeaderBuilder) );
    m_Builders.push_back( Ptr(new BodyBuilder) );
    m_Builders.push_back( Ptr(new FooterBuilder) );
}

NodePtr Director::buidObject(INodeFactory & f)
{
    std::shared_ptr<Node> obj = f.createGroup();
    for ( auto & i : m_Builders ){
        obj->add(i->build(f));
    }
    return f.createObj(obj);
}

NodePtr HeaderBuilder::build(INodeFactory & f)
{
    std::shared_ptr<Node> obj = f.createGroup();
    obj->add( f.createPair("title", f.createString("Header Lable")) );
    obj->add( f.createPair("margin", f.createNum(2)) );
    obj->add( f.createPair("padding", f.createNum(3)) );
    return f.createPair("header", f.createObj(obj));
}

NodePtr FooterBuilder::build(INodeFactory & f)
{
    std::shared_ptr<Node> obj = f.createGroup();
    obj->add( f.createPair("author", f.createString("Oleksii Skachkov")) );
    obj->add( f.createPair("year", f.createNum(2020)) );
    return f.createPair("footer", f.createObj(obj));
}

NodePtr BodyBuilder::build(INodeFactory & f)
{
    std::shared_ptr<Node> obj = f.createGroup();
    obj->add( f.createPair("size", f.createNum(100500)) );
    obj->add( f.createPair("payload", f.createString("Tm9kZVB0ciBIZWFkZXJCdWlsZGVyOjpidWlsZChJTm9kZUZhY3RvcnkgJiBmKQp7CiAgICBzdGQ6OnNoYXJlZF9wdHI8Tm9kZT4gb2JqID0gZi5jcmVhdGVHcm91cCgpOwogICAgb2JqLT5hZGQoIGYuY3JlYXRlUGFpcigidGl0bGUiLCBmLmNyZWF0ZVN0cmluZygiSGVhZGVyIExhYmxlIikpICk7CiAgICBvYmotPmFkZCggZi5jcmVhdGVQYWlyKCJtYXJnaW4iLCBmLmNyZWF0ZU51bSgyKSkgKTsKICAgIG9iai0+YWRkKCBmLmNyZWF0ZVBhaXIoInBhZGRpbmciLCBmLmNyZWF0ZU51bSgzKSkgKTsKICAgIHJldHVybiBmLmNyZWF0ZVBhaXIoImhlYWRlciIsIGYuY3JlYXRlT2JqKG9iaikpOwp9CgpOb2RlUHRyIEZvb3RlckJ1aWxkZXI6OmJ1aWxkKElOb2RlRmFjdG9yeSAmIGYpCnsKICAgIHN0ZDo6c2hhcmVkX3B0cjxOb2RlPiBvYmogPSBmLmNyZWF0ZUdyb3VwKCk7CiAgICBvYmotPmFkZCggZi5jcmVhdGVQYWlyKCJhdXRob3IiLCBmLmNyZWF0ZVN0cmluZygiT2xla3NpaSBTa2FjaGtvdiIpKSApOwogICAgb2JqLT5hZGQoIGYuY3JlYXRlUGFpcigieWVhciIsIGYuY3JlYXRlTnVtKDIwMjApKSApOwogICAgcmV0dXJuIGYuY3JlYXRlUGFpcigiZm9vdGVyIiwgZi5jcmVhdGVPYmoob2JqKSk7Cn0=")) );
    return f.createPair("footer", f.createObj(obj));
}
