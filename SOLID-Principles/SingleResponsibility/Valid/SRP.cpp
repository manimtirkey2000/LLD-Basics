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


// ShoppingCart class now only has one responsibility: managing products in the cart
class ShoppingCart {
    public:
        vector<Product*> products;

        void addProduct(Product* product) {
            products.push_back(product);
        }

        double calculateTotal() {
            double total = 0;
            for (Product* product : products) {
                total += product->getPrice();
            }
            return total;
        }
};

// Separate class for printing invoice
class ShoppingCartPrinter {
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartPrinter(ShoppingCart* cart) {
            this->cart = cart;
        }

        void printInvoice() {
            cout << "Invoice:" << endl;
            for (Product* product : cart->products) {
                cout << product->getName() << " - $" << product->getPrice() << endl;
            }
            cout << "Total: $" << cart->calculateTotal() << endl;
        }
};

// Separate class for saving cart to database
class ShoppingCartSaver {
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartSaver(ShoppingCart* cart) {
            this->cart = cart;
        }
        void saveToDB() {
            cout << "Saving cart to database..." << endl;
        }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product(10.0, "Product 1"));
    cart->addProduct(new Product(20.0, "Product 2"));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartSaver* saver = new ShoppingCartSaver(cart);
    saver->saveToDB();

    delete cart;
    delete printer;
    delete saver;

    return 0;
}