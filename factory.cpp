#include "factory.h"
#include "config.h"

std::shared_ptr<INode> Factory::createNum(double value)
{
    return std::shared_ptr<INode>(new NumNode(value));
}

std::shared_ptr<StringNode> Factory::createString(const std::string & s)
{
    std::shared_ptr<INode> innerStr(new ValueNode<std::string>(s));
    std::shared_ptr<StringNode> res(new StringNode(innerStr));
    return res;
}

std::shared_ptr<INode> Factory::createPair(const std::string & key, const std::shared_ptr<INode> & value)
{
    return std::shared_ptr<INode>(new KeyValueNode(createString(key), value));
}

std::shared_ptr<Node> Factory::createGroup()
{
    return std::shared_ptr<Node>(new Node());
}

std::shared_ptr<INode> Factory::createArr(const std::shared_ptr<Node> & inner)
{
    return std::shared_ptr<INode>(new ArrayNode(inner));
}

std::shared_ptr<INode> Factory::createObj(const std::shared_ptr<Node> & inner)
{
    return std::shared_ptr<INode>(new ObjectNode(inner));
}

Factory::~Factory()
{
}