// Imports
using System.Timers;
using Timer = System.Timers.Timer;


// Project Namespace
namespace ATUWhackAMole;


/**
 * 
 *	Information
 *	
 *	This is a VERY simple and VERY barebones sample answer for the first App Development asssignment!
 *   
 *  That means there are NO images, but there are variables for it.
 *  If you'd like to put in your own images, look for (CTRL+F) "IMAGE:" in this page and put in the image names in the variables.
 *   
 *  For static images, such as the background please visit the MainPage.xaml file!
 *   
 *  Please remember that uploading / presenting this project AS IS will not get you any marks, as
 *  you'd have to include licensing and original credit, and it's public on GitHub.
 *   
 *  Comments are here to explain what everything does line-by-line, and the project does in fact work and run.
 *  
 *  It's also divided into sections, for readability.
 *
 */


// Main Page Class
public partial class MainPage : ContentPage
{
    // ---------------------------------------------------------------------------------------


    // Global "Settings" (hard-coded)
    const int default_time = 60 * 5;						// what the timer resets to when a game starts (in seconds)
	const int timer_interval = 1000;                        // how long between the timer intervals, should be kept at 1s (in ms)

	const int mole_hit_points = 100;						// how many points to give for hitting a mole
	const int mole_spawn_every = 3;							// how many timer intervals / steps / (basically seconds), in between mole spawns
	const int mole_lifetime = 2800;							// how long a mole exists, before it despawns


	// Global Variables
	int score = 0;											// a variable to globally store the game scorre
	int time_remaining = 0;                                 // a variable storing the current time remaining
	int spawn_mole_in = 0;									// a variable that counts how many steps it has been, it "spawn_mole_in" _ steps

	Timer timer = new Timer();								// the timer object, that calls every "interval" (1 second by default)
	Random random = new Random();							// the RNG object, that's used to generate a random number

    List<ImageButton> holes = new List<ImageButton>();		// a list of image buttons, which are all available slots to be turned into moles
    List<ImageButton> moles = new List<ImageButton>();		// a list of image buttons, which are slots taken, filled with moles


    // ---------------------------------------------------------------------------------------


    // @Constructor: Main Page (This is the main constructor needed to initialize things, as it only runs)
    public MainPage()
	{
		// initialize this component
		InitializeComponent();

		// initialize the timer
		IntializeTimer();
	}


    // ---------------------------------------------------------------------------------------


    // @Function: Starts the game
    private void StartGame(int grid_size)
	{
		// show elements ...
		GameContainer.IsVisible = true;			// ... game screen
		StatsContainer.IsVisible = true;		// ... stats
		ResetButton.IsVisible = true;           // ... reset button

		// hide elements ...
		MenuContainer.IsVisible = false;		// ... menu screen
		GameOverContainer.IsVisible = false;	// ... game over screen

		// create game grid, using the grid size
		CreateGrid(grid_size);

		// reset all stats
		score = 0;
		time_remaining = default_time;
		spawn_mole_in = mole_spawn_every;

		// start the timer
		timer.Start();
	}


    // @Function: Stops the game (and displays game over!)
    private void StopGame()
	{
		// show elements ...
        GameOverContainer.IsVisible = true;     // ... game over screen
        StatsContainer.IsVisible = true;        // ... stats

        // hide elements ...
		GameContainer.IsVisible = false;        // ... game screen
        MenuContainer.IsVisible = false;        // ... menu screen
        ResetButton.IsVisible = false;          // ... reset button

        // clear the game grid
        DestroyGrid();

		// stop the timer
		timer.Stop();
    }


	// @Function: Resets the game (back to the main menu)
	private void ResetGame()
	{
        // show elements ...
        StatsContainer.IsVisible = true;        // ... stats
        MenuContainer.IsVisible = true;         // ... menu screen

        // hide elements ...
        GameOverContainer.IsVisible = false;    // ... game over screen
        GameContainer.IsVisible = false;        // ... game screen
        ResetButton.IsVisible = false;          // ... reset button

		// clear the game grid (if exists, unlikely)
		DestroyGrid();

		// stop the timer (if it's still running, also unlikely)
		timer.Stop();
    }


    // ---------------------------------------------------------------------------------------


	// @Function: Create game grid
	private void CreateGrid(int grid_size)
	{
		// create a new grid (and set some basic properties)
		Grid grid = new Grid();
        grid.RowSpacing = 4;
        grid.ColumnSpacing = 4;
        grid.HorizontalOptions = LayoutOptions.Center;
        grid.VerticalOptions = LayoutOptions.Center;

		// repeat grid size times
		for (int i = 0; i < grid_size; i++)
		{
			// create a row and column
			grid.ColumnDefinitions.Add(new ColumnDefinition());
			grid.RowDefinitions.Add(new RowDefinition());
		}

		// for every cell (x, y) in the grid ...
		for (int y = 0; y < grid_size; y++)
		{
			for (int x = 0; x < grid_size; x++)
			{
				// ... create a new button for the mole (and set some basic properties)
				ImageButton button = new ImageButton();
				button.WidthRequest = 64;
				button.HeightRequest = 64;
				button.BackgroundColor = Colors.Transparent;

				// ... IMAGE: set the image to a hole (empty / no mole)
				button.Source = "hole.png";

				// ... connect when it's clicked to the function/handler for it
				button.Clicked += MoleButton_Clicked;

                // ... set the button (x, y), and add it to the grid
                Grid.SetRow(button, y);
				Grid.SetColumn(button, x);
				grid.Children.Add(button);

				// ... update empty holes with the button (since it's empty)
				holes.Add(button);
			}
		}

		// finally, add the grid to the game container and make it visible
		GameContainer.Add(grid);
		GameContainer.IsVisible = true;
    }


