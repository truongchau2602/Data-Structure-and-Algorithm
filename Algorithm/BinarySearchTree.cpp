#include <iostream>
#define SPACE 10

using namespace std;

class TreeNode
{
    public:
        int value; // key or data
        TreeNode* left;
        TreeNode* right;

        //create a default constructor;
        TreeNode()
        {
                value = 0;
                left = NULL;
                right = NULL;
        }

        //create the parameterized constructor;
        TreeNode(int v)
        {
                value = v;
                left = NULL;
                right = NULL;
        }
};

class BST {

    public:
        TreeNode* root;

        BST()
        {
                root = NULL;
        }
        
        bool isTreeEmpty()
        {
              if (root == NULL)
                {
                        return true;
                }
                else 
                {
                        return false;
                }
        }

        void insertNode(TreeNode* new_node)
        {
                if (root == NULL)
                {
                        root = new_node;
                        cout << "Value Inserted as root node! " << endl;
                }
                else
                {
                        TreeNode* temp = root;

                        while (temp != NULL) //2.2
                        {
                                if (new_node->value == temp -> value) //2.2.1
                                {
                                        cout << "Value Already exist, " 
                                        << "Insert another value! " << endl;
                                        return;
                                }
                                else if ((new_node -> value < temp->value) && (temp -> left == NULL)) //2.2.2
                                {
                                        temp->left = new_node;
                                        cout << "Value Inserted to the LEFT! " << endl;
                                        break;
                                }
                                else if (new_node -> value < temp -> value) //2.2.3
                                {
                                        temp = temp->left;
                                }
                                else if ((new_node -> value > temp -> value) && (temp->right == NULL)) //2.2.4
                                {
                                        temp ->right = new_node;
                                        cout << "Value Inserted to the RIGHT! " << endl;
                                        break;
                                }
                                else //2.2.5
                                {
                                        temp = temp -> right;
                                }
                        }    
                }
        };

        void print2D(TreeNode *r, int space)
        {
                if (r == NULL) //Base case
                        return;
                space += SPACE; // Increase distance between levels
                print2D(r->right, space); //Process right child first
                cout << endl;
                for (int i = SPACE; i < space; i++) //Print current node after space count
                        cout << " ";
                cout << r ->value << "\n";
                print2D(r -> left, space); // Process left child
        };

        void printPreorder(TreeNode *r) // (current NODE, LEFT, RIGHT)
        {
                if (r == NULL)
                        return;
                /* first print data of node */
                cout << r->value << " ";
                /* then recur of LEFT subtree*/
                printPreorder(r ->left);
                /* now recur on RIGHT subtree*/
                printPreorder(r->right);
        };

        void printInorder(TreeNode *r) // (LEFT, current NODE, RIGHT)
        {
                if (r == NULL)
                        return;
               /* first recur on LEFT child */
                printInorder(r -> left);
                /* then print the data of node */
                cout << r->value << " ";
                /* now recur on RIGHT child*/
                printInorder(r->right); 
        };

        void printPostorder(TreeNode *r) // (LEFT, RIGHT, current NODE)
        {
                if (r == NULL)
                        return;
               /* first recur on LEFT child */
                printPostorder(r -> left);
                /* then recur on RIGHT child*/
                printPostorder(r->right); 
                /*now print the data of node */
                cout << r->value << " ";
        };

        TreeNode* searchNode(int v)
        {
                if (root == NULL)
                {
                        cout << "\n Empty Tree.\n";
                        return root;
                }
                else
                {
                        TreeNode *temp = root; //2.1
                        //temp is a pointer so it accesses the member (use ->)
                        while (temp != NULL) //2.2
                        {
                                if (v == temp ->value) //2.2.1
                                {
                                        return temp;
                                }
                                else if (v < temp->value) //2.2.2
                                {
                                        temp = temp->left;
                                }
                                else  //2.2.3
                                {
                                        temp = temp ->right;
                                }
                        }
                        return NULL;
                }
        }

        TreeNode* recursiveSearch(TreeNode* r, int val)
        {
                if (r == NULL || r->value == val)
                        return r;
                else if (val < r->value)
                        return recursiveSearch(r->left, val);
                else
                        return recursiveSearch(r->right,val);
        }

        int height(TreeNode* r)
        {
                if (r == NULL) // 1
                        return -1; //exit condition and return back to its previous step.
                else // 2
                {
                        /* compute the height of each subtree */
                        int left_height = height(r -> left); // 2.1
                        int right_height = height(r -> right); // 2.2

                        /*use the larger one */
                        if (left_height > right_height) // 2.3
                                return (left_height + 1);
                        else
                                return (right_height + 1); // 2.4
                }
        }

