
# Parking Lot
Design a parking lot using object-oriented principles.

## [Solution](https://github.com/SrGrace/Object-Oriented-Design/blob/master/Parking%20Lot/ParkingLot.cpp)

**Questions to be asked:** 
<br>
* what types of vehicles it can support. 
* whether the parking lot has multiple levels, and so on.
<br>

For our purposes right now, we'll make the following assumptions. We made these specifc assumptions to add a bit of complexity to 
the problem without adding too much. If you made diﬀerent assumptions, that's totally fine.

* The parking lot has multiple levels. Each level has multiple rows of spots.
* The parking lot can park motorcycles, cars, and buses.
* The parking lot has motorcycle spots, compact spots, and large spots.
* A motorcycle can park in any spot.
* A car can park in either a single compact spot or a single large spot.
* A bus can park in five large spots that are consecutive and within the same row. It cannot park in small spots.
<br>

For the implementation, create an base class Vehicle, from which Car, Bus, and Motorcycle inherit. To handle the 
diﬀerent parking spot sizes, just one class ParkingSpot which has a member variable indicating the size.
<br>

**Classes includes:**

```c++

class Vehicle {}
class Bus : public Vehicle {}
class Car : public Vehicle {}
class Motorcycle : public Vehicle {}

class ParkingLot {}

class Level {}   // level in parking garage

class ParkingSpot {}

```


