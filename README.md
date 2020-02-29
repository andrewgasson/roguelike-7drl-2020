# 7DRL 2020
A traditional roguelike for the 7DRL challenge 2020 (#7DRL2020).

To check out the 7DRL challenge, go here: <https://7drl.com/>.

## Current status
Currently, the character (@ symbol with background and foreground colours) can move around a box, and will collide with the box's edges. This first day was primarily about setting up the code in preparation for the gameplay mechanics. However, there really isn't a "game" at this point.

- Code architecture
- Rendering
- Input handling
- Game action handling

## TODO list
- Implement UI system
	- API
	- Structures
	- Rendering
- Core gameplay mechanics
	- Map, tiles, and mechanisms
	- Map generation (will there be a static overworld like Angband or ADOM?)
	- Turn system
	- Basic AI
	- Dumb pathfinding
	- Database/datatables
	- Event log
	- Main menu
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
- End game
	- What is the goal?
	- What is the motive?
	- What are the stakes?
	- What are the conflicts?
	- What are the possible outcomes?
