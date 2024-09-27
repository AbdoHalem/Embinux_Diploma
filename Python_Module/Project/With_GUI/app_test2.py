import tkinter as tk
from tkinter import messagebox
import employee

# Define the functions for each action
def login():
    global employee_id
    ID = id_entry.get()
    Password = password_entry.get()
    
    found = employee.login(ID, Password)
    if found == 1:
        employee_id = ID
        login_frame.pack_forget()
        main_frame.pack()
    else:
        messagebox.showerror("Login Failed", "Invalid Employee ID or Password. Please try again.")

def display_info():
    if employee_id:
        info = employee.display(employee_id)
        result_text.set(info)

def calculate_bonus():
    if employee_id:
        bonus = employee.Calc_Bonus(employee_id)
        result_text.set(bonus)

def calculate_discount():
    if employee_id:
        discount = employee.Calc_Discount(employee_id)
        result_text.set(discount)

def remind_holidays():
    if employee_id:
        holidays = employee.Holidays(employee_id)
        result_text.set(holidays)

# Function to create the login frame
def create_login_frame():
    global id_entry, password_entry, login_frame
    login_frame = tk.Frame(root)

    tk.Label(login_frame, text="Employee ID").grid(row=0, column=0)
    id_entry = tk.Entry(login_frame)
    id_entry.grid(row=0, column=1)
    
    tk.Label(login_frame, text="Password").grid(row=1, column=0)
    password_entry = tk.Entry(login_frame, show="*")
    password_entry.grid(row=1, column=1)
    
    login_button = tk.Button(login_frame, text="Login", command=login)
    login_button.grid(row=2, column=0, columnspan=2)

    login_frame.pack()

# Function to create the main frame
def create_main_frame():
    global main_frame, result_text
    main_frame = tk.Frame(root)

    tk.Label(main_frame, text="Select an option:").pack()

    info_button = tk.Button(main_frame, text="Display Employee Information", command=display_info)
    info_button.pack()

    bonus_button = tk.Button(main_frame, text="Calculate Bonus", command=calculate_bonus)
    bonus_button.pack()

    discount_button = tk.Button(main_frame, text="Calculate Discount", command=calculate_discount)
    discount_button.pack()

    holidays_button = tk.Button(main_frame, text="Remind Legal Holidays", command=remind_holidays)
    holidays_button.pack()

    exit_button = tk.Button(main_frame, text="Exit", command=root.destroy)
    exit_button.pack()

    result_text = tk.StringVar()
    result_label = tk.Label(main_frame, textvariable=result_text, justify=tk.LEFT)
    result_label.pack()

# Main script to run the GUI application
if __name__ == "__main__":
    root = tk.Tk()
    root.title("Employee Management System")
    
    employee_id = None
    
    create_login_frame()
    create_main_frame()
    
    root.mainloop()
