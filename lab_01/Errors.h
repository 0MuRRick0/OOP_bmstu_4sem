#pragma once

#include <QMessageBox>

typedef enum {
    SUCCESS,                   // Успешное выполнение
    ERROR_FILE_NOT_SELECTED,    // Файл не выбран
    ERROR_FILE_OPEN,           // Ошибка открытия файла
    ERROR_MEMORY_ALLOCATION,   // Ошибка выделения памяти
    ERROR_PARSE_VERTEX,        // Ошибка парсинга вершины
    ERROR_PARSE_FACE,          // Ошибка парсинга полигона
    ERROR_OBJ_LOAD_FAILED,     // Ошибка загрузки OBJ-файла
    ERROR_UNKNOWN,             // Неизвестная ошибка
    ERROR_INVALID_ARGUMENT,    // Неверный аргумент
    ERROR_INVALID_INPUT,        // Неверный ввод
    ERROR_FILE_CONTENTS         // Неверное содержание файла
} ErrorCode;

void ShowErrorMessage(QWidget* parent, ErrorCode error);