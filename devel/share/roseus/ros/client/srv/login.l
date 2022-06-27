;; Auto-generated. Do not edit!


(when (boundp 'client::login)
  (if (not (find-package "CLIENT"))
    (make-package "CLIENT"))
  (shadow 'login (find-package "CLIENT")))
(unless (find-package "CLIENT::LOGIN")
  (make-package "CLIENT::LOGIN"))
(unless (find-package "CLIENT::LOGINREQUEST")
  (make-package "CLIENT::LOGINREQUEST"))
(unless (find-package "CLIENT::LOGINRESPONSE")
  (make-package "CLIENT::LOGINRESPONSE"))

(in-package "ROS")





(defclass client::loginRequest
  :super ros::object
  :slots (_req_code _node_name ))

(defmethod client::loginRequest
  (:init
   (&key
    ((:req_code __req_code) 0)
    ((:node_name __node_name) "")
    )
   (send-super :init)
   (setq _req_code (round __req_code))
   (setq _node_name (string __node_name))
   self)
  (:req_code
   (&optional __req_code)
   (if __req_code (setq _req_code __req_code)) _req_code)
  (:node_name
   (&optional __node_name)
   (if __node_name (setq _node_name __node_name)) _node_name)
  (:serialization-length
   ()
   (+
    ;; uint16 _req_code
    2
    ;; string _node_name
    4 (length _node_name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _req_code
       (write-word _req_code s)
     ;; string _node_name
       (write-long (length _node_name) s) (princ _node_name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _req_code
     (setq _req_code (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; string _node_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _node_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass client::loginResponse
  :super ros::object
  :slots (_ack_code ))

(defmethod client::loginResponse
  (:init
   (&key
    ((:ack_code __ack_code) 0)
    )
   (send-super :init)
   (setq _ack_code (round __ack_code))
   self)
  (:ack_code
   (&optional __ack_code)
   (if __ack_code (setq _ack_code __ack_code)) _ack_code)
  (:serialization-length
   ()
   (+
    ;; uint16 _ack_code
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _ack_code
       (write-word _ack_code s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _ack_code
     (setq _ack_code (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass client::login
  :super ros::object
  :slots ())

(setf (get client::login :md5sum-) "ec021ca287a263e3d68ad93e1193a7d9")
(setf (get client::login :datatype-) "client/login")
(setf (get client::login :request) client::loginRequest)
(setf (get client::login :response) client::loginResponse)

(defmethod client::loginRequest
  (:response () (instance client::loginResponse :init)))

(setf (get client::loginRequest :md5sum-) "ec021ca287a263e3d68ad93e1193a7d9")
(setf (get client::loginRequest :datatype-) "client/loginRequest")
(setf (get client::loginRequest :definition-)
      "uint16 req_code
string node_name
---
uint16 ack_code
")

(setf (get client::loginResponse :md5sum-) "ec021ca287a263e3d68ad93e1193a7d9")
(setf (get client::loginResponse :datatype-) "client/loginResponse")
(setf (get client::loginResponse :definition-)
      "uint16 req_code
string node_name
---
uint16 ack_code
")



(provide :client/login "ec021ca287a263e3d68ad93e1193a7d9")


