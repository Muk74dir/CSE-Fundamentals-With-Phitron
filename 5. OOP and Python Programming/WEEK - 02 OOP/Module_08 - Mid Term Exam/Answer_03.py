from math import factorial
class Calculator:
    def __init__(self, a, b, c) -> None:
        self.a = a
        self.b = b
        self.c = c
    
    def sum(self):
        return self.a + self.b + self.c
    
    def factorial(self):
        return factorial(self.b)
    
test = Calculator(2, 5, 3)
print(test.sum())
print(test.factorial()) 
