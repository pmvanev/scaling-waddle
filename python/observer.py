"""
Abstract Parent classes to implement the Observer Pattern.
An Observable is watch by one or more Observers.
When the Observable changes, it notifies the Observers by
calling their notify() method with a list of the changes.
"""

class Observable(object):

    def __init__(self):
        self.observers = []

    def notifyObservers(self, changes=[]):
        for observer in self.observers:
            observer.notify(changes)

    def addObserver(self, observer):
        self.observers.append(observer)

    def removeObserver(self, observer):
        self.observers.remove(observer)


class Observer(object):

    def __init__(self, observable):
        observable.addObserver(self)

    def notify(self, changes=[]):
        pass
