
#include "CustomButton.h"

bool CustomButton::event(QEvent* e)
{
    switch (e->type())
    {
    case QEvent::HoverEnter:
        hoverEnter(static_cast<QHoverEvent*>(e));
        return true;
        break;
    case QEvent::HoverLeave:
        hoverLeave(static_cast<QHoverEvent*>(e));
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(e);
}

void CustomButton::enterEvent(QEvent* e)
{
    //qDebug() << Q_FUNC_INFO << e->type();
}

void CustomButton::leaveEvent(QEvent* e)
{
    //qDebug() << Q_FUNC_INFO << e->type();
}


void CustomButton::hoverEnter(QHoverEvent* event)
{
    //qDebug() << Q_FUNC_INFO << event->type();
    selected();
}

void CustomButton::hoverLeave(QHoverEvent* event)
{
    //qDebug() << Q_FUNC_INFO << event->type();
    //Mettre en blanc
    deselect();
}

void CustomButton::hoverMove(QHoverEvent* event)
{
    //qDebug() << Q_FUNC_INFO << event->type();
    //mettre en vert
}