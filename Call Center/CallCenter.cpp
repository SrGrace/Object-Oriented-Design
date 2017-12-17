


// CallHandler represent the body of the program, and all calls are funneled first through it.
class CallHandler
{
    // 3 levels of employees: respondent, manager, director
    int LEVELS = 3;
    
    // initialize 10 respondents, 4 managers, and 2 directors
    int NUM_RESPONDENTS = 10;
    int NUM_MANAGERS = 4;
    int NUM_DIRECTORS = 2;
    
    vector< vector< Employees > > employeeLevels;
    
    /* list of employees, by level;
        employeeLevels[0] = respondents;
        employeeLevels[1] = managers;
        employeeLevels[2] = directors
    */
    
    vector< vector< Call > > callQueues;
    
    public:
        CallHandler() { ... }
        
        // get the first available employee who can handle this call
        Employee getHandlerForCall(Call call) { ... }
        
        // Route the call to an available employee, or saves in a queue if no employee is available
        void dispatchCall(Caller caller)
        {
            Call call = new Call(caller);
            dispatchCall(call);
        }
    
        // Route the call to an available employee, or saves in a queue if no employee is available
        void dispatchCall(Call call)
        {
            // try to route the call to an employee with minimal rank
            Employee emp = getHandlerForCall(call);
            
            if(emp != NULL)
            {
                emp.receiveCall(call);
                call.setHandler(emp);
            }
            else
            {
                // place the call to corrosponding call queue according to its rank
                call.reply("Please wait for free employee to reply");
                callQueues[call.getRank()].push_back(call);
            }
        }
    
        // An employee gets free. Look for a waiting call that employee can serve.
        // Return true if we assigned a call, false otherwise
        bool assignCall(Employee emp) { ... }
      
}



// Call represent a call from a user. A call has minimum rank and is assigned to the first employee, who can handle it.
class Call
{
    // Minimal rank of employee who can handle this call.
    Rank rank;
    
    // Person who is calling
    Caller caller;
    
    // Employee who is handling the call
    Employee handler;
    
    public:
        Call(Caller c)
        {
            rank = Rank.Responder;
            caller = c;
        }
        
        // set employee who is handling the call
        void setHandler(Employee e) { handler = e;}
        
        void reply(string msg) { ... }
        Rank getRank() { return rank; }
        void setRank(Rank r) { rank = r;}
        Rank incrementRank() { ... }
        void disconnect() { ... }
}


// Employee is a base class for all the different employee classes 
class Employee
{
    Call currentCall = NULL;
    Rank rank;
    
    public:
        Employee(CallHandler handler) { ... }
        
        // start the conversation
        void receiveCall(Call call) { ... }
        
        // Issue resolved, finish the call
        void callCompleted() { ... }
    
        // Issue has not been resolved. Escalate the call, and assign a new call to the employee
        void escalateAndAssign() { ... }
        
        // If an employee is free, Assign a new call
        bool assignNewCall() { ... }
        
        // Return whether or not the employee is free?
        bool isFree() { return currentCall == NULL; }
    
        Rank getRank() { return rank; }
        
}


// The Respondent, Manager, and Director classes that are derived from Employee class
class Director : public Employee
{
    public:
        Director()
        {
            rank = Rank.Director;
        }
}

class Manager : public Employee
{
    public:
        Manager()
        {
            rank = Rank.Manager;
        }
}

class Respondent : public Employee
{
    public:
        Respondent()
        {
            rank = Rank.Respondent;
        }
}





