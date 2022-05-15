#include "graphedge.h"
#include "graphnode.h"
#include <iostream>
#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// DONE
    ////
    /*
    if(_chatBot != nullptr)
    {
        
        delete _chatBot; 
        _chatBot = nullptr;
    }
    */

    ////
    //// EOF STDT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// DONE Task 2
////
void GraphNode::MoveChatbotHere(ChatBot chatBot)
{
    std::cout << "movechatbot " << std::endl;
    _chatBot = std::move(chatBot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STDT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// DONE CODE Task 4
    ////

    return _childEdges[index].get();

    ////
    //// EOF STDT CODE
}