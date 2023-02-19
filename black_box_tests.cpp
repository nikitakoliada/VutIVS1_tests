//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     Nikita Koliada <xkolia00@stud.fit.vutbr.cz>
// $Date:       $17.02.2023
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author Nikita Koliada
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//


class NotEmptyTree : public ::testing::Test
{


    void SetUp() override {
        std::vector<std::pair<bool, Node_t*>> nodes;
        std::vector<int> keys{2, 6, 1, 3, 12, 7, 19, 23};
        notEmptyBinaryTree.InsertNodes(keys, nodes);
    }
    protected:
        BinaryTree notEmptyBinaryTree;
};


class EmptyTree : public ::testing::Test
{

protected:
    BinaryTree emptyBinaryTree;
};

class TreeAxioms : public ::testing::Test
{
    void SetUp() override {
        std::vector<std::pair<bool, Node_t*>> nodes;
        std::vector<int> keys{1, 20, 2, 6, 9, 12, 3};
        axiomTestBinaryTree.InsertNodes(keys, nodes);
    }
protected:
    BinaryTree axiomTestBinaryTree;
};

// Test inserting a new node into an empty tree
TEST_F(EmptyTree, InsertNode)
{
    auto [isNew, node] = emptyBinaryTree.InsertNode(1);
    EXPECT_TRUE(isNew);
    EXPECT_EQ(node->key, 1);

    // Clear the tree
    emptyBinaryTree.~BinaryTree();
    new (&emptyBinaryTree) BinaryTree();

}
// Test deleting a node from an empty tree
TEST_F(EmptyTree, DeleteNode)
{
    bool isDeleted = emptyBinaryTree.DeleteNode(1);
    EXPECT_FALSE(isDeleted);
}

// Test finding a node in an empty tree
TEST_F(EmptyTree, FindNode)
{
    BinaryTree::Node_t *node = emptyBinaryTree.FindNode(1);
    EXPECT_EQ(node, nullptr);
}
// Test inserting
TEST_F(NotEmptyTree, InsertNode)
{
    // Test inserting an existing node
    auto [isNew1, node1] = notEmptyBinaryTree.InsertNode(1);
    EXPECT_FALSE(isNew1);
    EXPECT_EQ(node1->key, 1);

    // Test inserting a new node
    auto [isNew2, node2] = notEmptyBinaryTree.InsertNode(8);
    EXPECT_TRUE(isNew2);
    EXPECT_EQ(node2->key, 8);

}

// Test deleting
TEST_F(NotEmptyTree, DeleteNode)
{
    // Test deleting a non-existing node
    bool isDeleted1 = notEmptyBinaryTree.DeleteNode(10);
    EXPECT_FALSE(isDeleted1);

    // Test deleting an existing node
    bool isDeleted2 = notEmptyBinaryTree.DeleteNode(3);
    EXPECT_TRUE(isDeleted2);

}

TEST_F(NotEmptyTree, FindNode)
{
    // Test finding an existing node
    BinaryTree::Node_t *node1 = notEmptyBinaryTree.FindNode(1);
    EXPECT_NE(node1, nullptr);

    // Test finding a non-existing node
    BinaryTree::Node_t *node2 = notEmptyBinaryTree.FindNode(10);
    EXPECT_EQ(node2, nullptr);
}

//1 Všechny listové uzly (tedy uzly bez potomků) jsou „černé”.
TEST_F(TreeAxioms, Axiom1){

    std::vector<Node_t*> leafNodes;

    axiomTestBinaryTree.GetLeafNodes(leafNodes);
    for (auto leaf : leafNodes) {
        ASSERT_EQ(leaf->color, BinaryTree::BLACK);
    }
}
//2 Pokud je uzel „červený”, pak jsou jeho oba potomci „černé”.
TEST_F(TreeAxioms, Axiom2){
    std::vector<BinaryTree::Node_t*> nonLeafNodes;
    axiomTestBinaryTree.GetNonLeafNodes(nonLeafNodes);
    for (auto node : nonLeafNodes){
        if (node->color == BinaryTree::RED){
            ASSERT_EQ(node->pLeft->color, BinaryTree::BLACK);
            ASSERT_EQ(node->pRight->color, BinaryTree::BLACK);
        }
    }
}

//3 Každá cesta od každého listového uzlu ke kořeni obsahuje stejný
//  počet „černých” uzlů (vizte oranžové cesty v obrázku).

TEST_F(TreeAxioms, Axiom3){
    std::vector<BinaryTree::Node_t*> leafNodes;
    axiomTestBinaryTree.GetLeafNodes(leafNodes);
    int numBlackNodes = 0;
    auto currentNode = leafNodes[0];
    while (currentNode != axiomTestBinaryTree.GetRoot()) {
        currentNode = currentNode->pParent;
        if(currentNode->color == BinaryTree::BLACK)
            numBlackNodes++;
    }
    //basically number of black nodes that we counted previously must be the same as others, otherwise it is a FAIL
    for(auto node : leafNodes){
        int expectedNumBlackNodes = 0;
        while(node != axiomTestBinaryTree.GetRoot()){
            node = node->pParent;
            if(node->color == BinaryTree::BLACK)
                expectedNumBlackNodes++;
        }

        EXPECT_EQ(numBlackNodes, expectedNumBlackNodes);
    }

}







/*** Konec souboru black_box_tests.cpp ***/
