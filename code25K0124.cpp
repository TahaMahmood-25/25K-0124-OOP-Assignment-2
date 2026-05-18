#include <iostream>
#include <string>
using namespace std;

class Engine
{
private:
    int engineID;
    int horsepower;
    string fuelType;
    int engineCC;
    int cylinder;
    string condition;

public:
    Engine() : engineID(0)
    {
        horsepower = 0;
        fuelType = "Unknown";
        engineCC = 0;
        cylinder = 0;
        condition = "Unknown";
    }

    Engine(int id, int horsepower, string fuelType, int engineCC, int cylinder, string condition) : engineID(id)
    {
        this->horsepower = horsepower;
        this->fuelType = fuelType;
        this->engineCC = engineCC;
        this->cylinder = cylinder;
        this->condition = condition;
    }

    Engine(const Engine &e) : engineID(e.engineID)
    {
        horsepower = e.horsepower;
        fuelType = e.fuelType;
        engineCC = e.engineCC;
        cylinder = e.cylinder;
        condition = e.condition;
    }

    void display()
    {
        cout << "Horsepower: " << horsepower << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Engine Size: " << engineCC << endl;
        cout << "Cylinders: " << cylinder << endl;
        cout << "Condition: " << condition << endl;
    }

    void updateHorsepower(int hp)
    {
        horsepower = hp;
    }

    void updateCondition(string cond)
    {
        condition = cond;
    }

    void upgradeEngine(int extraHP)
    {
        horsepower += extraHP;
    }
};

class Transmission
{
private:
    string type;
    int gears;
    string condition;
    bool automatic;

public:
    Transmission()
    {
        type = "Manual";
        gears = 0;
        condition = "Unknown";
        automatic = 0;
    }

    Transmission(string type, int gears, string condition, bool automatic)
    {
        this->type = type;
        this->gears = gears;
        this->condition = condition;
        this->automatic = automatic;
    }

    void display()
    {
        cout << "Type: " << type << endl;
        cout << "Gears : " << gears << endl;
        cout << "COndition of gears  " << condition << endl;
        cout << "Is the gear automatic? : " << automatic << endl;
    }

    void updateGears(int g)
    {
        gears = g;
    }

    void updateCondition(string c)
    {
        condition = c;
    }

    void changeType(string t)
    {
        type = t;
    }
};

class vehicle
{
protected:
    int vehicleID;
    string brand;
    string model;

    int year;
    float price;
    int millage;

    Engine e; // Composition
    Transmission t;

public:
    vehicle(int id, string brand, string model, int year, float price, int millage) : vehicleID(id)
    {
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->price = price;
        this->millage = millage;
    }

    vehicle() : vehicleID(0)
    {
        brand = "NUCES";
        model = "Unknown";
        year = 0;
        price = 0.0;
        millage = 0;
    }

    vehicle(const vehicle &v) : vehicleID(v.vehicleID)
    {
        brand = v.brand;
        model = v.model;
        year = v.year;
        price = v.price;
        millage = v.millage;
    }

    float getPrice() const
    {
        return price;
    }

    string getBrand() const
    {
        return brand;
    }

    string getModel() const
    {
        return model;
    }

    int getYear() const
    {
        return year;
    }

    int getMilleage() const
    {
        return millage;
    }

    float operator+(const vehicle &v) const
    {
        return price + v.price;
    }

    bool operator==(const vehicle &v) const
    {
        return price == v.price;
    }

    virtual void displayDetails() = 0;

    virtual void display() const
    {
        cout << "Brand - " << brand << endl;
        cout << "Model - " << model << endl;
        cout << "Year - " << year << endl;
        cout << "Price - " << price << endl;
        cout << "Millage - " << millage;
    }

    void updatePrice(float newPrice)
    {
        price = newPrice;
    }

    void updateMillage(int newMillage)
    {
        millage = newMillage;
    }

    void applyDiscount(float percent)
    {
        price = price - (price * percent / 100);
    }

    virtual ~vehicle()
    {
    }
};

class Car : public vehicle
{
private:
    int doorsNum;
    string bodyType;

public:
    Car() : vehicle()
    {
        doorsNum = 4;
        bodyType = "Unknown";
    }

    Car(int id, string brand, string model, int year, float price, int mileage, int doors, string body) : vehicle(id, brand, model, year, price, mileage), doorsNum(doors), bodyType(body) {};

    void displayDetails() override
    {
        cout << "--- Car Details ---" << endl;
        display();
        cout << "Doors: " << doorsNum << endl;
        cout << "Body Type: " << bodyType << endl;
    }

    friend void compareCarDetails(Car &c1, Car &c2);
};

class Bike : public vehicle
{
private:
    string bikeType;
    bool isModified;

public:
    Bike() : vehicle()
    {
        bikeType = "Unknownb";
        isModified = false;
    }

