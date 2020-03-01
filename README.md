# 7DRL 2020
A traditional roguelike for the 7DRL challenge 2020 (#7DRL2020).

To check out the 7DRL challenge, go here: <https://7drl.com/>.

## Current status
Currently, the character (@ symbol with background and foreground colours) can move around a box, and will collide with the box's edges. There is also a sort of menu that allows you to continue playing or quit (really just a demo for states and GUI at the moment).

- Day #1 was primarily about setting up the code in preparation for the gameplay mechanics. However, there really isn't a "game" at this point.
- Day #2 was focused adding GUI state and rendering, cleaning the code architecture, and clarifying the gameplay (via private game design document based on gameplay.md in the document folder).

Completed mechanics:
- Code architecture
- Input-action translation
- Game state and game action translation
- Game rendering
- GUI state and rendering

Completed gameplay plan:
- End game
	- What is the goal?
	- What is the motive?
	- What are the stakes?
	- What are the conflicts?
	- What are the possible outcomes?

## TODO list
- Core gameplay mechanics
	- Map, tiles, and mechanisms (to finalise)
	- Map drawing and generation (to finalise)
	- Turn system
	- Basic AI
	- Dumb pathfinding
	- Database/datatables
	- Game event log
	- Main menu (to finalise)
	- Basic game save/load
	- Save on quit
	- Multiple game saves (?)
- Save and load config to and from file.
- Greater gameplay mechanics
	- Stats
	- Items
	- Equipment
	- Ranged (?)
	- Stat effects
	- Enemy templates
	- Shops
