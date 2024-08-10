#include "DrawableComponent.hpp"

sex::DrawableComponent::DrawableComponent()
{
}

sex::DrawableComponent::DrawableComponent(IDrawable *drawable) : _drawable{drawable}
{
}

void sex::DrawableComponent::set(IDrawable *drawable)
{
    _drawable.reset(drawable);
}

sex::IDrawable &sex::DrawableComponent::get()
{
    return *_drawable.get();
}
