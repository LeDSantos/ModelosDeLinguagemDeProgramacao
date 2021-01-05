package OlaMundo;

/**
 * UTILIZE O PROJETO DO PRIMEIRO LABORATÓRIO
 * @author santos
 */
public class OlaMundoComString {
    
    /** Creates a new instance of OlaMundoComString */
    public OlaMundoComString() {
    }
    
    public static void main(String args[]){
        String a1 = "Ola Mundo 1"; 
        String b1 = new String(a1);        
        
        System.out.print(a1);
        System.out.println(b1);
        System.out.println(new String("Ola Mundo 3"));
		
	int a = 1;
	int b = 0;
	boolean c = true;

	/*c = a & b;*/
	a = a & b;
	c = (a>1) && (b==0);
	c = (a>1) && (c);
	c = (a>1) & (b==0);
    }
    
}