import pyautogui as py
from time import sleep

n = int(input())
sleep(5)

for i in range(1, n+1):
    py.write("#"*i)
    py.write("\n")

