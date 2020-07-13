#pragma once

#include <vector>
#include <memory>
#include "drawer.h"

class INode
{
public:
	virtual ~INode(){}
	virtual void draw(IDrawer & ) = 0;
	virtual std::shared_ptr<INode> clone() const = 0;
};



typedef std::shared_ptr<INode> NodePtr;
typedef std::vector<NodePtr> NodeList;

class Node: public INode
{
public:
	void add(const NodePtr & node);
	virtual void draw(IDrawer & ) override;
	virtual std::shared_ptr<INode> clone() const override;

private:
	NodeList m_Children;
};

template<char open, char close>
class WrapperNode: public INode
{
	NodePtr m_Node;
public:
	WrapperNode(const NodePtr & node):
		m_Node(node)
	{
	}
	void draw(IDrawer & d) override
	{
		d.draw(open);
		m_Node->draw(d);
		d.draw(close);
	}
	virtual std::shared_ptr<INode> clone() const override
	{
		return NodePtr( new WrapperNode<open, close>(m_Node->clone()) );
	}
};

template<typename Value>
class ValueNode: public INode
{
	Value m_Value;
public:
	ValueNode(const Value & v):
		m_Value(v)
	{
	}
	void draw(IDrawer & d) override
	{
		d.draw(m_Value);
	}
	virtual std::shared_ptr<INode> clone() const override
	{
		return NodePtr( new ValueNode<Value>(m_Value) );
	}
};

typedef WrapperNode<'{', '}'> ObjectNode;
typedef WrapperNode<'[', ']'> ArrayNode;
typedef WrapperNode<'"', '"'> StringNode;
typedef ValueNode<double> NumNode;
typedef std::shared_ptr<StringNode> StringPtr;

class KeyValueNode: public INode
{
	StringPtr m_Key;
	NodePtr m_Value;
public:
	KeyValueNode(const StringPtr & key, const NodePtr & value);
	virtual void draw(IDrawer & d) override;
	virtual std::shared_ptr<INode> clone() const override;
};

template<typename Node, typename ValueType, ValueType value>
class ProxyNode: public INode
{
	NodePtr m_Data;
public:
	void draw(IDrawer & d) override
	{
		if ( !m_Data ){
			m_Data = NodePtr(new Node(value));
		}
		m_Data->draw(d);
	}
	virtual std::shared_ptr<INode> clone() const override
	{
		return NodePtr( new ProxyNode<Node, ValueType, value>() );
	}
};