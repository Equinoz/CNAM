package ihm;

import java.util.Scanner;

/**
 * Your class in package ihm to read from the keyboard and write on the screen
 * One issue should be to move this class to Singleton
 * @author Alain
 *
 */
public class IOKeyBoardConsole {

	// The Scanner is in another class according to MVC Design Pattern
	private static final Scanner sc = new Scanner(System.in); 

	/**
	 * example
	 * age = IOKeyBoardConsole.readANumber("enter your age :");
	 * @param text
	 * @return
	 */
	public static int readANumber(String text) {
		System.out.println(text);
		int number = sc.nextInt();		
		//System.out.println("number given = "+number);
		return number;
	}

	/**
	 * example
	 * age = IOKeyBoardConsole.readANumber("enter your age :");
	 * @param text, borne inférieure, borne supérieure
	 * @return
	 */
	public static int readANumber(String text, int min, int max) {
		int number = -1;
		while (number<min || number>max) {
		System.out.println(text);
		number = sc.nextInt();		
		//System.out.println("number given = "+number);
		}
		return number;
	}

	/**
	 * example
	 * name = IOKeyBoardConsole.readAString("Enter your name :");
	 * @param text
	 * @return
	 */
	public static String readAString(String text) {
		System.out.println(text);
		String word = sc.next();		
		//System.out.println("number given = "+word);
		return word;
	}

	/**
	 * You should only close once your scanner, at the end of the program
	 */
	public static void close() {
		sc.close();
	}

	public static void print(Object object) {
		System.out.println(object); // appel implicite à la méthode toString
	}
	
	public static void pressEnter() {
		System.out.println("press Enter to continue...");
		sc.nextLine();	
	}

	public static void viderTampon() {
		sc.nextLine();	
	}

	public static int selectMenu(String questionPrincipale, String[] choix) {
		String question=questionPrincipale+"\n";
		IOKeyBoardConsole.print(question);
		IOKeyBoardConsole.showMenuMenu(choix);
		return IOKeyBoardConsole.readANumber("entrez la ligne de votre choix : ");
	}

	public static void showMenuMenu(String[] choix) {
		String menu="";
		int position = 0;
		for (String ligne : choix) {
			menu += position+"- "+ligne+"\n";
			position++;
		}
		IOKeyBoardConsole.print(menu);
	}

	
	/**
	 * example
	 * continue = IOKeyBoardConsole.readABoolean("Do you want to play again ?");
	 * @param string
	 * @return
	 */
	public static boolean readABoolean(String string) {
		System.out.println(string+" y/Y n/N");
		String word = sc.next();		
		return word.equals("y")||word.equals("Y")||word.equals("o")||word.equals("O");
	}
	
}
