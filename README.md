# The Goldband Project (7DRL 2020)
_The Goldband Project_ is a traditional roguelike made for the 7DRL challenge 2020 (#7DRL2020).

To check out the 7DRL challenge, go here: <https://7drl.com/>.

![Screenshot of the Main Menu](https://github.com/andrewgasson/roguelike-7drl-2020/blob/master/document/picture/main_menu.png)

## Plan
### What is the goal?
To earn enough money to purchase a retirement home and retire.

### What is the motive?
Retirement + additional wealth = score. There will be a high score menu.

### What are the stakes?
Retirement without a retirement home leads to no high score, and no graveyard acknowledgement (considered retiring into poverty). Death before retirement puts a character in the graveyard (no high score).

### What are the core conflicts?
Gold. You must find and earn gold to purchase a retirement home, equipment, training, items, pay your taxes, and afford bonds to earn money from contracts that involve delving various wilderness landscapes.

### What are the possible outcomes?
- Victory with a new high score (heroic + enduring status)
- Victory with a score (heroic)
- Loss with no high score, but with a graveyard acknowledgment (death)
- Loss with no high score, and no graveyard acknowledgment (poverty)

## Status
Currently, the character can move around a box, and will collide with the box's edges. There is a main menu and pause menu. However, gameplay is under development.

## Log
- Day #1 was primarily about setting up the code in preparation for the gameplay mechanics. However, there really wasn't a "game" at this point.
- Day #2 focused adding GUI state and rendering, cleaning the code architecture, and clarifying the gameplay (via private game design document based on gameplay.md in the document folder).

## TODO
- Menu
	- Add prompts
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
- Save and load config to and from file.
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
