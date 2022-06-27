
(cl:in-package :asdf)

(defsystem "client-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "login" :depends-on ("_package_login"))
    (:file "_package_login" :depends-on ("_package"))
  ))