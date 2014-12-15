#include "boid.h"

boid::boid() {
    component = new QQmlComponent(management::engine, QUrl(QStringLiteral("qrc:/Boid.qml")));
    if(component->status() == component->Ready) {
        object = component->create(management::engine->rootContext());
        object->setProperty("parent", QVariant::fromValue(management::canvas));
        QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);
    }
    else
        qDebug() << component->errorString();

    setX(50 + ((double)rand()/(double)(RAND_MAX)) * (management::canvasWidth - 100));
    setY(50 + ((double)rand()/(double)(RAND_MAX)) * (management::canvasHeight - 100));
}

boid::~boid() {
    delete component;
    delete object;
}

void boid::Update() {
    // Logic goes here
    qDebug() << "Update";
}
