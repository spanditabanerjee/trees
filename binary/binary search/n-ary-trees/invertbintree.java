/* INVERTING A BINARY TREE */

class Node
{
    int data;
    Node left, right;
 
    public Node(int item)
    {
        data = item;
        left = right = null;
    }
}
 
class BinaryTree
{
    Node root;
 
    void invert()
    {
        root = invert(root);
    }
 
    Node invert(Node node)
    {
        if (node == null)
            return node;

        Node left = invert(node.left);
        Node right = invert(node.right);
 
        node.left = right;
        node.right = left;
 
        return node;
    }
 
    void inOrder()
    {
        inOrder(root);
    }
 
    void inOrder(Node node)
    {
        if (node == null)
            return;
 
        inOrder(node.left);
        System.out.print(node.data + " ");
 
        inOrder(node.right);
    }
 
   
    public static void main(String args[])
    {
        
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
 
       
        System.out.println("Inorder traversal of the input tree is :");
        tree.inOrder();
        System.out.println("");
 
       
        tree.invert();
 
        
        System.out.println("Inorder traversal of tree after inversion is : ");
        tree.inOrder();
 
    }
}