// Auto-generated. Do not edit!

// (in-package client.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class loginRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.req_code = null;
      this.node_name = null;
    }
    else {
      if (initObj.hasOwnProperty('req_code')) {
        this.req_code = initObj.req_code
      }
      else {
        this.req_code = 0;
      }
      if (initObj.hasOwnProperty('node_name')) {
        this.node_name = initObj.node_name
      }
      else {
        this.node_name = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type loginRequest
    // Serialize message field [req_code]
    bufferOffset = _serializer.uint16(obj.req_code, buffer, bufferOffset);
    // Serialize message field [node_name]
    bufferOffset = _serializer.string(obj.node_name, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type loginRequest
    let len;
    let data = new loginRequest(null);
    // Deserialize message field [req_code]
    data.req_code = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [node_name]
    data.node_name = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.node_name.length;
    return length + 6;
  }

  static datatype() {
    // Returns string type for a service object
    return 'client/loginRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '493479b65998b0b2b28fbe4e963ea7e6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint16 req_code
    string node_name
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new loginRequest(null);
    if (msg.req_code !== undefined) {
      resolved.req_code = msg.req_code;
    }
    else {
      resolved.req_code = 0
    }

    if (msg.node_name !== undefined) {
      resolved.node_name = msg.node_name;
    }
    else {
      resolved.node_name = ''
    }

    return resolved;
    }
};

class loginResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ack_code = null;
    }
    else {
      if (initObj.hasOwnProperty('ack_code')) {
        this.ack_code = initObj.ack_code
      }
      else {
        this.ack_code = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type loginResponse
    // Serialize message field [ack_code]
    bufferOffset = _serializer.uint16(obj.ack_code, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type loginResponse
    let len;
    let data = new loginResponse(null);
    // Deserialize message field [ack_code]
    data.ack_code = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a service object
    return 'client/loginResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7f47bb5ecdb3f7ca57312d7a1a86406b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint16 ack_code
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new loginResponse(null);
    if (msg.ack_code !== undefined) {
      resolved.ack_code = msg.ack_code;
    }
    else {
      resolved.ack_code = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: loginRequest,
  Response: loginResponse,
  md5sum() { return 'ec021ca287a263e3d68ad93e1193a7d9'; },
  datatype() { return 'client/login'; }
};
