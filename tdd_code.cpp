//======== Copyright (c) 2023, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - graph
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     Nikita Koliada <xkolia00@stud.fit.vutbr.cz>
// $Date:       $17.02.2023
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author Martin Dočekal
 * @author Karel Ondřej
 *
 * @brief Implementace metod tridy reprezentujici graf.
 */

#include "tdd_code.h"


Graph::Graph(){}

Graph::~Graph(){}

std::vector<Node*> Graph::nodes() {

    return this->graphNodes;

}

std::vector<Edge> Graph::edges() const{

    return this->graphEdges;

}

Node* Graph::addNode(size_t nodeId) {
    if(this->getNode(nodeId) == nullptr) {
        Node *node = new Node(nodeId);
        if(node == NULL){
            return nullptr;
        }

        this->graphNodes.push_back(node);
        return node;
    }
    else {
        return nullptr;
    }
}

bool Graph::addEdge(const Edge& edge){
    if(edge.a == edge.b){
        return false;
    }
    if(this->containsEdge(edge) == false) {
        this->graphEdges.push_back(edge);
        if(this->getNode(edge.a) == nullptr){
            this->addNode(edge.a);
        }
        if(this->getNode(edge.b) == nullptr){
            this->addNode(edge.b);
        }
        return true;
    }
    else {
        return false;
    }
}

void Graph::addMultipleEdges(const std::vector<Edge>& edges) {
    for(auto edge : edges){
        this->addEdge(edge);
    }
}

Node* Graph::getNode(size_t nodeId){
    for(auto node : this->graphNodes){
        if(node->id == nodeId){
            return node;
        }
    }
    return nullptr;
}

bool Graph::containsEdge(const Edge& edge) const{
    for(auto tmpEdge : this->graphEdges){
        if(tmpEdge == edge){
            return true;
        }
    }
    return false;
}

void Graph::removeNode(size_t nodeId){
    Node* node = this->getNode(nodeId);
    if(node == nullptr){
        throw std::out_of_range("node does not exist");
    }

    std::vector<Edge> newEdges;

    for(auto edge : this->graphEdges){
        if(edge.a != nodeId && edge.b != nodeId){
            newEdges.push_back(edge);
        }
    }
    this->graphEdges = newEdges;
    auto it = this->graphNodes.begin();
    while (it != this->graphNodes.end()) {
        if (*it == node) {
            this->graphNodes.erase(it);
            break;
        }
        ++it;

    }
    free(node);
}

void Graph::removeEdge(const Edge& edge){
    if(this->containsEdge(edge) == false){
        throw std::out_of_range("edge does not exist");
    }
    std::vector<Edge> newEdges;
    for(auto tmpEdge : this->graphEdges){
        if(tmpEdge != edge){
            newEdges.push_back(tmpEdge);
        }
    }
    this->graphEdges = newEdges;
}

size_t Graph::nodeCount() const{
    return this->graphNodes.size();
}

size_t Graph::edgeCount() const{
    return this->graphEdges.size();
}

size_t Graph::nodeDegree(size_t nodeId) const{
    size_t nodeDegree = 0;
    for(auto edge : graphEdges){
        if(edge.a == nodeId || edge.b == nodeId){
            nodeDegree++;
        }
    }
    if(nodeDegree == 0){
        throw std::out_of_range("edge does not exist");
    }
    return nodeDegree;
}

size_t Graph::graphDegree() const{
    size_t max = 0;
    for(auto node : this->graphNodes){
        size_t tmp = this->nodeDegree(node->id);
        if(tmp > max){
            max = tmp;
        }
    }
    return max;
}

void Graph::coloring(){

    for (auto node : this->graphNodes)
    {
        unsigned color = 1;

        if (node->color)
            continue;

        node->color = color++;

        for (auto edge : this->graphEdges)
        {

            bool begin;
            bool end;
            if(edge.a == node->id)
                begin = true;
            else
                begin = false;
            if(edge.b == node->id)
                end = true;
            else
                end = false;
            Node* tmpNode = nullptr;
            if (begin) {
                tmpNode = this->getNode(edge.b);
            } else if (end) {
                tmpNode = this->getNode(edge.a);
            }
            else{ continue; }

            tmpNode->color = color++;

        }
    }
}

void Graph::clear() {
    for(auto node : this->graphNodes)
        free(node);
    this->graphNodes.clear();
    this->graphEdges.clear();
}

/*** Konec souboru tdd_code.cpp ***/
