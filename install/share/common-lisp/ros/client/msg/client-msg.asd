
(cl:in-package :asdf)

(defsystem "client-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "current_time" :depends-on ("_package_current_time"))
    (:file "_package_current_time" :depends-on ("_package"))
  ))