        // Print nodes at a given level
        void printGivenLevel(TreeNode* r, int level)
        {
                if (r == NULL)
                        return;
                else if (level == 0)
                        cout << r -> value << " ";
                else // level > 0
                        printGivenLevel(r -> left, level -1);
                        printGivenLevel(r -> right, level -1);
        }

        void printLevelOrderBFS(TreeNode* r) //Breadth-first search
        {
                int h = height(r); //calculate height of tree
                for (int i = 0; i <= h; i++)
                        printGivenLevel(r,i);
        }

        TreeNode* minValueNode(TreeNode* node)
        {
                TreeNode* current = node;
                /* Loop down to find the leftmost leaf */
                while (current ->left != NULL)
                {
                        current = current -> left;
                }
                return current;
        }

        TreeNode* deleteNode(TreeNode* r, int v)
        {
                // Base case;
                if (r == NULL) // 1
                {
                        return NULL;
                }
                // If the key to be deleted is SMALLER than the root's key (r-> value),
                // then it lies in LEFT subtree.
                else if (v < r->value) // 2
                {
                        r -> left = deleteNode(r->left,v);
                }
                // If the key to be deleted is GREATER than the root's key (r-> value),
                // then it lies in RIGHT subtree.
                else if (v > r -> value) // 3
                {
                        r ->right =deleteNode(r->right, v);
                }
                // If key is same as root's key (r->value),
                // then This is the node to be deleted.
                else // 4
                {
                        if (r->left == NULL) // 4.1
                        {
                                TreeNode* temp = r -> right;
                                delete r;
                                return temp;
                        }
                        else if (r -> right == NULL) // 4.2
                        {
                                TreeNode* temp = r-> left;
                                delete r;
                                return temp;
                        }
                        else // 4.3
                        {
                                TreeNode* temp = minValueNode(r->right);
                                r -> value = temp -> value;
                                r -> right = deleteNode(r->right, temp -> value);
                        }
                }
                return r; // 5
        }
};

int main()
{
        BST obj;
        int option,val;

        do 
        {
                cout << "What operation do you want to perform? "
                << endl << "Select option number. Enter 0 to exit." << endl;
                cout << "1. Insert Node" << endl;
                cout << "2. Search Node" << endl;
                cout << "3. Delete Node" << endl;
                cout << "4. Print / Traversal BST values" << endl;
                cout << "5. Height of Tree" << endl;
                cout << "6. Clear Screen" << endl;
                cout << "0. Exit program" << endl;

                cin >> option;

                //Node n1;
                TreeNode *new_node = new TreeNode(); //Heap memory

                switch (option)
                {
                case 0:
                        break;
                case 1:
                        cout << "INSERT" << endl;
                        cout << "Enter Value of TREE NODE to INSERT in BST: ";
                        cin >> val;
                        new_node -> value = val;
                        obj.insertNode(new_node);
                        cout << endl;
                        break;
                case 2:
                        cout << "SEARCH" << endl;
                        cout << "Enter Value of TREE NODE to SEARCH in BST: ";
                        cin >> val;
                        //new_node = obj.searchNode(val); //return address
                        new_node = obj.recursiveSearch(obj.root, val);
                        if (new_node != NULL)
                        {
                                cout << "Value Found!" << endl;
                        }
                        else
                        {
                                cout << "Value NOT Found!" << endl;
                        }
                        break;
                case 3:
                        cout << "DELETE" <<endl;
                        cout << "Enter Value of TREE NODE to DELETE in BST: ";
                        cin >> val;
                        new_node = obj.searchNode(val);
                        if (new_node != NULL)
                        {
                                obj.deleteNode(obj.root, val);
                                cout << "Value Deleted!" << endl;
                        }
                        else
                        {
                                cout << "Value NOT Found!" << endl;
                        }
                        break;
                case 4:
                        cout << "PRINT and TRAVERSE: ";
                        obj.print2D(obj.root,3);
                        cout << endl;

                        cout << "Print Level Order BFS: " << endl;
                        obj.printLevelOrderBFS(obj.root);
                        cout << endl;

                        cout << "PRE - ORDER: (current NODE, LEFT, RIGHT)" << endl;
                        obj.printPreorder(obj.root);
                        cout << endl;

                        cout << "IN - ORDER: (LEFT, current NODE, RIGHT)" << endl;
                        obj.printInorder(obj.root);
                        cout << endl;

                        cout << "POST - ORDER: (LEFT, RIGHT, current NODE)" << endl;
                        obj.printPostorder(obj.root);
                        cout <<endl;
                        break;
                case 5:
                        cout << "TREE HEIGHT" << endl;
                        cout << "Height: " << obj.height(obj.root) << endl;
                        break;
                case 6:
                        system("cls");
                        break;
                default:
                        cout << "Enter Proper Option number: " << endl;        
                }
        
        } while(option != 0);

        return 0;
}