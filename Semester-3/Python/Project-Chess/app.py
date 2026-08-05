import tkinter as tk
from PIL import Image, ImageTk
import os, pygame

pygame.mixer.init()

script_dir = os.path.dirname(os.path.abspath(__file__))
image_path = os.path.join(script_dir, "..", "Images", "r-1.png")
sound_path = os.path.join(script_dir, "..", "Images", "the-rook.mp3")

root = tk.Tk()
root.title("Counter")
root.geometry("800x400")

image = Image.open(image_path)
print("Original:", image.size)

image = image.resize((32, 32), Image.Resampling.LANCZOS)
print("Resized:", image.size)

img = ImageTk.PhotoImage(image)
count = 0

def plus():
    global count
    count += 1
    print(f"Count went up! ({count})")
    label.config(text=f"Hello World! Current count is {count}")

def minus():
    global count
    count -= 1
    print(f"Count went down! ({count})")
    label.config(text=f"Hello World! Current count is {count}")

def reset():
    global count
    count = 0
    print(f"Count has been reset! ({count})")
    label.config(text=f"Hello World! Current count is {count}")

def darook():
    global count
    print(f"DA ROOK")
    label.config(text=f"DA ROOK")
    pygame.mixer.music.load(sound_path)
    pygame.mixer.music.play()

label = tk.Label(
    root,
    text=f"Hello World! Current count is {count}",
    font=("Arial", 20)
)

label.pack(pady=(100, 20))

button_frame = tk.Frame(root)
button_frame.pack()

button1 = tk.Button(
    button_frame,
    text="Count +1!",
    command=plus,
    font=("Arial", 16)
)

button2 = tk.Button(
    button_frame,
    text="Count -1!",
    command=minus,
    font=("Arial", 16)
)

button3 = tk.Button(
    button_frame,
    text="Reset",
    command=reset,
    font=("Arial", 16)
)

daROOK = tk.Button(
    button_frame,
    image=img,
    command=darook
)

daROOK.image = img

button1.pack(side="left", padx=10)
button2.pack(side="left", padx=10)
button3.pack(side="left", padx=10)
daROOK.pack(side="left", padx=10)

root.mainloop()