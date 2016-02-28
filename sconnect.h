#include <stdexcept>

/** secure connect:
 *
 * Quick and dirty hack to check QObject::connect()'s return value
 */
template<typename Sender, typename Signal, typename Receiver, typename Slot>
void sconnect(Sender sender, Signal signal, Receiver receiver, Slot slot, Qt::ConnectionType type=Qt::AutoConnection) {
	bool okay = QObject::connect(
		sender, signal, receiver, slot, type);
	if ( ! okay ) {
		throw std::runtime_error(
		std::string("QObject::connect failed. sender: ")+signal+" receiver: "+slot);
	}
}
