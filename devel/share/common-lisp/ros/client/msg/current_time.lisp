; Auto-generated. Do not edit!


(cl:in-package client-msg)


;//! \htmlinclude current_time.msg.html

(cl:defclass <current_time> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (year
    :reader year
    :initarg :year
    :type cl:fixnum
    :initform 0)
   (month
    :reader month
    :initarg :month
    :type cl:fixnum
    :initform 0)
   (day
    :reader day
    :initarg :day
    :type cl:fixnum
    :initform 0)
   (hour
    :reader hour
    :initarg :hour
    :type cl:fixnum
    :initform 0)
   (minute
    :reader minute
    :initarg :minute
    :type cl:fixnum
    :initform 0)
   (second
    :reader second
    :initarg :second
    :type cl:fixnum
    :initform 0))
)

(cl:defclass current_time (<current_time>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <current_time>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'current_time)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name client-msg:<current_time> is deprecated: use client-msg:current_time instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <current_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-msg:name-val is deprecated.  Use client-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'year-val :lambda-list '(m))
(cl:defmethod year-val ((m <current_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-msg:year-val is deprecated.  Use client-msg:year instead.")
  (year m))

(cl:ensure-generic-function 'month-val :lambda-list '(m))
(cl:defmethod month-val ((m <current_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-msg:month-val is deprecated.  Use client-msg:month instead.")
  (month m))

(cl:ensure-generic-function 'day-val :lambda-list '(m))
(cl:defmethod day-val ((m <current_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-msg:day-val is deprecated.  Use client-msg:day instead.")
  (day m))

(cl:ensure-generic-function 'hour-val :lambda-list '(m))
(cl:defmethod hour-val ((m <current_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-msg:hour-val is deprecated.  Use client-msg:hour instead.")
  (hour m))

(cl:ensure-generic-function 'minute-val :lambda-list '(m))
(cl:defmethod minute-val ((m <current_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-msg:minute-val is deprecated.  Use client-msg:minute instead.")
  (minute m))

(cl:ensure-generic-function 'second-val :lambda-list '(m))
(cl:defmethod second-val ((m <current_time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader client-msg:second-val is deprecated.  Use client-msg:second instead.")
  (second m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <current_time>) ostream)
  "Serializes a message object of type '<current_time>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'year)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'month)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'day)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hour)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'minute)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'second)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <current_time>) istream)
  "Deserializes a message object of type '<current_time>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'year)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'month)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'day)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hour)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'minute)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'second)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<current_time>)))
  "Returns string type for a message object of type '<current_time>"
  "client/current_time")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'current_time)))
  "Returns string type for a message object of type 'current_time"
  "client/current_time")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<current_time>)))
  "Returns md5sum for a message object of type '<current_time>"
  "a6f5c81d6c9a9e6b4dd87b84cc2c41c6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'current_time)))
  "Returns md5sum for a message object of type 'current_time"
  "a6f5c81d6c9a9e6b4dd87b84cc2c41c6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<current_time>)))
  "Returns full string definition for message of type '<current_time>"
  (cl:format cl:nil "string name~%~%uint8 year~%uint8 month~%uint8 day~%~%uint8 hour~%uint8 minute~%uint8 second~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'current_time)))
  "Returns full string definition for message of type 'current_time"
  (cl:format cl:nil "string name~%~%uint8 year~%uint8 month~%uint8 day~%~%uint8 hour~%uint8 minute~%uint8 second~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <current_time>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <current_time>))
  "Converts a ROS message object to a list"
  (cl:list 'current_time
    (cl:cons ':name (name msg))
    (cl:cons ':year (year msg))
    (cl:cons ':month (month msg))
    (cl:cons ':day (day msg))
    (cl:cons ':hour (hour msg))
    (cl:cons ':minute (minute msg))
    (cl:cons ':second (second msg))
))
