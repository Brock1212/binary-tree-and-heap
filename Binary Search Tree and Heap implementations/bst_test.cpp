#include"bst_3358.h"
#include"heap_3358.h"
#include<iostream>

using namespace std;

int main()
{
	/*BST_3358<int> Tree;

	Tree.insertItem(5);
	Tree.insertItem(3);
	Tree.insertItem(8);
	Tree.insertItem(2);
	Tree.insertItem(6);
	Tree.insertItem(1);
	Tree.insertItem(3);
	Tree.insertItem(4);
	Tree.insertItem(10);
	Tree.insertItem(7);

	cout << Tree.findItem(5) << " 5" << endl;
	cout << Tree.findItem(7) << " 7" << endl;
	cout << Tree.findItem(3) << " 3" << endl;
	cout << Tree.findItem(8) << " 8" << endl;
	cout << Tree.findItem(2) << " 2" << endl;
	cout << Tree.findItem(0) << " 0" << endl;
	cout << Tree.findItem(6) << " 6" << endl;
	cout << Tree.findItem(1) << " 1" << endl;
	cout << Tree.findItem(9) << " 9" << endl;
	cout << Tree.findItem(3) << " 3" << endl;
	cout << Tree.findItem(4) << " 4" << endl;
	cout << Tree.findItem(32) << " 32" << endl;

	cout <<"in order" <<endl;
	Tree.inOrderTraversal();
	cout << endl;
	cout <<"preorder" <<endl;
	Tree.preOrderTraversal();

	cout << endl << "Number of nodes " << Tree.countNodes() << endl;
	cout << "The Min node is " << Tree.findMin() << endl;
	cout << "The Max node is " << Tree.findMax() << endl;

	cout << endl << "making Tree empty" << endl;
	Tree.makeEmpty();
	Tree.preOrderTraversal();

    cout << "done" << endl;*/

	Heap_3358<int> Heap;

	Heap.insertItem(5);
	Heap.insertItem(3);
	Heap.insertItem(8);
	Heap.insertItem(2);
	Heap.insertItem(6);
	Heap.insertItem(1);
	Heap.insertItem(3);
	Heap.insertItem(4);
    Heap.insertItem(10);
	Heap.insertItem(7);

	Heap.display();
	cout << endl << "The minimum is " << Heap.findMin() << endl;
	Heap.deleteMin();
	Heap.display();
	cout << endl << "The minimum is " << Heap.findMin() << endl;

	Heap.makeEmpty();
	Heap.insertItem(12);
	Heap.display();

	return 0;
}



