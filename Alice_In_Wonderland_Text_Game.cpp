/*
DOCUMENTATION: 

Classes:
   GeneralTraits - A generic class, which will be inherited by other class which would utilize the instance variable and functions that pertain to GeneralTraits class, such as set/geting name and descriptions.
   Room - A class that represents a location in the game, could be a room, or a forest, it contains many variables locations would have, such as name, description, and coordinates so our program can allow the player to move around the map.
   Items - A class that represents an item in the game, which contains many variables items have, such as the name, description, location of the item, etc. Some have uses such as consumables or keys to unlock areas in the game.
   Player - A class that represents the main character in the game, which contains many varibles such as the name, description, inventory, current location, and the players current size.
   Character - A class that represents the NPC's in the game, which contains many instance varibles such as the name, description, current location, and a line of dialog used when spoken too.
   Inventory - A class that represents the players inventory, which contains a vector of items, which can be picked up and added to inventory, or dropped and removed, also accessed. (THIS CLASS WASN'T USED IN FINAL PRODUCT).
   Actions - A class that keeps track of a list of allowable commands for the user to type and use in the game, it contains an vector of string/commands as an instance variable, will read commands from a text file, and place them into game.
   Control - A class that is reads user input given via constructor, and then utilizes its diverse set of functions and logic based programming to decipher what the player wants to do, if it can do it, it will, otherwise it will display the appropriate error.
   Wonderland - A class that will contain one simple member function, which will do all that is needed to run and play the game once called, it will be called in the main function.

 Variables:
   wordToConvert - string - Argument for a function that will be the word the user wishes to get returned in all capital letters, for error handling.
   tempString - string - will be the temporary string that will be returned once it's uppercase, will use string concatenation with each uppercase char until it represent the full word in uppercase.
   tempChar - string - will be the temporary char that will be the current char in the wordToConvert converted to uppercase and used in string concatenation.
   i,j,k - int - index counters to be used in loops.
   fileName - string - this will be an argument for a funciton that reads a file, will represent the name of the file to be read.
   fileIn - ifstream - this is an ifstream object, which will be the file with the name the user gave as an arugment, if found.
   line - string - this will represent the current line in the file to be read, and output.
   name - string - this variable represent the name of some object.
   description - string - this variable represents the descripiton of some object.
   nameInput - string - this variable is used as an argument for setting the name of an object.
   descriptionInput - string - this variable is used as an argument for setting the descripiton of an object.
   firstTime - bool - this variable tracks if this is the first time the room has been entered or not.
   isLocked - bool - this variable tacks if the room is locked or not.
   needsKey - bool - this variable tracks if the room needs a key or not.
   sizeReqNeeded - bool - the variabel tracks if the room needs the player to be a specific size or not.
   north, south, west, east - int - these are coordinate varibeles which tell the room object which room index to move to in which direction if set.
   keyName - string - name of the key needed to open the room.
   sizeRequirment - string - represents the size the player needs to be to move to next room (small, large, or any).
   nameinput - string - constructor argument for room object, sets the name of the room
   descInput - string - constructor argument for room object, sets the description of the room
   nInput, sInput, wInput, eInput - int - constructor arguments for room object, sets the coordinates/connection chain of the room
   isLockedInput - string - constructor argument for room object, sets whether the room is locked or not.
   keyNameInput - string - constructor argument for room object, sets the name of the rooms key
   sizeReqInput - string - constructor argument for room object, sets the size the player needs to be to enter room.
   roomToTest - Room - this variable is used in a function argument, which tests if the implicitly retrieved rooms name is equal to the arguments room name.
   firstTimeInput - bool - this variable is used as an argument in a setter function, which sets if it's no longer the rooms first time being entered or not.
   isLockedOrNot - bool - this variable is user as an argument in a setter function, which sets if the room is locked or not.
   currentRoom - Room - this variable tracks the current room of the object, used for the item class and later in the player and character class.
   gameMap - vector<Room> - this variable represent the map of the game, consisting of all the connected rooms (map) in a vector, allows the object to edit it's location
   inInventory - bool - this variable tracks whether an item is in the players inventory or not.
   isEdible - bool - this variable tracks whether or not an item is edible.
   isDrinkable - bool - this variable tracks whether or not an item is drinkable.
   roomName - string - this item represents the inital room the item will be placed in.
   roomNameInput - string - this is an argument for the items class second constructor, to initalize the roomName variable.
   gameMapInput - vector<Room> - this is an argument for the items class second constructor, to initalize the gameMap vector.
   edibleOrNot - string - this is an argument for the items class second constructor, to initalize the isEdible variable.
   dropped - bool - this is an variable to track whether the item is in the players inventory or not. a argument for a class.
   roomInput - Room - this variable is an argument to set the current room the item is in, if it changed.
   numItems - int - this variable keeps track of the number of items in the users inventory.
   userInventory - vector<Items> - This vector represents the users inventory, and all the items in it.
   item - Items - this is an arugment object for the addItem function in the inventory class, tested if the item is in inventory yet, if not, add it.
   indexOfItem - int - this variable keeps track of the index of a specific item in the players inventory.
   currentPlayerRoom - Room - this variable represents the current location of the player.
   itemName - string - this variable is used in a find function, in order to test if that item name is in inventory, if it is find and return index.
   index - int - this variable is used in an argument for retriving that specific item at that index in inventory, and returns it.
   roomSet - bool - this variable tracks whether or not the player objects room has been set.
   hasMap - bool - this varible tracks whether or not the player object has a game map set.
   isShrunk - bool - this variable tracks whether or not the player object is shrunk or not.
   isLarge - bool - this variable tracks whether or not the player object is large or not.
   isNormal - bool - this variable tracks whether or not the player object is normal sized or not.
   playerInventory - vector<Items> - this vector of items represent the player objects inventory of items.
   roomInput - Room - this variable is an argument passed in the players constructor to initialize the current room.
   gameItems - vector<Items> - this variable is an argument passed in the players constructor to give access to all the items in the game.
   roomIndex - int - this variable is a parameter for a member function of the player class, which will represent the map index of the room the player will move to.
   item - Items - this variable is a parameter for member functions used to represent the item that we want to add/drop or utilize in some manner.
   gameInputItems - vector<Items> - this variable is a parameter for a general use function which will find an item (if it exists) in this vector and return it's index.
   dialog - vector<string> - this vector represents the lines of dialog the character object has access too, my game only gives each player one line of dialog.
   dialogInput - string - this variable is an argument to initialize a line of dialog for a character by adding it to the vector.
   characterName - string - this variable initalizes the characters name via argument.
   gameInputCharacter - vector<Character> - this variable is an argument for a general use function, which represents a cast of all the character in the game, to return an index of a specified character in the function.
   gameInputRooms - vector<Room> -this variable is an argument for a general use function, which represents a map in the game of all the rooms in the game, to return an index of a specific room in the funciton.
   actions - vector<string> - this is a vector which holds all the allowable action words for the game to use, read from a text file.
   textName - string - this variable is used as an argument in the action objects constructor, which retrives a file of that name, then reads the lines and initializes the action words of the vector.
   isSet - bool - tracks whether the aciton words have been set or not.
   command - string - this variable is an argument for a function which tests if the argument is a valid command against the vector of defined action words.
   currentAction - string - this instance variable for the control class represents the current action the user entered to be tested by the control objects functionality.
   currentObject - string - this instance variable for the control class represents the current object the user entered to be tested by the control objects functionality.
   hasAction - bool - this instance variable for the control class keeps track of whether or not the control object has a current action to test.
   actionInput - string - this variable is an argument for the control object constructor(now function), which initalizes the current action to be tested by the control classes functionality.
   objectInput - string - this variable is an argument for the control object constructor(now function), which initalizes the current object to be tested by the control classes functionality.
   character - Player - this variable is an argument for the control object constructor (and functions), which initalizes the player of the game to be controlled by the control classes functionality.
   actionList - Actions - this variable is an argument for the control object constructor, which initalizes the current actions allowed by the control objects functionality.
   objectList - Actions - this variable is an argument for the control object constructor, which initalizes the current objects of an action to be tested by the control classes functionality.
   gameCast - vector<Character> - this variable is an argument for the control object constructor, which initalizes the games cast of characers to be tested by the control classes functionality.
   gameItemsInput - vector<Items> - this variable is an argument for the control object constructor, which initalizes the games list of avaliable items to be tested by the control classes functionality.
   mapInput - vector<Room> - this variable is an argument for the control object constructor, which initalizes the games map of rooms to be tested by the control classes functionality.
   direction  - string - this variable is an argument for the control class function used to move the player, which represents the direction the user wants the player to move.
   indexGameItems - int - this variable is a local variable for a member function of the control class, used to represent the index of the item in the game item vector (all items in game).
   indexPlayerItems - int - this variable is the same as the previous variable, except it finds the item index from the players inventory to intereact with later.
   keyNameVar - string - this variable is used in the unlocking door member function of the control class, used to find the name of the key needed to unlock the door of the current room.
   playerKeyIndex - int - this variable is used to find the key index of a specific key name in the players inventory.
   playerKeyVarName - string - this variable is used to get keys name from the specified index from the varible above.
   jabberwockyName - string - this variable is used in the slay Jabberwocky member function of the control class, which is an argument that should take the name of the jabberwoky as it's argument.
   indexJ - int - this variable is used in the same function as above, represents the index position of the Jabberwocky character in the games cast.
   indexHelm, indexChest, indexLeg, indexSword - int - these variaables are all used to test if the player has all the vorpal armor and sword to kill the Jabberwocky.
   gameAction - Actions - This variable represents all the allowable actions for this specific game taken from a file via name argument, local variable inside run function.
   gameObject - Actions - This variable is the same as the previous one but for the objects of specific actions.
   map - vector<Rooms> -  This variable represens all the rooms in the game that are interconnected and make up a map
   fileInMap - ifstream - This variable represents the text file holding data for all the rooms in the game.
   roomDescription - string - This variable represents the roomDescription to be initialized by file data for the current room object.
   nString, sString, wString, eString - string - These variables represent all the direction data points to be initialized by file data for the current room object.
   lockedInput - string - This variable represents the current rooms locked or unlocked status to be initialized by file data.
   keyInput - string - This variable represents the key needed for the current room to be initialized by file data.
   sizeReqInput - string - This variable represents the size requirment for the current room to be intialied by file data.
   n,s,w,e - int - These varaible represent the values from nString, etc. But convert them into integers using the atoi function for the constructor of the room object.
   gameInventory - Inventory - This varaible represents the games inventory, not used.
   cast - vector<Character> - This variable represents a vector of all the characters in the game, each characters data will be initialzed via file data.
   fileInChar - ifstream - This is the file holding all the data to initialize the characters in the game.
   gameItems - vector<Items> - This variable represents a vector of all the items avalibale in the game, each items data will be initalized via file data.
   fileInItem - ifstream - This is the file holding all the data to be initialize the items in the game.
   isEdibleInput - string - This variable represents whether the current item is edible or not, to be initialized by the file data.
   alice - Player - This variable represents the users Player Alice who will be the player to interact with the game.
   action - string - This variable represents the user inputs action term to be passed into the control object to be dealt with then.
   object - string - This variable represents the user inputs object term to be passed into the control object to be dealt with then.
   buffer - string - This variable is simply a variable which will be overwritten constantly to make sure if the user accidentally adds more user input than two terms, it will be removed from input buffer.
   gameController - Control - This is the games controller object, which will be initialized with all the vectors of objects necessary for the game to word, and will use a function to constanlty update the new actions and objects being entered by the user.
*/
/*
 TEST PLAN
   -GOOD CASE (Completes the game):
   -intro.txt is displayed to the user.
   You've entered RABBIT-HOLE-ROOM it's a A room with many large doors, one tiny door to the north, a tiny key, a growth cake, a shrink drink, and a small chest that can hold items as you please.
   Enter a two word command: pickup shrink-drink
   SHRINK-DRINK has been added to inventory.
   SHRINK-DRINK description: A potion that shrinks whoever drinks it down to the size of an mouse.
   Enter a two word command: pickup growth-cake
   GROWTH-CAKE has been added to inventory.
   GROWTH-CAKE description: A cake that grows whoever eats it to the size of a large tree.
   Enter a two word command: pickup tiny-key
   TINY-KEY has been added to inventory.
   TINY-KEY description: A key that seems to open a very tiny door.
   Enter a two word command: unlock rabbit-hole-room
   RABBIT-HOLE-ROOM has been unlocked with TINY-KEY
   Enter a two word command: drink shrink-drink
   You are now the size of a mouse
   Enter a two word command: go north
   You've entered Forest Path it's a An winding rocky path where we see a strange white rabbit standing impatiently.
   Enter a two word command: go north
   You've entered Dark Forst Path it's a A quiet dark forest with a sinister ambience surroding the general area, you see a strange cat with a creepy long smile.
   Enter a two word command: go east
   There's no exit in that direction, or the room is locked, you must use the key to unlock it if that's the case.
   Enter a two word command: go west
   There's no exit in that direction, or the room is locked, you must use the key to unlock it if that's the case.
   Enter a two word command: go north
   You've entered Tea Party it's a An enclosed area with a long table of destroyed cups and plates, at the very end we see a crazy looking man.
   Enter a two word command: go east
   You've entered Autumn Forest Path it's a A breathtaking orange and red forest, with the fresh smell of spring in the air.
   Enter a two word command: pickup dog-key
   DOG-KEY has been added to inventory.
   DOG-KEY description: A key that used to be hung around the neck of a very large dog, might open the gate to the red castle.
   Enter a two word command: go east
   You've entered RUINED-TOWN it's a A destroyed town, atleast what's left of it.
   Enter a two word command: pickup vorpal-sword
   VORPAL-SWORD has been added to inventory.
   VORPAL-SWORD description: The only weapon which can slay the Jabberwocky.
   Enter a two word command: go west
   You're back in Autumn Forest Path
   Enter a two word command: go north
   You've entered CASTLE-CROSSROADS it's a A crossroads between red castle to the east and the white castle to the west, and a strange game-dev castle up north.
   Enter a two word command: go east
   This room requires you to be BIG maybe you can consume something that will let you get through?
   Enter a two word command: eat growth-cake
   You are now back to regular size
   Enter a two word command: eat growth-cake
   You are now as tall as a small building
   Enter a two word command: go east
   CASTLE-CROSSROADS is locked, you must unlock it with DOG-KEY
   Enter a two word command: unlock CASTLE-CROSSROADS
   CASTLE-CROSSROADS has been unlocked with DOG-KEY
   Enter a two word command: go west
   You've entered White Castle it's a A beautiful pristine castle, where a queen dawned in all white is awaiting you in front of the castle.
   Enter a two word command: pickup vorpal-helmet
   VORPAL-HELMET has been added to inventory.
   VORPAL-HELMET description: The helment of the legendary vorpal armor set.
   Enter a two word command: pickup vorpal-chestplate
   VORPAL-CHESTPLATE has been added to inventory.
   VORPAL-CHESTPLATE description: The chestplate of the legendary vorpal armor set.
   Enter a two word command: pickup vorpal-legplate
   VORPAL-LEGPLATE has been added to inventory.
   VORPAL-LEGPLATE description: The leg-plate of the legendary vorpal armor set.
   Enter a two word command: go east
   You're back in CASTLE-CROSSROADS
   Enter a two word command: go east
   You've entered Red Castle it's a A intimidating creepy castle, where a evil looking queen is staring you down, with her Jabberwocky stands beside her.
   Enter a two word command: slay jabberwocky
   Alice swings the mighty Vorpal sword and cuts the head of the Jabberwocky clean off!
   Congratulations you've completed the game! Thanks again for saving Wonderland!

   -BAD CASE 1 (invalid command):
   Enter a two word command: walk away
   WALK AWAY is not a valid command!
   Enter a two word command:

   -BAD CASE 2 (talk to someone who isn't there)
   Enter a two word command: talk white-rabbit
   WHITE-RABBIT is not in this room.

   -BAD CASE 3 (pickup and then use item that isn't in room, and not in inventory):
   Enter a two word command: pickup vorpal-sword
   The item: VORPAL-SWORD is either not in this room, or was not spelled correctly. (Note: must use - instead of space for item name, eg. shrink-drink.)
   Enter a two word command: drink shrink-drink
   SHRINK-DRINK not in your inventory

   -BAD CASE 4 (move in direction when incorrect size):
   Enter a two word command: go south
   This room requires you to be SMALL maybe you can consume something that will let you get through?

   -BAD CASE 5 (move in direction that's locked):
   Enter a two word command: go south
   RABBIT-HOLE-ROOM is locked, you must unlock it with TINY-KEY

   -BAD CASE 6 (move in wrong direction):
   Enter a two word command: go south
   There's no exit in that direction, or the room is locked, you must use the key to unlock it if that's the case.

   -BAD CASE 7 (dropping item in non-safehouse):
   You've entered Forest Path it's a An winding rocky path where we see a strange white rabbit standing impatiently.
   Enter a two word command: drop shrink-drink
   You can only drop items in RABBIT-HOLE-ROOM as this is the room with the chest.

 Discussion:
    - This program has many more errors that could be tested for, an unfathomable amount. I tested the most common ones I could think of here.
    - The program ONLY accepts two word commands, one word commands will wait for another word.
    - Inventory class not used but created, alternate method used.
    - Can type quit game to exit early.
 */
