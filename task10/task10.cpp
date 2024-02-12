#include <iostream>
#include <cstring>
using namespace std;
class Airplane {
private:
    int _id;
    char* _model;
    char* _color;
    double _engine;
    int _capacity;

public:
    static int staticId;
    static int MAXCOUNT;

    Airplane() : _id(0), _model(nullptr), _color(nullptr), _engine(0.0), _capacity(0) {}

    Airplane(int id, const char* model, const char* color, double engine, int capacity)
        : _id(id), _engine(engine), _capacity(capacity)
    {
        _model = new char[strlen(model) + 1];
        strcpy(_model, model);

        _color = new char[strlen(color) + 1];
        strcpy(_color, color);
    }

    ~Airplane() {
        delete[] _model;
        delete[] _color;
    }


    int getId() const { return _id; }

    const char* getModel() const { return _model; }

    const char* getColor() const { return _color; }

    double getEngine() const { return _engine; }

    int getCapacity() const { return _capacity; }

    void setId(int id) { _id = id; }

    void setModel(const char* model) {
        delete[] _model;
        _model = new char[strlen(model) + 1];
        strcpy(_model, model);
    }
    void setColor(const char* color) {
        delete[] _color;
        _color = new char[strlen(color) + 1];
        strcpy(_color, color);
    }
    void setEngine(double engine) { _engine = engine; }
    void setCapacity(int capacity) { _capacity = capacity; }

    void print() {
        cout << "ID: " << _id << ", Model: " << _model << ", Color: " << _color << ", Engine: " << _engine << ", Capacity: " << _capacity << endl;
    }
};

int Airplane::staticId = 0;
int Airplane::MAXCOUNT = 100;

class Garage {
private:
    Airplane** airplanes;
    size_t _count;
    char* _name;
    char* _address;

public:
    Garage() : airplanes(nullptr), _count(0), _name(nullptr), _address(nullptr) {}
    Garage(const char* name, const char* address) : _count(0) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);

        _address = new char[strlen(address) + 1];
        strcpy(_address, address);

        airplanes = new Airplane * [Airplane::MAXCOUNT];
    }

    ~Garage() {
        delete[] _name;
        delete[] _address;

        for (size_t i = 0; i < _count; ++i) {
            delete airplanes[i];
        }
        delete[] airplanes;
    }

    Airplane* getAirplaneById(int id) {
        for (size_t i = 0; i < _count; ++i) {
            if (airplanes[i]->getId() == id) {
                return airplanes[i];
            }
        }
        return nullptr;
    }

    Airplane** getAirplanesCapacityGreaterThan(int capacity) {
        size_t resultCount = 0;
        Airplane** result = new Airplane * [Airplane::MAXCOUNT];

        for (size_t i = 0; i < _count; ++i) {
            if (airplanes[i]->getCapacity() > capacity) {
                result[resultCount++] = airplanes[i];
            }
        }

        result[resultCount] = nullptr;
        return result;
    }


    Airplane** getAirplanesByColor(const char* color) {
        size_t resultCount = 0;
        Airplane** result = new Airplane * [Airplane::MAXCOUNT];

        for (size_t i = 0; i < _count; ++i) {
            if (strcmp(airplanes[i]->getColor(), color) == 0) {
                result[resultCount++] = airplanes[i];
            }
        }

        result[resultCount] = nullptr;
        return result;
    }


    void print() {
        cout << "Garage Name: " << _name << ", Address: " << _address << endl;
        for (size_t i = 0; i < _count; ++i) {
            airplanes[i]->print();
        }
    }
};