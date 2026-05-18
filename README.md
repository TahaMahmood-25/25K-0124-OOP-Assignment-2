Section 1: Class Definitions:
Reasoning:
On Pakwheels, every object is a listing. I defined a vehicle class to store basic attributes seen on the site like brand, model and price. Because every car has a specific and unique engine, I created a separate Engine class to handle horsepower and CC.
Hence, the code becomes modular.


Section 2: Constructors and Memory Management
Reasoning:
When a user fills out the “Sell” form, the system must create a new object immediately. The parameterized constructor is used to initialize the car’s data at the moment of creation. I also implemented the the copy constructor in the Listing class so that if a user wants to re-post or duplicate an old add, the system can create a new object with the same data.


Section 3: Constants and Static Members
Reasoning:
As there are thousands of users, I have used a static member “totalUser” because this data belongs to the entire platform, not to a single person. The const “UserID” is used because once a user has been registered, their ID should not be changed for security and tracking purposes.


Section 4: Composition and Aggregation
Reasoning:
I used composition for the Engine inside the Vehicle class because an engine cannot exist on the marketplace without a car. If the car object is deleted, the engine also gets deleted. However, for the Seller in a listing, I used Aggregation. This is because even if a specific car listing is sold and deleted, the seller’s account should still exist on Pakwheels to post other cars later.


Section 5: Functionality (Searching and Messaging)
Reasoning:
I implemented the searchByPrice function to iterate through the lists[] array and display only cars within the buyer’s budget. Furthermore, the Message class replicates the “Contact seller” feature, allowing a Buyer object to send a message to a Seller object.


Section 6: Inheritance:
Reasoning:
I created a base class vehicle and inherited Car, Bike, and Truck classes from it. This avoids code duplication and makes the system easier to manage and extend in the future.
Similarly, different types of users on the platform such as Buyer, Seller, and Admin all share common information like name, email, and userID. Therefore, these classes inherit from the User class. This follows the real-world structure of an online marketplace system.

Code snippits:

class Car : public vehicle
{
private:
    int doorsNum;
    string bodyType;
};

class Buyer : public User
{
private:
    string favourites[10];
    int count;
};


Section 7: Polymorphism:
Reasoning:
I used polymorphism so that the same function can behave differently for different objects.
For example, the displayDetails() function is declared as virtual in the vehicle class and overridden in the Car, Bike, and Truck classes. This allows the system to display different details depending on the actual vehicle type while using a single base class pointer.

Code snippits:

virtual void displayDetails() = 0;

void displayDetails() override
{
    cout << "--- Car Details ---" << endl;
    display();
    cout << "Doors: " << doorsNum << endl;
}


Section 8: Abstract Clases:
Reasongin:
I made the vehicle and User classes partially abstract by using pure virtual functions such as displayDetails() and displayProfile().
The system should only create specific objects like Cars, Bikes, Buyers, or Sellers.

Code snippits:

virtual void displayDetails() = 0;
virtual void displayProfile() = 0;


Section 9: Operator Overloading:
Reasoning:
I overloaded the == operator in the vehicle class to compare prices of two vehicles directly. (Comparing 2 listing on pakwheels)
I also overloaded the + operator to combine prices of two vehicles or two payments

Code snippits:

bool operator==(const vehicle &v) const
{
    return price == v.price;
}

float operator+(const Payment &p) const
{
    return amount + p.amount;
}


Section 10: Friend Functions:
Reasoning:
I used friend functions when an external function needed direct access to private or protected data members of a class.
For example, the compareCarDetails() function compares the number of doors between two car objects, while checkAffordability() checks whether a buyer’s budget is enough for a vehicle.

friend void compareCarDetails(Car &c1, Car &c2);
friend void checkAffordability(Buyer &b, vehicle &v);
