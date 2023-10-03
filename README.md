# Bank System Console Application

A console-based C++ application for managing a simple bank system.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [User Roles](#user-roles)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Bank System Console Application is a C++ project that simulates basic banking operations. It allows users to create accounts, deposit and withdraw funds, check account balances, and perform other banking tasks via a text-based console interface.

## Features

- User account creation
- Deposit and withdraw funds
- Account balance inquiries
- Account transactions history
- Multiple user roles (client, employee, admin)

## Getting Started

Follow these instructions to set up and run the Bank System Console Application on your local machine.

### Prerequisites

- C++ compiler (e.g., g++)
- Git (optional)

### Installation

1. Clone the repository (or download and extract the ZIP file):

   ```shell
   git clone https://github.com/ahmedosamaft/bank-system.git
2. Compile the source code:
     ```shell
     g++ -o bank_system main.cpp
3. Run the application:
   ```shell
     ./bank_system
## Usage
After running the application, you can interact with the Bank System using various commands. Here's how to use it:
### User Roles
1. Client: A client can be created by an employee or an admin and can deposit and withdraw funds from their account, as well as check their balance and transaction history.
2. Employee: An employee have additional capabilities, such as creating and closing client accounts.
3. Admin: An admin have additional capabilities upon an employee, such as creating and closing client & employee accounts.
  To perform actions, simply follow the on-screen instructions and input the required information.
## Contributing
Contributions to this project are welcome. If you'd like to contribute, please follow these steps:

1. Fork the project.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them with descriptive commit messages.
4. Push your changes to your fork.
5. Submit a pull request to the main repository.
- Please follow the project's code of conduct and contribution guidelines.

## License
**This project is licensed under the <a href="https://opensource.org/license/mit/" target="_blank">MIT License </a>**
