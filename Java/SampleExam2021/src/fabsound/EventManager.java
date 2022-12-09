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
 * 
 * 	- cascadingø* :		A way of 'chaining' methods together, it only works if all methods you use return the same object. (thisø*)
 * 						-> https://www.geeksforgeeks.org/method-chaining-in-java-with-examples/
 */


package fabsound;


public class EventManager extends Musician
{
	// class variables (using privateø* and protectedø*)
	private int numHolidays;
	private String firstName, lastName;
	
	protected double numOfHours = normalNumOfHours;
	
	// class constructorø*s
	EventManager(long id, String name, double hourlyRate, int numHolidays)
	{
		// update variables (using thisø*, and referring to variables from Musician)
		this.id = id;
		this.name = name;
		this.hourlyRate = hourlyRate;
		this.numHolidays = numHolidays;
	}
	
	EventManager(long id, String firstName, String lastName)
	{
		// referencing other constructorø*, above
		this(id, firstName + " " + lastName, 0.0, 0);
		
		// cascadingø* methods
		this.setFirstName(firstName)
			.setLastName(lastName);
	}
	
	// updates the name based from first and last names
	private void updateName()
	{
		this.name = String.format("%s %s", firstName, this.lastName);
	}
	
	// methods that set the first and last name, returning this object (Question 7c)
	public EventManager setFirstName(String firstName)
	{
		this.firstName = firstName;
		this.updateName();
		return this;
	}
	
	public EventManager setLastName(String lastName)
	{
		this.lastName = lastName;
		this.updateName();
		return this;
	}
	
	// (from abstract Musician) calculates and returns the salary
	@Override
	public double calculateSalary()
	{
		return this.numOfHours * this.hourlyRate;
	}
	
	// (from abstract Musician) displays the music manager's details to output
	@Override
	public void display()
	{
		// triple quote strings let you use multiple lines without \n!
		System.out.printf(
				"""
				
				Musician (Event Manager)
				
				Name: 					%s
				ID: 					|%02d|
				Number of Holidays: 	%d
				Weekly Salary: 			%.2f
				
				""",
//			this.getClass().getName(),			
			this.name,
			this.id,
			this.numHolidays,
			calculateSalary()
		);
	}
	
	// overrides and replaces what's returned when used as a string (such as in print)
	@Override
	public String toString()
	{
		this.updateName();
		return this.name;
	}
	
	// overrides and replaces default equals method
	@Override
	public boolean equals(Object obj)
	{
		// catch in case casting or accessing errors (tl;dr prevents errors)
		try
		{
			// cast object to event manager
			EventManager tmp = (EventManager) obj;
			
			// go through fail conditions (non-equal)
			if (!tmp.name.equals(this.name)) { return false; }
			if (tmp.id != this.id) { return false; }
			if (tmp.hourlyRate != this.hourlyRate) { return false; }
			if (tmp.numHolidays != this.numHolidays) { return false; }
			
			// nothing failed, they are equal
			return true;
		}
		catch (Exception e)
		{
			// something above failed, so they're probably not equal
			return false;
		}
	}
	
	// runtime code [Question 7d-i + 13]
	public static void main(String[] args) throws Exception
	{
		// [Q7] create a new event manager object, and update it's values
		EventManager amy = new EventManager(4, "Amy Lupton", 50.0, 0);
		
		amy.numOfHours += 5;
		
		// method cascadingø*
		amy.setFirstName("Amy")
		   .setLastName("Lupton");
		
		// [Q7] create another event manager object, and print it out
		EventManager joe = new EventManager(5, "Joe", "Lupton");		// ? .. not exactly sure why it asks for 'joe' not 'amy' Q7i
		
		System.out.println(joe);										// ? .. but here it is anyways
		
		// [Q13] compare amy to myHusband using the same params
		EventManager myHusband = new EventManager(4, "Amy Lupton", 50.0, 0);
		
		System.out.printf("\nAmy and myHusband are equal: %s", amy.equals(myHusband) ? "yes" : "no");
	}
}
