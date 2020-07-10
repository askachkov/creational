#include "factory.h"
#include "adapter.h"
#include "flyweight.h"
#include "config.h"

void exec(INodeFactory & f, IDrawer & d)
{
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