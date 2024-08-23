# Clinic Management System in C

This project is a simple Clinic Management System written in the C programming language. The system allows users to manage patient records, make reservations, and view appointment details. It features two modes: Admin mode and User mode, each with its own set of functionalities.

## Table of Contents

1. [Features](#features)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Admin Mode](#admin-mode)
5. [User Mode](#user-mode)
6. [Contributing](#contributing)
7. [License](#license)

## Features

- **Admin Mode**:
  - Secure login with password protection.
  - Add, edit, and manage patient records.
  - Reserve and cancel appointment slots with the doctor.
  
- **User Mode**:
  - View patient records.
  - Check today's appointment reservations.

## Usage

Upon running the program, the user will be prompted to choose between Admin mode and User mode.

### Admin Mode

To enter Admin mode, you will be required to enter a password. The default password is `1234`. The system allows up to three trials for password entry. If the entered password is incorrect for three consecutive times, the system will close automatically.

Once logged in, the following features are available:

1. **Add New Patient Record**: Enter the patient's name, age, gender, and a unique ID. If the entered ID already exists, the system will reject the entry.

2. **Edit Patient Record**: By entering a patient's ID, the system checks if it exists. If it does, the user can edit the patient's information. If not, the system will display an "Incorrect ID" message.

3. **Reserve a Slot with the Doctor**: By default, there are 5 available slots:
   - 2pm to 2:30pm
   - 2:30pm to 3pm
   - 3pm to 3:30pm
   - 4pm to 4:30pm
   - 4:30pm to 5pm

   The admin can reserve a slot by entering the patient's ID and the desired slot. Reserved slots will no longer appear in the list of available slots.

4. **Cancel Reservation**: The admin can cancel a reservation by entering the patient's ID. The canceled reservation will become available again.

### User Mode

No password is required for User mode. The following features are available:

1. **View Patient Record**: Enter the patient's ID to view their basic information.

2. **View Today's Reservations**: This will display all reservations, including the patient ID for each reserved slot.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please fork the repository and submit a pull request. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more information.
