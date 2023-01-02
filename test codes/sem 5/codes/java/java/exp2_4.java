import java.io.*;
import java.util.Scanner;

class FileReadWrite{
	
	void WriteData() {
		int age, salary, id;
		String name;
		id= Input.inputInt("Employee ID");
		name= Input.inputString("Employee name");
		age= Input.inputInt("Employee age");
		salary= Input.inputInt("Employee Salary");
		
		FileOutputStream fos;
		try {
			fos = new FileOutputStream("text.txt", true);
			DataOutputStream dos= new DataOutputStream(fos);
			
			
			dos.writeInt(id);
			dos.writeUTF(name);
			dos.writeInt(age);
			dos.writeInt(salary);
			
			dos.flush();
			fos.close();
		} catch (Exception e) {
			e.printStackTrace();
		}		
	}
	void ReadData() {
		FileInputStream fis;
		try {
			fis = new FileInputStream("text.txt");
			DataInputStream dis= new DataInputStream(fis);
			int c=1;
			while(true){
				int age, salary, id;
				String name;
				id = dis.readInt();
				name= dis.readUTF();
				age= dis.readInt();
				salary= dis.readInt();
				
				System.out.println("Employee "+ (c++));
				System.out.println("Employee Id: "+ id);
				System.out.println("Employee Name: "+ name);
				System.out.println("Age: "+age);
				System.out.println("Salary: "+ salary);
				
				System.out.println("-----------------------");

			}			
		} catch (FileNotFoundException e) {
			
		} catch (IOException e) {
		}
		
		
	}
}

public class exp2_4 {
	public static void main(String[] args) {
		FileReadWrite obj= new FileReadWrite();
		while(true) {
			System.out.println("===========================");
			System.out.println("Employee Data: \n\t1. Add employee\n\t2. Display All\n\t3. "+ "Exit");	
			int a= Input.inputInt("Option");
			
			switch (a) {
			case 1: {
				obj.WriteData();
				break;
			}
			case 2: {
				obj.ReadData();
				break;
			}
			case 3: {
				System.out.println("Exit Successully");
				System.exit(0);
				break;
			}
			default:
				System.out.println("Invalid input");
			}
		}
		
	}
}
class Input{
	static Scanner cin= new Scanner(System.in);
	static int inputInt(String a) {
		System.out.print("Enter "+a+": ");
		int aa= cin.nextInt();
		return aa;
	}
	static String inputString(String a) {
		System.out.print("Enter "+a+": ");
		String aa= cin.next();
		return aa;
    }
}
