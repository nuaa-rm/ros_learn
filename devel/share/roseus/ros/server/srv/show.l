;; Auto-generated. Do not edit!


(when (boundp 'server::show)
  (if (not (find-package "SERVER"))
    (make-package "SERVER"))
  (shadow 'show (find-package "SERVER")))
(unless (find-package "SERVER::SHOW")
  (make-package "SERVER::SHOW"))
(unless (find-package "SERVER::SHOWREQUEST")
  (make-package "SERVER::SHOWREQUEST"))
(unless (find-package "SERVER::SHOWRESPONSE")
  (make-package "SERVER::SHOWRESPONSE"))

(in-package "ROS")





(defclass server::showRequest
  :super ros::object
  :slots (_request _node_name ))

(defmethod server::showRequest
  (:init
   (&key
    ((:request __request) 0)
    ((:node_name __node_name) "")
    )
   (send-super :init)
   (setq _request (round __request))
   (setq _node_name (string __node_name))
   self)
  (:request
   (&optional __request)
   (if __request (setq _request __request)) _request)
  (:node_name
   (&optional __node_name)
   (if __node_name (setq _node_name __node_name)) _node_name)
  (:serialization-length
   ()
   (+
    ;; uint8 _request
    1
    ;; string _node_name
    4 (length _node_name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _request
       (write-byte _request s)
     ;; string _node_name
       (write-long (length _node_name) s) (princ _node_name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _request
     (setq _request (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; string _node_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _node_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass server::showResponse
  :super ros::object
  :slots (_response ))

(defmethod server::showResponse
  (:init
   (&key
    ((:response __response) 0)
    )
   (send-super :init)
   (setq _response (round __response))
   self)
  (:response
   (&optional __response)
   (if __response (setq _response __response)) _response)
  (:serialization-length
   ()
   (+
    ;; uint8 _response
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _response
       (write-byte _response s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _response
     (setq _response (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass server::show
  :super ros::object
  :slots ())

(setf (get server::show :md5sum-) "cfe71d70b666fd27790ae59c4609bc1d")
(setf (get server::show :datatype-) "server/show")
(setf (get server::show :request) server::showRequest)
(setf (get server::show :response) server::showResponse)

(defmethod server::showRequest
  (:response () (instance server::showResponse :init)))

(setf (get server::showRequest :md5sum-) "cfe71d70b666fd27790ae59c4609bc1d")
(setf (get server::showRequest :datatype-) "server/showRequest")
(setf (get server::showRequest :definition-)
      "uint8 request
string node_name
---
uint8 response

")

(setf (get server::showResponse :md5sum-) "cfe71d70b666fd27790ae59c4609bc1d")
(setf (get server::showResponse :datatype-) "server/showResponse")
(setf (get server::showResponse :definition-)
      "uint8 request
string node_name
---
uint8 response

")



(provide :server/show "cfe71d70b666fd27790ae59c4609bc1d")


