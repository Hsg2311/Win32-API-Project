#include "Animation.hpp"
#include "Texture.hpp"

void Animation::create( Texture* tex, Vec2 LT, Vec2 sliceSize, 
						Vec2 step, float duration, UINT frameCount ) {
	tex_ = tex;

	animFrames_.reserve( frameCount );
	for ( auto i = 0u; i < frameCount; ++i ) {
		auto frame = frameInfo{
			.LT = LT + step * i,
			.sliceSize = sliceSize,
			.duration = duration
		};

		animFrames_.emplace_back( frame );
	}
}
