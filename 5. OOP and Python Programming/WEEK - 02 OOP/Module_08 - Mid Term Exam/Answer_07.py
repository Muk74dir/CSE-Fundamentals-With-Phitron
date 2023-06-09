class Person:
    def __init__(self, name, age, height, weight) -> None:
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight


class Cricketer(Person):
    def __init__(self, name, age, height, weight) -> None:
        super().__init__(name, age, height, weight)

    def __lt__(self, other):
        if self.age < other.age:
            return True
        else:
            return False

Sakib = Cricketer('Sakib', 38, 68, 91)
Mushfiq = Cricketer('Mushfiq', 36, 55, 82)
Mustafiz = Cricketer('Mustafiz', 27, 69, 86)
Riyad = Cricketer('Riyad', 39, 72, 92)

players = [Sakib, Mushfiq, Mustafiz, Riyad]


min = 99999
for i in range(len(players)):
    for j in range(len(players)):
        if players[j].age < players[i].age and (players[j].age < min):
            min = players[j].age
            player = players[j]
    

print(f'The youngest player is : {player.name}. His age is : {min} years')