Project Specifications:

There are...
0 - * floors
2 - * elevators

Each elevator has:
> floor buttons = # floors
> floor lights = # floors (requested floors lit until visited)
> current floor lights = # floors (current floor lit)
> elevator motor -> up, down, stop commands
> sensor -> returns whether elevator is moving or stopped
> emergency break
> door -> open or close commands
> door sensor -> clear or obstacle present

On each floor there are:

> up and down buttons
> lights for up and down buttons
(bottom floor only has up, top floor only has down)

For each elevator on each floor:

> lights for next direction of that elevator (departing up or down, top and bottom floors only have one light)
> floor sensor that indicates when an elevator has arrived at that floor

Emergency Brake triggers:

> elevator commanded to stop, but does not stop at desired floor
> elevator commanded to move, but will not move
> doors commanded to open when stopped at floor, but will not open
> doors open while moving
> elevator continues up at top floor or down at bottom floor