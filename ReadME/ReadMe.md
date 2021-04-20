How to run and complie and test it:

    In order to run this application, you should compile the Controller.cpp file only, and you will interact with this delivery application by typing the command in the terminal, and this application will also provide some Prompts of what should you type in this application, a demo process of this application will be showed below.

    1. The user will be Prompted to type the length of the Map, you should type an integer to it, the size of it should be less than 2000 and greater than 10.

    2. After finishing the initialization of the map, you should type the manufacturers' name which located in this city. Remember that the name is unique for each manufacturer, the user should not use the same name(string type) twice. And if you want to terminate it just type 'quit' when the system require you to type the name.
    (BE CAREFUL: the name should not contain space,tab, and '-' in it, namely, follow the C++ variable name)

    3. Now you should type the orders of this company today. The first thing the user needed to do is type the name of the product, and the name of the product exists in the avaliable list of the manufacturer provided in the step 1. And then type the location of the customer, the the x,y must less than the map length and only positive integer allowed. And if you want to terminate it just type 'quit' when the system require you to type the name. You must type all orders in here, you have no chance to add any order if you quit at this stage. 

    4. Finally, you can handle one order, and find the soonest deadline order, find the warehouse location, and display the shotest path. Now the system will require you to give a specific command, you can type 'handle' command to handle one the soonest deadline order which means the warehouse location will be gained and the shortest path will be shown in the screen. Also you can type 'search_sn' command to search the serial number of the product, then the system will require you to type the name of the product, and it will return the serial number of the product. when you finish all orders, type 'quit' to exit, note that if you type 'quit', you have no chance to return back, so only type 'quit' when all the orders are finished.
    (NOTE: the 'search_sn' command may be used when the information of the order is displayed on the screen and you don't know or forget the serial number of a product but still remember the name of the product)

    If possible, compiling all this codes in the Vscode would be better.

How to test three functionality:

    1. The first functionality is finding the soonest deadline order of all the order. The testing interface is in the 'Func1Test_Interface.cpp'. You can run and compile it by typing the  '.\Func1Test_Interface.exe (path of the testing txt file)' in the terminal. If the test is correct, the terminal will show "the test result is correct" otherwise "the test result is wrong".
    
    For the testing txt file, the first line is the number of all orders, the follwing line is 'timestamp', 'name of product', 'customer location x', 'customer location y'. One line only one order.

    2. The second functionality is finding the warehouse location by using a product serial number. The testing interface is in the 'Func2Test_Interface.cpp'. You can run and compile it by typing the  '.\Func2Test_Interface.exe (path of the testing txt file)' in the terminal. If the test is correct, the terminal will show "the test result is correct" otherwise "the test result is wrong".
    
    For the testing txt file, the first line is the number of warehouses, the follwing line is the 'name of product', 'the serial number'. One line only one warehouse serial number map.

    3. The third functionality is finding shortest path from the source to the destination. The testing interface is in the 'Func3Test_Interface.cpp'. You can run and compile it by typing the  '.\Func3Test_Interface.exe (path of the testing txt file)' in the terminal. the terminal will display the path(composed by the x,y locations). 
    
    For the testing txt file, the first line is the length of the map, for each following line, will represent each row of the map and will include 2 * map_length integer in each lines which indicates the distance between two vertices, the first half of it represents all the vertical distance(north-south direction) of a specific row vertices, the second half of it represents all the horizontal distance(weat-east direction) of a specific row vertices.

NOTE:
    1. the Func1_Empirical.cpp, Func2_Empirical.cpp, Func3_Empirical.cpp are used only for the empirical analyse, it will support the graph and the analyse in the report, you can check this by uncomment all the code in it but remember please do not run it, because the file path is only exist in my device. Please do not mix this with the Func1Test_Interface, Func2Test_Interface, Func3Test_Interface.

    2. All the requied test files are in the test_files folder, and the emperical-analyse folder only stores the data of the empirical time complexity analyse. If you are not intended to verify the data, you can ignore it safely.

 
 