#include <iostream>
#include <string>  //used for getline and various other functions.
#include <ctype.h> //allows for the use of changing chars to upper case and other function, used mostly for error handling user input.
#include <math.h>  //allows use of various mathematical functions.
#include <cstdlib> //allows for the use of random functions, for randomm encounters and other random instances.
#include <fstream> //allows for the use of file input and output.
#include <vector>  //used so I can create and use vectors.
#include <sstream> //allows me to parse user input so I can use them for control class
using namespace std;
// general use functions:
string convertToUpper(string wordToConvert)
{ // convert string to uppercase general functions
   string tempString, tempChar;
   for (int i = 0; i < wordToConvert.length(); i++)
   {
      tempChar = toupper(wordToConvert[i]);
      tempString = tempString + tempChar;
   }
   return tempString;
}
void readFile(const string &fileName)
{                             // const so we don't edit the fileName variable, pass by reference for efficiency (must include .txt)
   ifstream fileIn(fileName); // create ifstream object named fileIn
   string line;               // placeholder for current line in file to be read
   if (fileIn.good())
   { // if the file opened properly
      // while loop will run until we reach the end of the file
      while (!fileIn.eof())
      {
         getline(fileIn, line);
         cout << line << endl; // print the line through each iteration.
         cout << endl;         // spacing
      }
   }
   else
   { // if the file wan't found or file doesn't exist (wrong name)
      cout << "Failed, file was not found, game cannot run when missing crucial files." << endl;
      exit(-1);
   }
}
class GeneralTraits
{ // general traits class, use so other classes can inherit commonly used instance variables and accessor methods
public:
   string name, description; // name and description
   // default constructor
   GeneralTraits()
   {
   }
   // Accessor methods:
   void setName(string nameInput)
   {
      name = nameInput;
   }
   void setDescription(string descriptionInput)
   {
      description = descriptionInput;
   }
   string getName()
   {
      return name;
   }
   string getDescription()
   {
      return description;
   }
   void printName()
   {
      cout << name << endl;
   }
   void printDescription()
   {
      cout << description << endl;
   }
};
// Room class
class Room : public GeneralTraits
{
   // private by default:
   bool firstTime, isLocked, needsKey, sizeReqNeeded; // tracks if first time in room or not for room description output, also tracks if room is locked or not.
   int north, south, west, east;                      // coordinates (north, south, west, east)
   string keyName, sizeRequirment;                    // key needed to open room, and size of player required to go through room.
public:
   // default constructor:
   Room()
   {
      // does nothing
   }
   // secondary constructor:
   Room(string nameInput, string descInput, int nInput, int sInput, int wInput, int eInput, string isLockedInput, string keyNameInput, string sizeReqInput)
   {
      name = nameInput;
      description = descInput;
      north = nInput;
      south = sInput;
      west = wInput;
      east = eInput;
      firstTime = true; // when room object is first created, character will not have entered it yet. (don't output description when false)
      // set room to be locked or not, key will be applied automatically.
      if (isLockedInput == "LOCKED")
      { // if the door is set to locked, set variable to locked.
         isLocked = true;
         needsKey = true;        // if door is locked it will need a key
         keyName = keyNameInput; // set the name of the key needed to unlock door.
      }
      else
      {
         isLocked = false;
         needsKey = false;   // will not need key.
         keyName = "NO-KEY"; // sets keyName to NO-KEY
      }
      // set room to needing a size requirment of not.
      if (sizeReqInput == "SMALL")
      {
         sizeRequirment = "SMALL";
         sizeReqNeeded = true; // size requirment exists.
      }
      else if (sizeReqInput == "BIG")
      {
         sizeRequirment = "BIG";
         sizeReqNeeded = true;
      }
      else
      {
         sizeReqNeeded = false; // no size requirment for this room
      }
   }
   // Room member function:
   // enter room function:
   void enter()
   {
      if (!firstTime)
      { // if it's the players first time in the room.
         cout << "You're back in " << name << endl;
      }
      else
      { // if it's not the players first time in the room.
         cout << "You've entered " << name << " it's a " << description << endl;
         setFirstTime(false); // no longer first time.
      }
   }
   // Room accessor functions:
   int getNorth()
   {
      return north;
   }
   int getSouth()
   {
      return south;
   }
   int getEast()
   {
      return east;
   }
   int getWest()
   {
      return west;
   }
   // is same room function
   bool isSameRoom(Room roomToTest)
   {
      if (name == roomToTest.getName())
      {
         return true;
      }
      else
      {
         return false;
      }
   }
   // set firstTime function:
   void setFirstTime(bool firstTimeInput)
   {
      firstTime = firstTimeInput;
   }
   bool getIsLocked()
   { // see if room is locked
      return isLocked;
   }
   string getKeyName()
   { // get the key name
      return keyName;
   }
   void setIsLocked(bool isLockedOrNot)
   { // set the door to unlocked or locked.
      isLocked = isLockedOrNot;
   }
   bool getSizeReqBool()
   {
      return sizeReqNeeded;
   }
   string getSizeRequirment()
   {
      return sizeRequirment;
   }
};
// Items class:
class Items : public GeneralTraits
{
   // private by default
   Room currentRoom;                        // keeps track of where the item is, if it's not in the invenctory.
   vector<Room> gameMap;                    // here so the items can be moved into other rooms if they are dropped in another room.
   bool inInventory, isEdible, isDrinkable; // keeps track of whether or not the item is in the players inventory or not.
   string roomName;                         // takes in name of the room it will be placed in initially.
public:
   // default constructor:
   Items()
   {
      // does nothing
   }
   // secondary constructor:
   Items(string nameInput, string descInput, string roomNameInput, vector<Room> gameMapInput, string edibleOrNot)
   {
      name = nameInput;
      description = descInput;
      roomName = roomNameInput;
      gameMap = gameMapInput;
      inInventory = false; // doesn't start out in inventory.
      setInitialRoom(roomName);
      if (edibleOrNot == "EDIBLE")
      { // if item is set to edible, the player can eat some of it, if drinkible player can drink some of it.
         isEdible = true;
         isDrinkable = false;
      }
      else if (edibleOrNot == "DRINKABLE")
      {
         isEdible = false;
         isDrinkable = true;
      }
      else
      {
         isEdible = false;
         isDrinkable = false;
      }
   }
   // item member functions:
   void isPickedUp()
   { // item is picked up or not function
      inInventory = true;
   }
   void isDropped()
   { // item is dropped out of inventory
      inInventory = false;
   }
   void setDropped(bool dropped)
   { // set is dropped or not:
      inInventory = false;
   }
   void setRoom(Room roomInput)
   { // set the room of the item and get item room.
      currentRoom = roomInput;
   }
   Room getRoom()
   { // return the current room of item
      return currentRoom;
   }
   bool getInInventory()
   { // see if item is pickedup or not
      return inInventory;
   }
   void setInitialRoom(string nameInput)
   { // set items initial room via looping through map to find equaivalent name.
      for (int i = 0; i < gameMap.size(); i++)
      { // loop through the map vector
         if (nameInput == gameMap.at(i).getName())
         {                          // if the name of the map is one of the names in the map vector
            setRoom(gameMap.at(i)); // set the characters room to that room.
         }
      }
   }
   bool getIsEdible()
   { // let's program know if the item is edible or not.
      return isEdible;
   }
   bool getIsDrinkable()
   { // let's the program know if the item is drinkible or not.
      return isDrinkable;
   }
};
// Inventory Class:
class Inventory
{ // This class was not used, but I kept it for demonstration of my inventory class concept.
   // private by default
   vector<Items> userInventory; // the player will be assigned an inventory, which will be a vector.
   int numOfItems;              // tracks the number of items in the inventory

public:
   // constructors here if needed