    Bike(int id, string brand, string model, int year, float price, int mileage, string btype, bool fairing) : vehicle(id, brand, model, year, price, mileage), bikeType(btype), isModified(fairing) {};

    void displayDetails() override
    {
        cout << "--- Bike Details ---" << endl;
        display();
        cout << "Bike Type: " << bikeType << endl;
        cout << "Has Fairing: " << (isModified ? "Yes" : "No") << endl;
    }
};

class Truck : public vehicle
{
private:
    float loadCapacity;
    int axleNum;

public:
    Truck() : vehicle()
    {
        loadCapacity = 0.0;
        axleNum = 2;
    }
    Truck(int id, string brand, string model, int year, float price, int mileage, float capacity, int axles) : vehicle(id, brand, model, year, price, mileage), loadCapacity(capacity), axleNum(axles) {};

    void displayDetails() override
    {
        cout << "--- Truck Details ---" << endl;
        display();
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
        cout << "Number of Axles: " << axleNum << endl;
    }
};

class User
{
protected:
    string name;
    string email;
    const int userID;
    static int totalUsers;

public:
    User() : userID(0)
    {
        name = "Unknown";
        email = "Unknown";
        totalUsers++;
    }

    User(string name, string email, int id) : userID(id)
    {
        this->name = name;
        this->email = email;
        totalUsers++;
    }

    User(const User &u) : userID(u.userID)
    {
        name = u.name;
        email = u.email;
        totalUsers++;
    }

    void display() const
    {
        cout << "Username" << name << endl;
        cout << "Email" << email << endl;
        cout << "User ID " << userID << endl;
    }

    static void showTotalUsers()
    {
        cout << "Total users: " << totalUsers << endl;
    }

    string getName() const
    {
        return name;
    }

    string getEmail() const
    {
        return email;
    }

    int getUserID() const
    {
        return userID;
    }

    virtual void displayProfile() = 0;
    virtual ~User() {}
};

int User::totalUsers = 0;

class Buyer : public User
{
private:
    string favourites[10];
    int count;
    float budget;

public:
    Buyer() : User()
    {
        count = 0;
        budget = 0.0;
    }

    Buyer(string name, string email, int ID, float budget) : User(name, email, ID)
    {
        count = 0;
        this->budget = budget;
    }

    void addFavourite(string vehicleName)
    {
        favourites[count] = vehicleName;
        count++;
    }

    void showFavourite()
    {
        for (int i = 0; i < count; i++)
        {
            cout << favourites[i] << endl;
        }
    }

    void sendMessage(string message)
    {
        cout << "Buyer sent message: " << message << endl;
    }

    float getBudget() const
    {
        return budget;
    }

    void displayProfile() override
    {
        cout << "--- Buyer Profile ---" << endl;
        display();
        cout << "Budget: " << budget << endl;
        cout << "Saved Favourites: " << count << endl;
    }

    bool operator==(const Buyer &b) const
    {
        return userID == b.userID;
    }
    friend void checkAffordability(Buyer &b, vehicle &v);
};

class Seller : public User
{
private:
    int totalListedcars;
    string shopName;
    float rating;

public:
    Seller() : User()
    {
        totalListedcars = 0;
        shopName = "Unknown";
        rating = 0.0;
    }

    Seller(string name, string email, int ID, string shop) : User(name, email, ID), shopName(shop)
    {
        totalListedcars = 0;
        rating = 5.0;
    }

    void addListing()
    {
        cout << "Lister added by owner " << endl;
        totalListedcars++;
    }

    void removeListing()
    {
        cout << "Listing removed " << endl;
        totalListedcars--;
    }

    int getTotalListing() const
    {
        return totalListedcars;
    }

    float getRating() const
    {
        return rating;
    }

    void updateRating(float newR)
    {
        rating = newR;
    }

    friend void compareSellers(Seller &s1, Seller &s2);

    void displayProfile() override
    {
        cout << "--- Seller Profile ---" << endl;
        display();
        cout << "Shop Name: " << shopName << endl;
        cout << "Total Listed Cars: " << totalListedcars << endl;
        cout << "Rating: " << rating << endl;
    }
};

class Admin : public User
{
private:
    string adminLevel;
    int actionsPerformed;
    static int totalAdmins;

public:
    Admin() : User()
    {
        adminLevel = "Junior";
        actionsPerformed = 0;
        totalAdmins++;
    }

    Admin(string name, string email, int ID, string level) : User(name, email, ID), adminLevel(level)
    {
        actionsPerformed = 0;
        totalAdmins++;
    }

    void performAction(string action)
    {
        cout << "Adminm " << name << "peformed " << action << endl;
        actionsPerformed++;
    }

    static void showTotalAdmins()
    {
        cout << "Total Admins " << totalAdmins << endl;
    }

