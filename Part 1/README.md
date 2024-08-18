<h1>Report for Step 3, Part 1</h1>
    <ul>
        <li>A) The clock cycles increased as I allocated more memory for my shapes, while maintaining the same number of Insert and Remove function calls.</li>
        <li>Test Outcomes:</li>
        <ul>
            <li>-- Allocating 1 kilobyte of memory for shapes resulted in:</li>
            <ul>
                <li>Insert time duration: 7553 clock cycles</li>
                <li>Remove time duration: 9722 clock cycles</li>
            </ul>
            <li>-- Allocating 100 megabytes of memory for shapes resulted in:</li>
            <ul>
                <li>Insert time duration: 32032 clock cycles</li>
                <li>Remove time duration: 26321 clock cycles</li>
            </ul>
        </ul>
        <li>B) Additionally, the clock cycles increased as I executed more Insert and Remove functions on my main vector, which contains the shapes, while keeping the allocated memory constant at 100 megabytes.</li>
        <li>Test Outcomes:</li>
        <ul>
            <li>-- Performing 5 Insert and 5 Remove functions:</li>
            <ul>
                <li>Insert time duration: 6289 clock cycles</li>
                <li>Remove time duration: 12900 clock cycles</li>
            </ul>
            <li>-- Performing 50 Insert and 50 Remove functions:</li>
            <ul>
                <li>Insert time duration: 85189 clock cycles</li>
                <li>Remove time duration: 118056 clock cycles</li>
            </ul>
        </ul>
        <li>C) The clock cycles also increased with the number of shapes in my main vector.</li>
        <li>D) It is essential to recognize that the number of clock cycles is affected by the specific implementation of the Insert and Remove operations. If these functions involve more console output, the time required to complete the tasks will increase.</li>
    </ul>
    <hr>
    <h1>Report for Step 5, Part 1</h1>
    <ul>
        <li>Surprisingly, the number of clock cycles decreased significantly!</li>
        <li>Comparison Between Previous and New Vectors:</li>
        <ul>
            <li>-- Using previous vector:</li>
            <ul>
                <li>Insert time duration: 7157 clocks</li>
                <li>Remove time duration: 10083 clocks</li>
            </ul>
            <li>-- Using vector pointer instead:</li>
            <ul>
                <li>Insert time duration: 60 clocks</li>
                <li>Remove time duration: 34 clocks</li>
            </ul>
        </ul>
        <li>Therefore, using vector pointers significantly reduces processing time by allowing us to work with references instead of making copies of the data. In summary, vector pointers optimize both time efficiency and memory usage, making them a better choice for frequent data modifications.</li>
    </ul>