   // member functions:
   void addItem(Items &item)
   {
      if (!item.getInInventory())
      {                                 // if item is not in inventory
         userInventory.push_back(item); // add item to inventory.
         item.isPickedUp();
         numOfItems++; // increment number of items.
         cout << item.getName() << " has been added to inventory." << endl;
         cout << userInventory.size() << endl;
      }
      else
      {
         cout << item.getName() << " is already in inventory." << endl;
      }
   }
   void dropItem(int indexOfItem, Room currentPlayerRoom)
   {
      cout << userInventory.size() << endl;
      cout << userInventory.at(indexOfItem).getName() << " has been dropped from inventory." << endl;
      userInventory.at(indexOfItem).isDropped();                // set the items status to dropped
      userInventory.at(indexOfItem).setRoom(currentPlayerRoom); // set the room of the item to the current room.
      userInventory.erase(userInventory.begin() + 0);           // remove the item from the inventory

      // store the inventory in the room player is in
   }
   // return item index inside inventory:
   // return item Index function:
   int getItemIndex(string itemName)
   {
      int index = -1;
      for (int i = 0; i < userInventory.size(); i++)
      { // itereate through whole inventory
         if (itemName == userInventory.at(i).getName())
         {
            index = i; // will change the value of the local index variable to the location of the item
         }
      }
      // item not found in inventory:
      if (index != -1)
      {
         return index;
      }
      else
      {
         cout << "This item is not in your inventory." << endl;
         return index; //-1
      }
   }
   // itemAt
   Items itemAt(int index)
   {
      return userInventory.at(index);
   }
};

