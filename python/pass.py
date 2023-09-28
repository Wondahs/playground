user_pass = {
    "john": "john100",
    "jude": "jude300",
    "jane": "jane200"
}

def log_in():
    """This function helps the user to log in. If username/password is incorrect after 3 login attempts, the function returns 'failed to login.'"""

    log_count = 0

    while log_count < 3:
        user_name = input("Enter username: ").lower()
        if user_name in user_pass:
            password = input("Enter password: ").lower()
            if password == user_pass[user_name]:
                print("Login Successful.\n")
                return "Thank you!"
            else:
                log_count += 1
                remaining_log = 3 - log_count
                print(f"Invalid password. {remaining_log} tries left.\n")
            else:
            log_count += 1
            remaining_log = 3 - log_count
            print(f"Invalid username. {remaining_log} tries left.\n")

    print("Failed to login.")
    return "Thank you!"

print("=" * 35)
print("Welcome to PyCloud 1.0")
print("=" * 35)
name = input("Please enter your name: ").title()
print(f"\nHi, {name}.")

while True:
    account = input("Do you have an account? (yes/no): ").lower()
    
    if account == "yes":
        while True:
            login = input("Do you want to login? (yes/no): ").lower()
            if login == "no":
                print("\nOkay, Bye!")
                break
            elif login == "yes":
                result = log_in()
                print(result)
                if result == "Thank you!":
                    break
            else:
                print("Invalid input. Please type 'yes' or 'no.'")
    
    elif account == "no":
        create = input("Do you want to create an account? (yes/no): ").lower()
        if create == "yes":
            user_name = input("Enter username: ")
            password = input("Enter password: ")
            user_pass[user_name] = password
            print("Account successfully created.\n")
        elif create == "no":
            print("Okay, Bye!")
            break
        else:
            print("Invalid input. Please type 'yes' or 'no.'")
    else:
        print("Invalid input. Please type 'yes' or 'no.'")
