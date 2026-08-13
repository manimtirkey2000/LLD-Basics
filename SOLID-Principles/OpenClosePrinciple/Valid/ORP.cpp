#include <bits/stdc++.h>
using namespace std;

class Product {
    public:
        double price;
        string name;

        Product(double price, string name) {
            this->price = price;
            this->name = name;
        }

    // getters
    double getPrice() {
        return price;
    }
    string getName() {
        return name;
    }

    // setters
    void setPrice(double price) {
        this->price = price;
    }
    void setName(string name) {
        this->name = name;
    }
};

class ShoppingCart{
    public:
        vector<Product*> products;

        void addProduct(Product* product) {
            products.push_back(product);
        }

        // 2. Get a list of all products in the cart
        vector<Product*> getProducts() {
            return products;
        }

        // 1. Calculate total price of products in the cart
        double calculateTotal() {
            double total = 0;
            for (auto product : products) {
                total += product->getPrice();
            }
            return total;
        }
};

class ShoppingCartPrinter {
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartPrinter(ShoppingCart* cart) {
            this->cart = cart;
        }

        void printInvoice() {
            cout << "Invoice:" << endl;
            for (auto product : cart->getProducts()) {
                cout << product -> getName() << " - $" << product -> getPrice() << endl;
            }
            cout << "Total: $" << cart->calculateTotal() << endl;
        }
};

// Method overriding is used to implement the Open/Closed Principle (OCP) in this code. The persistence class is an abstract class that defines a save method, which is overridden by its subclasses (SQLPersistence, MongoDBPersistence, and FilePersistence) to provide different implementations for saving the shopping cart data. This allows the code to be open for extension (by adding new persistence methods) but closed for modification (the existing code does not need to be changed).
class persistence {
    private:
        ShoppingCart* cart;
    public:
        persistence(ShoppingCart* cart) {
            this->cart = cart;
        }

        virtual void save(ShoppingCart* cart) = 0;
}; 

class SQLPersistence : public persistence {
    public:
        SQLPersistence(ShoppingCart* cart) : persistence(cart) {}

        void save(ShoppingCart* cart) override {
            cout << "Saving cart to SQL database..." << endl;
        }
};

class MongoDBPersistence : public persistence {
    public:
        MongoDBPersistence(ShoppingCart* cart) : persistence(cart) {}

        void save(ShoppingCart* cart) override {
            cout << "Saving cart to MongoDB database..." << endl;
        }
};

class FilePersistence : public persistence {
    public:
        FilePersistence(ShoppingCart* cart) : persistence(cart) {}

        void save(ShoppingCart* cart) override {
            cout << "Saving cart to file..." << endl;
        }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product(10.0, "Product 1"));
    cart->addProduct(new Product(20.0, "Product 2"));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    persistence* sqlPersistence = new SQLPersistence(cart);
    sqlPersistence->save(cart);

    persistence* mongoPersistence = new MongoDBPersistence(cart);
    mongoPersistence->save(cart);

    persistence* filePersistence = new FilePersistence(cart);
    filePersistence->save(cart);

    delete cart;
    delete printer;
    delete sqlPersistence;
    delete mongoPersistence;
    delete filePersistence;

    return 0;
}