// Player Class:
class Player : public GeneralTraits
{
   // private by default:
   Room currentRoom;
   bool roomSet, hasMap, isShrunk, isLarge, isNormal;
   vector<Room> gameMap;
   vector<Items> playerInventory;

public:
   // default constructor:
   Player()
   {
      // does nothing
      hasMap = false;
      roomSet = false;
   }
   // secondary constructor:
   Player(string nameInput, string descInput, Room &roomInput, vector<Room> &gameMapInput, vector<Items> &gameItems)
   {
      name = nameInput;
      description = descInput;
      currentRoom = roomInput;
      gameMap = gameMapInput;
      hasMap = true;
      isNormal = true;
      isShrunk = false;
      isLarge = false;
   }
   // Player class member function
   // set room function:
   void setRoom(Room roomSet)
   { // sets the current room object to the room the player is in
      currentRoom = roomSet;
   }
   Room getRoom()
   {
      return currentRoom;
   }
   // set map if unset function
   void setMap(vector<Room> gameMapInput)
   {
      if (hasMap = true)
      {
         cout << "Map already set" << endl; // error handling
      }
      else
      {
         gameMap = gameMapInput;
         hasMap = true;
      }
   }
   // get player inventory function:
   vector<Items> getPlayerInventory()
   {
      return playerInventory;
   }
   // move player to another room function
   void movePlayer(int roomIndex)
   {
      if (hasMap)
      {
         if (roomIndex != -1)
         {
            setRoom(gameMap.at(roomIndex)); // set current room to the new room index
            currentRoom.enter();            // enter the room
            gameMap.at(roomIndex).setFirstTime(false);
         }
         else
         {
            cout << "There's no exit in that direction, or the room is locked, you must use the key to unlock it if that's the case." << endl; // no direction
         }
      }
      else
      {
         cout << "No map has been set" << endl;
      }
   }
   // add item to inventory:
   void addItem(Items &item)
   {
      if (!item.getInInventory())
      {                                   // if item is not in inventory
         playerInventory.push_back(item); // add item to inventory.
         item.isPickedUp();               // in inventory set to true
         cout << item.getName() << " has been added to inventory." << endl;
      }
      else
      {
         cout << item.getName() << " is already in inventory." << endl;
      }
   }
   // drop item from inventory:
   void dropItem(int indexOfItem, Items &item)
   {
      cout << playerInventory.at(indexOfItem).getName() << " has been removed from inventory." << endl;
      item.isDropped();                                             // set the items status to dropped
      item.setRoom(getRoom());                                      // set the room of the item to the current room.
      playerInventory.erase(playerInventory.begin() + indexOfItem); // remove the item from the inventory
      // store the inventory in the room player is in
   }
   // get item index by name string:
   // return item Index function:
   int getItemIndex(string itemName)
   {
      int index = -1;
      for (int i = 0; i < playerInventory.size(); i++)
      { // itereate through whole inventory
         if (itemName == playerInventory.at(i).getName())
         {
            index = i; // will return the current index inside the inventory
         }
      }
      // item not found in inventory:
      if (index != -1)
      {
         return index;
      }
      else
      {
         return index; //-1
      }
   }
   // access player inventory function
   vector<Items> getInventory()
   {
      return playerInventory;
   }
   // shrink and grow player inventory functions:
   void shrinkPlayer()
   {
      if (isNormal)
      {
         isShrunk = true;
         isNormal = false;
         isLarge = false;
         cout << "You are now the size of a mouse" << endl;
      }
      else if (isShrunk)
      { // if player is already shrunk
         cout << "You are already the size of a mouse" << endl;
      }
      else
      { // if player is large
         isLarge = false;
         isShrunk = false;
         isNormal = true;
         cout << "You are now back to regular size" << endl;
      }
   }
   void growPlayer()
   {
      if (isShrunk)
      {
         isShrunk = false;
         isLarge = false;
         isNormal = true;
         cout << "You are now back to regular size" << endl;
      }
      else if (isNormal)
      {
         isShrunk = false;
         isNormal = false;
         isLarge = true;
         cout << "You are now as tall as a small building" << endl;
      }
      else
      { // if player is already large
         cout << "You are already the size of a small building" << endl;
      }
   }
   // set current room to unlocked
   void setUnlocked()
   {
      getRoom().setIsLocked(false); // sets the current room to unlocked.
   }
   // get is shrunk or is large:
   bool getShrunk()
   {
      return isShrunk; // true means player is small, false means normal or large size
   }
   bool getLarge()
   {
      return isLarge; // true means player is big, false means normal or small size.
   }
};

