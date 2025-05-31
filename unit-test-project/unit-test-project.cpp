#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/exam_subscription.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	exam_subscription* build_subscription(int start_day, int start_month, int start_year)
	{
		exam_subscription* subscription = new exam_subscription;
		subscription->examdate.day = start_day;
		subscription->examdate.month = start_month;
		subscription->examdate.year = start_year;
		return subscription;
	}

	//       
	void delete_subscription(exam_subscription* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		TEST_METHOD(TestMethod1) //     
		{
			
			exam_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 2015); 
			subscriptions[1] = build_subscription(2, 1, 2015); 
			subscriptions[2] = build_subscription(3, 1, 2015); 
			Assert::AreEqual(2, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod2) //        
		{
			exam_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(20, 1, 2015); 
			subscriptions[1] = build_subscription(22, 1, 2015); 
			subscriptions[2] = build_subscription(19, 1, 2015); 
			Assert::AreEqual(3, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod3) //         
		{
			exam_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(29, 4, 2015);  
			subscriptions[1] = build_subscription(27, 4, 2015);  
			subscriptions[2] = build_subscription(25, 4, 2015);  
			Assert::AreEqual(4, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod4) //         
		{
			exam_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(29, 2, 2016); // 11 
			subscriptions[1] = build_subscription(22, 2, 2016); // 12 
			subscriptions[2] = build_subscription(25, 2, 2016); // 10 
			Assert::AreEqual(7, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

	};

}
