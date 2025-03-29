#pragma once

#include <QMessageBox>

typedef enum {
    SUCCESS,                   // �������� ����������
    ERROR_FILE_NOT_SELECTED,    // ���� �� ������
    ERROR_FILE_OPEN,           // ������ �������� �����
    ERROR_MEMORY_ALLOCATION,   // ������ ��������� ������
    ERROR_PARSE_VERTEX,        // ������ �������� �������
    ERROR_PARSE_FACE,          // ������ �������� ��������
    ERROR_OBJ_LOAD_FAILED,     // ������ �������� OBJ-�����
    ERROR_UNKNOWN,             // ����������� ������
    ERROR_INVALID_ARGUMENT,    // �������� ��������
    ERROR_INVALID_INPUT,        // �������� ����
    ERROR_FILE_CONTENTS         // �������� ���������� �����
} ErrorCode;

void ShowErrorMessage(QWidget* parent, ErrorCode error);