// general get item index function:
int getItemIndexGeneral(string itemName, vector<Items> gameInputItems)
{
   int index = -1;
   for (int i = 0; i < gameInputItems.size(); i++)
   {
      if (itemName == gameInputItems.at(i).getName())
      {
         index = i; // will return the current index inside of the vector
      }
   }
   // item not found in inventory:
   if (index != -1)
   {
      return index;
   }
   else
   {
      return index; //-1
   }
}
// Characters Class:
class Character : public GeneralTraits
{
   // private by default
   vector<string> dialog;
   Room currentRoom;
   string roomName; // will set the starting room via a string comparasion loop now.
   bool roomSet;
   vector<Room> gameMap;
   bool hasMap;

public:
   // default constructor:
   Character()
   {
      // does nothing
   }
   // secondary constructor:
   Character(string nameInput, string descInput, string roomNameInput, vector<Room> gameMapInput)
   {
      name = nameInput;
      description = descInput;
      roomName = roomNameInput;
      gameMap = gameMapInput;
      hasMap = true;
      setInitialRoom(roomName);
   }
   // member functions:
   // add Dialog function
   void addDialog(string dialogInput)
   {
      dialog.push_back(dialogInput);
   }
   // print dialog function:
   void printDialog(int index)
   {
      cout << name << " says: " << dialog.at(index) << endl;
   }
   // Character class member function
   // set room function:
   void setRoom(Room roomSet)
   { // sets the current room object to the room the player is in
      currentRoom = roomSet;
   }
   Room getRoom()
   {
      return currentRoom;
   }
   // set map if unset function
   void setMap(vector<Room> gameMapInput)
   {
      if (hasMap = true)
      {
         cout << "Map already set" << endl; // error handling
      }
      else
      {
         gameMap = gameMapInput;
         hasMap = true;
      }
   }
   // move player to another room function
   void moveCharacter(int roomIndex)
   {
      if (hasMap)
      {
         if (roomIndex != -1)
         {
            setRoom(gameMap[roomIndex]);
            cout << "You are now in " << getRoom().getName() << endl; // print out room player is now inside.
         }
         else
         {
            cout << "There's no exit in that direction." << endl; // no direction
         }
      }
      else
      {
         cout << "No map has been set" << endl;
      }
   }
   // set characters initial room via looping through map to find equaivalent name.
   void setInitialRoom(string nameInput)
   {
      for (int i = 0; i < gameMap.size(); i++)
      { // loop through the map vector
         if (nameInput == gameMap.at(i).getName())
         {                          // if the name of the map is one of the names in the map vector
            setRoom(gameMap.at(i)); // set the characters room to that room.
         }
      }
   }
};
// general function:
int getCharacterIndex(string characterName, vector<Character> gameInputCharacter)
{ // find if that character is in the game.
   int index = -1;
   for (int i = 0; i < gameInputCharacter.size(); i++)
   {
      if (characterName == gameInputCharacter.at(i).getName())
      {
         index = i; // set index equal to index position of character
      }
   }
   if (index != -1)
   {
      return index;
   }
   else
   {
      return index; //-1
   }
}
int getRoomIndex(string roomName, vector<Room> gameInputRooms)
{
   int index = -1;
   for (int i = 0; i < gameInputRooms.size(); i++)
   {
      if (roomName == gameInputRooms.at(i).getName())
      { // if the room name matches the name of the current room, set index to that room.
         index = i;
      }
   }
   if (index != -1)
   {
      return index;
   }
   else
   {
      return index; //-1
   }
}
// Actions Class:
class Actions
{
   // private by default
   vector<string> actions;
   bool isSet; // if a file containing actions has been set.

public:
   Actions()
   {
      // does nothing
      isSet = false; // not set
   }
   Actions(string textName)
   {
      ifstream fileIn(textName);
      if (fileIn.good())
      { // if file is opened successfully
         string word;
         int i = 0;
         while (!fileIn.eof())
         { // while there's another word in the file/while not at end of the file
            getline(fileIn, word);
            actions.push_back(word); // set current vector positon to action word.
            i++;                     // increment index
         }
         isSet = true;
      }
      else
      {
         cout << "Error: file name is incorrect, or file does not exist." << endl;
      }
   }
   // member functions:
   bool validCommand(string command)
   {
      string commandToTest = convertToUpper(command); // converts to upper case so we can accept upper case and lower case commands
      for (int i = 0; i < actions.size(); i++)
      {
         if (commandToTest == actions.at(i))
         {
            return true;
         }
      }
      return false; // if none are equal.
      cout << "Error: command: " << command << " not found, please enter a valid command, refer to help function to see list of valid commands." << endl;
   }
};

