; Auto-generated. Do not edit!


(cl:in-package client-srv)


;//! \htmlinclude login-request.msg.html

(cl:defclass <login-request> (roslisp-msg-protocol:ros-message)
  ((req_code
    :reader req_code
    :initarg :req_code
    :type cl:fixnum
    :initform 0)
   (node_name
    :reader node_name
    :initarg :node_name
    :type cl:string
    :initform ""))
)

(cl:defclass login-request (<login-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <login-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'login-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name client-srv:<login-request> is deprecated: use client-srv:login-request instead.")))

(cl:ensure-generic-function 'req_code-val :lambda-list '(m))
(cl:defmethod req_code-val ((m <login-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-srv:req_code-val is deprecated.  Use client-srv:req_code instead.")
  (req_code m))

(cl:ensure-generic-function 'node_name-val :lambda-list '(m))
(cl:defmethod node_name-val ((m <login-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-srv:node_name-val is deprecated.  Use client-srv:node_name instead.")
  (node_name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <login-request>) ostream)
  "Serializes a message object of type '<login-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'req_code)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'req_code)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'node_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'node_name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <login-request>) istream)
  "Deserializes a message object of type '<login-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'req_code)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'req_code)) (cl:read-byte istream))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<login-request>)))
  "Returns string type for a service object of type '<login-request>"
  "client/loginRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'login-request)))
  "Returns string type for a service object of type 'login-request"
  "client/loginRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<login-request>)))
  "Returns md5sum for a message object of type '<login-request>"
  "ec021ca287a263e3d68ad93e1193a7d9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'login-request)))
  "Returns md5sum for a message object of type 'login-request"
  "ec021ca287a263e3d68ad93e1193a7d9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<login-request>)))
  "Returns full string definition for message of type '<login-request>"
  (cl:format cl:nil "uint16 req_code~%string node_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'login-request)))
  "Returns full string definition for message of type 'login-request"
  (cl:format cl:nil "uint16 req_code~%string node_name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <login-request>))
  (cl:+ 0
     2
     4 (cl:length (cl:slot-value msg 'node_name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <login-request>))
  "Converts a ROS message object to a list"
  (cl:list 'login-request
    (cl:cons ':req_code (req_code msg))
    (cl:cons ':node_name (node_name msg))
))
;//! \htmlinclude login-response.msg.html

(cl:defclass <login-response> (roslisp-msg-protocol:ros-message)
  ((ack_code
    :reader ack_code
    :initarg :ack_code
    :type cl:fixnum
    :initform 0))
)

(cl:defclass login-response (<login-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <login-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'login-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name client-srv:<login-response> is deprecated: use client-srv:login-response instead.")))

(cl:ensure-generic-function 'ack_code-val :lambda-list '(m))
(cl:defmethod ack_code-val ((m <login-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-srv:ack_code-val is deprecated.  Use client-srv:ack_code instead.")
  (ack_code m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <login-response>) ostream)
  "Serializes a message object of type '<login-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ack_code)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ack_code)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <login-response>) istream)
  "Deserializes a message object of type '<login-response>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ack_code)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ack_code)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<login-response>)))
  "Returns string type for a service object of type '<login-response>"
  "client/loginResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'login-response)))
  "Returns string type for a service object of type 'login-response"
  "client/loginResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<login-response>)))
  "Returns md5sum for a message object of type '<login-response>"
  "ec021ca287a263e3d68ad93e1193a7d9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'login-response)))
  "Returns md5sum for a message object of type 'login-response"
  "ec021ca287a263e3d68ad93e1193a7d9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<login-response>)))
  "Returns full string definition for message of type '<login-response>"
  (cl:format cl:nil "uint16 ack_code~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'login-response)))
  "Returns full string definition for message of type 'login-response"
  (cl:format cl:nil "uint16 ack_code~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <login-response>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <login-response>))
  "Converts a ROS message object to a list"
  (cl:list 'login-response
    (cl:cons ':ack_code (ack_code msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'login)))
  'login-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'login)))
  'login-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'login)))
  "Returns string type for a service object of type '<login>"
  "client/login")