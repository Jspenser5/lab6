import tkinter as tk
from random import randint
root = tk.Tk()
root.title('Midpoint Displacement')
root.geometry('1129x512')
root.resizable(False, False)
photo = tk.PhotoImage(file='logo.png')
root.iconphoto(False, photo)

y1_index = 0
y2_index = 511
points = [0]*512
set_points = [0, 511]
shifter = False
def foo():
    print("hellow world")


def gen_points(arr: list, left: int, right: int, r: float):
    mid = (right + left) // 2
    if right - left <= 1:
        return
    arr[mid] = (arr[left] + arr[right]) / 2 + r * ((right - left)/5) * randint(-1, 1)
    gen_points(arr, left, mid, r)
    gen_points(arr, mid, right, r)


def get_midpoint_list(left: int, right: int,):
    global points, set_points
    set_points.sort()
    points[0] = left
    points[len(points) - 1] = right
    for i in range(len(set_points) - 1):
        gen_points(points, set_points[i], set_points[i+1], float(R_input.get()))
    set_points = [0, 511]


def reshape():
    global shifter
    shifter = True
    graph.delete('all')
    y1 = int(y1_input.get())
    y2 = int(y2_input.get())
    get_midpoint_list(y1, y2)
    if min(points) < 0:
        m = min(points)
        for i in range(0, len(points)):
            points[i] -= m
    for i in range(y1_index, y2_index):
        graph.create_polygon(2*(i - y1_index), 512-points[i], 2*(i + 1 - y1_index), 512 - points[i+1],
                             2*(i + 1 - y1_index), 512, 2*(i - y1_index), 512)


def shift_right():
    global points, y1_index, y2_index, shifter
    if not shifter:
        return
    graph.delete('all')
    y1_index += 128
    y2_index += 128
    if y2_index > len(points):
        points = points + [0]*128
        points[y2_index] = randint(0, 400)
        y2_input.delete(0, 'end')
        y2_input.insert(0, points[y2_index])
        gen_points(points, y2_index - 128, y2_index, float(R_input.get()))

    if min(points) < 0:
        m = min(points)
        for i in range(0, len(points)):
            points[i] -= m
    for i in range(y1_index, y2_index):
        graph.create_polygon(2*(i - y1_index), 512-points[i], 2*(i + 1 - y1_index), 512 - points[i+1],
                             2*(i + 1 - y1_index), 512, 2*(i - y1_index), 512)

    if(y2_index < len(points) - 1):
        right_shift_bt.config(background='white')
    else:
        right_shift_bt.config(background='red')
    left_shift_bt.config(background='white')


def shift_left():
    global points, y1_index, y2_index
    if not shifter:
        return
    graph.delete('all')
    if y1_index == 0:
        points = [0] * 128 + points
        points[0] = randint(0, 400)
        y1_input.delete(0, 'end')
        y1_input.insert(0, points[0])
        gen_points(points, 0, 128, float(R_input.get()))
    else:
        y1_index -= 128
        y2_index -= 128

    if min(points) < 0:
        m = min(points)
        for i in range(0, len(points)):
            points[i] -= m
    for i in range(y1_index, y2_index):
        graph.create_polygon(2 * (i - y1_index), 512 - points[i], 2 * (i + 1 - y1_index), 512 - points[i + 1],
                             2 * (i + 1 - y1_index), 512, 2 * (i - y1_index), 512)

    if (y1_index > 0):
        left_shift_bt.config(background='white')
    else:
        left_shift_bt.config(background='red')
    right_shift_bt.config(background='white')


def add_point(event):
    global points, set_points
    x1 = event.x
    y1 = event.y
    set_points.append(x1//2)
    points[x1//2] = 512 - y1
    graph.create_line(x1, 512, x1, y1, fill='red')


def clear_graph():
    global set_points, points, shifter, y1_index, y2_index
    shifter = False
    graph.delete('all')
    set_points = [0, 511]
    points.clear()
    points = [0]*512
    y1_input.delete(0, 'end')
    y2_input.delete(0, 'end')
    y1_index = 0
    y2_index = 511


y1_lbl = tk.Label(root, text='y1:', font=('Arial', 15))
y1_input = tk.Entry(root, font=('Arial', 15))
y1_lbl.place(x=1025, y=0)
y1_input.place(x=1060, y=0, width=60)

y2_lbl = tk.Label(root, text='y2:', font=('Arial', 15))
y2_input = tk.Entry(root, font=('Arial', 15))
y2_lbl.place(x=1025, y=30)
y2_input.place(x=1060, y=30, width=60)

R_lbl = tk.Label(root, text='R:', font=('Arial', 15))
R_input = tk.Entry(root, font=('Arial', 15))
R_input.insert(0, '1.4')
R_lbl.place(x=1025, y=60)
R_input.place(x=1060, y=60, width=60)

reshape_bt = tk.Button(root, command=reshape, text='Обновить', font=('Arial', 15))
right_shift_bt = tk.Button(root, command=shift_right, text='-->', font=('Berlin Sans FB', 15), background='red')
left_shift_bt = tk.Button(root, command=shift_left, text='<--', font=('Berlin Sans FB', 15), background='red')
reshape_bt.place(x=1025, y=90)
right_shift_bt.place(x=1077, y=130, width=52)
left_shift_bt.place(x=1025, y=130, width=52)

clear_bt = tk.Button(root, command=clear_graph, text='Очистить', font=('Arial', 15))
clear_bt.place(x=1025, y=170)

graph = tk.Canvas(root, width=1024, height=512, background='grey')
graph.bind('<Button-1>', add_point)
graph.place(x=0, y=0)


root.mainloop()
