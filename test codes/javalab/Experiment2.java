class methods{
    public int a;
    public String name;
    // Static method
    static{
        System.out.println("This is static");
    }
    // setters
    public void setA(int a){
        this.a = a;
    }
    public void setName(String name){
        this.name = name;
    }
    // getters
    public int getA(){
        return a;
    }
    public String getName() {
        return name;
    }
    // constructor
    methods(){
        a = 12;
        name = "Gaurang";
        System.out.println("Constructor of the class");
    }
    public static void display(){
        System.out.println("I am static method of methods class and I do not require object to be called but I require a class reference");
    }
}

public class Experiment2 {
    // static method
    public static void display(){
        System.out.println("I am static method of Experiment2 class and I do not require object to be called");
    }
    public static void main(String[] args) {
        methods obj = new methods();
        obj.setA(12);
        obj.setName("Gaurang");
        System.out.println("The value of A is: "+obj.getA());
        System.out.println("The name is: "+ obj.getName());
        methods.display();
    }
}
