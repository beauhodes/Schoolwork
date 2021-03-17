//Beau Hodes
//EECS 560 Lab 6

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"

// The instantiating ItemType class must have the relational operators
// implemented for comparing: ItemType (on the LHS) to KeyType (on RHS).
// For example, given ItemType item and KeyType aKey, it must be valid
// to write:
//       if (item == aKey)
//          ...
//       else if (item < aKey)
//          ...

template<typename KeyType, typename ItemType>
class BinarySearchTree
{
private:
   BinaryNode<ItemType>* rootPtr;

protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------
   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
   BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr,
                                       BinaryNode<ItemType>* newNode);

  int heightHelper(BinaryNode<ItemType>* treePtr) const;

  void destroyTree(BinaryNode<ItemType>* treePtr);

  int numberOfNodesHelper(BinaryNode<ItemType>* treePtr) const;

  BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;

   // Removes the given target value from the tree while maintaining a
   // binary search tree.
   BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
                                     KeyType aKey,
                                     bool& success);

   // Removes a given node from a tree while maintaining a
   // binary search tree.
   BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);

   // Removes the leftmost node in the left subtree of the node
   // pointed to by nodePtr.
   // Sets inorderSuccessor to the value in this node.
   // Returns a pointer to the revised subtree.
   BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
                                            ItemType& inorderSuccessor);

   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
		KeyType aKey) const;

   void levelOrderHelper(BinaryNode<ItemType>* root);
   void traverseLevel(BinaryNode<ItemType>* root, int level);
   void spiralOrderHelper(BinaryNode<ItemType>* root);
   void spiralLevel(BinaryNode<ItemType>* root, int level, bool leftRight);
   void leftRightViewHelper(BinaryNode<ItemType>* root, bool isLeft);
   void leftViewPrinter(BinaryNode<ItemType>* root, int curLevel, int* deepLevel);
   void rightViewPrinter(BinaryNode<ItemType>* root, int curLevel, int* deepLevel);
   void kthSmallestHelper(BinaryNode<ItemType>* root, int k);

public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();
   BinarySearchTree(const ItemType& rootItem);
   BinarySearchTree(const BinarySearchTree<KeyType, ItemType>& tree);
   virtual ~BinarySearchTree();

   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const;
   int getHeight() const;
   int getNumberOfNodes() const;
   bool add(const ItemType& newEntry);
   bool remove(const KeyType& aKey);
   ItemType getEntry(const KeyType& aKey);
   void setEntry(const KeyType& aKey, const ItemType& item);
   bool contains(const KeyType& aKey) const;
   void clear();
   void inOrderSuccessor(int val);
   BinaryNode<ItemType>* findMin(BinaryNode<ItemType>* tracker);
   void kthSmallest(int k);
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void levelOrderPrint();
   void spiralOrderPrint();
   void leftView();
   void rightView();

   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   BinarySearchTree<KeyType, ItemType>& operator=(const BinarySearchTree<KeyType, ItemType>& rightHandSide);
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"

#endif
