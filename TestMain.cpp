//
// Created by henry on 23/10/2015.
//

#include "TestHandler.h"

#include <iostream>
#include <stdexcept>

//#include <cppunit/TestRunner.h>
//#include <cppunit/TestResult.h>
//#include <cppunit/TestResultCollector.h>
//#include <cppunit/extensions/HelperMacros.h>
//#include <cppunit/BriefTestProgressListener.h>
//#include <cppunit/extensions/TestFactoryRegistry.h>

#include <cppunit/ui/text/TestRunner.h>
//#include <cppunit/TestResult.h>

using namespace std;

using namespace CPPUNIT_NS;

int main(){

    CppUnit::TextUi::TestRunner runner;
    runner.addTest( TestHandler::suite() );
    runner.run();
    return 0;

//    CppUnit::TestSuite suite;
//    CppUnit::TestResult result;
//    suite.addTest( new CppUnit::TestCaller<TestHandler>(
//            "testRead_synarthsh_from_file",
//            &ComplexNumberTest::testRead_synarthsh_from_file ) );
//    suite.run( &result );
//
////    TestCaller<TestHandler> test( "testRead_synarthsh_from_file",
////                                                 &TestHandler::testRead_synarthsh_from_file);
//
//    suite.run(&result);
//
////    return result.wasSuccessful() ? 0 : 1;

}
