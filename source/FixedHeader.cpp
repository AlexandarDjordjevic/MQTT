#include <MQTT/FixedHeader.hpp>
#include <math.h>

namespace MQTT{
  /**
   * @brief Pimpl implementation
   * 
   */
  struct FixedHeader::impl{
    ControlType controlType;
    size_t headerRemainingLength;
    uint8_t flags;
    uint8_t remainingLength;
    QOS qos;
  };

  FixedHeader::FixedHeader()
    : pimpl(new FixedHeader::impl())
  {

  }
  
  ControlType FixedHeader::getControlType(){
    return pimpl->controlType;
  }
  
  void FixedHeader::setControlType(ControlType controlType){
    pimpl->controlType = controlType;    
  }
  
  uint8_t FixedHeader::getFlags(){
    return pimpl->flags;
  }
  
  void FixedHeader::setFlags(uint8_t flags){
    pimpl->flags = flags;
  }
  
  size_t FixedHeader::getRemainingLength() 
  {
    return pimpl->headerRemainingLength;
  }
  
  void FixedHeader::setRemainingLength(const uint8_t* buffer) 
  {
    auto offset = 0;
    do{
      pimpl->headerRemainingLength += (*(buffer + offset) & 0x7f) * pow(128, offset);
    }while(( (*(buffer + offset) & 0x80) == 0x80) && 3 > offset++);
  }
  
  QOS FixedHeader::getQOS() 
  {
    return pimpl->qos;
  }
  
  void FixedHeader::setQOS(QOS qos) 
  {
    pimpl->qos = qos;
  }

  FixedHeader::~FixedHeader(){

  }



}//namespace MQTT