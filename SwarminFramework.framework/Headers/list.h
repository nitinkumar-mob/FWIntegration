
/*************************************************************************
 * 
 * swarmin.ai confidential
 * 
 * 
 *  2020 -  swarmin.ai incorporated 
 *  All Rights Reserved.
 *
*************************************************************************/

#ifndef _swarmin_LIST_H
#define _swarmin_LIST_H

class cPtrNode
{
    public:
        cPtrNode(void* anObject);
        inline void* getObject() {return currObj;}

        inline void setNext(cPtrNode* nextNode) {next = nextNode;}
        inline cPtrNode* getNext() {return next;}

    private:
        void* currObj;
        cPtrNode* next;
};

class cPtrList
{
    public:
        cPtrList();
        ~cPtrList();

        void append(void* anObject);
        void append(cPtrNode* aListNode);
        // Merges the lists; deletes the container object of anotherList
        // if the second parameter is set to true.
        void appendList(cPtrList* anotherList, 
                        bool deleteAnotherList = true); 

        void deleteAllNodes();
        bool deleteNode(cPtrNode* nodeToBeDeleted);
        bool removeNode(cPtrNode* nodeToBeRemoved);

        inline void setHead(cPtrNode* aNode) {head = aNode;}
        inline cPtrNode* getHead() {return head;}

        inline cPtrNode* getTail() {return tail;}
        inline int getSize() {return numObjects;}
        inline bool isEmpty() {return (numObjects) ? false : true;}

   protected:
        void initializeList();

    private:
        int numObjects;
        cPtrNode* head;
        cPtrNode* tail;
};



#endif
