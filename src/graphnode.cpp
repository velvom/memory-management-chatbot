#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // Warm up Task
    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// Task 4
//void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    //_childEdges.push_back(edge);
    // Give ownership of this outgoing graph edge to GraphNode
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
// Task 5
//void GraphNode::MoveChatbotHere(ChatBot *chatbot)
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    //_chatBot = chatbot;
    //_chatBot->SetCurrentNode(this);
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // Task 5
    // newNode->MoveChatbotHere(_chatBot);
    //_chatBot = nullptr; // invalidate pointer at source
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // Task 4
    //return _childEdges[index];
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
