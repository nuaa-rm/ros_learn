;; Auto-generated. Do not edit!


(when (boundp 'server::time)
  (if (not (find-package "SERVER"))
    (make-package "SERVER"))
  (shadow 'time (find-package "SERVER")))
(unless (find-package "SERVER::TIME")
  (make-package "SERVER::TIME"))

(in-package "ROS")
;;//! \htmlinclude time.msg.html


(defclass server::time
  :super ros::object
  :slots (_sec _name ))

(defmethod server::time
  (:init
   (&key
    ((:sec __sec) "")
    ((:name __name) "")
    )
   (send-super :init)
   (setq _sec (string __sec))
   (setq _name (string __name))
   self)
  (:sec
   (&optional __sec)
   (if __sec (setq _sec __sec)) _sec)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:serialization-length
   ()
   (+
    ;; string _sec
    4 (length _sec)
    ;; string _name
    4 (length _name)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _sec
       (write-long (length _sec) s) (princ _sec s)
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _sec
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _sec (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get server::time :md5sum-) "9fbfca278f613909c27792d3987b7cbf")
(setf (get server::time :datatype-) "server/time")
(setf (get server::time :definition-)
      "string sec
string name
")



(provide :server/time "9fbfca278f613909c27792d3987b7cbf")


