// Shopping cart header file
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

//Forward Declaration
class item;
class Cart;

class Product
{
    string name;
    int id;
    int price;

  public:
    Product(){}
    Product(int u_id, string name, int price) // u_id means unique id
    {
        id = u_id;
        this->price = price;
        this->name = name;
    }
    string getDisplayName()
    {
        return name + ": Rs " + to_string(price)+"\n";
    }
    string getFirstLetter()
    {
        return name.substr(0,1);
    }
    friend class Item; //Item is a friend of Product now. So product can share its details with item.
    friend class Cart;
};
class Item
{
    Product product;
    int quantity;

  public:
    Item(){} 
    Item(Product p, int q) : product(p), quantity(q) {}    
    int getItemPrice()
    {
        return quantity*product.price;
    }
    string getItemInfo()
    {
        return to_string(quantity)+" X "+product.name+" => Rs."+to_string(getItemPrice())+"\n";
    }
    friend class Cart;
};
class Cart
{
    unordered_map <int, Item> items;
    public:
    void addProduct(Product product)
    {
        if(items.count(product.id)==0)
        {
            Item newItem(product,1);
            items[product.id]=newItem;
        }
        else
        {
            items[product.id].quantity+=1; 
        }
    }
    int getTotal()
    {
        int total=0;
        for( auto itemPair:items)
        {
            auto item=itemPair.second;
            total+=item.getItemPrice();
        }
        return total;
    }
    void viewCart()
    {
        if(items.empty()) 
        {
            cout<<"Cart is empty";
        }
        for(auto itemPair:items) 
                {
            auto item=itemPair.second;
            cout<<item.getItemInfo();
        }
        cout<<endl<<"Total Amount: Rs "<<getTotal()<<endl;
    }
    bool isEmpty()
    {
        return items.empty();
    }

};