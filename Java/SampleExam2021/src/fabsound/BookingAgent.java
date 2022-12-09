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
 * 	- privateø* :		Anything made private with it's keyword limit access to only within the same class, which means;
 * 						if you make something private you can't use it outside the class.
 * 						-> https://www.javatpoint.com/private-keyword-in-java
 * 
 * 	- thisø* :			'this' is used inside methods or constructors to access the current object, it's variables, and more.
 * 						-> https://www.w3schools.com/java/ref_keyword_this.asp
 */


package fabsound;


public class BookingAgent extends Musician implements BusinessMusicCertification
{
	// class variables (using privateø*)
	private double bonus;
	private double salary;
	private double numOfHours = normalNumOfHours;
	private double examFee;
	
	// class constructorø*s
	BookingAgent(String name, double hourlyRate, double bonus)
	{
		// update variables (using thisø*, and referring to variables from Musician)
		this.name = name;
		this.hourlyRate = hourlyRate;
		this.bonus = bonus;
	}
	
	// sets the agent's bonus (overloaded)
	public void setBonus(double bonus)
	{
		this.bonus = bonus;
	}
	
	public void setBonus(double bonus, double salary) // ? worded weirdly.. (take with a grain of salt)
	{
		this.salary += salary;
		this.bonus += bonus;
	}
	
	// (from abstract Musician) calculates, updates and returns the salary
	@Override
	public double calculateSalary()
	{
		this.salary = this.numOfHours * 60.0; // this.hourlyRate;
		return this.salary;
	}
	
	// (from abstract Musician) displays the music manager's details to output
	@Override
	public void display()
	{
		// triple quote strings let you use multiple lines without \n!
		System.out.printf(
				"""
				
				Musician (Booking Agent)
				
				Name: 					%s
				Salary: 				%.2f
				Bonus:					%.2f
				
				""",		
			this.name,
			calculateSalary(),
			this.bonus
		);
	}
	
	// (from interface BusinessMus..) calculates and updates the exam fee
	@Override
	public void payExamFee()
	{
		this.examFee = DISCOUNT_FACTOR * EXAM_FEE;
	}
	
	// runtime code [Question 8e + 9c + 10 + 11 + 12]
	public static void main(String[] args) throws Exception
	{
		// [Q8e] create a booking agent object and display it 
		BookingAgent jill = new BookingAgent("Jill", 60.0, 5000.0);
		jill.display();
		
		// [Q9c] 'pay' the exam fee 
		jill.payExamFee();
		
		// [Q10] print out medical covers directly from interface & class
		BusinessMusicCertification.displayMedicalCover();
		Musician.displayMedicalCover();
		
		// [Q11] create a business music cert from booking agent constructor (polymorphism)
		BusinessMusicCertification bobHorgan = new BookingAgent("Bob Horgan", 60, 2000);
		
		// [Q12] update medical cover, then compare two booking agent' medical cover
		BookingAgent.medicalCover = 2000;
		
		BookingAgent jack = new BookingAgent("Jack", 0, 0);
		BookingAgent sean = new BookingAgent("Sean", 0, 0);
		
		System.out.printf("\nJack's medical cover: %.2f\nSean's medical cover: %.2f", jack.medicalCover, sean.medicalCover);
	}
}
