import java.util.*;
class Card implements Comparable{
    private char symbol;
    private int number;
    public Card() {
    }

    public char getSymbol() {
        return symbol;
    }

    public void setSymbol(char symbol) {
        this.symbol = symbol;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    @Override
    public int hashCode() {
        return String.valueOf(symbol).hashCode();
    }

    @Override
    public boolean equals(Object obj){
        if (obj instanceof Card card) {
            return (card.symbol == this.symbol);
        } else {
            return false;
        }
    }

    @Override
    public int compareTo(Object o) {
        if (o.equals(symbol)) return 1;
        else return -1;
    }
}
public class exp2two {
    public static void main(String[] args) {
       Set <Card> cardSet = new HashSet<>();
       Scanner scanner = new Scanner(System.in);
        System.out.print("Number of Cards you Want ");
        int number = scanner.nextInt();
        int i=0;
        while (i != number){
            System.out.println("Enter "+(i+1)+" th card ");
            char character = scanner.next().charAt(0);
            int integer = scanner.nextInt();
            Card card = new Card();
            card.setSymbol(character);
            card.setNumber(integer);
            cardSet.add(card);
            i++;
        }
        System.out.println("Cards in Set are :");
        cardSet.forEach((printLoop)->{
            System.out.println(printLoop.getSymbol()+" -> "+ printLoop.getNumber());
        });
    }
}