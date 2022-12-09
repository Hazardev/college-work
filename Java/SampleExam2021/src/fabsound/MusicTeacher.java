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
 * 	- finalø* :			This keyword can only be used on variables, methods and classes:
 * 						with a variable: it makes it a constant,
 * 						with a method: it prevents it from being overridden,
 * 						and with a class: it stops inheritance (making using 'extends' on it not work)
 * 						-> https://www.geeksforgeeks.org/final-keyword-in-java/
 * 	
 * 	- privateø* :		Anything made private with it's keyword limit access to only within the same class, which means;
 * 						if you make something private you can't use it outside the class.
 * 						-> https://www.javatpoint.com/private-keyword-in-java
 * 
 * 	- protectedø* :		Whatever is protected is limited from being accessed outside the current package, unless extended
 * 						from the original package.
 * 						-> https://www.geeksforgeeks.org/protected-keyword-in-java-with-examples/
 * 
 * 	- constructorø* :	A method that's called when a new object is created from the class (initializing it),
 * 						which for example, in this case would be 'new MusicTeacher()'.
 * 						You can also add multiple, that take different parameters to create!
 * 						-> https://www.w3schools.com/java/java_constructors.asp
 * 
 * 	- thisø* :			'this' is used inside methods or constructors to access the current object, it's variables, and more.
 * 						-> https://www.w3schools.com/java/ref_keyword_this.asp
 */


package fabsound;


public final class MusicTeacher extends Musician
{
	// class variables (using privateø* and protectedø*)
	private int numHolidays;
	
	protected double numOfHours = normalNumOfHours;
	protected MusicDegree degree = new MusicDegree();
	
	// class constructorø*s
	MusicTeacher(long id, String name, double hourlyRate, int numHolidays)
	{
		// update variables (using thisø*, and referring to variables from Musician)
		this.id = id;
		this.name = name;
		this.hourlyRate = hourlyRate;
		this.numHolidays = numHolidays;
	}
	
	// (from abstract Musician) calculates and returns the salary
	@Override
	public double calculateSalary()
	{
		return this.numOfHours * this.hourlyRate;
	}
	
	// (from abstract Musician) displays the music teacher's details to output
	@Override
	public void display()
	{
		// triple quote strings let you use multiple lines without \n!
		System.out.printf(
				"""
				
				Musician (Music Teacher)
				
				Name: 					%s
				ID: 					|%02d|
				Number of Holidays: 			%d
				Week Salary: 				%.2f
				
				""",
//			this.getClass().getName(),
			this.name,
			this.id,
			this.numHolidays,
			calculateSalary()
		);
	}
	
	// runtime code [Question 6c-d + 14]
	public static void main(String[] args) throws Exception
	{
		// [Q6] create a new music teacher object, then display it
		MusicTeacher seanSmith = new MusicTeacher(003, "Sean Smith", 60.00, 25);
		
		seanSmith.display();
		
		// [Q14] display the teacher's music degree
		seanSmith.degree.displayDegree();
	}
}
