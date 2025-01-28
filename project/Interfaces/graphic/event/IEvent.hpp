/**
 * @ Author: Perry Chouteau
 * @ Create Time: 2024-05-13 00:01:34
 * @ Modified by: Perry Chouteau
 * @ Modified time: 2025-01-28 00:29:03
 * @ Description:
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
