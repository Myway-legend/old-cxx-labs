#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(TestCompositeShape)

BOOST_AUTO_TEST_CASE(testMove)
{
  std::shared_ptr< samoilenko::Shape > circle = samoilenko::makeCircle();
  std::shared_ptr< samoilenko::Shape > rectangle = samoilenko::makeRect();
  samoilenko::CompositeShape comp{circle, rectangle};
  const double startingRectWidth = comp.getFrameRect().width;
  const double startingRectHeight = comp.getFrameRect().height;
  comp.move({ -5.1, 3.6 });

  BOOST_CHECK_CLOSE(startingRectWidth, comp.getFrameRect().width, samoilenko::TOLERANCE);
  BOOST_CHECK_CLOSE(startingRectHeight, comp.getFrameRect().height, samoilenko::TOLERANCE);
  comp.move(5.0, 3.5);

  BOOST_CHECK_CLOSE(startingRectWidth, comp.getFrameRect().width, samoilenko::TOLERANCE);
  BOOST_CHECK_CLOSE(startingRectHeight, comp.getFrameRect().height, samoilenko::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testArea)
{
  std::shared_ptr< samoilenko::Shape > circle = samoilenko::makeCircle();
  std::shared_ptr< samoilenko::Shape > rectangle = samoilenko::makeRect();
  samoilenko::CompositeShape comp{circle, rectangle};
  const double startingArea = comp.getArea();
  const double factor = 2.0;
  comp.scale(factor);

  BOOST_CHECK_CLOSE(startingArea, comp.getArea() / (factor * factor), samoilenko::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testCopy)
{
  std::shared_ptr< samoilenko::Shape > circle = samoilenko::makeCircle();
  std::shared_ptr< samoilenko::Shape > rectangle = samoilenko::makeRect();
  samoilenko::CompositeShape comp1{circle, rectangle};
  samoilenko::CompositeShape comp2(comp1);
  BOOST_CHECK_CLOSE(comp1.getFrameRect().height, comp2.getFrameRect().height, samoilenko::TOLERANCE);
}

BOOST_AUTO_TEST_CASE(testInsert)
{
  std::shared_ptr< samoilenko::Shape > circle = samoilenko::makeCircle();
  std::shared_ptr< samoilenko::Shape > rectangle = samoilenko::makeRect();
  samoilenko::CompositeShape comp{circle, rectangle};
  std::shared_ptr< samoilenko::Shape > circle2 = samoilenko::makeCircle();
  BOOST_CHECK_NO_THROW(comp.insert(circle2));
}

BOOST_AUTO_TEST_CASE(testRemove)
{
  std::shared_ptr< samoilenko::Shape > circle = samoilenko::makeCircle();
  std::shared_ptr< samoilenko::Shape > rectangle = samoilenko::makeRect();
  samoilenko::CompositeShape comp{circle, rectangle};
  BOOST_CHECK_NO_THROW(comp.remove(1));
}
BOOST_AUTO_TEST_SUITE_END()
