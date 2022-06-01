
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;

    Node **dimensions;

    Node(int key, int level)
    {
        this->key = key;

        // Allocate memory to forward
        dimensions = new Node*[level+1];

        // Fill forward array with 0(NULL)
        memset(dimensions, 0, sizeof(Node*)*(level+1));
    }
};

class SkipList
{
    int MAXLVL;
    float P;

    // current level of skip list 
    int level;

    // pointer to header node 
    Node *header;
public:
    SkipList(int MAXLVL, float P)
    {
        this->MAXLVL = MAXLVL;
        this->P = P;
        level = 0;

        // create header node and initialize key to -1
        header = new Node(-1, MAXLVL);
    }
    int randomLevel()
    {
        float r = (float)rand()/RAND_MAX;
        int lvl = 0;
        while (r < P && lvl < MAXLVL)
        {
            lvl++;
            r = (float)rand()/RAND_MAX;
        }
        return lvl;
    }
    Node* createNode(int key, int level)
    {
        Node *n = new Node(key, level);
        return n;
    }
    void insertElement(int key)
    {
        Node *current = header;

        Node *update[MAXLVL+1];
        memset(update, 0, sizeof(Node*)*(MAXLVL+1));


        for (int i = level; i >= 0; i--)
        {
            while (current->dimensions[i] != NULL &&
                   current->dimensions[i]->key < key)
                current = current->dimensions[i];
            update[i] = current;
        }

        /* reached level 0 and forward pointer to
           right, which is desired position to
           insert key.
        */
        current = current->dimensions[0];

        /* if current is NULL that means we have reached
           to end of the level or current's key is not equal
           to key to insert that means we have to insert
           node between update[0] and current node */
        if (current == NULL || current->key != key)
        {
            // Generate a random level for node
            int rlevel = randomLevel();

            // If random level is greater than list's current
            // level (node with highest level inserted in
            // list so far), initialize update value with pointer
            // to header for further use
            if (rlevel > level)
            {
                for (int i=level+1;i<rlevel+1;i++)
                    update[i] = header;

                // Update the list current level
                level = rlevel;
            }

            // create new node with random level generated
            Node* n = createNode(key, rlevel);

            // insert node by rearranging pointers
            for (int i=0;i<=rlevel;i++)
            {
                n->dimensions[i] = update[i]->dimensions[i];
                update[i]->dimensions[i] = n;
            }
            cout << "Successfully Inserted key " << key << "\n";
        }
    }
    void displayList()
    {
        cout<<"\n*****Skip List*****"<<"\n";
        for (int i=0;i<=level;i++)
        {
            Node *node = header->dimensions[i];
            cout << "Level " << i << ": ";
            while (node != NULL)
            {
                cout << node->key<<" ";
                node = node->dimensions[i];
            }
            cout << "\n";
        }
    }

};




// Driver to test above code 
int main()
{
    // Seed random number generator 
    srand((unsigned)time(0));

    // create SkipList object with MAXLVL and P  
    SkipList lst(3, 0.5);

    lst.insertElement(3);
    lst.insertElement(6);
    lst.insertElement(7);
    lst.insertElement(9);
    lst.insertElement(12);
    lst.insertElement(19);
    lst.insertElement(17);
    lst.insertElement(26);
    lst.insertElement(21);
    lst.insertElement(25);
    lst.displayList();
} 