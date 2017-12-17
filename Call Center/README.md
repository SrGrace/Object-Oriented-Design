

# Call Center:

Imagine you have a call center with three levels of employees: respondent, manager, and director. An incoming telephone call must 
be frst allocated to a respondent who is free. If the respondent can't handle the call, he or she must escalate the call to a manager.
If the manager is not free or not able to handle it, then the call should be escalated to a director. Design the classes and
data structures for this problem. Implement a method dispatchCall () which assigns a call to the first available employee

<br>
<br>
<br>

##[OOPS Design i.e. Solution](https://github.com/SrGrace/Object-Oriented-Design/blob/master/Call%20Center/CallCenter.cpp)
<br>

* All three ranks of employees have diﬀerent work to be done, so those specifc functions are profle specifc. We should keep these things 
within their respective class.
* There are a few things which are common to them, like address, name, job title, and age. These things can be kept in one class and 
can be extended or inherited by others.
* Finally, there should be one CallHandler class which would route the calls to the correct person.

