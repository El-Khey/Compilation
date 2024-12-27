#ifndef __VIRTUAL_MACHINE_H__
#define __VIRTUAL_MACHINE_H__

#include <stdio.h>
#include <stdlib.h>

#include "../../ast/ast.h"
#include "vm_cell.h"

vm_cell get_variable_cell(int index_declaration);

vm_cell get_struct_cell(Node *struct_access);

vm_cell get_array_cell(Node *arra_access);


void handle_variable_declaration(int index_declaration);

void handle_variable_affectation(int index_declaration, vm_cell cell);

void handle_array_affectation(Node *array_index_list, vm_cell cell);

void handle_structure_affectation(Node* struct_field_access, vm_cell cell);

void handle_function_return_value(vm_cell cell);

#endif // __VIRTUAL_MACHINE_H__