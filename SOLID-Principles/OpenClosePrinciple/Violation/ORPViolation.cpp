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

class ShoppingCartDB {
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartDB(ShoppingCart* cart) {
            this->cart = cart;
        }
        // Break ORP by adding multiple methods for saving to different databases
        void saveToSQLDB() {
            cout << "Saving cart to SQL database..." << endl;
        }

        void saveToMongoDB() {
            cout << "Saving cart to MongoDB database..." << endl;
        }

        void saveToFile() {
            cout << "Saving cart to file..." << endl;
        }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product(10.0, "Product 1"));
    cart->addProduct(new Product(20.0, "Product 2"));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartDB* db = new ShoppingCartDB(cart);
    db->saveToSQLDB();
    db->saveToMongoDB();
    db->saveToFile();

    delete cart;
    delete printer;
    delete db;

    return 0;
}