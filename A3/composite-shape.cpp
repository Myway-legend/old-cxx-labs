#include "composite-shape.hpp"
#include <iostream>

samoilenko::CompositeShape::CompositeShape(const std::initializer_list< std::shared_ptr< Shape > >& list):
  figures_(std::make_unique< figure[] >(list.size() * 2)),
  count_(0),
  capacity_(list.size() * 2)
{
  for (auto&& element: list)
  {
    figures_[count_] = element;
    count_++;
  }
}

samoilenko::CompositeShape::CompositeShape(const CompositeShape& other):
  figures_(std::make_unique< figure[] >(other.count_)),
  count_(other.count_),
  capacity_(other.capacity_)
{
  for (size_t i = 0; i < count_; i++)
  {
    figures_[i] = other.figures_[i];
  }
}

samoilenko::CompositeShape& samoilenko::CompositeShape::operator=(const CompositeShape& other)
{
  if (this == &other)
  {
    return *this;
  }
  CompositeShape temp(other);
  swap(temp);
  return *this;
}

samoilenko::CompositeShape& samoilenko::CompositeShape::operator=(CompositeShape&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }
  figures_.reset();
  figures_ = std::move(other.figures_);
  count_ = other.count_;
  capacity_ = other.capacity_;
  return *this;
}

double samoilenko::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < count_; i++)
  {
    area += figures_[i]->getArea();
  }
  return area;
}

samoilenko::rectangle_t samoilenko::CompositeShape::getFrameRect() const
{
  rectangle_t firstRect = figures_[0]->getFrameRect();
  double minX = firstRect.pos.x - firstRect.width / 2;
  double minY = firstRect.pos.y - firstRect.height / 2;
  double maxX = firstRect.pos.x + firstRect.width / 2;
  double maxY = firstRect.pos.y + firstRect.height / 2;
  for (size_t i = 1; i < count_; ++i) {
    firstRect = figures_[i]->getFrameRect();
    double currMinX = firstRect.pos.x - firstRect.width / 2;
    double currMaxX = firstRect.width / 2 + firstRect.pos.x;
    double currMinY = firstRect.pos.y - firstRect.height / 2;
    double currMaxY = firstRect.height / 2 + firstRect.pos.y;
    minX = std::min(minX, currMinX);
    maxX = std::max(maxX, currMaxX);
    minY = std::min(minY, currMinY);
    maxY = std::max(maxY, currMaxY);
  }
  return {maxX - minX, maxY - minY, {minX + (maxX - minX) / 2, minY + (maxY - minY) / 2}};
}


void samoilenko::CompositeShape::move(const point_t& position)
{
  rectangle_t temp = getFrameRect();
  const double x = position.x - temp.pos.x;
  const double y = position.y - temp.pos.y;
  move(x, y);
}

void samoilenko::CompositeShape::move(const double x, const double y)
{
  for (size_t i = 0; i < count_; i++)
  {
    figures_[i]->move(x, y);
  }
}

void samoilenko::CompositeShape::scale(const double factor)
{
  rectangle_t frameRect = getFrameRect();
  double newX = 0;
  double newY = 0;
  rectangle_t temp;
  for (size_t i = 0; i < count_; i++)
  {
    temp = figures_[i]->getFrameRect();
    newX = temp.pos.x + factor * (frameRect.pos.x - temp.pos.x);
    newY = temp.pos.y + factor * (frameRect.pos.y - temp.pos.y);
    figures_[i]->move({ newX, newY });
    figures_[i]->scale(factor);
  }
}

void samoilenko::CompositeShape::insert(const std::shared_ptr< Shape >& newFigure)
{
  if (!figures_)
  {
    throw std::runtime_error("Object has been moved");
  }
  if (!newFigure)
  {
    throw std::invalid_argument("Shape pointer must not be nullptr");
  }
  if (capacity_ == count_)
  {
    reserve(capacity_ * 2);
  }
  figures_[count_] = newFigure;
  count_++;
}

void samoilenko::CompositeShape::remove(size_t index)
{
  if (index >= count_)
  {
    throw std::out_of_range("Index out of range");
  }
  if (count_ <= 1)
  {
    throw std::runtime_error("Composite shape must have at least one shape");
  }
  for (size_t i = index; i < count_ - 1; ++i)
  {
    figures_[i] = figures_[i + 1];
  }
  count_--;
}

void samoilenko::CompositeShape::reserve(size_t newCapacity)
{
  if (capacity_ < newCapacity)
  {
    sharedContainer tempContainer = std::make_unique< figure[] >(newCapacity);
    for (size_t i = 0; i < count_; ++i)
    {
      tempContainer[i] = figures_[i];
    }
    figures_ = std::move(tempContainer);
    capacity_ = newCapacity;
  }
}

void samoilenko::CompositeShape::swap(CompositeShape& other) noexcept
{
  figures_.swap(other.figures_);
  std::swap(count_, other.count_);
  std::swap(capacity_, other.capacity_);
}
