Overview
This project was an experimental TCP server written in C, originally intended to evolve into a lightweight HTTP handling layer / networking core.
Development has been discontinued.
The codebase remains here for reference, experimentation, and potential future reuse of isolated components (socket handling, concurrency experiments, parsing attempts, etc.).
Current State
At the point of abandonment, the project includes:
Basic TCP server implementation
Socket lifecycle handling (bind / listen / accept loop)
Early-stage request handling logic (non-production, incomplete)
Experimental concurrency ideas (threading with very bad implementation)
It does not provide:
A working HTTP server
Production-grade stability
Complete protocol implementation
Security hardening
Cross-platform guarantees (pthread used so just for linux mac and freebsd)
Design Intent (Historical)
The original goal was to explore:
High-performance networking in pure C
Minimal dependency server architecture
Comparison against event-driven and thread-per-request models
Building a custom HTTP stack from raw sockets
This direction was later abandoned due to scope creep and architectural complexity.
Why It Was Abandoned
The project grew beyond its initial experimental scope and started to resemble a full HTTP server implementation. At that point:
Complexity exceeded intended learning boundaries
Performance benchmarking required a more stable baseline
Architectural decisions became premature optimization territory
Existing mature solutions already cover the target space effectively
What Remains Useful
Even though the project is incomplete, the following parts may still be useful:
Socket abstraction layer
Basic TCP accept loop patterns
Threading experiments
Error handling level
Status
Archived / Not maintained
No guarantees are made regarding correctness, safety, or compatibility.
Notes
If revisited in the future, the recommended approach would be:
Start from a minimal event loop (epoll/kqueue-based)
Avoid premature HTTP layer design
Benchmark before architecture expansion
Keep protocol logic strictly separated from transport
