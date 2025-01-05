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
