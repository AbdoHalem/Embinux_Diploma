import employee
# import getpass

# Welcome Section
print("Welcome to the Employee Management System")
print("Please login to continue.")

# Login Section
ID = 0; Password = 0
for i in range(3):
    ID = input("Enter your Employee ID: ")
    Password = input("Enter your Password: ")

    found = employee.login(ID, Password)
    if(found == 1):
        break
    elif(found == 0 and i == 2):
        print("Try again later.")
    else:
        continue

# Select your purpose
choice = 0
while(choice != 5):
    print("Select an option:\n1- Display Employee Information")
    print("2- Calculate Bonus\n3- Calculate Discount")
    print("4- Remind Legal Holidays\n5- Exit")
    choice = int(input("Enter your choice: "))
    print("")
    if(choice == 1):
        employee.display(ID)
    elif(choice == 2):
        employee.Calc_Bonus(ID)
    elif(choice == 3):
        employee.Calc_Discount(ID)
    elif(choice == 4):
            employee.Holidays(ID)
    elif(choice == 5):
        print("Thanks for using the Employee Management System. Good Bye!")
        break

    choice = input("\nPress Enter to return to the main menu.")