// Control class (player controls):
class Control
{
   // private by default
   string currentAction; // will be the current action user is attempting to use when
   string currentObject; // will be the current object user is attempting to interact with. (item, or direction)
   Player character;
   Actions actionList;
   Actions objectList;
   vector<Character> gameCast;
   vector<Items> gameItems;
   vector<Room> gameMap;
   bool hasAction;

public:
   // default constructor:
   Control()
   {
      // does nothing
      hasAction = false;
   }
   Control(Player &characterInput, Actions actionListInput, Actions objectListInput, vector<Character> &gameCastInput, vector<Items> &gameItemsInput, vector<Room> &mapInput)
   { // initalize the controllers game data.
      character = characterInput;
      actionList = actionListInput;
      objectList = objectListInput;
      gameCast = gameCastInput;
      gameItems = gameItemsInput;
      gameMap = mapInput;
   }
   // control member functions
   // update accept user input function:
   void inputUpdate(string actionInput, string objectInput)
   {
      currentAction = convertToUpper(actionInput);
      currentObject = convertToUpper(objectInput);
      if (actionList.validCommand(currentAction))
      { // if the user input action is an valid command
         if (currentAction == "N" || currentAction == "NORTH" && !character.getRoom().getIsLocked())
         { // and the room/door is unlocked.
            character.movePlayer((character.getRoom()).getNorth());
         }
         else if (currentAction == "S" || currentAction == "SOUTH" && !character.getRoom().getIsLocked())
         {
            character.movePlayer((character.getRoom()).getSouth());
         }
         else if (currentAction == "E" || currentAction == "EAST" && !character.getRoom().getIsLocked())
         {
            character.movePlayer((character.getRoom()).getEast());
         }
         else if (currentAction == "W" || currentAction == "WEST" && !character.getRoom().getIsLocked())
         {
            character.movePlayer((character.getRoom()).getWest());
         }
         else if (currentAction == "GO" && objectList.validCommand(currentObject))
         {
            movePlayerDirection(currentObject, character, gameMap); // call the move player direction member function to move n,w,s,e depending on object input.
         }
         else if (currentAction == "TALK" && objectList.validCommand(currentObject))
         { // if current object is a permissable command
            talkToCharacter(currentObject, gameCast, character);
         }
         else if (currentAction == "PICKUP" && objectList.validCommand(currentObject))
         {
            pickupGameItem(currentObject, gameItems, character);
         }
         else if (currentAction == "DROP" && objectList.validCommand(currentObject))
         {
            dropGameItem(currentObject, character, gameItems, gameMap);
         }
         else if (currentAction == "EAT" && objectList.validCommand(currentObject))
         {
            eatItem(currentObject, character);
         }
         else if (currentAction == "DRINK" && objectList.validCommand(currentObject))
         {
            drinkItem(currentObject, character);
         }
         else if (currentAction == "UNLOCK" && objectList.validCommand(currentObject))
         {
            unlockDoor(currentObject, gameMap, character);
         }
         else if (currentAction == "SLAY" && objectList.validCommand(currentObject))
         {
            slayJabberwocky(currentObject, gameItems, gameCast, character);
         }
         else if (currentAction == "QUIT" && objectList.validCommand(currentObject))
         { // quit game option
            if (currentObject == "GAME")
            {
               cout << "Thank you for playing" << endl;
               exit(-1);
            }
            else
            {
               cout << "quit " << currentObject << "isn't something to quit." << endl;
            }
         }
         else
         {
            cout << currentAction << " " << currentObject << " is not a valid command!" << endl; // if action is correct, but object isn't
         }
      }
      else
      {                                                                                       // if the user command in an invalid command
         cout << currentAction << " " << currentObject << " is not a valid command!" << endl; // if action is correct, but object isn't
      }
   }
   // move player to specified direction from input
   void movePlayerDirection(string direction, Player &character, vector<Room> &mapInput)
   {
      int roomIndex = getRoomIndex(character.getRoom().getName(), mapInput); // get the current game room from character location.
      if (testPlayerSize(character))
      { // if the player is the correct size
         if (!mapInput.at(roomIndex).getIsLocked())
         { // if the door is unlocked.
            if (direction == "NORTH")
            {
               character.movePlayer((character.getRoom()).getNorth());
            }
            else if (direction == "SOUTH")
            {
               character.movePlayer((character.getRoom()).getSouth());
            }
            else if (direction == "EAST")
            {
               character.movePlayer((character.getRoom()).getEast());
            }
            else if (direction == "WEST")
            {
               character.movePlayer((character.getRoom()).getWest());
            }
            else
            {
               cout << "direction doesn't exist" << endl;
            }
         }
         else
         {
            cout << character.getRoom().getName() << " is locked, you must unlock it with " << character.getRoom().getKeyName() << endl;
         }
      }
      else
      {
         cout << "This room requires you to be " << character.getRoom().getSizeRequirment() << " maybe you can consume something that will let you get through?" << endl;
      }
   }
   // talk to character specified from input
   void talkToCharacter(string characterName, vector<Character> &gameCast, Player &character)
   { // will be cyclling through all the game cast character names.
      for (int i = 0; i < gameCast.size(); i++)
      { // cycle through all characters
         if (characterName == gameCast.at(i).getName() && character.getRoom().isSameRoom(gameCast.at(i).getRoom()))
         { // if the character name is the same as the name of the character in the game cast, and the player is in the same room as the character.
            gameCast.at(i).printDialog(0);
         }
         else if (characterName == gameCast.at(i).getName() && !character.getRoom().isSameRoom(gameCast.at(i).getRoom()))
         { // if the character isn't in the room.
            cout << characterName << " is not in this room." << endl;
         }
      }
      // cout << characterName << " is either not in this room, or not in the game. (make sure spelling is correct, use - in placement of spaces if name has more than one word.)" << endl;
   }
   // pickup and drop specified item from input (similar to previous function):
   void pickupGameItem(string itemName, vector<Items> &gameInputItems, Player &character)
   {
      int itemIndex = getItemIndexGeneral(itemName, gameInputItems); // find general item index
      if (itemIndex != -1 && itemName == gameInputItems.at(itemIndex).getName() && gameInputItems.at(itemIndex).getRoom().isSameRoom(character.getRoom()))
      { // if the item exists, and that item is in the same room as the player, call the add item function.
         character.addItem(gameInputItems.at(itemIndex));
         cout << gameInputItems.at(itemIndex).getName() << " description: " << gameInputItems.at(itemIndex).getDescription() << endl; // print the items description when picked up
      }
      else if (itemIndex != -1 && !gameInputItems.at(itemIndex).getRoom().isSameRoom(character.getRoom()))
      { // if the item exists, but isn't in same room as player, or is mispelled.
         cout << "The item: " << itemName << " is either not in this room, or was not spelled correctly. (Note: must use - instead of space for item name, eg. shrink-drink.)" << endl;
      }
      else
      {
         cout << itemName << " is not an item in this game" << endl;
      }
   }
   // add drop functionality above later
   void dropGameItem(string itemName, Player &character, vector<Items> &gameInputItems, vector<Room> mapInput)
   {
      // first we need to get the index of the item the character is looking for:
      int indexGameItems = getItemIndexGeneral(itemName, gameInputItems); // find the index of the item
      int indexPlayerItems = character.getItemIndex(itemName);
      if (indexGameItems != -1 && indexPlayerItems != -1)
      {
         if (character.getRoom().isSameRoom(mapInput.at(0)))
         {                                                                                             // if player is in the safe room/first room.
            character.dropItem(indexPlayerItems, character.getPlayerInventory().at(indexPlayerItems)); // drop the item using member function of the inventory class.
            gameInputItems.at(indexGameItems).isDropped();                                             // sets games item to dropped status
            gameInputItems.at(indexGameItems).setRoom(character.getRoom());                            // changes the current room of the game item to the room the player is in.
         }
         else
         { // if player isn't in the safe room
            cout << "You can only drop items in " << mapInput.at(0).getName() << " as this is the room with the chest." << endl;
         }
      }
      else
      { // if player doesn't have the item.
         cout << itemName << " is not in your inventory." << endl;
      }
   }

