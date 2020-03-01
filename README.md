# 7DRL 2020
A traditional roguelike for the 7DRL challenge 2020 (#7DRL2020).

To check out the 7DRL challenge, go here: <https://7drl.com/>.

## Current status
Currently, the character (@ symbol with background and foreground colours) can move around a box, and will collide with the box's edges. There is also a sort of menu that allows you to continue playing or quit (really just a demo for states and GUI at the moment).

- Day #1 was primarily about setting up the code in preparation for the gameplay mechanics. However, there really wasn't a "game" at this point.
- Day #2 focused adding GUI state and rendering, cleaning the code architecture, and clarifying the gameplay (via private game design document based on gameplay.md in the document folder).

Completed mechanics:
- Code architecture
- Input-action translation
- Game state and game action translation
- Game rendering
- GUI state and rendering

Completed gameplay plan:
- End game
	- What is the goal? To earn enough money to purchase a retirement home and retire.
	- What is the motive? Retirement + additional wealth = score. There will be a private high score leaderboard.
	- What are the stakes? Retirement without a retirement home leads to no high score, and no graveyard acknowledgement. Death before retirement puts a character in the graveyard (no high score).
	- What are the conflicts? Wealth: you need gold to purchase a retirement home, equipment, training, items, pay your taxes, afford bonds to earn money from contracts.
	- What are the possible outcomes? Victory with a new high score; victory with a score; failure, with no high score, but with a graveyard acknowledgment; failure, with no high score, and no graveyard acknowledgement.

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
