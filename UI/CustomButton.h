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
        QPixmap pixmap(path); // Charger l'image � partir du chemin d'image
        QIcon icon(pixmap); // Cr�er une ic�ne � partir de la pixmap
        setIcon(icon); // D�finir l'ic�ne comme source d'image pour le bouton
        setIconSize(pixmap.size()); // D�finir la taille de l'ic�ne pour qu'elle corresponde � la taille de l'image charg�e
        setFixedSize(pixmap.rect().size()); // D�finition de la taille fixe du bouton pour correspondre � la taille de l'ic�ne
        setFlat(true);
    }

    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);
    bool event(QEvent* e);

    void hoverEnter(QHoverEvent* event);
    void hoverLeave(QHoverEvent* event);
    void hoverMove(QHoverEvent* event);

    // Vous pouvez ajouter des fonctions membres suppl�mentaires selon vos besoins

public slots:
    // D�finissez vos slots personnalis�s ici
    void selected()
    {
        QString path = "image/selected/" + _imgName;
        QPixmap pixmap(path); // Charger l'image � partir du chemin d'image
        QIcon icon(pixmap); // Cr�er une ic�ne � partir de la pixmap
        setIcon(icon); // D�finir l'ic�ne comme source d'image pour le bouton
        setIconSize(pixmap.size()); // D�finir la taille de l'ic�ne pour qu'elle corresponde � la taille de l'image charg�e
    }

    void deselect()
    {
        QString path = "image/unselected/" + _imgName;
        QPixmap pixmap(path); // Charger l'image � partir du chemin d'image
        QIcon icon(pixmap); // Cr�er une ic�ne � partir de la pixmap
        setIcon(icon); // D�finir l'ic�ne comme source d'image pour le bouton
        setIconSize(pixmap.size()); // D�finir la taille de l'ic�ne pour qu'elle corresponde � la taille de l'image charg�e
    }

private:
    // D�finissez vos membres priv�s ici
    QString _imgName;
};


#endif // CUSTOM_BUTTON