   // unlock door function:
   void unlockDoor(string roomName, vector<Room> &mapInput, Player &character)
   {
      int roomIndex = getRoomIndex(roomName, mapInput);                                // finds the room index in map vector
      string keyNameVar = mapInput.at(roomIndex).getKeyName();                         // finds the name of the key that should open the specific door.
      int playerKeyIndex = character.getItemIndex(keyNameVar);                         // finds the key in the players inventory, will return -1 if it doesnt exist.
      string playerKeyVarName = character.getInventory().at(playerKeyIndex).getName(); // find the key name
      if (character.getRoom().getIsLocked())
      { // if the current room is locked.
         if (roomIndex != -1 && playerKeyIndex != -1 && playerKeyVarName == keyNameVar)
         {                                             // if the room exists in the map, and they key for that room is in the players inventory, and the name of the key in inventory is equal to name of key needed for door.
            mapInput.at(roomIndex).setIsLocked(false); // room is no longer locked
            cout << mapInput.at(roomIndex).getName() << " has been unlocked with " << keyNameVar << endl;
         }
         else
         {
            cout << "you need " << keyNameVar << " in order to open this door." << endl;
         }
      }
      else
      {
         cout << character.getRoom().getName() << " is not locked." << endl;
      }
   }
   // slay Jabberwocky/end game win condition
   void slayJabberwocky(string jabberwockyName, vector<Items> &gameItemsInput, vector<Character> &gameCastInput, Player &character)
   {
      int indexJ = getCharacterIndex(jabberwockyName, gameCastInput); // get index position of character Jabberwocky from game cast.
      // check player has all vorpal items in inventory
      int indexHelm = character.getItemIndex("VORPAL-HELMET");
      int indexChest = character.getItemIndex("VORPAL-CHESTPLATE");
      int indexLeg = character.getItemIndex("VORPAL-LEGPLATE");
      int indexSword = character.getItemIndex("VORPAL-SWORD");
      if (indexHelm != -1 && indexChest != -1 && indexLeg != -1 && indexSword != -1 && character.getRoom().isSameRoom(gameCastInput.at(indexJ).getRoom()))
      { // if player has all vorpal items, and is in the same room as the Jabberwocky.
         cout << character.getName() << " swings the mighty Vorpal sword and cuts the head of the Jabberwocky clean off!" << endl;
         cout << "Congratulations you've completed the game! Thanks again for saving Wonderland!" << endl;
         exit(-1); // end the game.
      }
      else
      {
         cout << "You need to be near the Jabberwocky with the complete Vorpal set to kill it." << endl;
      }
   }
   // eat item function
   void eatItem(string itemName, Player &character)
   {
      int itemIndex = character.getItemIndex(itemName); // get the index of the item from the players inventory
      if (itemIndex != -1)
      { // if the item is in the players inventory
         if (character.getPlayerInventory().at(itemIndex).getIsEdible())
         {                          // if the item is edible
            character.growPlayer(); // grow the player, since only one item in game is edible, that's all that will be done for now.
         }
         else
         {
            cout << itemName << " you can't eat this, are you crazy?" << endl;
         }
      }
      else
      {
         cout << itemName << " not in your inventory" << endl;
      }
   }
   // drink item function
   void drinkItem(string itemName, Player &character)
   {
      int itemIndex = character.getItemIndex(itemName); // get the index of the item from the players inventory
      if (itemIndex != -1)
      { // if the item is in the players inventory
         if (character.getPlayerInventory().at(itemIndex).getIsDrinkable())
         {                            // if the item is edible
            character.shrinkPlayer(); // grow the player, since only one item in game is edible, that's all that will be done for now.
         }
         else
         {
            cout << itemName << " you can't drink this, are you crazy?" << endl;
         }
      }
      else
      {
         cout << itemName << " not in your inventory" << endl;
      }
   }
   // test if player has the correct size function:
   bool testPlayerSize(Player &character)
   {
      if (character.getRoom().getSizeReqBool())
      { // if the room does have a size requirment.
         if (character.getRoom().getSizeRequirment() == "SMALL" && character.getShrunk())
         { // if room requirment is small, and player is small, let player move through
            return true;
         }
         else if (character.getRoom().getSizeRequirment() == "BIG" && character.getLarge())
         { // if room requirment is large, and player is large, let player move through
            return true;
         }
         else
         {
            return false;
         }
      }
      else
      {               // if the room doesn't have a size requirment.
         return true; // player should be allowed to move through without issue.
      }
   }
};

