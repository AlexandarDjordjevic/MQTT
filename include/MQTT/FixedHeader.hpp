/**
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once

#include <memory>

namespace MQTT
{
    enum class ControlType{
      Reserved = 0,
      CONNECT,
      CONNACK,
      PUBLISH,
      PUBACK,
      PUBREC,
      PUBREL,
      PUBCOMP,
      SUBSCRIBE,
      SUBACK,
      UNSUBSCRIBE,
      UNSUBACK,
      PINGREQ,
      PINGRESP,
      DISCONNECT
  };

  enum class ProtocolVersion : uint8_t
  {
      MQTT_3_1 = 0x03,
      MQTT_3_1_1 = 0x04
  };

  enum class QOS : uint8_t
  {
      QOS_0 = 0x00,
      QOS_1 = 0x01,
      QOS_2 = 0x02
  };   

  class FixedHeader{
  public:
    /**
     * @brief Default contstructor
     * 
     */
    FixedHeader();

    /**
     * @brief Default destructor
     * 
     */
    ~FixedHeader();

    FixedHeader(const FixedHeader &) = delete;
    FixedHeader &operator=(const FixedHeader &) = delete;
    FixedHeader(FixedHeader &&) = delete;
    FixedHeader &operator=(const FixedHeader &&) = delete;

    /**
     * @brief Get the packet control type
     * 
     * @return ControlType 
     */
    ControlType getControlType();

    /**
     * @brief Get the packet control type
     * 
     * @param ct 
     */
    void setControlType(ControlType ct);

    /**
     * @brief Get the Flags
     * 
     * @return uint8_t 
     */
    uint8_t getFlags();

    /**
     * @brief Set the Flags
     * 
     */
    void setFlags(uint8_t flags);

    /**
     * @brief Get the Remaining Length
     * 
     * @return size_t 
     */
    size_t getRemainingLength();

    /**
     * @brief Set the Remaining Length
     * 
     * @param remainingLen 
     */
    void setRemainingLength(const uint8_t* buffer);

    /**
     * @brief Get QOS
     * 
     * @return QOS 
     */
    QOS getQOS();

    /**
     * @brief Set QOS
     * 
     * @param qos 
     */
    void setQOS(QOS qos);

  private:
    struct impl;
    std::unique_ptr<impl> pimpl;
  };

} // namespace MQTT
