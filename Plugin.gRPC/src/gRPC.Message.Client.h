#ifndef __GRPC_MESSAGE_CLIENT_H__
#define __GRPC_MESSAGE_CLIENT_H__

#include <iostream>
#include <memory>
#include <string>


#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>

#include "rpc_src/rpc_message.grpc.pb.h"

namespace Rpc
{
    using grpc::Channel;
    using grpc::ClientAsyncResponseReader;
    using grpc::ClientContext;
    using grpc::CompletionQueue;
    using grpc::Status;

    using pkg_grpc::ClientMessage;
    using pkg_grpc::MessageReply;
    using pkg_grpc::SecurityService;

    class Client {
    public:

    Client(std::shared_ptr<Channel> channel);
    ~Client();

    std::string send(const std::string& message);

    private:
    std::unique_ptr<SecurityService::Stub> stub_;

    };
} // namespace gRpc

#endif //__GRPC_MESSAGE_CLIENT_H__