#include "Errors.h"

void ShowErrorMessage(QWidget* parent, ErrorCode error) {
    QString title = "Ошибка";
    QString message;

    switch (error) {
    case SUCCESS:
        return;

    case ERROR_FILE_NOT_SELECTED:
        message = "Файл не выбран. Пожалуйста, выберите файл для загрузки.";
        break;

    case ERROR_FILE_OPEN:
        message = "Не удалось открыть файл. Проверьте путь и права доступа.";
        break;

    case ERROR_MEMORY_ALLOCATION:
        message = "Ошибка выделения памяти. Недостаточно ресурсов для выполнения операции.";
        break;

    case ERROR_PARSE_VERTEX:
        message = "Ошибка парсинга вершины. Проверьте формат данных в OBJ-файле.";
        break;

    case ERROR_FILE_CONTENTS:
        message = "Ошибка парсинга вершины. Проверьте формат данных в OBJ-файле.";
        break;

    case ERROR_PARSE_FACE:
        message = "Ошибка парсинга полигона. Неверный формат граней в OBJ-файле.";
        break;

    case ERROR_OBJ_LOAD_FAILED:
        message = "Ошибка загрузки OBJ-файла. Проверьте целостность файла.";
        break;

    case ERROR_UNKNOWN:
        message = "Произошла неизвестная ошибка. Попробуйте перезапустить приложение.";
        break;

    case ERROR_INVALID_ARGUMENT:
        message = "Неверный аргумент. Проверьте входные параметры функции.";
        break;

    case ERROR_INVALID_INPUT:
        message = "Неверный ввод. Проверьте корректность введенных данных.";
        break;

    default:
        message = "Неопознанная ошибка. Код: " + QString::number(error);
        break;
    }

    QMessageBox::critical(parent, title, message);
}