    // @Function: Destroy the game grid
    private void DestroyGrid()
	{
		// clear the lists containing holes and moles (by creating new lists)
        holes = new List<ImageButton>();
        moles = new List<ImageButton>();

		// check if there's already a grid that exists
		if (GameContainer.Children.Count > 0)
		{
			// iterate over any objects and ...
            for(int i = 0; i < GameContainer.Children.Count; i++)
            {
				// ... remove them all
                GameContainer.Children.RemoveAt(0);
            }
        }
    }


    // ---------------------------------------------------------------------------------------

	
	// @Function: Initializes the timer (runs only once by default)
	private void IntializeTimer()
	{
		// set the timer interval
		timer.Interval = timer_interval;

		// connect the timer at intervals (elapsed) to the handler
		timer.Elapsed += TimerHandler;
	}


    // @Function(Handler): Runs at every timer interval (1 second by default)
    private void TimerHandler(object sender, ElapsedEventArgs e)
    {
		// decreaste the timer by 1
		time_remaining -= 1;

		// check if timer is done
		if (time_remaining <= 0)
		{
			// stop the timer!
			timer.Stop();

			// change it to 0, in case it went past 0
			time_remaining = 0;

			// stop the game
			StopGame();
		}

		// dispatch and run the timer updater
		Dispatcher.Dispatch(TimerUpdater);
    }


    // @Function: Timer function that runs after every interval, from above
    private void TimerUpdater()
	{
		// format the time into "mm:ss" (string)
		var formatted_time = TimeSpan.FromSeconds(time_remaining).ToString(@"mm\:ss");

        // update the label
        TimerLabel.Text = formatted_time;

		// decrease mole spawn step
		spawn_mole_in -= 1;

		// checks if it should spawn a mole
		if (spawn_mole_in <= 0)
		{
			// resets the steps
			spawn_mole_in = mole_spawn_every;

			// spawns a mole
			CreateMole();
		}
	}


    // ---------------------------------------------------------------------------------------


	// @Function: Creates / spawns a mole randomly on the grid
	private void CreateMole()
	{
		// check if there are any holes before doing anything!
		if (holes.Count > 0)
		{
			// picks a random hole from holes (using a random number)
			int number = random.Next(0, holes.Count);
			var hole = holes[number];

            // update the holes and moles lists (add it to moles, remove it from holes)
            holes.Remove(hole);
            moles.Add(hole);

            // IMAGE: update the image to a mole
            hole.Source = "mole.png";

            /******************************************************************************************************
			 *	This is the slightly advanced and not covered by the course so far part
			 *	
			 *  In basic terms, it creates a task, and then cancels it if any property of the button changes,
			 *  such as, the image!
			 *  
			 *  This just accounts for if another coin spawns, before the token despawn task ends.
            /******************************************************************************************************/

            // create a cancellation token to cancel the coin despawn in case the user clicks it
            var tokenSource = new CancellationTokenSource();

            // creates a task with a delay before it destroys the mole (this is whats cancellable)
            Task.Delay(mole_lifetime, tokenSource.Token).ContinueWith(task =>
            {
                // disconnect the cancel check handler (from below)
                hole.PropertyChanged -= handler;

                // checks if it wasnt cancelled, and if it wasn't ...
                if (!tokenSource.IsCancellationRequested)
                {
					// ... dispatch to destroy the mole
                    Dispatcher.Dispatch(() => 
					{ 
						DestroyMole(hole); 
					});
                }
            });

            // a handler function which cancels the task above
            void handler(object sender, EventArgs a)
            {
                // cancel the scheduled task above
                tokenSource.Cancel();
            }

            // connect the handler to if a property of the coin changes (it will trigger if the image changes)
            hole.PropertyChanged += handler;

            /******************************************************************************************************/
        }
    }


	// @Function: Destroys the specified mole from the grid
	private void DestroyMole(ImageButton mole)
	{
		// IMAGE: update the image to a hole (no mole)
		mole.Source = "hole.png";

		// update the holes and moles lists (remove it from moles, add it to holes)
		moles.Remove(mole);
		holes.Add(mole);
	}


    // @Function(Handler): This function runs when any mole/hole button is clicked
    private void MoleButton_Clicked(object sender, EventArgs e)
	{
		// cast the sender (button) into an actual button (this is kind of like "hey sender is actually a button, not just some 'object'"!)
		ImageButton button = (ImageButton) sender;

		// check if there actually is a mole there, and it's not just a hole (since they all connect here)
		if (moles.Contains(button))
		{
			// update the score
			score += mole_hit_points;
			ScoreLabel.Text = Convert.ToString(score);

			// despawn the mole!
			DestroyMole(button);
		}
	}


    // ---------------------------------------------------------------------------------------


    // @Function(Handler)[Async]: A function that runs when the reset button is clicked
    private async void ResetButton_Clicked(object sender, EventArgs e)
	{
		// prompt the user if they're sure they want to end the game
        var confirm = await DisplayAlert("End Game", "Are you sure you want to end the game?", "Yes", "No");

		// check if the user hit yes
        if (confirm)
		{
			// stop the game
			StopGame();
		}
	}


    // @Function(Handler): A function that runs when the retry button at the end screen is clicked
    private void BackToMenuButton_Clicked(object sender, EventArgs e)
    {
		// reset the game to main menu
		ResetGame();
    }


    // @Function(Handler): A function that runs when the 3x3 button in the start menu is clicked
    private void Play3x3Button_Clicked(object sender, EventArgs e)
	{
		// start the game with a grid size of 3
		StartGame(3);
	}


    // @Function(Handler): A function that runs when the 5x5 button in the start menu is clicked
    private void Play5x5Button_Clicked(object sender, EventArgs e)
	{
        // start the game with a grid size of 5
        StartGame(5);
    }

}

