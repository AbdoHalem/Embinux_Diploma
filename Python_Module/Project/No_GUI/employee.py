employees = [{"ID": "123", "Name": "Abdelrahman", "Department": "Software",
              "Salary": 10000, "Password": "1234", "Absence": 2},
              {"ID": "456", "Name": "Mohamed", "Department": "Software",
              "Salary": 10000, "Password": "5678", "Absence": 5}]

# APIs for Employees
def login(ID, Password):
    found = 0
    for i in employees:
        if(i["ID"] == ID):
            if(i["Password"] == Password):
                print("Login Successful!\n")
                found = 1; break
            else:
                print("Wrong Password!")
                break
        else:
            continue
    if(found == 0 and i["ID"] != ID):
        print("Invalid ID!")

    return found
            
def display(ID):
    for i in employees:
        if i["ID"] == ID:
            print("Employee Information:")
            print("Name:",i["Name"])
            print("Department:",i["Department"])
            print("Salary:",i["Salary"])
            print("Days of Absence:",i["Absence"])

def Calc_Bonus(ID):
    for i in employees:
        if(i["ID"] == ID):
            print("\nBonus Calculation: \nBonus: ", int(i["Salary"] * 0.1), "$",sep="")
            break

def Calc_Discount(ID):
    for i in employees:
        if(i["ID"] == ID):
            # Discount = (Absence_Days / 40) * Salary (as in the example)
            print("\nDiscount Calculation: \nDiscount: ", int(i["Salary"] * (i["Absence"] / 40)), "$",sep="")
            break

def Holidays(ID):
    legal_days = 12 # As in the example
    for i in employees:
        if(i["ID"] == ID):
            print("\nReminder: \nRemaining Legal Holidays:", legal_days - i["Absence"])
            break