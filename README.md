# Simulation game dev by Jaouen and Romain

2D game developed with SFML, implementing a simulation game with behaviors trees.

## 📋 Description

This project is a simulation game about customers and merchants with a behavior tree with a systeme of time (morning, day, evening):

The player can see the simulation evolve and decide how many customers as well as their speed.

Their is also 3 events : A theft, A fire and An inflation 

---

## 🎮 Features

- **IA with behaviors trees** 
- **A menu** : can edit the speed and the number of customers
- **Endless simulation** 

## 🛠️ Technologies used

- **Language**: C++
- **Librarie**:SFML

# Behavior tree
**👤 Customer Sequence**

Handles the complete customer lifecycle.

Flow:

**Customer**

→ Go To Merchant
    → Choose Merchant
    → Move To Merchant
→ Buy
→ Exit
→ Destroy (if needed)


✔ Represents the full flow from arrival to departure.

**🏪 Merchant (Selector / Fallback)**

Controls merchant logic depending on the time of day.



**🌅 Morning**

Check: isMorning
→ Handle Money (rent, deficit reset)
→ Fallback
    → Pay Raw Materials
    → Destroy Shop (if payment fails)


Focus: financial validation and survival.



**☀️ Day**

Check: isDay
→ Events (Selector)
    → Event 1
    → Event 2
    → Default


Focus: dynamic daily events.



**🌙 Evening**

Check: isEvening

If deficit > 0:
    Increase Orders
    or Raise Prices

If deficit < 0:
    Reduce Orders
    or Lower Prices


Focus: adaptive economic strategy.


**🎮 Game Sequence (Global Time Manager)**


Manages the day/night cycle and global orchestration.



**🌅 Morning**

Create Merchant
→ All Morning Actions Finished
→ Time → Day



**☀️ Day**

Create Customers
→ All Day Actions Finished
→ Handle Events
→ Time → Evening



**🌙 Evening**

All Evening Actions Finished
→ Time → Morning
