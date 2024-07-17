
# COVID-19 Patient Management System

![C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg)


## About

Welcome to the COVID-19 Patient Management System. This application is designed to manage patient data, including registration and access to patient records, with a focus on COVID-19 related information. The system is built using C++ and offers a simple console-based interface for user authentication, patient data entry, and record retrieval.

## Features

- **User Authentication**: Secure login with predefined user credentials.
- **Patient Registration**: Collects and stores patient information such as name, CPF, address, date of birth, and comorbidity details.
- **Patient Record Access**: Retrieve and display stored patient records based on CPF.
- **Data Storage**: Saves patient data in text files for easy access and modification.
- **Comorbidity Statistics**: Appends comorbidity data to a separate file for statistical analysis.

## Getting Started

### Prerequisites

- C++ Compiler (GCC, Clang, MSVC, etc.)

### Installation

1. **Clone the repository**:
    ```
    git clone https://github.com/your-username/covid19-patient-management-system.git
    cd covid19-patient-management-system
    ```

2. **Compile the code**:
    ```
    g++ -o covid19_system main.cpp
    ```

3. **Run the application**:
    ```
    ./covid19_system
    ```

## Usage

### Login

- Upon starting the application, you will be prompted to enter your user code and password.
- Use the predefined credentials:
  - **User Code**: `123456`
  - **Password**: `654321`

### Menu Options

1. **Register Patient**:
   - Enter the patient's details as prompted.
   - The system will save the details to a file named after the patient's CPF.

2. **Access Patient Records**:
   - Enter the patient's CPF to retrieve and display their stored data.

3. **Exit**:
   - Choose this option to exit the application.

### Data Structure

- **Patient Data File**: Each patient’s data is stored in a text file named after their CPF.
- **Comorbidity Statistics File**: Comorbidity data is appended to `listaComorbidade.txt`.

## Example

### Registering a Patient

```plaintext
==========Menu de Atendimento a COVID-19==========
1. Cadastrar Paciente
2. Consultar Cadastro
0. Sair
Escolha uma opcao: 1
Digite o Nome do Paciente: John Doe
Digite o CPF do Paciente (Nao use pontos ou tracos): 12345678900
Digite o Endereco do Paciente: 123 Main St
Digite o Bairro do Paciente: Downtown
Digite a Cidade do Paciente: Metropolis
Digite o CEP do Paciente: 12345678
Digite o E-mail do Paciente: john.doe@example.com
Digite a Data de Nascimento (dd-mm-yyyy): 01-01-1980
Digite a Data de Diagnostico (dd-mm-yyyy): 01-01-2022
Digite 1 para possuir comorbidade ou 2 para nao possuir: 1
Digite a comorbidade do Paciente: Hypertension
Os dados do paciente foram salvos com sucesso.
```

### Accessing Patient Records

```plaintext
==========Menu de Atendimento a COVID-19==========
1. Cadastrar Paciente
2. Consultar Cadastro
0. Sair
Escolha uma opcao: 2
Digite o paciente_cpf do Paciente (Nao use pontos ou tracos): 12345678900
Nome: John Doe
CPF: 12345678900
Endereco: 123 Main St
Bairro: Downtown
Cidade: Metropolis
CEP: 12345678
E-mail: john.doe@example.com
Data de Nascimento: 01-01-1980
Data de Diagnostico: 01-01-2022
Idade: 42
Comorbidade: Hypertension
```

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests with your improvements.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Inspired by the need for efficient patient data management during the COVID-19 pandemic.
- Developed with love and care to assist healthcare professionals in managing patient information effectively.

---

**Developed by Rodney Victor (https://github.com/rodneyvictorsoares)**

For more details, visit the [GitHub Repository](https://github.com/rodneyvictorsoares/sncovid).
