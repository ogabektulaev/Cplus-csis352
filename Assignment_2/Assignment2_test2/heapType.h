//THIS FILE IS INCOMPLETE!
//remember to declare a node struct!
#ifndef H_heapType
#define H_heapType

#include <iostream>

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
			
			//Overloading the assignment operator
            const heapType<Type>& operator= (const heapType<Type>& h);
            
			bool isEmpty() const; //returns boolean value if it is empty or not
            Type top() const; //returns the top of the heap
            void pop();  //pops the heapTop once
            void insert(const Type& newElement); //inserts new elements into the heap
            int length(); // returns the length of the heap
            void dump() const; //prints the heap elements
			void destroy(); // destroys the whole heap

            heapType();
            heapType(const heapType<Type>& otherHeap);
            ~heapType();

        protected:
            int count = 0;
            nodeType<Type> *heapTop;

        private:
            void copyHeap(nodeType<Type>* &copiedHeap, nodeType<Type>* otherHeap); //copy constructor
			void printerForDump(nodeType<Type> *p) const;
			void destroyHeap(nodeType<Type>* &p);
			int lengthHeap(nodeType<Type>* p);
    };
			




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
		return heapTop->info;
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
template <class Type>
    void heapType<Type>::insert(const Type& newElement) {
        nodeType<Type> *current;
        nodeType<Type> *trailCurrent;
        nodeType<Type> *newNode;
        bool found;
        newNode = new nodeType<Type>;
        newNode->info = newElement;
        newNode->llink = nullptr;
        newNode->rlink = nullptr;

        if (heapTop == nullptr) {
            heapTop = newNode;
            count++;
        } else {
            found = false;
            current = heapTop;
            while (current != nullptr && !found) {
                if (current -> info >= newElement) {
                    found = true;
                } else {
                    trailCurrent = current;
                    current = current -> llink;
                }
            }
            if (current == heapTop) {
                //cout << "IN CURRENT == HEAPTOP" << endl;
                heapTop -> rlink = newNode;
                newNode -> llink = heapTop;
                heapTop = newNode;
                count++;
            } else if (newElement == current -> info) {
                //cout << "IN newElement == current" << endl;
                current -> rlink = newNode;
                newNode -> llink = current;
                current = newNode;
                count++;
            } else if (newElement > current -> info) {
                //cout << "IN newElement > current" << endl;
                current -> rlink = newNode;
                newNode -> llink = trailCurrent;
                current = newNode;
                count++;
            } else {
				if (current != nullptr) {
					//cout << "the last else" << endl;
					trailCurrent -> llink = newNode;
					newNode -> rlink = trailCurrent;
					newNode -> llink = current;
					current -> rlink = newNode;
					count++;
					}
				}
        }
    }


template<class Type>
int heapType<Type>::length(){
	return count;
}

//int length()
template<class Type>
int heapType<Type>::lengthHeap(nodeType<Type> *p){
	if (p==NULL)
      return 0;
   else if (p->llink==NULL && p->rlink==NULL)
      return 1;
   else
      return lengthHeap(p->llink) + lengthHeap(p->rlink);
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
			printerForDump(p->llink);
            //printerForDump(p->rlink);
        }
}

//destroy()
template <class Type>
void heapType<Type>::destroy(){
	destroyHeap(heapTop);
}

//destroyHeap()
template <class Type>
void heapType<Type>::destroyHeap(nodeType<Type>* &p)
{
        if (p != NULL)
        {
                destroyHeap(p->llink);
                //destroyHeap(p->rlink);
                delete p;
                p = NULL;
        }
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





#endif