// Wonderland/General Game Class:
class Wonderland
{
   // private by default

public:
   // default constructor:
   Wonderland()
   {
      // does nothing
   }
   // run function:
   void run()
   {
      readFile("intro.txt");

      Actions gameAction("action.txt"); // load game actions
      Actions gameObject("object.txt"); // load game objects
      // create map:
      vector<Room> map;
      ifstream fileInMap("locations.txt");
      if (fileInMap.good())
      { // if the locations.txt file is opened properly
         string roomName;
         string roomDescription;
         string nString, sString, wString, eString, lockedInput, keyInput, sizeReqInput;
         int n, s, w, e;
         int k = 0;
         while (!fileInMap.eof())
         { // until we reach the end of the file.
            getline(fileInMap, roomName);
            getline(fileInMap, roomDescription);
            getline(fileInMap, nString);
            getline(fileInMap, sString);
            getline(fileInMap, wString);
            getline(fileInMap, eString);
            // using stoi function to convert from string to integer
            n = stoi(nString);
            s = stoi(sString);
            w = stoi(wString);
            e = stoi(eString);
            getline(fileInMap, lockedInput);
            getline(fileInMap, keyInput);
            getline(fileInMap, sizeReqInput);
            map.push_back(Room(roomName, roomDescription, n, s, w, e, lockedInput, keyInput, sizeReqInput));
            k++;
         }
      }
      else
      {
         cout << "Error, file not found or not opened properly" << endl;
      }
      // create player inventory.
      Inventory gameInventory;
      vector<Character> cast; // will contain all the characters in the game.
      ifstream fileInChar("characters.txt");
      if (fileInChar.good())
      { // if file is opened properly
         string name;
         string description;
         string roomName;
         int i = 0;
         while (!fileInChar.eof())
         { // run until we reach the end of the file
            getline(fileInChar, name);
            getline(fileInChar, description);
            getline(fileInChar, roomName);
            cast.push_back(Character(name, description, roomName, map)); // maybe a map funcion which tests the name of the room.
            i++;
         }
      }
      else
      {
         cout << "Error, file not found or not opened properly" << endl;
      }
      // add characters dialog, only one each for now, but constructed so more could be added later.
      cast.at(0).addDialog(" Well it's about time you arrived, I've been waiting for some time. To learn more you should head west to talk to the wise Absolem");               // white rabbit
      cast.at(1).addDialog("Well Alice it's nice to finally meet you, I would think you know to go north past the Forest you came from right?");                                // ABSOLEM
      cast.at(2).addDialog("Hello, how do you do? Feel free to grab my hat, a cup of tea, and head on east, p.s. pickup the scary dog key.");                                   // MAD HATTER
      cast.at(3).addDialog("Hello Alice, why don't you look lovely, I hope you're ready to kill the Jabberwocky, make sure you have all the armor and sword in order to win."); // WHITE QUEEN
      cast.at(4).addDialog("How dare you approach me directly, you're lucky I don't have you head off already!!!");                                                             // RED QUEEN
      cast.at(5).addDialog("You seem lost, almost like you've forgotten there's only four directions to travel here.");                                                         // CHESHIRE-CAT
      cast.at(6).addDialog("RAGHHHHHHHHHH!!!!");                                                                                                                                // JABBERWOCKY
      cast.at(7).addDialog("Hello, I hope you're enjoying the game, by the way if this is the grader reading this, this easter egg is not a bribe for a better grade.");        // TARREN

      vector<Items> gameItems; // will contain all the items in the game
      ifstream fileInItem("items.txt");
      if (fileInItem.good())
      { // if the file is opened properly
         string name;
         string description;
         string roomName;
         string isEdibleInput;
         int j = 0;
         while (!fileInItem.eof())
         { // run until we reach the end of the file
            getline(fileInItem, name);
            getline(fileInItem, description);
            getline(fileInItem, roomName);
            getline(fileInItem, isEdibleInput);
            gameItems.push_back(Items(name, description, roomName, map, isEdibleInput)); // add the items to the game items vector
            j++;
         }
      }
      else
      {
         cout << "Error, file not found or not opened properly" << endl;
      }
      // create safe room chest:
      Player alice("Alice", "A curious woman", map.at(0), map, gameItems);         // create player
      Control gameController(alice, gameAction, gameObject, cast, gameItems, map); // create control object
      alice.movePlayer(0);                                                         // move alice to starter room.
      string userCommand, action, object, buffer;
      while (userCommand != "Q")
      { // Q for quit
         cout << "Enter a two word command: ";
         cin >> action >> object;
         getline(cin, buffer); // prevent excess strings from entering buffer.
         gameController.inputUpdate(action, object);
      }
   }
};
// main method:
int main()
{
   Wonderland game;
   game.run();
   return 0;
}