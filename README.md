"Реализовать класс кофеварки, соответствующий следующим интерфейсам:
class ICoffeeMachine {
public:
 virtual ~ICoffeуMachine() {}
 virtual bool MakeAmericano(Glasses) = 0;
 virtual bool MakeLatte(Glasses) = 0;
};

class ICoffeeMachineRecipe {
public:
 virtual ~ICoffeeMachineRecipe() {}
 virtual bool SetAmericanoRecipe(uint32 water, uint32 sugar, uint32 milk) = 0;
 virtual bool SetLatteRecipe(uint32 water, uint32 sugar, uint32 milk) = 0;
};
Также у кофеварки должны быть методы добавления сахара, молока и воды, которые в нее загружаются. 
В случае каких либо ошибок функции возвращают false иначе true"