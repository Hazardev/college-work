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
 *	Even better, if you don't know what something means or does,
 *	all you need to do is double click on something that has an
 *	asteriskø* and then press Ctrl + F to find it below.
 *	
 *	Links are provided for every note since they're better explenations than mine!
 *	You can CTRL + Click them to open them. Nice quick n' easy :)
 *  
 *	REMINDER -	PLEASE.. DO NOT COPY PASTE !
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
 * 	- abstractø* :		Think of it like a 'template'; abstract methods/functions can only be used inside abstract classes
 * 						and can't have any functionality ({} body) but HAVE TO be overridden in classes that inherit it.
 * 						Inheriting from another class is as easy as using the 'extends' keyword followed by the class it's
 * 						inheriting from. You also can't make an object (using new) from an abstract class since..
 * 						it is, as said.. kind of like a 'template'!
 * 						-> https://www.w3schools.com/java/java_abstract.asp
 * 
 * 	- interfaceø* :		Similar to abstractø* classes!
 * 						It's featured by using "implements" instead of "extends".
 * 						-> https://www.w3schools.com/java/java_interface.asp
 */


package fabsound;


public interface BusinessMusicCertification
{
	// interfaceø* variables
	public final double EXAM_FEE = 1000.0;
	public final double DISCOUNT_FACTOR = 0.9;
	public final double MEDICAL_COVER = 50.0;
	
	// interfaceø* methods
	public abstract void payExamFee();
	
	default void displayExamFee()
	{
		System.out.printf("\nThe exam fee is %.2f", EXAM_FEE);
	}
	
	static void displayMedicalCover()
	{
		System.out.printf("\nThe business medical cover is %.2f", MEDICAL_COVER);
	}
}
