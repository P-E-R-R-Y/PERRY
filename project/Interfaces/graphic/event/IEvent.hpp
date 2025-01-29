/**
 * @file IEvent.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * @addtogroup graphic
 * @{
 */

#ifndef IEVENT_HPP
#define IEVENT_HPP

namespace graphic {

  /**
   * @brief Event interface
   * @interface IEvent
   */
  class IEvent {
    public:
      virtual ~IEvent() = default;
  };

}

#endif // IEVENT_HPP
