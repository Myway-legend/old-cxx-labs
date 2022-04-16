#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>
#include "base-types.hpp"
#include "shape.hpp"

namespace samoilenko
{
  class CompositeShape: public Shape
  {
    using figure = std::shared_ptr< samoilenko::Shape >;
    using sharedContainer = std::unique_ptr< figure[] >;
  public:
    CompositeShape(const std::initializer_list< std::shared_ptr< Shape > >& list);
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept = default;
    ~CompositeShape() = default;
    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& position) override;
    void move(double x, double y) override;
    void scale(double factor) override;
    void insert(const std::shared_ptr< Shape >& newFigure);
    void remove(size_t index);
    void reserve(size_t newCapacity);
    void swap(CompositeShape& other) noexcept;
  private:
    sharedContainer figures_;
    size_t count_;
    size_t capacity_;
  };
}

#endif