    void displayProfile() override
    {
        cout << "--- Admin Profile ---" << endl;
        display();
        cout << "Admin Level: " << adminLevel << endl;
        cout << "Actions Performed: " << actionsPerformed << endl;
    }
};
int Admin::totalAdmins = 0;

class Listing
{
private:
    int listingID;
    vehicle *v;
    Seller *s; // Aggregation
    bool approved;
    string date;

public:
    Listing() : listingID(0)
    {
        v = nullptr;
        s = nullptr;
        approved = false;
        date = "Unknown";
    }

    Listing(int ID, vehicle *v, Seller *s, string date) : listingID(ID)
    {
        this->v = v;
        this->s = s;
        this->date = date;
        approved = false;
    }

    Listing(const Listing &L) : listingID(L.listingID)
    {
        v = L.v;
        s = L.s;
        approved = L.approved;
        date = L.date;
    }

    void approve()
    {
        approved = true;
        cout << "Listing Approved ..." << endl;
    }

    void remove()
    {
        approved = false;
        cout << "Listing is removed ..," << endl;
    }

    void display() const
    {
        cout << "Listing ID - " << listingID << endl;
        cout << "Date -" << date << endl;
        cout << "Approved - " << approved << endl;

        cout << "Seller infO" << endl;
        s->display();

        cout << "Vehicle info" << endl;
        v->display();
    }

    float getVehiclePrice() const
    {
        return v->getPrice();
    }

    bool isApproved()
    {
        return approved;
    }

    int getListingID() const
    {
        return listingID;
    }
};

class Message
{
private:
    int messageID;
    string txt;
    Buyer *sender;
    Seller *reciever;
    string Date;

public:
    Message() : messageID(0)
    {
        txt = "Unknown";
        sender = nullptr;
        reciever = nullptr;
        Date = "Unknown";
    }

    Message(int ID, string txt, Buyer *s, Seller *r, string date) : messageID(ID)
    {
        this->txt = txt;
        sender = s;
        reciever = r;
        Date = date;
    }

    Message(const Message &m) : messageID(m.messageID)
    {
        txt = m.txt;
        sender = m.sender;
        reciever = m.reciever;
        Date = m.Date;
    }

    void display()
    {
        cout << "Message ID: " << messageID << endl;
        cout << "Date: " << Date << endl;
        cout << "Text: " << txt << endl;
    }

    void editMessage(string newText)
    {
        txt = newText;
    }

    void deleteMessage()
    {
        txt = "DelEted Message";
    }

    int getMessageID()
    {
        return messageID;
    }
};

class MarketPlace
{
private:
    Listing lists[50];
    Message messages[50];
    int listingCount;
    int messageCount;
    string MarketplaceName;

public:
    MarketPlace()
    {
        listingCount = 0;
        messageCount = 0;
        MarketplaceName = "Car Market ";
    }

    void addListing(Listing L)
    {
        if (listingCount < 50)
        {
            lists[listingCount] = L;
            listingCount++;
        }
        cout << "Listing Added" << endl;
    }

    void approveListing(int ID)
    {
        for (int i = 0; i < listingCount; i++)
        {
            if (lists[i].getListingID() == ID)
            {
                lists[i].approve();
                return;
            }
        }
    }

    void deleleListing(int ID)
    {
        for (int i = 0; i < listingCount; i++)
        {
            if (lists[i].getListingID() == ID)
            {
                lists[i].remove();
                return;
            }
        }
    }

    void searchByPrice(float price)
    {
        for (int i = 0; i < listingCount; i++)
        {
            if (lists[i].getVehiclePrice() <= price)
            {
                cout << "lists: " << endl;
                lists[i].display();
            }
        }
    }

    void sendMessage(Message m)
    {
        if (messageCount < 50)
        {
            messages[messageCount] = m;
            messageCount++;
            cout << "Message sent" << endl;
        }
    }

    void showAll()
    {
        for (int i = 0; i < listingCount; i++)
        {
            cout << "Listing #" << i << endl;
            lists[i].display();
        }
    }
};

class Payment
{
private:
    int paymentID;
    float amount;
    string paymentMethod;
    string status;

public:
    Payment()
    {
        paymentID = 0;
        amount = 0;
        paymentMethod = "Unknown";
        status = "Unknown";
    }

    Payment(int id, float amount, string method)
    {
        paymentID = id;
        this->amount = amount;
        paymentMethod = method;
        status = "Pending";
    }

    void completePayment()
    {
        status = "Completed";
        cout << "Payment Successful." << endl;
    }

    void display()
    {
        cout << "Payment ID: " << paymentID << endl;
        cout << "Amount: " << amount << endl;
        cout << "Method: " << paymentMethod << endl;
        cout << "Status: " << status << endl;
    }

    float operator+(const Payment &p) const
    {
        return amount + p.amount;
    }

