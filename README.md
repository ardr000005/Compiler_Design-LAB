# 🧠 Compiler Design Laboratory

This repository contains all the **Compiler Design Lab** experiments implemented using **C**, **LEX**, and **YACC**.  
It demonstrates the various phases of a compiler — from lexical analysis to code generation and optimization.

---

## 📁 Repository Structure

```
Compiler_Design-LAB/
│
├── LEX/
│ ├── Printf_Scanf/
│ ├── email_validation.l
│ ├── odd_even.l
│ └── vowels_consonants.l
│
├── LEX_YAC/
│ ├── Calculator/
│ ├── Count_IF_ELSE/
│ ├── Valid_Email/
│ ├── Valid_Identifier/
│ └── arithmetic/
│
├── Lexical_analyzer/
│
├── code_optimization/
│
├── backend.c
├── dfa.c
├── epsilon-nfa.c
├── first_follow.c
├── intermediatecode.c
├── recursivedescent.c
└── shiftreduce.c

```
---

## 🧩 Overview of Experiments

### 🔹 1. Lexical Analysis (LEX Programs)
Implements token recognition and pattern matching using **LEX**.

- `odd_even.l` – Identifies even and odd numbers.  
- `vowels_consonants.l` – Counts vowels and consonants.  
- `email_validation.l` – Validates email address format.  
- `Printf_Scanf/` – Demonstrates tokenization of printf/scanf statements.

---

### 🔹 2. Syntax Analysis (LEX + YACC Programs)
Implements parsing and syntax validation using **YACC** along with LEX.

- `Calculator/` – Arithmetic expression evaluation.  
- `Count_IF_ELSE/` – Counts number of if-else statements.  
- `Valid_Identifier/` – Checks valid identifiers in C.  
- `Valid_Email/` – Validates email pattern using grammar.  
- `arithmetic/` – Parses arithmetic operations using grammar rules.

---

### 🔹 3. DFA and NFA
- `dfa.c` – Simulation of **Deterministic Finite Automata**.  
- `epsilon-nfa.c` – Converts **ε-NFA** to **NFA/DFA** representation.

---

### 🔹 4. FIRST and FOLLOW Sets
- `first_follow.c` – Computes **FIRST** and **FOLLOW** sets for a given grammar.  
  Useful for building predictive parsers.

---

### 🔹 5. Parsing Techniques
- `recursivedescent.c` – Implements **Recursive Descent Parser**.  
- `shiftreduce.c` – Demonstrates **Shift Reduce Parsing** with stack-based approach.

---

### 🔹 6. Intermediate Code Generation
- `intermediatecode.c` – Converts high-level expressions into **3-address code** format.  
- Demonstrates quadruples, triples, and indirect triples representations.

---

### 🔹 7. Code Optimization
- `code_optimization/` – Shows Code optimization in sum code

---

### 🔹 8. Backend / Code Generation
- `backend.c` – Translates intermediate code into **target machine code** representation.

---

## ⚙️ Tools & Environment

| Tool | Description |
|------|--------------|
| **LEX / FLEX** | Lexical Analyzer Generator |
| **YACC / BISON** | Syntax Analyzer Generator |
| **GCC** | C Compiler |
| **OS** | Linux / Ubuntu recommended |

---

## 🚀 How to Run

### 1️⃣ Compile and Run C Programs
```bash
gcc filename.c -o output
./output
```
2️⃣ Compile and Run LEX Programs
```
lex filename.l
gcc lex.yy.c -o output -ll
./output
```
3️⃣ Compile and Run LEX + YACC Programs
```
lex filename.l
yacc -d filename.y
gcc lex.yy.c y.tab.c -o output -ll -ly
./output
```
📚 Concepts Covered
```
    Lexical Analysis

    Finite Automata (DFA, NFA, ε-NFA)

    Syntax Analysis

    Recursive Descent Parsing

    Shift Reduce Parsing

    FIRST and FOLLOW computation

    Intermediate Code Generation

    Code Optimization

    Code Generation
```
👨‍💻 Author

Aravind R (ardr000005)
B.Tech CSE Student
Compiler Design Laboratory 

This repository is intended for educational use.
Feel free to fork, improve, or refer to these codes for learning Compiler Design concepts.
