package binarytreetest;
public class BinaryTreeTestMe {
    public static void main(String[] args) {
        new BinaryTreeTestMe().run();
    }

    static class No {
        private boolean empty;
        private boolean root;
        private int value;
        private No left;
        private No right;

        // construtor para adicionar um novo valor
        public No(int value){
            this.value = value;
            this.empty = false;
        }

        // caso seja criada empty a arvore
        public No(){
            this.empty = true;
            this.root = true;
        }

    }

    public void run() {
        No root = new No(5);           
        insert(root, 3);
        insert(root, 7);
        /* insert(root, 7);
        insert(root, 6);
        insert(root, 9);
        insert(root, 1);
        insert(root, 4);   */                 
                
        //System.out.println("Tamanho: "+size(root));
        //System.out.println("Profundidade: "+ depthMax(root));
        //System.out.println("Altura: "+ height(root));
        //printInorder(root);
        //printPostoder(root);      
        //System.out.println("Vazia: "+ isEmpty(root));
        //System.out.println("Menor valor "+minValue(root));

        delete(root, 3);
        printInorder(root);
    }

    /* IMCOMPLETE */
    private int size(No no) {  
      if ((no == null) || (no.empty)) {
        return(0); 
      }
      else { 
          // verificar caso em que ela é vazia
        return(size(no.left) + 1 + size(no.right)); 
      } 
    }      

    /* DONE */ 
    private boolean isEmpty(No no){
        if ((no == null) || (no.empty)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    /* DONE */
    private void insert(No no, int value){
        if (value < no.value) {
            if (no.left != null) { 
                // se já existir um nó, a verificação vai para ele
                insert(no.left, value);
            }
            else {
                // senão um novo nó é criado
                System.out.println("valor " +value + " adicionado a esquerda de "+no.value);
                no.left = new No(value);
            }
        }
        else if (value > no.value){
            if (no.right != null) {
                insert(no.right, value);
            }
            else {
                no.right = new No(value);
                System.out.println("valor " +value+ " adicionado a direita "+ no.value );
            }
        }
       else System.out.println("valor " + no.value +" já foi inserido!");
    }

    /* DONE */
    private void printInorder(No no){
        if (no != null) {
            printInorder(no.left);
            System.out.println(no.value);
            printInorder(no.right);
        }
    }
    
    /* DONE */
    private void printPostoder(No no) { 
        if (no != null){
            printPostoder(no.left);
            printPostoder(no.right); 

            System.out.println(no.value);
        }
    } 
  
    /* FIXME */
    private int depthMax(No no) { 
      if (no==null) { 
        return(0); 
      } 
      else { 
        int lDepth = depthMax(no.left); 
        int rDepth = depthMax(no.right);

        // use the larger + 1 
        return(Math.max(lDepth, rDepth) + 1); 
      } 
    }    

    /* FIXME */
    private int height(No no){
        if (no == null)
             return -1;
        else
             return Math.max(height(no.left), height(no.right)) + 1;
    }   
    
    /* DONE */
    private int minValue(No no) {
        if (no.left == null)
            return no.value;
        else
            return minValue(no.left);
    }
    
    /* DONE */
    private boolean search(No no, int value) {
        if (no.value == value) 
           return true;
        else if (no==null)
           return false;

        if (value > no.value)
           return search(no.right, value);
        else
           return search(no.left, value);
    }

    private No searchForDelete(No no, int value) {
        if ((no == null) || (no.value == value)) 
           return no;

        if (value > no.value)
           return searchForDelete(no.right, value);
        else
           return searchForDelete(no.left, value);
    }   
    
    private void delete(No no, int value){
        No aux = searchForDelete(no, value);
        if (aux == null) {
            System.out.println("Valor não está na árvore");
            //return null;
        }
        else {
            // node is a leaf
            if ((aux.left == null) && (aux.right == null)) {
                aux = null;
                
            }
            //else if  ONE CHILD
                // 
            //else if  TWO CHILD
                // 
        }
             //return aux;   
    }

    
    
}
