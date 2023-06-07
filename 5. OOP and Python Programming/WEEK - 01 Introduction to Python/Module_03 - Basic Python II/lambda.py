def double(x):
    return x*2

result = double(44)
print(result)

double = lambda x : x*2
squared = lambda y : y**2

result = double(200)
output = squared(4)

print(result, output)

add = lambda a, b, c : a+b+c
print(add(1, 2, 3))

nums = [1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10]

doubled = map(double, nums)
print(list(doubled))

print(list(map(lambda x: x+3, nums)))

actors = [
    { "name": "Sakib", "age": 45 },
    {"name": "Salman", "age": 50},
    {"name": "Shahrukh", "age": 55}
]
juniors = filter(lambda x : x["age"] < 50, actors)
print(actors)
print(list(juniors))

