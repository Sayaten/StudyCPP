#ifndef __FP_NY_PIZZA_INGREDIENT_FACTORY_HPP__
#define __FP_NY_PIZZA_INGREDIENT_FACTORY_HPP__

class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
	public:
		virtual Dough* createDough() override
		{
			return new ThinCrustDough();
		}
		virtual Sauce* createSauce() override
		{
			return new MarinaraSauce();
		}
		virtual Cheese* createCheese() override
		{
			return new ReggianoCheese();
		}
		virtual Veggies** createVeggies()
		{
			Veggies **veggies = new Veggies[]{ new Garlic(), new Onion(), new Mushroom(), new RedPepper() };
			return Veggies;
		}
		virtual Pepperoni* createPepperoni()
		{
			return new slicedPepperoni();
		}
		virtual Clams* createClam()
		{
			return new FreshClams();
		}
};

#endif