    bool operator==(const Payment &p) const
    {
        return amount == p.amount;
    }
};

void compareCarDetails(Car &c1, Car &c2)
{
    cout << c1.brand << "has" << c1.doorsNum << "doors" << endl;
    cout << c2.brand << "has " << c2.doorsNum << "doors" << endl;

    if (c1.doorsNum > c2.doorsNum)
    {
        cout << c1.brand << "has more number of doors " << endl;
    }
    else if (c2.doorsNum > c1.doorsNum)
    {
        cout << c2.brand << "has more number of doors " << endl;
    }
    else
    {
        cout << "Both have same number of doors." << endl;
    }
}

void checkAffordability(Buyer &b, vehicle &v)
{
    cout << "Buyer's budget:" << b.budget << endl;
    cout << "Vehcile's price" << v.getPrice() << endl;

    if (b.budget >= v.getPrice())
    {
        cout << "You can affort this vehicle" << endl;
    }
    else
    {
        cout << "You canot afford this vehicle" << endl;
    }
}

void compareSellers(Seller &s1, Seller &s2)
{
    cout << s1.name << " has rating: " << s1.rating << endl;
    cout << s2.name << " has rating: " << s2.rating << endl;

    if (s1.rating > s2.rating)
        cout << s1.name << " is the better seller." << endl;
    else if (s2.rating > s1.rating)
        cout << s2.name << " is the better seller." << endl;
    else
        cout << "Both sellers have equal rating." << endl;
}

int main()
{
    Car car1(1, "Toyota", "Corolla", 2020, 250000, 30000, 4, "sedan");
    Bike bike2(2, "Honda", "CD-70", 2022, 150000, 5000, "Not modified", true);
    Truck truck1(3, "toyata", "REVO Daala", 2020, 500000, 800000, 3.5, 4);

    vehicle *vPtr;
    vPtr = &car1;
    vPtr->displayDetails();
    cout << "\n";

    vPtr = &bike2;
    vPtr->displayDetails();
    cout << "\n";

    vPtr = &truck1;
    vPtr->displayDetails();
    cout << "\n";

    Buyer buyerB1("Talha Shahid", "talha.shahid@nu.edu.pk", 101, 3000000);
    Seller seller1("Qasim Keeryo", "QasimSahab@nu.edu.pk", 201, "Qasim Motors");
    Seller seller2("Taha Mahmood", "k250124@nu.edu,pk", 67, "4 GPA");
    Admin Admin1("HOD", "HODkaEmail@nu.edu.pk", 301, "HOD1");

    User *uPtr;
    uPtr = &buyerB1;
    uPtr->displayProfile();
    cout << "\n";

    uPtr = &seller1;
    uPtr->displayProfile();
    cout << "\n";

    uPtr = &Admin1;
    uPtr->displayProfile();
    cout << "\n";

    Car car2(4, "Suzuki", "Alto", 2021, 1800000, 15000, 4, "Hatchback");

    if (car1 == car2)
    {
        cout << "Both cars have same priec" << endl;
    }
    else
    {
        cout << "Cars have different price" << endl;
    }

    float totalPrice = car1 + car2;
    cout << "Combined price of both cars = " << totalPrice;

    Buyer buyer2("Ali", "Ali@gmail.com", 101, 200000);
    if (buyerB1 == buyer2)
    {
        cout << "Same buyer " << endl;
    }
    else
    {
        cout << "Different buyer" << endl;
    }

    Payment p1(1, 100000, "Cash");
    Payment p2(2, 100000, "Card");

    float comboPrice = p1 + p2;
    cout << " Combined price = " << comboPrice << endl;

    if (p1 == p2)
        cout << "Both payments have equal amount." << endl;
    else
        cout << "Payments are different." << endl;

    compareCarDetails(car1, car2);
    checkAffordability(buyerB1, car1);
    compareSellers(seller1, seller2);

    MarketPlace m;

    seller1.addListing();
    seller1.addListing();

    Listing l1(1, &car1, &seller1, "2026-05-01");
    Listing l2(2, &bike2, &seller1, "2026-05-05");

    m.addListing(l1);
    m.addListing(l2);

    Admin1.performAction("Approve Listing 1");
    m.approveListing(1);

    buyerB1.addFavourite("Toyota Corolla");
    buyerB1.addFavourite("Honda CD-70");

    Message m1(1, "Is your CD 70 availbale for sale? ", &buyerB1, &seller1, "18-05-2026");
    m.sendMessage(m1);

    m.searchByPrice(3000000);
    cout << "\n";

    m.showAll();

    User::showTotalUsers();
    cout << "\n";
    Admin::showTotalAdmins();
    cout << "\n";

    Payment payment(1, 2500000, "EasyPaisa");
    payment.completePayment();
    cout << "\n";
    payment.display();
}