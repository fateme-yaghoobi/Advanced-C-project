<h1>Refrigerator Simulation</h1>
    <p>The device I have simulated is a refrigerator.</p>
    <p>What is the refrigerator made of? Is anything else made from the refrigerator or not?</p>
    <p>To find the answers to these questions, please read the following information.</p>
    <ul>
        <li>First, we have a base class named <strong>Shapes</strong>, from which two classes, <strong >Box</strong> and <strong>Cylinder</strong>, inherit directly.</li>
        <li>The <strong>Handle</strong> class inherits directly from the <strong>Cylinder</strong> class (the Handle refers to the refrigerator's handle).</li>
        <li>The <strong>WaterTank</strong> and <strong>Fridge</strong> classes inherit directly from the <strong>Box</strong> class.</li>
        <li>The <strong>Fridge</strong> class contains objects from the <strong>WaterTank</strong>, <strong>Handle</strong>, and <strong>Box</strong> classes within its body through composition, and these objects are also initialized.</li>
        <li>All the mentioned classes have specific member functions. To see them, please refer to the main code file.</li>
        <li>Additionally, the <strong>SideBySide</strong> class inherits from the <strong>Fridge</strong> class and, besides having its own specific data members, uses polymorphism for some of its functions.</li>
    </ul>
