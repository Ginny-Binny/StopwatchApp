public class JavaTester{
   public int division(int a, int b) throws ArithmeticException{
      int t = a/b;
      return t;
   }
   public static void main(String args[]){
      JavaTester obj = new JavaTester();
      try{
         System.out.println(obj.division(15,0));
      }
      catch(ArithmeticException e){
         System.out.println("You shouldn't divide number by zero");
      }
   }
}