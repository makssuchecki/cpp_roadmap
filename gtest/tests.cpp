#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

using ::testing::_;
using ::testing::Gt;
using ::testing::InSequence;
using ::testing::Return;

int add(int a, int b) { return a + b; }

TEST(MathTest, AddsPositive) {
    EXPECT_EQ(add(2, 3), 5);
    ASSERT_NE(add(1, 1), 0);
}

class QueueTest : public ::testing::Test {
protected:
    void SetUp() override { v = {1, 2, 3}; }
    std::vector<int> v;
};

TEST_F(QueueTest, HasThreeElements) {
    EXPECT_EQ(v.size(), 3u);
}

struct IOrderSink {
    virtual ~IOrderSink() = default;
    virtual bool submit(int id, double price) = 0;
};

class MockSink : public IOrderSink {
public:
    MOCK_METHOD(bool, submit, (int id, double price), (override));
};

TEST(SinkTest, SubmitsOrder) {
    MockSink sink;
    EXPECT_CALL(sink, submit(42, Gt(100.0)))
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_TRUE(sink.submit(42, 101.5));
}

TEST(SinkTest, OrderOfCalls) {
    MockSink sink;
    InSequence seq;
    EXPECT_CALL(sink, submit(1, _)).WillOnce(Return(true));
    EXPECT_CALL(sink, submit(2, _)).WillOnce(Return(false));

    sink.submit(1, 10.0);
    sink.submit(2, 20.0);
}