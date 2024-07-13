# Veil: An Unreal 5 PvP Tactical FPS
Veil is meant to be a medium sized project focused on creating an FPS in the vein of R6: Siege but with some QoL features. Currently, the plan is to only have custom games and use this as a proof of concept since it doesn't require accounts, matchmaking, MMR, anti-cheat, etc.

# Build Details
Built using Unreal Engine 5.4 (might upgrade to 5.5 when it comes out)

Heavily utilizes GAS for ease of replication

Uses Steamworks for networking

# Features
## Current
- First person and 3rd person models with basic animations
- Modifiable gun system with attachments
  - 4 Scopes - 1x, 2.5x, 4x, 8x
  - 5 Barrels - Flash Hider, Compensator, Muzzle Break, Extended Barrel, Suppressor
  - 4 Grips - Vertical, Horizontal, Angled, Stubby
  - 2 Side Barrel - Laser Sight, Rangefinder
  - 4 Stocks - Heavy duty, standard, light, no stock
  - Attachments effects are implemented, models are not
- Working ADS system
- Working deterministic recoil system
- Working damage system with dropoff, bullet pen and headshot damage
- Working bullet counting + reloading
- Start spectating teammates on death
- Objective implementation (Planting, Defusing and winning on time/elimination)
- Round termination conditions and resets
- Destructible environment pieces

## Planned
- Joining lobbies, setting teams and starting a match
  - Extreme priority, required to test really anything
- Loadout selection
  - Low priority, useful for testing but not necessary
- Gadgets
  - High priority for system implementation
  - Med priority for individual gadget implementation
- Character selection
  - Low priority, not necessary for development, only for final gameplay
  - If the gadgets work themselves, character selection is relatively trivial
- More guns
  - Low priority, base gun and all attachments are already implemented
- Drones and cameras
  - Med priority, important for core gameplay
- Menus
  - Low priority, mostly necessary once starting external testing
- In-game UI (WIP)
  - Med priority, useful for testing and important for core gameplay
- Better animations, models, etc
  - If I get funding and can pay for artists lmao
