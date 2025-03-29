#include "qt6.h"

static void fill_triangle(QPixmap* pixmap, const triangle& input) {
    QPainter painter(pixmap);
    QColor qcolor(input.color.r, input.color.g, input.color.b);
    painter.setPen(qcolor);
    painter.setBrush(QBrush(qcolor));

    QPolygon triangle;

    triangle.append(QPoint(input.p[0].x, input.p[0].y));
    triangle.append(QPoint(input.p[1].x, input.p[1].y));
    triangle.append(QPoint(input.p[2].x, input.p[2].y));

    painter.drawPolygon(triangle);
}

void drawScene(const mesh& mymesh, projParams& params) {
    QPixmap pixmap(params.width, params.height);
    pixmap.fill(params.backgroundColor);

    for (int i = 0; i < mymesh.tri_count; i++) {
        fill_triangle(&pixmap, mymesh.tris[i]);
    }

    params.ui.pixmap_label->setPixmap(pixmap);
}

void setupConnections(Ui::Form& ui)
{

    QShortcut* shortcutLeft = new QShortcut(QKeySequence(Qt::Key_Left), ui.pixmap_label);
    QObject::connect(shortcutLeft, &QShortcut::activated, [&]() {
        ShowErrorMessage(ui.horizontalLayoutWidget, MoveCamera(X, -0.3));
        ShowErrorMessage(ui.horizontalLayoutWidget, ProjectAction(ui));
        });

    QShortcut* shortcutRight = new QShortcut(QKeySequence(Qt::Key_Right), ui.pixmap_label);
    QObject::connect(shortcutRight, &QShortcut::activated, [&]() {
        ShowErrorMessage(ui.horizontalLayoutWidget, MoveCamera(X, 0.3));
        ShowErrorMessage(ui.horizontalLayoutWidget, ProjectAction(ui));
        });

    QShortcut* shortcutUp = new QShortcut(QKeySequence(Qt::Key_Up), ui.pixmap_label);
    QObject::connect(shortcutUp, &QShortcut::activated, [&]() {
        ShowErrorMessage(ui.horizontalLayoutWidget, MoveCamera(Y, 0.3));
        ShowErrorMessage(ui.horizontalLayoutWidget, ProjectAction(ui));
        });

    QShortcut* shortcutDown = new QShortcut(QKeySequence(Qt::Key_Down), ui.pixmap_label);
    QObject::connect(shortcutDown, &QShortcut::activated, [&]() {
        ShowErrorMessage(ui.horizontalLayoutWidget, MoveCamera(Y, -0.3));
        ShowErrorMessage(ui.horizontalLayoutWidget, ProjectAction(ui));
        });

    QShortcut* shortcutZoomIn = new QShortcut(QKeySequence(Qt::Key_PageUp), ui.pixmap_label);
    QObject::connect(shortcutZoomIn, &QShortcut::activated, [&]() {
        ShowErrorMessage(ui.horizontalLayoutWidget, MoveCamera(Z, 0.3));
        ShowErrorMessage(ui.horizontalLayoutWidget, ProjectAction(ui));

        });

    QShortcut* shortcutZoomOut = new QShortcut(QKeySequence(Qt::Key_PageDown), ui.pixmap_label);
    QObject::connect(shortcutZoomOut, &QShortcut::activated, [&]() {
        ShowErrorMessage(ui.horizontalLayoutWidget, MoveCamera(Z, -0.3));
        ShowErrorMessage(ui.horizontalLayoutWidget, ProjectAction(ui));
        });

    QObject::connect(ui.openButton, &QPushButton::clicked, [&]() {ShowErrorMessage(ui.horizontalLayoutWidget, ReadAction(figureColor)); ShowErrorMessage(ui.horizontalLayoutWidget, ProjectAction(ui));});
    QObject::connect(ui.moveButton, &QPushButton::clicked, [&]() {ShowErrorMessage(ui.horizontalLayoutWidget, TransformAction(ui, TRANSLATE)); ShowErrorMessage(ui.horizontalLayoutWidget, ProjectAction(ui));});
    QObject::connect(ui.rotateButton, &QPushButton::clicked, [&]() {ShowErrorMessage(ui.horizontalLayoutWidget, TransformAction(ui, ROTATE)); ShowErrorMessage(ui.horizontalLayoutWidget, ProjectAction(ui));});
    QObject::connect(ui.scaleButton, &QPushButton::clicked, [&]() {ShowErrorMessage(ui.horizontalLayoutWidget, TransformAction(ui, SCALE)); ShowErrorMessage(ui.horizontalLayoutWidget, ProjectAction(ui));});
    QObject::connect(qApp, &QCoreApplication::aboutToQuit, [&]() {ShowErrorMessage(ui.horizontalLayoutWidget, FreeAction());});
}