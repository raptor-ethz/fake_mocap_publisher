#include "domain_participant.h"
#include "publisher.h"

#include "Mocap_msg.h"
#include "Mocap_msgPubSubTypes.h"

#include <chrono>

int main(int argc, char **argv) {
  // initialize DDS objects
  DefaultParticipant dp(0, "fake_mocap_publisher");
  DDSPublisher mocap_pub(idl_msg::Mocap_msgPubSubType(), "mocap_srl_quad",
                         dp.participant());
  cpp_msg::Mocap_msg mocap;

  // chrono
  std::chrono::time_point<std::chrono::steady_clock> loop_timer;
  const int DELAY = 5; //200Hz

  // loop
  for(int i = 0; ; ++i) {
    loop_timer = std::chrono::steady_clock::now();

    mocap.header.timestamp = i;
    mocap_pub.publish(mocap);

    // reset counter if limit reached
    if (i == INT32_MAX) {
      i = 1;
    }

    // control frequency
    loop_timer += std::chrono::milliseconds(DELAY);
    std::this_thread::sleep_until(loop_timer);
  }

  return 0;
}