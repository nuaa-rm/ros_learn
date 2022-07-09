
(cl:in-package :asdf)

(defsystem "client-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "show" :depends-on ("_package_show"))
    (:file "_package_show" :depends-on ("_package"))
  ))