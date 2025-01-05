# Présentation du projet

Ce readme a pour but d'organiser le déroulement de la présentation et de servir de support pour tester les différentes fonctionnalités du projet.

---

## 1. Test du Compilateur

### Analyse Lexicale

```bash	
./compiler.exe -f ./example/compilation/lexical/unknow_char.txt
```
### Analyse Syntaxique

```bash	
./compiler.exe -f ./example/compilation/syntax/reserved_token.txt
```

```bash
./compiler.exe -f ./example/compilation/syntax/mixed_declaration.txt
```

### Analyse Sémantique

1. Array & Struct:

<!-- Assignement -->
```bash
./compiler.exe -f ./example/compilation/semantic/array_struct/assignement.txt
```

<!-- Access -->
```bash
./compiler.exe -f ./example/compilation/semantic/array_struct/access.txt
```

<!-- Undefined -->
```bash
./compiler.exe -f ./example/compilation/semantic/array_struct/undefined.txt
```

2. Function:

<!-- Call -->
```bash
./compiler.exe -f ./example/compilation/semantic/func_proc/func_call.txt
```

<!-- Prototype -->
```bash
./compiler.exe -f ./example/compilation/semantic/func_proc/prototype.txt
```

<!-- Definition -->
```bash
./compiler.exe -f ./example/compilation/semantic/func_proc/re-un-defined.txt
```


3. Expression:

<!-- Arithmetic -->
```bash
./compiler.exe -f ./example/compilation/semantic/expression/arithmetic_expression.txt
```

<!-- Boolean -->
```bash
./compiler.exe -f ./example/compilation/semantic/expression/boolean_expression.txt
```

5. Type:

<!-- Base Type -->
```bash
./compiler.exe -f ./example/compilation/semantic/type/base_type.txt 
```

<!-- Redefined Type -->
```bash
./compiler.exe -f ./example/compilation/semantic/type/redefined.txt 
```

<!-- Undefined Type -->
```bash
./compiler.exe -f ./example/compilation/semantic/type/undefined.txt
```

6. Overloading:

```bash
./compiler.exe -f ./example/compilation/semantic/overload/assignement.txt
```

### 2. Test de l'Interpréteur

On commence par tester les fichiers contenant des erreurs d'interprétation.

#### Erreurs d'interprétation

1. Array:

<!-- Out of bound index -->
```bash
./compiler.exe -f ./example/interpretation/errors/arrays/out_of_bounds.txt -o ./z_test.o && ./interpreter.exe -f ./z_test.o
```

<!-- Wrong indices -->
```bash
./compiler.exe -f ./example/interpretation/errors/arrays/wrong_dimension.txt -o ./z_test.o && ./interpreter.exe -f ./z_test.o
```

<!-- Wrong indice type -->
```bash
./compiler.exe -f ./example/interpretation/errors/arrays/indice_type.txt -o ./z_test.o && ./interpreter.exe -f ./z_test.o
```

2. Expression:

<!-- Division by 0 -->
```bash
./compiler.exe -f ./example/interpretation/errors/expression/divisionbyzero.txt -o ./z_test.o && ./interpreter.exe -f ./z_test.o
```

<!-- Null variable -->
```bash
./compiler.exe -f ./example/interpretation/errors/expression/uninitialized.txt -o ./z_test.o && ./interpreter.exe -f ./z_test.o
```

#### Petits exemples fonctionnels

##### Tableaux

1. Tableau de caractères:

```bash
./compiler.exe -f ./example/interpretation/functional/mini/string.txt -o ./z_test.o && ./interpreter.exe -sf ./z_test.o
```

2. Matrice 3 dimensions:

Commenter la ligne d'appel de la fonction `main` :
```bash
./compiler.exe -f ./example/interpretation/functional/mini/matrix_3d.txt -o ./z_test.o && ./interpreter.exe -sf ./z_test.o
```

3. Tableau dans une structure:

```bash
./compiler.exe -f ./example/interpretation/functional/mini/struct_array.txt -o ./z_test.o && ./interpreter.exe -sf ./z_test.o
```

##### Conditions 

```bash
./compiler.exe -f ./example/interpretation/functional/mini/condition.txt -o ./z_test.o && ./interpreter.exe -f ./z_test.o
```

#### App plus complexe

1. Factorial Calculator:

```bash
./compiler.exe -f ./example/interpretation/functional/app/factorial_calculator.txt -o ./z_test.o && ./interpreter.exe -f ./z_test.o
```

2. Simple Calculator:

```bash
./compiler.exe -f ./example/interpretation/functional/app/simple_calculator.txt -o ./z_test.o && ./interpreter.exe -f ./z_test.o
```

3. Matrix Calculator:

```bash
./compiler.exe -f ./example/interpretation/functional/app/matrix_calculator.txt -o ./z_test.o && ./interpreter.exe -f ./z_test.o
```