Notice: The program.exe file is only executable by Linux systems!!

--------------------------------------------------------

The device I have simulated is a refrigerator. 

What is the refrigerator made of? Is anything else made from the refrigerator or not? 

To find the answers to these questions, please read the following information.

---------------------------------------------------------

_ First, we have a base class named **Shapes**, from which two classes, **Box** and **Cylinder**, inherit directly. 
_ The **Handle** class inherits directly from the **Cylinder** class (the Handle refers to the refrigerator's handle).
_ The **WaterTank** and **Fridge** classes inherit directly from the **Box** class.
_ The **Fridge** class contains objects from the **WaterTank**, **Handle**, and **Box** classes within its body through composition, and these objects are also initialized.
_ All the mentioned classes have specific member functions. To see them, please refer to the main code file.
_ Additionally, the **SideBySide** class inherits from the **Fridge** class and, besides having its own specific data members, utilizes polymorphism for some of its functions.