# Object-Oriented-Design

Object-Oriented system design i.e sketch out the classes and methods to implement technical problems or real-life objects.

## How to Approach

### Step 1: Handle Ambiguity

* Make assumptions or, ask clarifying questions.
* Go through "six W's": who, what, where, when, how, why.

### Step 2: Define the Core Objects

Suppose we are asked to do the object-oriented design for a restaurant. Our core objects might be things like **Table, Guest, Party, 
Order, Meal, Employee, Server, and Host etc**.

### Step 3: Analyse Relationships

Ask questions like...

Which objects are members of which other objects? <br>
Do any objects inherit from any others? <br>
Are relationships one-to-many or many-to-many?

For example, **Restaurant design**:
* **Party** should have an array of **Guests**.
* **Server** and **Host** inherit from **Employee**.
* Each **Table** has one **Party**, but each **Party** may have multiple **Tables**.
* There is one **Host** for the Restaurant.

### Step 4: Investigate Actions

At this point, we have the basic outline of the object-oriented design. Now, we have to consider key actions that the objects will take
and how they relate to each other. Add and update some forgotten objects, if possible.

## Design Patterns

### Singleton Class (Can interfere with unit testing)

The singleton pattern ensures that a class has only one instance and ensures access to the instance through the application.
**Example:**

```java
public class Restaurant 
{
    private static Restaurant _instance = null;
    protected Restaurant() { .... }
    public static Restaurant getInstance() 
    {
        if(_instance == null)
            _instance = new Restaurant();
            
        return _instance;
    }
}
```

### Factory Mathod

The Factory Method offers an interface for creating an instance of a class, with its sub-classes deciding which class to instantiate.
**Example:**

```java
public class CardGame
{
    public static CardGame createCardGame(GameType type)
    {
        if(type == GameType.Poker)
            return new PokerGame();
            
        else if(type == GameType.BlackJack)
            return new BlackJackGame();
            
        return null;
    }
}
```

