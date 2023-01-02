interface A{
    void show();
}
interface B{
    void disp();

}

class multiple implements A, B{

    public void show(){
        System.out.println(" This is interface a");
    }
    public void disp(){
        System.out.println(" this is interface B");
    }

    public static void main(String[] args){
       multiple m= new multiple();
       
       m.show();
       m.disp();

    }
     
}
