from tkinter import *
from tkinter import filedialog
import matplotlib
matplotlib.use("TkAgg")
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
import numpy as np
import xlrd
import math
import operator

class suaib:
    def __init__(self, window):
        window.geometry('550x850+300+300')
        self.button_1 = Button(window, text="Browse", command=self.browse, width=15, font="none 8 bold")
        self.button_1.grid(row=2, column=1, sticky=W)
        self.button_2 = Button(window, text="Run", command=self.run, width=15, font="none 8 bold")
        self.button_2.grid(row=6, column=1, sticky=W)

        self.finput = StringVar()
        self.field = Entry(window, textvariable=self.finput, font="none 10 bold")
        self.field.grid(row=4, column=3, sticky=W)

        self.view = StringVar()
        self.field_2 = Label(window, textvariable=self.view, height=1, width=15, fg="yellow", font="Helvetica 12 bold", bg="gray", bd=5)
        self.field_2.grid(row=8, column=3, sticky=W)

        self.view_path = StringVar()
        self.field_3 = Label(window, textvariable=self.view_path, height=1, width=20, fg="yellow", font="none 9 bold",
                             bg="gray", bd=2)
        self.field_3.grid(row=1, column=3, sticky=W)

        self.blank_0 = Label(window, text="   ")
        self.blank_0.grid(row=0, column=0)
        self.blank_1 = Label(window, text="   ")
        self.blank_1.grid(row=3, column=0)
        self.blank_2 = Label(window, text="   ")
        self.blank_2.grid(row=5, column=0)
        self.blank_3 = Label(window, text="   ")
        self.blank_3.grid(row=7, column=0)
        self.blank_4 = Label(window, text="   ")
        self.blank_4.grid(column=5)
        self.blank_5 = Label(window, text="   ")
        self.blank_5.grid(column=2)

        self.lebel_0 = Label(window, text="Input Signal", font="none 10 bold")
        self.lebel_0.grid(row=1, column=1, sticky=W)
        self.lebel_1 = Label(window, text="Sampling Freq.", font="none 10 bold")
        self.lebel_1.grid(row=4, column=1, sticky=W)
        self.lebel_2 = Label(window, text="Hz", font="none 10 bold")
        self.lebel_2.grid(row=4, column=4, sticky=W)
        self.lebel_3 = Label(window, text="Base Frequency", font="none 10 bold")
        self.lebel_3.grid(row=8, column=1, sticky=W)
        self.lebel_4 = Label(window, text="Hz", font="none 10 bold")
        self.lebel_4.grid(row=8, column=4, sticky=W)
        self.lebel_5 = Label(window, text="Figure", font="none 10 bold")
        self.lebel_5.grid(row=10, column=1, sticky=W)

    def browse(self):
        filename = filedialog.askopenfilename(filetypes = (("Excel", "*.xlsx"), ("All File", "*.*")))
        self.view_path.set(filename)
        workbook = xlrd.open_workbook(filename)
        sheet = workbook.sheet_by_name("Sheet1")
        self.num_column = sheet.ncols
        self.y_axis = []
        for r in range(0, self.num_column):
            self.y_axis.append(sheet.cell_value(0, r))

    def run(self):
        self.fs = int(self.finput.get())
        ts = 1/self.fs
        x_axis = np.linspace(0, self.num_column * ts, self.num_column)
        fourier = np.fft.fft(self.y_axis)
        fourier[0] = 0
        ffft = fourier[:math.floor(len(fourier) / 2)]
        magnitudes = abs(ffft)
        self.f_axis = np.arange(0, self.fs/2, (self.fs / len(self.y_axis)))
        self.index, value = max(enumerate(magnitudes), key=operator.itemgetter(1))
        self.out = self.f_axis[self.index]
        self.view.set(str(self.out))
        fig1 = plt.figure(figsize=(8, 3), dpi=70)
        ax1 = fig1.add_subplot(111)
        ax1.plot(x_axis, self.y_axis)
        plt.title("Time Domain")
        canvas1 = FigureCanvasTkAgg(fig1, root)
        canvas1.get_tk_widget().grid(row=11, column=1, columnspan=7, sticky=W)

        fig2 = plt.figure(figsize=(8, 3), dpi=70)
        ax2 = fig2.add_subplot(111)
        ax2.plot(self.f_axis, magnitudes)
        plt.title("Frequency Domain")
        canvas2 = FigureCanvasTkAgg(fig2, root)
        canvas2.get_tk_widget().grid(row=12, column=1, columnspan=7, sticky=W)
        canvas1.draw()
        canvas2.draw()
        print(len(self.f_axis))
        print(len(magnitudes))

root = Tk()
root.title("Frequency Estimation")
c = suaib(root)
root.mainloop()

