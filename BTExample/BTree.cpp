#include "BTree.h"
#include "StaticStack.h"
#include "QueueAsArr.h"

#include <iostream>
using namespace std;

int BTree::size(BNode* tmp)
{
	if (tmp == nullptr)
		return 0;
	else
		return 1 + size(tmp->left) + size(tmp->right);

}


void BTree::insert(int elem)
{
	BNode* prev = nullptr;
	BNode* p = root;

	//traverse til you find 
	//the spot

	while (p != nullptr)
	{
		//ukazuje na prethodnika
		prev = p;


		//ide do nullptr
		if (*p < elem)
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}


	}

	//adding algorithm

	if (prev == nullptr)

		root = new BNode(elem);

	else if (*prev < elem)
	{
		prev->right = new BNode(elem);
	}
	else 
	{
		prev->left = new BNode(elem);
	}
	this->countNodes++;

}

BNode* BTree::search(int elem)
{
	BNode* p = root;

	while(p!=nullptr)
	{

		if (*p == elem)
			return p;
		else if (*p > elem)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}

	}

}

void BTree::postOrder(BNode* ptr)
{
	if (ptr != nullptr)
	{
		//prvo deca pa koren!
		postOrder(ptr->left);
		postOrder(ptr->right);

		cout << ptr->info << " ";

	}


}
void BTree::preOrder(BNode* ptr)
{
	if (ptr != nullptr)
	{
		cout << ptr->info << " ";
		
		preOrder(ptr->left);
		preOrder(ptr->right);


	}

}
//mod for different nodes
void BTree::inOrderArr(BNode* ptr,int* data,int* i)
{
	

	if (ptr != nullptr)
	{
		
		inOrderArr(ptr->left,data,i);
		data[(*i)++] = ptr->info;
		inOrderArr(ptr->right,data,i);


	}
}

void BTree::inOrder(BNode* ptr)
{

	if (ptr != nullptr)
	{
		

		inOrder(ptr->left);
		cout << ptr->info << " \n";
		inOrder(ptr->right);

	
	}

}


void BTree::itPreOrder()
{
	BNode* tmp = this->root;
	Stek T(2 * this->countNodes);

	T.push(tmp);


	while (!T.isEmpty())
	{
		tmp = T.pop();
		cout << *tmp;

		if (tmp->right)
			T.push(tmp->right);
		if (tmp->left)
			T.push(tmp->left);


	}


}

void BTree::inItOrder()
{
	BNode* tmp = this->root;
	Stek T(2 * this->countNodes);
	bool done = 0;

	while (!done)
	{
		
		//to the leftmost node
		while (tmp != nullptr)
		{
			//pops later
			T.push(tmp);
			tmp = tmp->left;
		}
		

		tmp = T.pop();
		cout << *tmp;

		if (tmp->right != nullptr)
		{
			tmp = tmp->right;
		}
		else
			tmp = nullptr;
			
		if (T.isEmpty() && tmp==nullptr)
			done = 1;
	}
		
}


void BTree::delByCopy(BNode* t)
{
	
	if (t->right == nullptr && t->left == nullptr)
	{
		delete t;
		return;
	}

	if (t->left == nullptr)
		t = t->right;
	else if (t->right == nullptr)
		t = t->left;
	else
	{
		BNode* tmp = t->left;
		BNode* prev = t;

		//rightmost in left subtree
		while (tmp->right != nullptr)
		{
			prev = tmp;
			tmp = tmp->right;
		}

		t->info = tmp->info;

		if (prev == t)
			prev->left = tmp->left;
		else
			prev->right = tmp->left;
	}


}









void BTree::delByMerge(BNode* t)
{
	BNode* tmp = t;
	if (t != nullptr)
	{
		if (t->right == nullptr && t->left == nullptr)
		{
			delete t;
			return;
		}
		if (t->right == nullptr)//ako ima nula ili jednog potomka
		{//prvo ako nema desnog  pointer 
			//roditelja se postavlja se na levi
			*t = *t->left;
		}
		else if (t->left == nullptr)
		{

			*t = *t->right;
			
		}
		else
		{
			//rightmost is attached to 
			//right subtree of t
			//keeping the order!

			tmp = tmp->left;
			while (tmp->right != nullptr)//dokle god postoji tmp->right
			{
				tmp = tmp->right;
			}
			//dodavanje na desno podstablo
			//krajnje desnog u levom 
			//podstablu
			tmp->right = t->right;

			*t = *t->left;
		}
	}




}


void BTree::findAndDeleteMerge(int elem) {
	BNode* tmp = this->root;
	BNode* prev = nullptr;

	while (tmp != nullptr)
	{
		if (tmp->info == elem)
			break;
		prev = tmp;
		if (tmp->info < elem)
		{
			tmp = tmp->right;
		}
		else
			tmp = tmp->left;

	}

	if (tmp != nullptr && tmp->info == elem)
	{
		//delByMerge(tmp);
		delByCopy(tmp);
		/*
		if (tmp == this->root)
		{
			delByMerge(root);
		}
		else if (prev->left == tmp)
		{
			delByMerge(prev->left);
		}
		else
			delByMerge(prev->right);
		*/
	}

	else if (root != nullptr)
		throw "not found!";
	else
		throw "empty tree";

}



void BTree::itPostOrder()
{
	
	/*
	*1-  Prodje kroz leve cvorove
	*	 ubaci te i desne potomke na stek
	*
	*2-  Izbaci poslednji ubacen,
	*	 to je list najverovatnije
	*	 ispita prethodnog da li ima desnog
	*	 potomka i da li je ta vrednost
	*	 na steku
	*
	*3-	 Ako su zadovoljeni uslovi
	*	 ponovi se korak 1
	*
	*4-  Ako nisu odstampa se vrednost
	*	 levi podstablo ili desno ili koren!
	*	 postavi se vrednost na nullptr
	*	 da bi se uzela vrednost iz steka
	*	 (korak 2)
	*
	*5-  Dokle god stek nije prazan!
	*/

	BNode* ptr = this->root;
	Stek T(20);
	T.push(ptr);

	while(!T.isEmpty())
	{
		//ide do krajnje levog elementa!
		while (ptr != nullptr)
		{
			if(ptr->right)
				T.push(ptr->right);
			
			T.push(ptr);

			ptr = ptr->left;
		}
		
		ptr = T.pop();

		//ako postoji desni potomak obrada! 

		if (ptr->right != nullptr && *ptr->right == T.topElem()->info)
		{

			T.pop();

			T.push(ptr);

			ptr = ptr->right;

		}
		else
		{
			//ako nema desnog potomka 
			//odstampa levi ili pretka
			cout << ptr->info << " ";
			ptr = nullptr;
		}


	
	}


}

void BTree::breadthFirst() 
{
	QAsArr T(2*this->countNodes);
	
	BNode* tmp = this->root;

	if (tmp != nullptr)
	{
		T.enq(tmp);
		while (!T.isEmpty())
		{
			tmp = T.deq();

			cout << *tmp;

			if (tmp->left)
				T.enq(tmp->left);
			if (tmp->right)
				T.enq(tmp->right);
		}
	}
}

