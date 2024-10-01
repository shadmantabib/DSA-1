#include<iostream>
#include<fstream>
#include<string>


using namespace std;

 ifstream fin("off2input.txt");
  ofstream fout("offoutput.txt");
class Node
{
public:
    int value;
    Node * left;
    Node * right;

    Node()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    Node(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node * root;
    BST()
    {
        root = NULL;
    }

    Node* insertRecursive(Node *r, Node *new_node)
    {
        if(r==NULL)
        {
            r=new_node;
            cout <<"Insertion done"<<endl;
            return r;
        }

        if(new_node->value < r->value)
        {
            r->left = insertRecursive(r->left,new_node);
        }
        else if (new_node->value > r->value)
        {
            r->right = insertRecursive(r->right,new_node);
        }
        else
        {
            cout << "No duplication allowed!" << endl;
            return r;
        }

        return r;
    }


    void printPreorder1(Node * r){
        if (r == NULL)
            return;




        cout << r -> value ;
        fout << r -> value ;
        if(r->left==NULL && r->right==NULL){
            return;
        }
        cout<<"(";
         fout<<"(";
        printPreorder1(r -> left);

        cout<<")";
        fout<<")";
        cout<<"(";
         fout<<"(";
        printPreorder1(r -> right);
        cout<<")";
        fout<<")";




    }


    void printPreorder(Node * r) //(current node, Left, Right)
    {
        if (r == NULL)
            return;

        cout << r -> value << " ";
         fout << r -> value << " ";

        printPreorder(r -> left);

        printPreorder(r -> right);
    }

    void printInorder(Node * r) //  (Left, current node, Right)
    {
        if (r == NULL)
            return;

        printInorder(r -> left);

        cout << r -> value << " ";
          fout << r -> value << " ";

        printInorder(r -> right);
    }
    void printPostorder(Node * r) //(Left, Right, Root)
    {
        if (r == NULL)
            return;

        printPostorder(r -> left);

        printPostorder(r -> right);

        cout << r -> value << " ";
           fout << r -> value << " ";
    }

    Node * itsearch(int v)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            Node * temp = root;
            while (temp != NULL)
            {
                if (v == temp -> value)
                {
                    return temp;
                }
                else if (v < temp -> value)
                {
                    temp = temp -> left;
                }
                else
                {
                    temp = temp -> right;
                }
            }
            return NULL;
        }
    }

    Node * recsearch(Node * r, int val)
    {
        if (r == NULL || r -> value == val)
            return r;

        else if (val < r -> value)
            return recsearch(r -> left, val);

        else
            return recsearch(r -> right, val);
    }





    Node * minval(Node * node)
    {
        Node * current = node;

        while (current -> left != NULL)
        {
            current = current -> left;
        }
        return current;
    }

    Node * deleteNode(Node * r, int v)
    {

        if (r == NULL)
        {
            return NULL;
        }

        else if (v < r -> value)
        {
            r -> left = deleteNode(r -> left, v);
        }

        else if (v > r -> value)
        {
            r -> right = deleteNode(r -> right, v);
        }

        else
        {

            if (r -> left == NULL)
            {
                Node * temp = r -> right;
                delete r;
                return temp;
            }
            else if (r -> right == NULL)
            {
                Node * temp = r -> left;
                delete r;
                return temp;
            }
            else
            {

                Node * temp = minval(r -> right);

                r -> value = temp -> value;

                r -> right = deleteNode(r -> right, temp -> value);

            }
        }
        return r;
    }

};

int main()
{
    BST obj;
    int option, val;
    string ch2;
    string ch3;

      //Node * new_node = new Node();

      while(!fin.eof()){
        Node * new_node = new Node();
        fin>>ch2;
        fin>>ch3;
        if(ch2=="I"){
            new_node->value = stoi(ch3);
            obj.root= obj.insertRecursive(obj.root,new_node);

            obj.printPreorder1(obj.root);
            cout<<endl;
             fout<<endl;

        }
         if(ch2=="F"){
            new_node = obj.recsearch(obj.root, stoi(ch3));
            if (new_node != NULL)
            {
                cout << "TRUE" << endl;
                fout << "TRUE" << endl;
            }
            else
            {
                cout << "FALSE" << endl;
                 fout << "FALSE" << endl;
            }

         }
         if(ch2=="T"){
            if(ch3=="Pre"){
                obj.printPreorder(obj.root);
                cout<<endl;
                 fout<<endl;
            }
            if(ch3=="Post"){
                 obj.printPostorder(obj.root);
                 cout<<endl;
                 fout<<endl;
            }
            if(ch3=="In"){
                 obj.printInorder(obj.root);
                 cout<<endl;
                 fout<<endl;
            }

         }
         if(ch2=="D"){
            new_node = obj.itsearch(stoi(ch3));
            //cout<< new_node->value<<endl;
            if( new_node->left==NULL && new_node->right==NULL){
                //cout<<"NULL"<<endl;
                obj.deleteNode(obj.root, stoi(ch3));
                obj.printPreorder1(obj.root);
                cout<<endl;
                fout<<endl;
            }
              //cout<< new_node->left->value<<endl;
                //cout<< new_node->right->value<<endl;

            //if (new_node != NULL)
            //{
            //    obj.deleteNode(obj.root, val);
            //    cout << "Value Deleted" << endl;
            //}
            else
            {
                cout << "Invalid Operation" << endl;
                 fout << "Invalid Operation" << endl;
            }


         }



      }


    return 0;
}
