#pragma once

#include "node.h"
#include <map>

class MapAdapterNode: public INode
{
    std::map<std::string, double> m_Object;
public:
    MapAdapterNode( const std::map<std::string, double> & d ):
        m_Object(d)
    {
    }
    void draw(IDrawer & d) override
    {
        bool isFirst = true;
        d.draw('{');
        for ( auto & i : m_Object ){
            if ( !isFirst ){
                d.draw(", ");
            } else {
                isFirst = false;
            }
            d.draw('"');
            d.draw(i.first);
            d.draw("\": ");
            d.draw(i.second);
        }
        d.draw('}');
    }
    std::shared_ptr<INode> clone()const
    {
        return std::shared_ptr<INode>(new MapAdapterNode(m_Object));
    }
};