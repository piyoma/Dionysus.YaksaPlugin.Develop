#include "gRPC.Message.Client.h"
#include <iostream>

namespace Rpc
{
   Client::Client(std::shared_ptr<Channel> channel)
        : stub_(SecurityService::NewStub(channel))
    {
        
    }
    Client::~Client()
    {
        
    }
    std::string Client::send(const std::string& message) {

        ClientMessage request;
        request.set_message(message);

        MessageReply reply;

        ClientContext context;
        CompletionQueue cq;

        Status status;
        auto deadline = std::chrono::system_clock::now() + std::chrono::seconds(1);
        context.set_deadline(deadline);
        std::unique_ptr<ClientAsyncResponseReader<MessageReply> > rpc(
            stub_->AsyncReceiveMessages(&context, request, &cq));

        rpc->Finish(&reply, &status, (void*)1);
        void* got_tag;
        bool ok = false;

        GPR_ASSERT(cq.Next(&got_tag, &ok));

        GPR_ASSERT(got_tag == (void*)1);
    
        GPR_ASSERT(ok);

        if (status.ok()) {
            return reply.message();

        } else {
            //std::cout << "RPC failed " << status.error_message() << std::endl;
            return status.error_message();

        }
    }
} // namespace Rpc