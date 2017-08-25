#ifndef BST_3358_H_
#define BST_3358_H_

// File Name: bst_3358.h
//
// Author: Jill Seaman and Brock Yarbrough
// Date: 4/21/15
// Assignment Number: 6
// CS 3358 Spring 2015
// Instructor: Jill Seaman
//
// A binary search tree

#include <iostream>
#include <cassert>

using namespace std;

template<class ItemType>
class BST_3358 {
public:


    //Constructors and destructor
    BST_3358();
    ~BST_3358();

    /****************************
     makeEmpty

     Function: Removes all the items from the BST.
     Postconditions: All the items have been removed/deallocated
     *****************************/
    void makeEmpty();


    /****************************
     insertItem

     Function: Adds newItem to the BST.
     Postconditions: newItem is in the proper position for a BST.
     *****************************/
 	void insertItem(const ItemType &);


    /****************************
     findItem

     Function: Determines if target is in BST.
     Postconditions: Returns true if the item is in the BST, else false.
     *****************************/
    bool findItem(const ItemType& x);

    /****************************
     findMin

     Function: Finds minimum element in BST.
     Preconditions: BST has at least one node.
     Postconditions: Returns the smallest element in the BST.
     *****************************/
    ItemType findMin();

    /****************************
     findMax

     Function: Finds maximum element in BST.
     Preconditions: BST has at least one node.
     Postconditions: Returns the largest element in the BST.
     *****************************/
    ItemType findMax();

    /****************************
     countNodes

     Function: Counts the number of nodes in the BST
     Postconditions: returns the number of nodes in the BST
     *****************************/
    int countNodes();

    /****************************
     preOrderTraversal

     Function: prints the preOder (Node, Left, Right) traversal to standard output
     Note: this function should print out a "#" to represent empty trees!
     Postconditions: none
     *****************************/
    void preOrderTraversal();

    /****************************
     inOrderTraversal

     Function: prints the inOder (Left, Node, Right) traversal to standard output
     Postconditions: none
     *****************************/
    void inOrderTraversal();


private:
    struct TreeNode {
        ItemType data;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode * root;

    //Private functions that are called from the public functions
    bool findItem(TreeNode* t, const ItemType& x);
    ItemType findMin(TreeNode* t);
    ItemType findMax(TreeNode* t);

