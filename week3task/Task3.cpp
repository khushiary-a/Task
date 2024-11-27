// Event Handling System for Touchscreen Input
// Objective: Simulate an event-driven system for processing touchscreen inputs on an HMI.
// Requirements:
// Create an Event class to represent user interactions:
// Attributes: eventType (e.g., Tap, Swipe), x and y coordinates, and timestamp.
// Implement an event queue using std::queue:
// Store multiple events.
// Process events one by one.
// Handle specific events:
// Tap: Display a message showing the tapped position.
// Swipe: Calculate the swipe direction (up/down/left/right) and display it.
// Simulate event generation:
// Populate the queue with random events.
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <chrono>
 
class Event {
public:
    std::string eventType;
    int x, y;
 
    Event(const std::string& type, int xCoord, int yCoord)
        : eventType(type), x(xCoord), y(yCoord) {}
};
 
void processEvents(std::queue<Event>& events) {
    while (!events.empty()) {
        Event event = events.front();
        events.pop();
 
        if (event.eventType == "Tap") {
            std::cout << "Tap Event at (" << event.x << ", " << event.y << ")\n";
        } else if (event.eventType == "Swipe") {
            std::cout << "Swipe Event detected: Start (" << event.x << ", " << event.y << ")\n";
        }
    }
}
 
int main() {
    std::queue<Event> eventQueue;
 
    eventQueue.push(Event("Tap", 50, 100));
    eventQueue.push(Event("Swipe", 10, 20));
 
    processEvents(eventQueue);
    return 0;
}