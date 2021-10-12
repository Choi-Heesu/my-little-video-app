#ifndef video_reader_hpp
#define video_reader_hpp

extern "C" {
#include <inttypes.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

struct VideoReaderState {
  // Public things for other parts of the program to read from
  int width, height;

  // Private internal state
  AVFormatContext* av_format_ctx;
  AVCodecContext* av_codec_ctx;
  int video_stream_index;
  AVPacket* av_packet;
  AVFrame* av_frame;
  SwsContext* sws_scaler_ctx;
};

bool video_reader_open(VideoReaderState* state, const char* filename);
bool video_reader_read_frame(VideoReaderState* state, uint8_t* frame_buffer);
void video_reader_close(VideoReaderState* state);

#endif