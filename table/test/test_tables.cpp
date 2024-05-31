#include "gtest.h"
#include "hash.h"
#include "avl.h"
#include "unorderedlist.h"
#include "unorderedvect.h"
#include "ordered.h"


TEST(HashTableTest, InsertAndSearch) {
    HashTable<int, int, std::hash<int>> hashTable;
    hashTable.insertp(1, 100);
    hashTable.insertp(2, 200);
    EXPECT_EQ(*(hashTable.searchp(1)), 100);
    EXPECT_EQ(*(hashTable.searchp(2)), 200);
}

TEST(HashTableTest, Remove) {
    HashTable<int, int, std::hash<int>> hashTable;
    hashTable.insertp(1, 100);
    hashTable.insertp(2, 200);
    hashTable.deletep(1);
    EXPECT_EQ(hashTable.searchp(1), nullptr);
    EXPECT_EQ(*(hashTable.searchp(2)), 200);
}

TEST(AVLTreeTest, InsertAndSearch) {
    AVLTree<int, int> avlTree;
    avlTree.insert(1, 100);
    avlTree.insert(2, 200);
    EXPECT_EQ(*(avlTree.search(1)), 100);
    EXPECT_EQ(*(avlTree.search(2)), 200);
}

TEST(AVLTreeTest, Remove) {
    AVLTree<int, int> avlTree;
    avlTree.insert(1, 100);
    avlTree.insert(2, 200);
    avlTree.remove(1);
    EXPECT_EQ(avlTree.search(1), nullptr);
    EXPECT_EQ(*(avlTree.search(2)), 200);
}


TEST(UnorderedTablesListTest, InsertAndSearch) {
    UnorderedTablesList<int, int> unorderedList;
    unorderedList.insert(1, 100);
    unorderedList.insert(2, 200);
    EXPECT_EQ(*(unorderedList.search(1)), 100);
    EXPECT_EQ(*(unorderedList.search(2)), 200);
}

TEST(UnorderedTablesListTest, Remove) {
    UnorderedTablesList<int, int> unorderedList;
    unorderedList.insert(1, 100);
    unorderedList.insert(2, 200);
    unorderedList.remove(1);
    EXPECT_EQ(unorderedList.search(1), nullptr);
    EXPECT_EQ(*(unorderedList.search(2)), 200);
}
TEST(UnorderedVectorTest, InsertAndSearch) {
    UnorderedTables<int, int> unorderedVector;
    unorderedVector.insert(1, 100);
    unorderedVector.insert(2, 200);
    EXPECT_EQ(*(unorderedVector.search(1)), 100);
    EXPECT_EQ(*(unorderedVector.search(2)), 200);
}
TEST(UnorderedVectorTest, Remove) {
    UnorderedTables<int, int> unorderedVector;
    unorderedVector.insert(1, 100);
    unorderedVector.insert(2, 200);
    unorderedVector.remove(1);
    EXPECT_EQ(unorderedVector.search(1), nullptr);
    EXPECT_EQ(*(unorderedVector.search(2)), 200);
}

TEST(OrderedTest, InsertAndSearch) {
    OrderedTables<int, int> ordered;
    ordered.insert(1, 100);
    ordered.insert(2, 200);
    EXPECT_EQ(*(ordered.search(1)), 100);
    EXPECT_EQ(*(ordered.search(2)), 200);
}

TEST(OrderedTest, Remove) {
    OrderedTables<int, int> ordered;
    ordered.insert(1, 100);
    ordered.insert(2, 200);
    ordered.remove(1);
    EXPECT_EQ(ordered.search(1), nullptr);
    EXPECT_EQ(*(ordered.search(2)), 200);
}