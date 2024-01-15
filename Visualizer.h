#pragma once

#include <QtWidgets/QMainWindow>
#include "OpenGLWindow.h"
#include <Qvector>
#include <set>

class OpenGLWindow;

class Visualizer : public QMainWindow {
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();

private:
    void setupUi();
    void openFileSelectionDialog();
    void completeFileSelect();
    void callSort();
    void showModel();
    void handleComboBoxChange();

private:
    QWidget* mCentralWidget;
    OpenGLWindow* mRenderer;

    QPushButton* mDoneFileSelectButton;
    QPushButton* mAddFileButton;
    QPushButton* mSortButton;
    QPushButton* mShowModelButton;

    QStringList mFileList;
    QStringList mFilePathList;

    QVector<GLfloat>mVertices;
    QVector<GLfloat>mColors;

    QListView* mListOfFiles;
    QComboBox* mParameterList;
    QLabel* mChooseParameterLabel;

    QTableWidget* mModelTable;

    QHBoxLayout* mMainLayout;
    QSplitter* mSplitter;
    QVBoxLayout* mVerticalLayout;

    QString mAddFileButtonStyle = "QPushButton {"
        "   background-color: #4CAF50; /* Set a green background color */"
        "   border: 2px solid #45A049; /* Set a darker green border color */"
        "   border-radius: 5px; /* Set border radius */"
        "   color: #FFFFFF; /* Set text color to white */"
        "   font-weight: bold; /* Make the text bold */"
        "}"
        "QPushButton:hover {"
        "   background-color: #45A049; /* Set a slightly darker green on hover */"
        "}";

    QString mTableStyle =
        "QTableWidget {"
        "   background-color: #FFFFFF; /* Set background color */"
        "   border: 2px solid #4A90E2; /* Set border color */"
        "   border-radius: 5px; /* Set border radius */"
        "   color: #333333; /* Set text color */"
        "   selection-background-color: #E6E6E6; /* Set selection background color */"
        "}"
        "QTableWidget::item {"
        "   padding: 5px; /* Set padding for items */"
        "}"
        "QTableWidget::item:selected {"
        "   background-color: #4A90E2; /* Set background color for selected items */"
        "   color: #FFFFFF; /* Set text color for selected items */"
        "}"
        "QHeaderView::section {"
        "   background-color: #4A90E2; /* Set background color for header section */"
        "   color: #FFFFFF; /* Set text color for header section */"
        "   padding: 5px; /* Set padding for header section */"
        "}";

    QString mFileSelectButtonStyle =
        "QPushButton {"
        "   background-color: #4A90E2; /* Set background color */"
        "   border: 2px solid #336699; /* Set border color */"
        "   border-radius: 5px; /* Set border radius */"
        "   color: #FFFFFF; /* Set text color */"
        "}"
        "QPushButton:hover {"
        "   background-color: #336699; /* Set background color on hover */"
        "}";

    QString mShowModelButtonStyle =
        "QPushButton {"
        "   background-color: #FFD700; /* Set background color */"
        "   border: 2px solid #B8860B; /* Set border color */"
        "   border-radius: 5px; /* Set border radius */"
        "   color: #000000; /* Set text color */"
        "}"
        "QPushButton:hover {"
        "   background-color: #DAA520; /* Set background color on hover */"
        "}";

    QString mParameterListButtonStyle =
        "QComboBox {"
        "   border: 2px solid #4A90E2; /* Set border color */"
        "   border-radius: 5px; /* Set border radius */"
        "   padding: 1px 18px 1px 3px; /* Set padding */"
        "   background-color: #FFFFFF; /* Set background color */"
        "   color: #333333; /* Set text color */"
        "   selection-background-color: #E6E6E6; /* Set selection background color */"
        "}";

    QString mSortButtonStyle =
        "QPushButton {"
        "   background-color: #DC143C; /* Set background color */"
        "   border: 2px solid #8B0000; /* Set border color */"
        "   border-radius: 5px; /* Set border radius */"
        "   color: #FFFFFF; /* Set text color */"
        "}"
        "QPushButton:hover {"
        "   background-color: #B22222; /* Set background color on hover */"
        "}";
};
