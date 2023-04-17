#ifndef CUSTOM_BUTTON
#define CUSTOM_BUTTON
#include <QPushButton>
#include <QHoverEvent>
#include <QEvent>
#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QDebug>
#include <QObject>

class CustomButton : public QPushButton {
    Q_OBJECT;
public:
    
    CustomButton(const QString& imgName, QWidget* parent = nullptr) : QPushButton(parent) {
        this->setAttribute(Qt::WA_Hover, true);
        _imgName = imgName;
        QString path = "image/unselected/" + _imgName;
        QPixmap pixmap(path); // Charger l'image à partir du chemin d'image
        QIcon icon(pixmap); // Créer une icône à partir de la pixmap
        setIcon(icon); // Définir l'icône comme source d'image pour le bouton
        setIconSize(pixmap.size()); // Définir la taille de l'icône pour qu'elle corresponde à la taille de l'image chargée
        setFixedSize(pixmap.rect().size()); // Définition de la taille fixe du bouton pour correspondre à la taille de l'icône
        setFlat(true);
    }

    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);
    bool event(QEvent* e);

    void hoverEnter(QHoverEvent* event);
    void hoverLeave(QHoverEvent* event);
    void hoverMove(QHoverEvent* event);

    // Vous pouvez ajouter des fonctions membres supplémentaires selon vos besoins

public slots:
    // Définissez vos slots personnalisés ici
    void selected()
    {
        QString path = "image/selected/" + _imgName;
        QPixmap pixmap(path); // Charger l'image à partir du chemin d'image
        QIcon icon(pixmap); // Créer une icône à partir de la pixmap
        setIcon(icon); // Définir l'icône comme source d'image pour le bouton
        setIconSize(pixmap.size()); // Définir la taille de l'icône pour qu'elle corresponde à la taille de l'image chargée
    }

    void deselect()
    {
        QString path = "image/unselected/" + _imgName;
        QPixmap pixmap(path); // Charger l'image à partir du chemin d'image
        QIcon icon(pixmap); // Créer une icône à partir de la pixmap
        setIcon(icon); // Définir l'icône comme source d'image pour le bouton
        setIconSize(pixmap.size()); // Définir la taille de l'icône pour qu'elle corresponde à la taille de l'image chargée
    }

private:
    // Définissez vos membres privés ici
    QString _imgName;
};


#endif // CUSTOM_BUTTON
