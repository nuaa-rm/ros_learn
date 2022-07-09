; Auto-generated. Do not edit!


(cl:in-package client-srv)


;//! \htmlinclude show-request.msg.html

(cl:defclass <show-request> (roslisp-msg-protocol:ros-message)
  ((request
    :reader request
    :initarg :request
    :type cl:fixnum
    :initform 0)
   (node_name
    :reader node_name
    :initarg :node_name
    :type cl:string
    :initform ""))
)

(cl:defclass show-request (<show-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <show-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'show-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name client-srv:<show-request> is deprecated: use client-srv:show-request instead.")))

(cl:ensure-generic-function 'request-val :lambda-list '(m))
(cl:defmethod request-val ((m <show-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-srv:request-val is deprecated.  Use client-srv:request instead.")
  (request m))

(cl:ensure-generic-function 'node_name-val :lambda-list '(m))
(cl:defmethod node_name-val ((m <show-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-srv:node_name-val is deprecated.  Use client-srv:node_name instead.")
  (node_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <show-request>) ostream)
  "Serializes a message object of type '<show-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'request)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'node_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'node_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <show-request>) istream)
  "Deserializes a message object of type '<show-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'request)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'node_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'node_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<show-request>)))
  "Returns string type for a service object of type '<show-request>"
  "client/showRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'show-request)))
  "Returns string type for a service object of type 'show-request"
  "client/showRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<show-request>)))
  "Returns md5sum for a message object of type '<show-request>"
  "cfe71d70b666fd27790ae59c4609bc1d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'show-request)))
  "Returns md5sum for a message object of type 'show-request"
  "cfe71d70b666fd27790ae59c4609bc1d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<show-request>)))
  "Returns full string definition for message of type '<show-request>"
  (cl:format cl:nil "uint8 request~%string node_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'show-request)))
  "Returns full string definition for message of type 'show-request"
  (cl:format cl:nil "uint8 request~%string node_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <show-request>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'node_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <show-request>))
  "Converts a ROS message object to a list"
  (cl:list 'show-request
    (cl:cons ':request (request msg))
    (cl:cons ':node_name (node_name msg))
))
;//! \htmlinclude show-response.msg.html

(cl:defclass <show-response> (roslisp-msg-protocol:ros-message)
  ((response
    :reader response
    :initarg :response
    :type cl:fixnum
    :initform 0))
)

(cl:defclass show-response (<show-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <show-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'show-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name client-srv:<show-response> is deprecated: use client-srv:show-response instead.")))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <show-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-srv:response-val is deprecated.  Use client-srv:response instead.")
  (response m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <show-response>) ostream)
  "Serializes a message object of type '<show-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'response)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <show-response>) istream)
  "Deserializes a message object of type '<show-response>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'response)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<show-response>)))
  "Returns string type for a service object of type '<show-response>"
  "client/showResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'show-response)))
  "Returns string type for a service object of type 'show-response"
  "client/showResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<show-response>)))
  "Returns md5sum for a message object of type '<show-response>"
  "cfe71d70b666fd27790ae59c4609bc1d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'show-response)))
  "Returns md5sum for a message object of type 'show-response"
  "cfe71d70b666fd27790ae59c4609bc1d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<show-response>)))
  "Returns full string definition for message of type '<show-response>"
  (cl:format cl:nil "uint8 response~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'show-response)))
  "Returns full string definition for message of type 'show-response"
  (cl:format cl:nil "uint8 response~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <show-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <show-response>))
  "Converts a ROS message object to a list"
  (cl:list 'show-response
    (cl:cons ':response (response msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'show)))
  'show-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'show)))
  'show-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'show)))
  "Returns string type for a service object of type '<show>"
  "client/show")