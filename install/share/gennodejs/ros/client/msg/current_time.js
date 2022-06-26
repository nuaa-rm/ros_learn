// Auto-generated. Do not edit!

// (in-package client.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class current_time {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.name = null;
      this.year = null;
      this.month = null;
      this.day = null;
      this.hour = null;
      this.minute = null;
      this.second = null;
    }
    else {
      if (initObj.hasOwnProperty('name')) {
        this.name = initObj.name
      }
      else {
        this.name = '';
      }
      if (initObj.hasOwnProperty('year')) {
        this.year = initObj.year
      }
      else {
        this.year = 0;
      }
      if (initObj.hasOwnProperty('month')) {
        this.month = initObj.month
      }
      else {
        this.month = 0;
      }
      if (initObj.hasOwnProperty('day')) {
        this.day = initObj.day
      }
      else {
        this.day = 0;
      }
      if (initObj.hasOwnProperty('hour')) {
        this.hour = initObj.hour
      }
      else {
        this.hour = 0;
      }
      if (initObj.hasOwnProperty('minute')) {
        this.minute = initObj.minute
      }
      else {
        this.minute = 0;
      }
      if (initObj.hasOwnProperty('second')) {
        this.second = initObj.second
      }
      else {
        this.second = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type current_time
    // Serialize message field [name]
    bufferOffset = _serializer.string(obj.name, buffer, bufferOffset);
    // Serialize message field [year]
    bufferOffset = _serializer.uint16(obj.year, buffer, bufferOffset);
    // Serialize message field [month]
    bufferOffset = _serializer.uint16(obj.month, buffer, bufferOffset);
    // Serialize message field [day]
    bufferOffset = _serializer.uint16(obj.day, buffer, bufferOffset);
    // Serialize message field [hour]
    bufferOffset = _serializer.uint16(obj.hour, buffer, bufferOffset);
    // Serialize message field [minute]
    bufferOffset = _serializer.uint16(obj.minute, buffer, bufferOffset);
    // Serialize message field [second]
    bufferOffset = _serializer.uint16(obj.second, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type current_time
    let len;
    let data = new current_time(null);
    // Deserialize message field [name]
    data.name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [year]
    data.year = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [month]
    data.month = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [day]
    data.day = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [hour]
    data.hour = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [minute]
    data.minute = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [second]
    data.second = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.name.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'client/current_time';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f8c079afbf79a38ac7d2176ca422dbdb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string name
    
    uint16 year
    uint16 month
    uint16 day
    
    uint16 hour
    uint16 minute
    uint16 second
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new current_time(null);
    if (msg.name !== undefined) {
      resolved.name = msg.name;
    }
    else {
      resolved.name = ''
    }

    if (msg.year !== undefined) {
      resolved.year = msg.year;
    }
    else {
      resolved.year = 0
    }

    if (msg.month !== undefined) {
      resolved.month = msg.month;
    }
    else {
      resolved.month = 0
    }

    if (msg.day !== undefined) {
      resolved.day = msg.day;
    }
    else {
      resolved.day = 0
    }

    if (msg.hour !== undefined) {
      resolved.hour = msg.hour;
    }
    else {
      resolved.hour = 0
    }

    if (msg.minute !== undefined) {
      resolved.minute = msg.minute;
    }
    else {
      resolved.minute = 0
    }

    if (msg.second !== undefined) {
      resolved.second = msg.second;
    }
    else {
      resolved.second = 0
    }

    return resolved;
    }
};

module.exports = current_time;
