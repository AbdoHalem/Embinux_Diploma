employees = [{"ID": "123", "Name": "Abdelrahman", "Department": "Software",
              "Salary": 10000, "Password": "1234", "Absence": 2},
              {"ID": "456", "Name": "Mohamed", "Department": "Software",
              "Salary": 10000, "Password": "5678", "Absence": 5}]

def login(ID, Password):
    found = 0
    for i in employees:
        if i["ID"] == ID:
            if i["Password"] == Password:
                found = 1
                break
            else:
                return 0
    return found

def display(ID):
    for i in employees:
        if i["ID"] == ID:
            info = (
                f"Employee Information:\n"
                f"Name: {i['Name']}\n"
                f"Department: {i['Department']}\n"
                f"Salary: {i['Salary']}\n"
                f"Days of Absence: {i['Absence']}"
            )
            return info

def Calc_Bonus(ID):
    for i in employees:
        if i["ID"] == ID:
            bonus = f"Bonus Calculation: \nBonus: {int(i['Salary'] * 0.1)}$"
            return bonus

def Calc_Discount(ID):
    for i in employees:
        if i["ID"] == ID:
            discount = f"Discount Calculation: \nDiscount: {int(i['Salary'] * (i['Absence'] / 40))}$"
            return discount

def Holidays(ID):
    legal_days = 12
    for i in employees:
        if i["ID"] == ID:
            holidays = f"Reminder: \nRemaining Legal Holidays: {legal_days - i['Absence']}"
            return holidays
