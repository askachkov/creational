#pragma once

#include "node.h"

class INodeFactory
{
public:
	virtual ~INodeFactory(){}
	virtual std::shared_ptr<INode> createNum(double value) = 0;
	virtual std::shared_ptr<StringNode> createString(const std::string & s) = 0;
	virtual std::shared_ptr<INode> createPair(const std::string & key, const std::shared_ptr<INode> & value) = 0;
	virtual std::shared_ptr<Node> createGroup() = 0;
	virtual std::shared_ptr<INode> createArr(const std::shared_ptr<Node> & inner) = 0;
	virtual std::shared_ptr<INode> createObj(const std::shared_ptr<Node> & inner) = 0;
};

class Factory: public INodeFactory
{
public:
	virtual ~Factory();
	virtual std::shared_ptr<INode> createNum(double value);
	virtual std::shared_ptr<StringNode> createString(const std::string & s);
	virtual std::shared_ptr<INode> createPair(const std::string & key, const std::shared_ptr<INode> & value);
	virtual std::shared_ptr<Node> createGroup();
	virtual std::shared_ptr<INode> createArr(const std::shared_ptr<Node> & inner);
	virtual std::shared_ptr<INode> createObj(const std::shared_ptr<Node> & inner);
};