    void insertItem(TreeNode*& t, const ItemType& newItem);
    void inOrderTraversal(TreeNode* t) const;
    void preOrderTraversal(TreeNode* t) const;
    int countNodes(TreeNode* t) const;
    void makeEmpty(TreeNode*& t);

};

/*******************************
 / Function implementations
 ********************************/

//***********************************************************
// BST_3358<ItemType>::BST_3358() constructor that sets the root
//  to NULL
//
// returns: nothing void.
//***********************************************************
template<class ItemType>
BST_3358<ItemType>::BST_3358 ()
{
	root = NULL;
}

//***********************************************************
// BST_3358<ItemType>::~BST_3358() destructor that destroys tree
//
// returns: nothing void.
//***********************************************************
template<class ItemType>
BST_3358<ItemType>::~BST_3358 ()
{
	makeEmpty();
}

//***********************************************************
// void BST_3358 <ItemType>::makeEmpty(TreeNode* t)
// makes the tree empty
// param-1 Treenode T: pointer to current node
//
// returns: nothing, void
//***********************************************************
template<class ItemType>
void BST_3358 <ItemType>::makeEmpty(TreeNode*& t)
{
	if (t !=NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
		t = NULL;
	}
}

//***********************************************************
// void BST_3358<ItemType>::makeEmpty() makes Tree empty
//
//
// returns: nothing void.
//***********************************************************
template<class ItemType>
void BST_3358 <ItemType>::makeEmpty()
{
    makeEmpty(root);
}

//***********************************************************
// bool BST_3358 <ItemType>::findItem(TreeNode* t, const ItemType& x)
//	looks for item passed to it n the Tree
// param-1 Treenode T: pointer to current node
// param-2 ItemType x: value being found
//
// returns: True if item is in the tree
//***********************************************************
template<class ItemType>
bool BST_3358 <ItemType>::findItem(TreeNode* t, const ItemType& x)
{
    if (t==NULL)
    	return false;
    if (x < t->data)
    	return findItem(t->left, x);
    if (x > t->data)
    	return findItem(t->right, x);

    return true;
}

//***********************************************************
// bool BST_3358 <ItemType>::findItem(const ItemType& x)
// findItem(TreeNode* t, const ItemType& x)
// param-1 ItemType& x: item being looked for
//
// returns: true if item is found
//***********************************************************
template<class ItemType>
bool BST_3358 <ItemType>::findItem(const ItemType& x)
{
    return findItem(root,x);
}

//***********************************************************
// ItemType BST_3358 <ItemType>::findMin(TreeNode* t) const
// finds minimum value in the tree
// param-1 Treenode T: pointer to current node
//
// returns: minimum value in the tree
//***********************************************************
template<class ItemType>
ItemType BST_3358 <ItemType>::findMin(TreeNode* t) {
	assert(t!=NULL);

	if (t->left)
		return findMin(t->left);
	else
		return t->data;

}

//***********************************************************
// ItemType BST_3358<ItemType>::findMin() calls findMin(TreeNode* t)
//
//
// returns: minimum value in the tree
//***********************************************************
template<class ItemType>
ItemType BST_3358 <ItemType>::findMin() {
	return findMin(root);
}

//***********************************************************
// ItemType BST_3358 <ItemType>::findMax(TreeNode* t)
// finds the max value in the tree
// param-1 Treenode T: pointer to current node
//
// returns: max value in tree.
//***********************************************************
template<class ItemType>
ItemType BST_3358 <ItemType>::findMax(TreeNode* t) {
	assert(t!=NULL);

	if (t->right)
	  return findMax(t->right);
	else
	  return t->data;

}

//***********************************************************
// ItemType BST_3358<ItemType>::findMax() calls findMax(TreeNode* t)
//
//
// returns: maximum value in tree
//***********************************************************
template<class ItemType>
ItemType BST_3358 <ItemType>::findMax() {
    return findMax(root);
}

//***********************************************************
// void BST_3358 <ItemType>::insertItem(TreeNode*& t, const ItemType& newItem)
//	inserts newitem into the tree.
// param-1 Treenode T: pointer to current node
// param-2 ItemType newItem: data being put into tree
//
// returns: nothing, void
//***********************************************************
template<class ItemType>
void BST_3358 <ItemType>::insertItem(TreeNode*& t, const ItemType& newItem)
{
	if (t == NULL)
	{
		t = new TreeNode;
		t->data = newItem;
		t->left = NULL;
		t->right = NULL;
	}
	else if (newItem < t->data)
		insertItem(t->left, newItem);

	else if (newItem > t->data)
	    insertItem(t->right, newItem);
	else
	    return;


}

//***********************************************************
// void BST_3358 <ItemType>::insertItem(const ItemType& newItem)
// calls insertItem(TreeNode*& t, const ItemType& newItem)
// param-1 ItemType newItem: item to be inserted
//
// returns: nothing, void.
//***********************************************************
template<class ItemType>
void BST_3358 <ItemType>::insertItem(const ItemType& newItem)
{
    insertItem(root, newItem);
}

//***********************************************************
// int BST_3358 <ItemType>::countNodes(TreeNode* t) const
// counts the number of nodes in the tree
// param-1 Treenode T: pointer to current node
//
// returns: number of nodes in tree.
//***********************************************************
template<class ItemType>
int BST_3358 <ItemType>::countNodes(TreeNode* t) const
{
	if (t == NULL)
		return 0;
	else
		return 1 + (countNodes(t->left) + countNodes(t->right));



}

//***********************************************************
// int BST_3358<ItemType>::countNodes() calls countNodes(TreeNode* t) const
//
//
// returns: number of nodes in the tree
//***********************************************************
template<class ItemType>
int BST_3358 <ItemType>::countNodes()
{
    return countNodes(root);

}

//***********************************************************
// void BST_3358 <ItemType>::preOrderTraversal(TreeNode* t) const
// traverses tree by node, left, then right.
// param-1 Treenode T: pointer to current node
//
// returns: nothing, void
//***********************************************************
template<class ItemType>
void BST_3358 <ItemType>::preOrderTraversal(TreeNode* t) const
{
	if (t == NULL)
	{
		cout << "#" << endl;
		return;
	}
	cout << t->data << " ";
	if (t->left)
	    preOrderTraversal(t->left);
	else
		cout << "# ";
	if (t->right)
		preOrderTraversal(t->right);
	else
		cout << "# ";
}

//***********************************************************
// void BST_3358<ItemType>::preOrderTraversal() calls
// preOrderTraversal(TreeNode* t) const
//
// returns: nothing void.
//***********************************************************
template<class ItemType>
void BST_3358 <ItemType>::preOrderTraversal()
{
    preOrderTraversal(root);
    cout << endl;
}

//***********************************************************
// void BST_3358 <ItemType>::inOrderTraversal(TreeNode* t) const
// traverses tree in order from smallest to largest
// param-1 Treenode T: pointer to current node
//
// returns: nothing, void
//***********************************************************
template<class ItemType>
void BST_3358 <ItemType>::inOrderTraversal(TreeNode* t) const
{
	if (t==NULL)
		return;
	if (t->left)
		 inOrderTraversal(t->left);
	cout << t->data << " ";
	if (t->right)
	     inOrderTraversal(t->right);
}

//***********************************************************
// void BST_3358<ItemType>::inOrderTraversal() calls
// inOrderTraversal(TreeNode* t) const
//
// returns: nothing void.
//***********************************************************
template<class ItemType>
void BST_3358 <ItemType>::inOrderTraversal()
{
    inOrderTraversal(root);
    cout << endl;
}




#endif /* BST_3358_H_ */
