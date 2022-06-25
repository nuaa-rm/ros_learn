;; Auto-generated. Do not edit!


(when (boundp 'client::current_time)
  (if (not (find-package "CLIENT"))
    (make-package "CLIENT"))
  (shadow 'current_time (find-package "CLIENT")))
(unless (find-package "CLIENT::CURRENT_TIME")
  (make-package "CLIENT::CURRENT_TIME"))

(in-package "ROS")
;;//! \htmlinclude current_time.msg.html


(defclass client::current_time
  :super ros::object
  :slots (_name _year _month _day _hour _minute _second ))

(defmethod client::current_time
  (:init
   (&key
    ((:name __name) "")
    ((:year __year) 0)
    ((:month __month) 0)
    ((:day __day) 0)
    ((:hour __hour) 0)
    ((:minute __minute) 0)
    ((:second __second) 0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _year (round __year))
   (setq _month (round __month))
   (setq _day (round __day))
   (setq _hour (round __hour))
   (setq _minute (round __minute))
   (setq _second (round __second))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:year
   (&optional __year)
   (if __year (setq _year __year)) _year)
  (:month
   (&optional __month)
   (if __month (setq _month __month)) _month)
  (:day
   (&optional __day)
   (if __day (setq _day __day)) _day)
  (:hour
   (&optional __hour)
   (if __hour (setq _hour __hour)) _hour)
  (:minute
   (&optional __minute)
   (if __minute (setq _minute __minute)) _minute)
  (:second
   (&optional __second)
   (if __second (setq _second __second)) _second)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint8 _year
    1
    ;; uint8 _month
    1
    ;; uint8 _day
    1
    ;; uint8 _hour
    1
    ;; uint8 _minute
    1
    ;; uint8 _second
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _year
       (write-byte _year s)
     ;; uint8 _month
       (write-byte _month s)
     ;; uint8 _day
       (write-byte _day s)
     ;; uint8 _hour
       (write-byte _hour s)
     ;; uint8 _minute
       (write-byte _minute s)
     ;; uint8 _second
       (write-byte _second s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _year
     (setq _year (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _month
     (setq _month (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _day
     (setq _day (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _hour
     (setq _hour (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _minute
     (setq _minute (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _second
     (setq _second (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get client::current_time :md5sum-) "a6f5c81d6c9a9e6b4dd87b84cc2c41c6")
(setf (get client::current_time :datatype-) "client/current_time")
(setf (get client::current_time :definition-)
      "string name

uint8 year
uint8 month
uint8 day

uint8 hour
uint8 minute
uint8 second
")



(provide :client/current_time "a6f5c81d6c9a9e6b4dd87b84cc2c41c6")


