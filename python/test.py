#This is a simple login program.

def log_in( ):
	""" This function helps user to login. If username/password incorrect after 3 login attempts, the function returns 'failed to login."""
	
	password = ""
	user_name = ""
	log_count = 0
	logged_in = False

	while logged_in == False and log_count <= 2:
		user_name = input("Enter username: \n").lower()
		if user_name in user_pass:
			password = input("Enter password: \n").lower()
			if user_name in user_pass and password == user_pass[user_name]:
				print("Login Successful.\n")
				logged_in = True
				break	
			else:
				try:
					if password != user_pass[user_name]:
						log_count += 1
						remaining_log = 3 - log_count
						print(f"Invalid password. {remaining_log} tries left.\n")
				except KeyError:
					print("")
		else:
			try:
				if user_name not in user_pass:
					log_count += 1
					remaining_log = 3 - log_count
					print(f"Invalid username. {remaining_log} tries left.\n")
			except KeyError:
				log_count += 1			
	else:
		print("Failed to login.")
	return ("Thank you!")


#Dictionary holding username and password. A few usernames with their password have been logged.
user_pass = {
"john":"john100", 
"jude":"jude300",
"jane":"jane200"}

create = ""
to_login = ""
logged_in = False
login = ""
no_login = False
print("*" * 35)
#Welcomes user.
print("Welcome to PyCloud 1.0")
print("*" * 35)
#Collects name of user.
name = input("Please enter your name: ").title()
print(f"\nHi, {name}.")

#login loop. 
	#Breaks if user login successful. it also breaks if user doesn't want to login, or doesn't want to create account.
while log_in != "Thank you!" and create != "NO" and to_login != "NO" and logged_in != True and no_login != True:
	account = input("Do you have an account? \n").upper()
	
#Asks if user wants to login. If yes, login function is called.
	if account == "YES":
		while login != "NO":
			login = input("Do you want to login? \n").upper()
			if login == "NO":
				print("\nOkay, Bye!")
				no_login = True
				break
			elif login == "YES":
				print(log_in())
				logged_in = True
				break
			else:
				print("Invalid input. Please type 'Yes' or 'No.'")
			
#Account creation prompt. If "no", program terminates. if "yes", account creation prompt comes up
	elif account == "NO":
		account_created = False
		while account_created == False:
			create = input("Do you want to create an account? \n").upper()
			if create == "NO":
				print("Okay, Bye!")
				break
			if create == "YES":
				
	#Collects new username and password.
				user_name = input("Enter username: \n")
				password = input("Enter password: \n")
				
	#Adds new username and password to dictionary
				user_pass[user_name] = password
				print("Account successfully created.\n")
				account_created = True
				
	#Asks if user wants to login. If yes, login function is called. If no, program terminates.
				while log_in != "Thank you!":
					to_login = input("Do you want to login now? \n").upper()
					if to_login == "YES":
						print(log_in())
						logged_in = True
						break						
					elif to_login == "NO":
						print("Okay, Bye!")
						break			
					else:
						print("Invalid input. Please type 'Yes' or 'No.'")
					
	#Tells user to put correct command
			else:
				print("Invalid input. Please type 'Yes' or 'No.'")
	else:
		print("Invalid input. Please type 'Yes' or 'No.'")
