#include <iostream>

using namespace std;

class Medicine {
private:
    string name, formula;
    int manufacture_date, expiration_date;
    float price;
public:
    Medicine(string name, string formula, int m_date, int e_date, float price)
    : name(name), formula(formula), manufacture_date(m_date), expiration_date(e_date), price(price) {}
    
    string getName() const;
    string getFormula() const;
    int getManufactureDate() const;
    int getExpirationDate() const;
    float getPrice() const;

    void setName(string name);
    void setFormula(string formula);
    void setManufactureDate(int m_date);
    void setExpirationDate(int e_date);
    void setPrice(float price);

    bool operator == (const Medicine& obj) { return obj.expiration_date == expiration_date; }

    virtual void print();
};

class Tablet : public Medicine {
private:
    float sucrose_level;
public:
    Tablet(string name, string formula, int m_date, int e_date, float price, float s_level)
    : Medicine(name, formula, m_date, e_date, price), sucrose_level(s_level) {}

    float getSucroseLevel() const;
    void setSucroseLevel(float s_level);

    void print() override;
};

class Capsule : public Medicine {
private:
    float absorption_percentage;
public:
    Capsule(string name, string formula, int m_date, int e_date, float price, float absorption)
    : Medicine(name, formula, m_date, e_date, price), absorption_percentage(absorption) {}
    
    float getAbsorptionPercentage() const;
    void setAbsorptionPercentage(float absorption);

    void print() override;
};

class Syrup : public Medicine {
    float concentration;
private:
public:
    Syrup(string name, string formula, int m_date, int e_date, float price, float conc)
    : Medicine(name, formula, m_date, e_date, price), concentration(conc) {}
    
    float getConcentration() const;
    void setConcentration(float conc);

    void print() override;
};

// global medicine array maintained for the store
int medicine_count = 3;
Medicine *medicine_list[] = {
    new Capsule("Medicine 1", "Formula 1", 1, 20, 10, 10),
    new Tablet("Medicine 2", "Formula 2", 2, 30, 20, 5),
    new Syrup("Medicine 3", "Formula 3", 3, 40, 30, 30)
};

class Pharmacist {
public:
    // searches medicine by formula
    void search_medicine(Medicine *medicine);
};

class Counter {
private:
    static float revenue;
public:
    // searches medicine by name
    void search_medicine(Medicine *medicine);

    void update_revenue(float amount);
};