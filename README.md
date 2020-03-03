# The Goldband Project (7DRL 2020)

![Screenshot of the Main Menu](https://github.com/andrewgasson/roguelike-7drl-2020/blob/master/document/picture/main_menu.png)

_The Goldband Project_ is a traditional roguelike made for the 7DRL challenge 2020 (#7DRL2020).

To check out the 7DRL challenge, go here: <https://7drl.com/>.

## Game Design Plan
_The Goldband_ project is set in a capitalist medieval fantasy world, where only those who retire are heroes and wealth triumphs over all, and all others are tragedies or outright forgotten.

### What is the goal?
To earn enough money to purchase a retirement home and retire.

### What is the motive?
Retirement + additional wealth = score. There will be a high score menu.

### What are the stakes?
Retiring without a retirement home (poverty ending) results in no high score, and no graveyard. Death before retiring (death ending) results in no high score, but the character is listed in the graveyard (for a time).

### What are the core conflicts?
Gold. You must find and earn gold to purchase a retirement home, equipment, training, items, pay your taxes, and afford bonds to earn money from contracts that involve delving various wilderness landscapes.

### What are the possible outcomes?
- Victory with a new high score (heroic + enduring status)
- Victory with a score (heroic)
- Loss with no high score, but with a graveyard acknowledgment (death)
- Loss with no high score, and no graveyard acknowledgment (poverty)

## Status
Currently, the character can move around a box, and will collide with the box's edges. There is a main menu and pause menu. After the save system is added (next on the list), the development of gameplay will be underway.

## Log
- Day #1 was primarily about setting up the code in preparation for the gameplay mechanics. However, there really wasn't a "game" at this point.
- Day #2 focused adding GUI state and rendering, cleaning the code architecture, and clarifying the gameplay (via private game design document based on gameplay.md in the document folder).
- Day #3 focused on creating a proper main menu and pause menu, preparing for GUI prompts (also known as modals or dialogs in some systems), and changing game state to use a push and pop stack, rather than just a set, which is necessary for deep menu hierarchies, and retaining their state (for example: default game state <-> pause menu <-> setting menu <-> sub-setting menu). Also cleaned up the README.
- Day #4 focused on adding prompt function (and a bool prompt with associated controls and render), testing the new game state stack, and creating a color tool that allows for the ability to add a layer of transparency over the pre-rendered terminal scene, which helps prompts pop out. The end of the day focused on preparation for saving and loading the config (as .ini) and game (as binary).

## TODO
- Save and load config to and from file.
- Core gameplay mechanics
	- Map, tiles, and mechanisms
	- Map drawing and generation
	- Turn system
	- Basic AI
	- Dumb pathfinding
	- Database/datatables
	- Game event log
	- Hall of Fame
	- Graveyard
	- Purchase retirement home
	- Retire (or outcast) option
	- Basic game save/load
	- Save on quit
	- Multiple game saves (?)
- Greater gameplay mechanics
	- Gold
	- Skills
	- Equipment
	- Items
	- Shops
	- Ranged (?)
	- Magic (?)
	- Stat effects
	- Enemy templates
