#ifndef RISCV_VP_UART_H
#define RISCV_VP_UART_H

#include <stdint.h>
#include <poll.h>
#include <systemc>
#include "abstract_uart.h"

class UART : public AbstractUART {
public:
	UART(const sc_core::sc_module_name&, uint32_t);
	~UART(void);

private:
	enum {
		NFDS = 2,
	};
	struct pollfd fds[NFDS];

	void handle_input(int fd);
	void write_data(uint8_t);
	void read_data(void);
};

#endif  // RISCV_VP_UART_H
