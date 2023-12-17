#include<iostream>
#include<vector>
#include"ShoppingCart.h"
using namespace std;
vector<Product> allProducts={
    Product(1,"apple",102),
    Product(2,"mango",91),
    Product(3,"guava",48),
    Product(4,"chickoo",84),
    Product(5,"strawberry",69),
    Product(6,"banana",36),
    Product(7,"orange",50),
    Product(8,"pineapple",75)
};
Product* chooseProduct()
{
    //Displays Product first
    cout<<"Available products"<<endl<<endl; 
    for(auto product: allProducts) 
    {
        cout<<product.getDisplayName();
    }
    cout<<"------------------"<<endl;
    cout<<"Enter first letter of item to be added in the cart"<<endl;
    string choose;
    cin>>choose;
    //return address of the chosen product
    for(int i=0; i<allProducts.size(); i++) 
        {
        if(allProducts[i].getFirstLetter()==choose)
        {
            return &allProducts[i];
        }
    }
    cout<<"Product not available"<<endl<<endl;
    return NULL;
}
bool Checkout(Cart &cart) //pass by reference
{
    if(cart.isEmpty())
    {
        return false;
    }
    cout<<"Enter the amount to be paid in cash: Rs ";
    int amount;
    cin>>amount;
    if(amount>=cart.getTotal())
    {
        cout<<"Your Change: Rs "<<amount-cart.getTotal()<<endl;
        cout<<"Thank You for shopping with us!"<<endl;
        return true;
    }
    else
    {
        cout<<"Not enough cash!"<<endl;
        return false;
    }
}
int main()
{
    char action;
    Cart cart;
    while(true)
    {
        cout<<"Select an action"<<endl;
        cout<<"1. (a)dd item to cart"<<endl;
        cout<<"2. (v)iew cart"<<endl;
        cout<<"1. (c)heckout"<<endl;
        cin>>action;
        if (action=='a')
        {
            //view all products+ choose product+ add to cart
            Product* p=chooseProduct();
            if(p!=NULL)
            {
                cout<<"Added to cart =>"<<p->getDisplayName();
                cart.addProduct(*p);
            }

        }
        else if(action=='v')
        {
            cout<<"------------------"<<endl;
            cart.viewCart();
            cout<<"------------------"<<endl;
        }
        else if(action=='c')
        {
            cout<<"------------------"<<endl;
            cart.viewCart();
            cout<<"------------------"<<endl;
            if(Checkout(cart))
            {
                break;
            }
            else
            {
                cout<<"Checkout unsuccessful, Try again"<<endl;
            }
        }
        else
        {
            cout<<"Invalid input, Choose again"<<endl;
        }
    }
}