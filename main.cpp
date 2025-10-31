#include<iostream>
#include<numbers>
#include<format>
#include<memory>
#include<vector>

namespace {
	class IShape {
	public:
		virtual void Size() = 0;
		virtual void Draw() = 0;
	};

	class Circle : public IShape {
	private:
		float Radius_{};
		float Area_{};

	public:
		Circle(float r_) : Radius_{ r_ } {}

		virtual void Size() override {
			Area_ = Radius_ * Radius_ * std::numbers::pi_v<float> * 0.5f;
		}

		virtual void Draw() override {
			std::cout << std::format("半径{}の円の面積 = {}\n", Radius_, Area_);
		}
	};

	class Rectangle : public IShape {
	private:
		float Width_{};
		float Height_{};
		float Area_{};

	public:
		Rectangle(float w_, float h_) : Width_{ w_ }, Height_{ h_ } {}

		virtual void Size() override {
			Area_ = Width_ * Height_;
		}

		virtual void Draw() override {
			std::cout << std::format("長さ{}、高さ{}の矩形の面積 = {}\n", Width_, Height_, Area_);
		}
	};
}

int main() {
	std::vector<std::unique_ptr<IShape>> shapes{};
	shapes.emplace_back(new Circle{ 15.0f });
	shapes.emplace_back(new Rectangle{ 3.0f, 4.0f });
	shapes.emplace_back(new Rectangle{ 7.5f, 7.5f });
	shapes.emplace_back(new Circle{ 8.0f });

	for (auto& shape : shapes) {
		shape->Size();
		shape->Draw();
	}

	return 0;
}