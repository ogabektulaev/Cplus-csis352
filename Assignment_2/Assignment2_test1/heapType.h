//THIS FILE IS INCOMPLETE!
//remember to declare a node struct!
#ifndef H_heapType
#define H_heapType

#include <iostream>
#include <cassert>

using namespace std;

//Definition of the Node
template <class Type>
struct nodeType
{
        Type info;
        nodeType<Type>  *llink;
        nodeType<Type>  *rlink;
};


//Definition of the Class
template <class Type>
    class heapType 
    {
        public:
            const heapType<Type>& operator= (const heapType<Type>& h);
            bool isEmpty() const;
            Type top() const;
            void pop();
            void insert(const Type& newElement);
            int length();
            void dump() const;
			void destroyHeap(nodeType<Type>* &p);

            heapType();
            heapType(const heapType<Type>& otherHeap);
            ~heapType();

        protected:
            int count = 0;
            nodeType<Type> *heapTop;

        private:
            void copyHeap(nodeType<Type>* &copiedHeap, nodeType<Type>* otherHeap);
			void printerForDump(nodeType<Type> *p) const;
    };

    //include all function implementations in this file as well because it is a templated class!



//Overloading the assignment operator
template<class Type>
const heapType<Type>& heapType<Type>::
           operator=(const heapType<Type>& h)
{
        if (this != &h) //avoid self-copy
        {
                if (heapTop != NULL)  //if the binary tree is not empty, 
                                      //destroy the binary tree
                        pop(heapTop);

                if (h.heapTop == NULL) //otherTree is empty
                        heapTop = NULL;
                else
                        copyHeap(heapTop, h.heapTop);
        }//end else

   return *this;
}


//isEmpty() 
template<class Type>
bool heapType<Type>::isEmpty() const
{
        return (heapTop == NULL);
}


//top() const
template<class Type>
Type heapType<Type>::top() const
{
	return heapTop;
}


//void pop()
template<class Type>
void heapType<Type>::pop()
{
     nodeType<Type> *current;    //pointer to traverse 
                                     //the tree
     nodeType<Type> *trailCurrent;   //pointer behind current
     nodeType<Type> *temp;        //pointer to delete the node

     if (heapTop == NULL)
         cout << "Error: The node to be deleted is NULL."
              << endl;
     else if (heapTop->llink == NULL && heapTop->rlink == NULL)
          {
             temp = heapTop;
             heapTop = NULL;
             delete temp;
          }
     else if (heapTop->llink == NULL)
          {
             temp = heapTop;
             heapTop = temp->rlink;
             delete temp;
          }
     else if (heapTop->rlink == NULL)
          {
             temp = heapTop;
             heapTop = temp->llink;
             delete temp;
          }
     else
     {
        current = heapTop->llink;
        trailCurrent = NULL;

        while (current->rlink != NULL)
        {
            trailCurrent = current;
            current = current->rlink;
        }//end while

        heapTop->info = current->info;

        if (trailCurrent == NULL) //current did not move; 
                                  //current == p->llink; adjust p
            heapTop->llink = current->llink;
        else
            trailCurrent->rlink = current->llink;
 
        delete current;
     }//end else
}//end deleteFromTree



//insert()
template<class Type>
void heapType<Type>::insert(const Type& newElement){
	nodeType<Type> *current;  //pointer to traverse the tree
    nodeType<Type> *trailCurrent; //pointer behind current
    nodeType<Type> *newNode;  //pointer to create the node

    newNode = new nodeType<Type>;
    assert(newNode != NULL);
    newNode->info = newElement;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (heapTop == NULL)
       heapTop = newNode;
    else
    {
       current = heapTop;
 
       while (current != NULL)
       {
           trailCurrent = current;
           if (current->info == newElement)
           {
               cout << "The item to be inserted is already in ";
               cout << "the list -- duplicates are not allowed."
                    << endl;
               return;
           }
           else{
               if (current->info > newElement)
                   current = current->llink;
               else
                   current = current->rlink;

		   
       }//end while

       if (trailCurrent->info > newElement)
           trailCurrent->llink = newNode;
       else
           trailCurrent->rlink = newNode;
   }
	//cout << "//" << count << "//" << endl;
} //function end


//int length()
template<class Type>
int heapType<Type>::length(){
	if (heapTop==NULL)
      return 0;
   else if (heapTop->llink==NULL && heapTop->rlink==NULL)
      return 1;
   else
      return length(heapTop->llink) + length(heapTop->rlink);
}


//void dump()
template<class Type>
void heapType<Type>::dump() const{
	printerForDump(heapTop);
	//cout << heapTop->llink << " :: " << heapTop->rlink << endl;
}

template<class Type>
void heapType<Type>::printerForDump(nodeType<Type> *p) const{
	if (p != NULL)
        {
			cout << p->info << " ";
			//cout << p->llink << " ";	
		    //cout << p->rlink << " ";
			printerForDump(p->llink);
            printerForDump(p->rlink);
        }
	//cout << "//" << count << "//" << endl;
}

template<class Type>
heapType<Type>::heapType()
{
	heapTop = NULL;
}


      //copy constructor
template <class Type>
heapType<Type>::heapType
              (const heapType<Type>& otherHeap)
{
        if (otherHeap.heapTop == NULL) //otherTree is empty
                heapTop = NULL;
        else
                copyHeap(heapTop, otherHeap.heapTop);
}

template <class Type>
heapType<Type>::~heapType()
{
        destroyHeap(heapTop);
}


template <class Type>
void  heapType<Type>::copyHeap(nodeType<Type>* &copiedHeap, nodeType<Type>* otherHeap)
{
        if (otherHeap == NULL)
                copiedHeap = NULL;
        else
        {
                copiedHeap = new nodeType<Type>;
                copiedHeap->info = otherHeap->info;
                copyHeap(copiedHeap->llink, otherHeap->llink);
                copyHeap(copiedHeap->rlink, otherHeap->rlink);
        }
} //end copyHeap


//destroyHeap()
template <class Type>
void  heapType<Type>::destroyHeap(nodeType<Type>* &p)
{
        if (p != NULL)
        {
                destroyHeap(p->llink);
                destroyHeap(p->rlink);
                delete p;
                p = NULL;
        }
}


#endif
