#include <iostream>
#include <string>
#include <vector>

class Product
{
private:
	std::string prodName;
	double price;
public:
	Product(std::string name, double price) : prodName{ name }, price{ price } {}
	std::string getPrName()
	{
		return prodName;
	}
	double getPrice()
	{
		return price;
	}
	bool operator==(const Product& other) const
	{
		return (prodName == other.prodName && price == other.price);
	}
	void setPrName(std::string name)
	{
		this->prodName = name;
	}
	void setPrice(double price)
	{
		this->price = price;
	}
};
///////////////
class Dish
{
private:
	std::string dishName;
	std::vector<Product> prod_list;
public:
	Dish(std::string name) : dishName{ name } {}
	std::string getDiName()
	{
		return dishName;
	}
	std::vector<Product>& getPrList()
	{
		return prod_list;
	}
	bool operator==(const Dish& other) const
	{
		return (dishName == other.dishName && prod_list == other.prod_list);
	}
	void addProd(const Product& prod)
	{
		prod_list.push_back(prod);
	}
	void deleteProd(const Product& prod)
	{
		prod_list.erase(remove(prod_list.begin(), prod_list.end(), prod), prod_list.end());
	}
	double total_dish()
	{
		double cost = 0.0;
		for (Product& prod : prod_list)
		{
			cost += prod.getPrice();
		}
		return cost;
	}
};
///////////////
class Beverage
{
private:
	std::string beverName;
	std::vector<Product> fruit_list;
public:
	Beverage(std::string name) : beverName{ name } {}
	std::string getBvName()
	{
		return beverName;
	}
	std::vector<Product>& getFrList()
	{
		return fruit_list;
	}
	bool operator==(const Beverage& other) const
	{
		return (beverName == other.beverName && fruit_list == other.fruit_list);
	}
	void addFruit(const Product& fruit)
	{
		fruit_list.push_back(fruit);
	}
	void deleteFruit(const Product& fruit)
	{
		fruit_list.erase(remove(fruit_list.begin(), fruit_list.end(), fruit), fruit_list.end());
	}
	double total_bever()
	{
		double cost = 0.0;
		for (Product& prod : fruit_list)
		{
			cost += prod.getPrice();
		}
		return cost;
	}
};
/////////////
class Order
{
private:
	int table;
	std::vector<Dish> dishes;
	std::vector<Beverage> beverages;
public:
	Order(int table) : table{ table } {}

	void addDish(Dish& dish)
	{
		dishes.push_back(dish);
	}
	void addBever(Beverage& bever)
	{
		beverages.push_back(bever);
	}
	void deleteDish(Dish& dish)
	{
		dishes.erase(remove(dishes.begin(), dishes.end(), dish), dishes.end());
	}
	void deleteBever(Beverage& bever)
	{
		beverages.erase(remove(beverages.begin(), beverages.end(), bever), beverages.end());
	}
	double total_order()
	{
		double cost = 0.0;
		for (Dish& dish : dishes)
		{
			cost += dish.total_dish();
		}
		for (Beverage& bever : beverages)
		{
			cost += bever.total_bever();
		}
		return cost;
	}
};


int main()
{
	Product cheese("Mozzarella", 4.0);
	Product meat1("Salami", 5.0);
	Product meat2("Chicken", 6.0);
	Product veget1("Tomato", 2.5);
	Product veget2("Olives", 1.0);
	Product veget3("Corn", 3.5);
	Product fruit1("Orange", 2.7);
	Product fruit2("Pinapple", 7.5);
	Product fruit3("Mango", 8.0);

	Dish pizza1("Salami Pizza");
	pizza1.addProd(cheese);
	pizza1.addProd(meat1);
	pizza1.addProd(veget1);
	pizza1.addProd(veget2);

	Dish pizza2("Hawaiian Pizza");
	pizza2.addProd(cheese);
	pizza2.addProd(meat2);
	pizza2.addProd(fruit2);
	pizza2.addProd(veget3);

	Beverage juice("Multivitamin");
	juice.addFruit(fruit1);
	juice.addFruit(fruit2);
	juice.addFruit(fruit3);

	Order order1(1);
	order1.addDish(pizza1);
	order1.addDish(pizza2);
	order1.deleteDish(pizza2);
	Order order2(2);
	order2.addDish(pizza2);
	order2.addBever(juice);

	std::cout << "Total of order 1: " << order1.total_order() << std::endl;
	std::cout << "Total of order 2: " << order2.total_order();
}

