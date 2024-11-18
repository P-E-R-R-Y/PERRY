# IN PROGRESS

# P.E.R.R.Y.

## Description

This project is a engine, and the goal is to build it like, it will be able to use any library like (sfml/raylib..) to build an app/game.

For Epitech guys who have work on some project knows as Arcade,Rtype, I want to combine all those projects to build the engine who can help you make all your C/CPP software project in 2days. (it's based on cpp)

## Info

<table>
  <tr>
    <th>Author</th>
    <th colspan="2">Document status</th>
  </tr>
  <tr>
    <td>Perry Chouteau +Help of friends</td>
    <td colspan="2">En cours</td>
  </tr>
</table>

## History

| Date       | Author         | Purpose |
|------------|--------------- | - |
| 07/03/2023 | Perry Chouteau | basics of the document |
| 10/03/2023 | Perry Chouteau | add a lot of Parts & sub-parts |
| 14/03/2023 | Perry Chouteau | add a link to dev & setup markdown |
| 18/03/2023 | Perry Chouteau | update summary |
| 22/04/2024 | Perry Chouteau | will try to update with news update & vision of the project |
| 22/04/2024 | Perry Chouteau | updating to the 2024 vision of the project. |

# Summary

- [x] [PERRY](#perry-1)
  - [x] [Project](#project)
  - [x] [Engine](#engine)
  - [x] [Runtime](#runtime)
  - [x] [Reliable](#reliable)
  - [x] [YAML](#Yaml)

- [ ] [Plan](#plan-daction)

- [ ] [Engine](#engine-1)
  - [ ] [ECS](#ecs-entity-component-system)
  - [ ] [CBD](#cbd-component-based-design)

- Module
  - Graphics3
  - Graphics2
  - ...

- [ ] [Graphic3](#multimedia)
  - [x] [Window](#window)
    - [x] [Window](#window-1)
    - [ ] [Event](#event)
    - [x] [Camera](#camera)
  - [ ] [Graphic](#graphics)
    - [ ] [Model2](#model2)
    - [ ] [Model3](#model3)
    - [ ] [Text](#text)
  - [ ] [Audio](#audio)
    - [ ] [Sound](#sound)
    - [ ] [Music](#music)

- [ ] [CrossPlateform](#crossplateform)
  - [ ] [Plateform](#plateform)
  - [ ] [Type](#type)

- [x] [About](#about)
  - [x] [Developer](#developer)
  - [x] [Setup](#setup)

# PERRY

## Project

I want to build a engine, with a lot of specs. It will implement cross-platform, network udp/tcp, multimedia library (abstraction, replication, ), game engine,

## Engine

My goal is to build the reliable project I ever made combining everything I learn & everything I want to understand better..

## Runtime

My goal should be to implement runtime loading function.
to run a library a game as an arcade gameplay using my ecs I want to make any game possible to build.

## Reliable

My project should be the most stable possible

## YAML

I want to use .yml to setup the library.

# Plan d'Action

- [x] POC
  - [x] Build an interface of a multimedia library
    - [x] IWindow Basics
  - [x] Build an encapsulation of libraries
    - [x] SfmlWindow Basics
    - [x] RaylibWindow Basics
    - [x] SDLWindow Basics
    - [ ] LibCacaWindow Basics (Not need for now)
  - [x] Build it dynamically
  - [x] Build Core
    - [x] Handle IMultimediaCore
    - [x] Handle IGameCore
    - [x] Switch library at runtime
    - [x] Build simple IGameCore
    - [ ] Build a Game.
    - [x] Build combination of simple GameCore & simple MultimediaCore 
- [ ] Poc V2
  - [x] Stop being tired of working of big stuff
  - [ ] Handle 2d
    - [x] Handle Image
    - [ ] Handle 2d simple polygone
    - [ ] Handle transformation
  - [x] Handle 3d
    - [x] Handle Model(Cube but you could just avoid using 3d and define unimplemented on your library encaps..)
    - [ ] need to Upgrade to real model.
  - [x] Handle Event
    - [x] Sdl
    - [x] Sfml
    - [x] Raylib
- [ ] MVP (push to later)
  - [ ] Make it cross plateform
- [ ] Release
  - [ ] Make it work on 32/64 & inversed bite type.
- [ ]

# Engine

## ECS (entity component system)

This engine will implement the ECS from rtype with my add-ons.

## CBD (component based design)

I want to add a cbd system over the ECS. but I'm not realy sure about that.

# Module
- engine
- graphics2
- graphics3
- Window
- network
- json
- audio
- physics (math)
- ...
- ide

# Graphic3

## Window

handle a simple window

## Event

handle simple event

## Camera

## Graphics

## Model2

## Model3

## Text

# Audio2

# Long
- Music
# Small
- Sound

# About

## Developer

Firstly it's a personal work but in the future if I work with other devs, you should check this [Developer.md](docs/Developer.md).

## Setup

Secondly if you want to install the library to build your game you should folow this [Setup.md](docs/Setup.md)

## known libs
https://en.cppreference.com/w/c/links/libs


## Credits (Thanks for feeding my brains with features)
 
- Malek Gatoufi
- [0xMemoryGrinder](https://github.com/0xMemoryGrinder) 
- [Matis Dalleau](https://github.com/HelifeWasTaken)
