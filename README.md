# Project-NightClub-Operating-Systems

This project was carried out for the Operating Systems course, in which it was requested to simulate a nightclub.
The nightclub is composed of various areas, such as dance floors, sofa areas, bakery, go-kart track, mini-golf, etc... (e.g., Day After, Viseu.)

Typically, each space, for safety and club policies reasons, has different access rules. Some are freely accessible to all users, others only to users with special privileges, and still, some have time restrictions.
Users, after entering the nightclub, go to a specific dance floor and can move from floor to floor, or to other areas, staying in each for a certain time. In the case of a floor being crowded, the user should either wait or go to another area or even leave the nightclub. In this simulation, the user should, at least, try to access the majority of the spaces.
The simulation to be implemented aims to evaluate the operational conditions of such an establishment in terms of how many people it can serve, average wait times, how many give up, among other factors.

**Architecture:**
The developed system contains two applications: the first one (Simulator) performs the entire simulation, and the second one (Monitor) receives all messages sent by the first one and processes them.

The **Simulator** randomly generates the arrival of users (each user is a **thread**) to resources, allowing proper coordination and synchronization through **semaphores**, and sends messages to the Monitor (communication via **sockets**).

The **Monitor** accepts a connection from a Simulator and saves all the logs sent by it into a file. Data processing of the simulation occurs at the Monitor level (calculating the average waiting time, for example).
During the operation of the Monitor, data about its execution status is displayed.

