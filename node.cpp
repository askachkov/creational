#include "node.h"

using namespace std;

void Node::add(const NodePtr & node)
{
    m_Children.push_back(node);
}

void Node::draw(IDrawer & d)
{
    for ( int i = 0; i < m_Children.size(); ++i ){
        if ( i > 0 ){
            d.draw(", ");
        }
        m_Children[i]->draw(d);
    }
}

KeyValueNode::KeyValueNode(const StringPtr & key, const NodePtr & value):
    m_Key(key),
    m_Value(value)
{
}

void KeyValueNode::draw(IDrawer & d)
{
    m_Key->draw(d);
    d.draw(": ");
    m_Value->draw(d);
}