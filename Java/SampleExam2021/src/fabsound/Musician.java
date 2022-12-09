/**
 *	@credit hazardev - All rights reserved.
 *	@license MIT
 */

/**
 * 	< Info >
 * 	
 * 	You can find information / explenation about something commented
 * 	in the notes' section below!
 * 
 * 	Even better, if you don't know what something means or does,
 *  all you need to do is double click on something that has an
 *  asteriskø* and then press Ctrl + F to find it below.
 *  
 *  Links are provided for every note since they're better explenations than mine!
 *  You can CTRL + Click them to open them. Nice quick n' easy :)
 *  
 *  REMINDER - 	PLEASE.. DO NOT COPY PASTE !
 *  			unless.. you've fully changed the :
 *  			- structure
 *  			- variable names
 *  			- comments
 *  			... to where it's FULLY your own code.
 */

/** 
 * 	< Notes >
 * 	
 * 	- publicø* : 		A keyword that allows access to a class, variable or method from anywhere including outside the package.
 * 						-> https://www.javatpoint.com/public-keyword-in-java
 * 
 * 	- protectedø* :		Whatever is protected is limited from being accessed outside the current package, unless extended
 * 						from the original package.
 * 						-> https://www.geeksforgeeks.org/protected-keyword-in-java-with-examples/
 * 
 * 	- staticø* :		This keyword simply lets you use the method, variable, or whatever you're making static directly,
 * 						in the same class. It can also be used to make a static block of code (using 'static {}') that
 * 						runs exactly once only when the class is first loaded.
 * 						-> https://www.geeksforgeeks.org/static-keyword-java/
 * 
 * 	- abstractø* :		Think of it like a 'template'; abstract methods/functions can only be used inside abstract classes
 * 						and can't have any functionality ({} body) but HAVE TO be overridden in classes that inherit it.
 * 						Inheriting from another class is as easy as using the 'extends' keyword followed by the class it's
 * 						inheriting from. You also can't make an object (using new) from an abstract class since..
 * 						it is, as said.. kind of like a 'template'!
 * 						-> https://www.w3schools.com/java/java_abstract.asp
 */


package fabsound;


public abstract class Musician
{
	// class variables (using protectedø*, publicø* and staticø*)
	protected long id;
	protected String name;
	protected double hourlyRate;
	protected double normalNumOfHours = 37.5;
	
	public static double medicalCover = 500;
	
	// abstractø* methods for calculating the salary, and displaying the musician
	public abstract double calculateSalary();
	
	public abstract void display();
	
	// a staticø* method for displaying the medical cover for the musician
	public static void displayMedicalCover()
	{
		System.out.printf("\nThe musician medical cover is %.2f", medicalCover);
	}
}
