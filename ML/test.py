from tkinter import *

window_size = 300
window = Tk()
window.geometry(f'{window_size}x{window_size}')
canvas = Canvas(window, width=window_size, height=window_size, bg="green")
canvas.pack()
canvas.create_text(window_size/2, window_size/2, text="Hello,\nWorld", 
									font=('Helvetica 60 bold'), justify="center")
window.mainloop()