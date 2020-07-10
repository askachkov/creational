#include "factory.h"
#include "adapter.h"
#include "flyweight.h"
#include "config.h"
#include "builder.h"

void exec(INodeFactory & f, IDrawer & d)
{
	Director director;
	std::shared_ptr<Node> arr = f.createGroup();
	arr->add( f.createNum(3) );
	arr->add( f.createNum(4) );
	arr->add( f.createNum(6) );

	std::map<std::string, double> mapObject;
	mapObject["height"] = 4.1;
	mapObject["width"] = 2.4;
	mapObject["depth"] = 2.2;

	std::shared_ptr<Node> obj = f.createGroup();
	obj->add(f.createPair("params", NodePtr(new MapAdapterNode(mapObject))) );
	obj->add(f.createPair("key1", f.createString("big data")));
	obj->add(f.createPair("key2", f.createString("big data")));
	obj->add(f.createPair("key3", f.createString("big data 2")));
	obj->add(f.createPair("nums", f.createArr(arr)));

	obj->add(f.createPair("proxy", NodePtr( new ProxyNode<NumNode, int, 778>() ) ));

	obj->add(f.createPair("builder", director.buidObject(f)));

	std::shared_ptr<INode> res = f.createObj(obj);
	res->draw(d);
	d.draw("\n");
	res->draw(d);
	d.draw("\n");
}

int main(int argc, char* argv[])
{
	ConsoleDrawer d;
	CashNodeFactory f;

	Config::instance().set("APP_NAME", "CRE");

	exec(f, d);
	return 0;
}

// {
//    "params":{
//       "depth":2.2,
//       "height":4.1,
//       "width":2.4
//    },
//    "key1":"big data",
//    "key2":"big data",
//    "key3":"big data",
//    "nums":[
//       3,
//       4,
//       6
//    ],
//    "proxy":778
// }

// {
//    "params":{
//       "depth":2.2,
//       "height":4.1,
//       "width":2.4
//    },
//    "key1":"big data",
//    "key2":"big data",
//    "key3":"big data 2",
//    "nums":[
//       3,
//       4,
//       6
//    ],
//    "proxy":778,
//    "builder":{
//       "header":{
//          "title":"Header Lable",
//          "margin":2,
//          "padding":3
//       },
//       "footer":{
//          "size":100500,
//          "payload":"Tm9kZVB0ciBIZWFkZXJCdWlsZGVyOjpidWlsZChJTm9kZUZhY3RvcnkgJiBmKQp7CiAgICBzdGQ6OnNoYXJlZF9wdHI8Tm9kZT4gb2JqID0gZi5jcmVhdGVHcm91cCgpOwogICAgb2JqLT5hZGQoIGYuY3JlYXRlUGFpcigidGl0bGUiLCBmLmNyZWF0ZVN0cmluZygiSGVhZGVyIExhYmxlIikpICk7CiAgICBvYmotPmFkZCggZi5jcmVhdGVQYWlyKCJtYXJnaW4iLCBmLmNyZWF0ZU51bSgyKSkgKTsKICAgIG9iai0+YWRkKCBmLmNyZWF0ZVBhaXIoInBhZGRpbmciLCBmLmNyZWF0ZU51bSgzKSkgKTsKICAgIHJldHVybiBmLmNyZWF0ZVBhaXIoImhlYWRlciIsIGYuY3JlYXRlT2JqKG9iaikpOwp9CgpOb2RlUHRyIEZvb3RlckJ1aWxkZXI6OmJ1aWxkKElOb2RlRmFjdG9yeSAmIGYpCnsKICAgIHN0ZDo6c2hhcmVkX3B0cjxOb2RlPiBvYmogPSBmLmNyZWF0ZUdyb3VwKCk7CiAgICBvYmotPmFkZCggZi5jcmVhdGVQYWlyKCJhdXRob3IiLCBmLmNyZWF0ZVN0cmluZygiT2xla3NpaSBTa2FjaGtvdiIpKSApOwogICAgb2JqLT5hZGQoIGYuY3JlYXRlUGFpcigieWVhciIsIGYuY3JlYXRlTnVtKDIwMjApKSApOwogICAgcmV0dXJuIGYuY3JlYXRlUGFpcigiZm9vdGVyIiwgZi5jcmVhdGVPYmoob2JqKSk7Cn0="
//       },
//       "footer":{
//          "author":"Oleksii Skachkov",
//          "year":2020
//       }
//    }
// }