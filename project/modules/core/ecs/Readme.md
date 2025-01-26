# ECS

## Description

## Component

They define characterisitics of Entities, for example: **Position(x, y)**, **Velocities(x,y)**, **Controllable(bool)**, **Collidable(bool)** or **Renderable(path)**  

# Entity

They define object, and can contain Components.

# System

System are function that update/edit values example:  **MoveSystem() { Positions += Velocities};**