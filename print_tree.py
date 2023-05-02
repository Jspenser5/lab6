# 1. Напишите программу, которая на координатной плоскости, стартуя с единичного квадрата,
# рисует Дерево Пифагора в зависимости от заданного числа шагов n и параметра α (например
# возьмите α = 45)◦
# 2.
# Сделайте возможность изменения параметра α.
# Таким образом, мы сумеем построить не только “классическое” дерево, но и “обдуваемое ветром”.
# 3.
# Подберите опытным путем такое значение n, что его увеличение не изменяет видимое изображение.
# Сделайте это для разных значений параметра α.
from turtle import *
from math import cos, radians, log

shape("turtle")
pensize(2)
setup(900, 900)
screensize(900, 900)
len_side = 100
count = 0
angle = 0
coeff = 0
speed(0)
tracer(10000, 0)
hideturtle()


# Изменение цвета карандаша в зависимости от длины стороны
def set_colour(len_):
    if len_ <= 20:
        pencolor('green')
    else:
        pencolor('brown')


# Масштабирования
def reshape():
    clear()
    size = screensize()
    global len_side
    global angle
    global count
    screensize(size[0] + 600, size[1] + 400)
    len_side += 50
    up()
    setx(-len_side)
    sety(-(size[1] + 400)//2 + 10)
    down()
    start(len_side, count, angle)
    update()


# Сохранить картинку изображения, как tree.eps файл
def save_image():
    getscreen().getcanvas().postscript(file='tree.eps')


# Функции для отрисовки
def gen(len_, count, angle):
    set_colour(len_)
    if count <= 0:
        forward(len_)
    else:
        right(90 + angle)
        forward(len_ * cos(radians(angle)))
        left(90)
        gen(len_ * cos(radians(angle)), count - 1, angle)
        set_colour(len_)
        left(90)
        forward(len_ * cos(radians(angle)))
        left(90)
        forward(len_ * cos(radians(angle)))
        right(180 - angle)

        forward(len_)

        right(90 + angle)
        forward(len_ * cos(radians(90 - angle)))
        left(90)
        forward(len_ * cos(radians(90 - angle)))
        left(90)
        gen(len_ * cos(radians(90 - angle)), count - 1, angle)
        set_colour(len_)
        left(90)
        forward(len_ * cos(radians(90 - angle)))
        right(180 - angle)


def start(len_, count, angle):
    pencolor('brown')
    forward(len_)
    left(90)
    forward(len_)
    left(90)
    gen(len_, count, angle)
    pencolor('brown')
    left(90)
    forward(len_)
    left(90)


def draw_tree():
    clear()
    size = screensize()
    global angle, count, coeff
    angle = numinput('pythagorean tree', 'Angle', 45, minval=10, maxval=80)
    optimal = log(4/len_side, max(cos(radians(angle)), cos(radians(90 - angle))))
    count = numinput("pythagorean tree", 'Count stages', int(optimal), minval=0, maxval=100)
    coeff = int((45 - angle)*1.5)
    screensize(size[0] + 5*abs(coeff), size[1] + 10*abs(coeff))
    up()
    setx(-(len_side // 2) - (coeff * len_side)//17)
    sety(-((size[1] + 10*abs(coeff))//2) + 20)
    down()
    start(len_side, count, angle)
    update()
    listen()

# main
draw_tree()
listen()
onkey(draw_tree, 'r')
onkey(reshape, '+')
onkey(save_image, 's')
mainloop()
