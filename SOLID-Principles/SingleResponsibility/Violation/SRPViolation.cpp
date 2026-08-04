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

// ShoppingCart class violates the Single Responsibility Principle (SRP) because it has multiple responsibilities: managing products, calculating total price, and printing invoice. Each of these responsibilities should be in separate classes.
class ShoppingCart{
    public:
        vector<Product*> products;

        void addProduct(Product* product) {
            products.push_back(product);
        }
        
        // 1. Calculate total price of products in the cart
        double calculateTotal() {
            double total = 0;
            for (auto product : products) {
                total += product->getPrice();
            }
            return total;
        }

        // 2. Print invoice for the products in the cart (should be in a separate class)
        void printInvoice() {
            cout << "Invoice:" << endl;
            for (auto product : products) {
                cout << product -> getName() << " - $" << product -> getPrice() << endl;
            }
            cout << "Total: $" << calculateTotal() << endl;
        }

        // 3. Save the cart to the database (should be in a separate class)
        void saveToDB() {
            cout << "Saving cart to database..." << endl;
        }
};

int main() {
    ShoppingCart cart;
    cart.addProduct(new Product(10.0, "Product 1"));
    cart.addProduct(new Product(20.0, "Product 2"));
    cart.addProduct(new Product(30.0, "Product 3"));

    cart.printInvoice();
    cart.saveToDB();
    return 0;
}

