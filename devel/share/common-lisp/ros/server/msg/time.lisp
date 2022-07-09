; Auto-generated. Do not edit!


(cl:in-package server-msg)


;//! \htmlinclude time.msg.html

(cl:defclass <time> (roslisp-msg-protocol:ros-message)
  ((sec
    :reader sec
    :initarg :sec
    :type cl:string
    :initform "")
   (name
    :reader name
    :initarg :name
    :type cl:string
    :initform ""))
)

(cl:defclass time (<time>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <time>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'time)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name server-msg:<time> is deprecated: use server-msg:time instead.")))

(cl:ensure-generic-function 'sec-val :lambda-list '(m))
(cl:defmethod sec-val ((m <time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader server-msg:sec-val is deprecated.  Use server-msg:sec instead.")
  (sec m))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <time>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader server-msg:name-val is deprecated.  Use server-msg:name instead.")
  (name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <time>) ostream)
  "Serializes a message object of type '<time>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'sec))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'sec))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <time>) istream)
  "Deserializes a message object of type '<time>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sec) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'sec) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<time>)))
  "Returns string type for a message object of type '<time>"
  "server/time")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'time)))
  "Returns string type for a message object of type 'time"
  "server/time")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<time>)))
  "Returns md5sum for a message object of type '<time>"
  "9fbfca278f613909c27792d3987b7cbf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'time)))
  "Returns md5sum for a message object of type 'time"
  "9fbfca278f613909c27792d3987b7cbf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<time>)))
  "Returns full string definition for message of type '<time>"
  (cl:format cl:nil "string sec~%string name~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'time)))
  "Returns full string definition for message of type 'time"
  (cl:format cl:nil "string sec~%string name~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <time>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'sec))
     4 (cl:length (cl:slot-value msg 'name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <time>))
  "Converts a ROS message object to a list"
  (cl:list 'time
    (cl:cons ':sec (sec msg))
    (cl:cons ':name (name msg))
))
