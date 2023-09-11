// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: rpc_message.proto

#include "rpc_message.pb.h"
#include "rpc_message.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace pkg_grpc {

static const char* SecurityService_method_names[] = {
  "/pkg_grpc.SecurityService/ReceiveMessages",
};

std::unique_ptr< SecurityService::Stub> SecurityService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< SecurityService::Stub> stub(new SecurityService::Stub(channel, options));
  return stub;
}

SecurityService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_ReceiveMessages_(SecurityService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status SecurityService::Stub::ReceiveMessages(::grpc::ClientContext* context, const ::pkg_grpc::ClientMessage& request, ::pkg_grpc::MessageReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::pkg_grpc::ClientMessage, ::pkg_grpc::MessageReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_ReceiveMessages_, context, request, response);
}

void SecurityService::Stub::async::ReceiveMessages(::grpc::ClientContext* context, const ::pkg_grpc::ClientMessage* request, ::pkg_grpc::MessageReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::pkg_grpc::ClientMessage, ::pkg_grpc::MessageReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ReceiveMessages_, context, request, response, std::move(f));
}

void SecurityService::Stub::async::ReceiveMessages(::grpc::ClientContext* context, const ::pkg_grpc::ClientMessage* request, ::pkg_grpc::MessageReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ReceiveMessages_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::pkg_grpc::MessageReply>* SecurityService::Stub::PrepareAsyncReceiveMessagesRaw(::grpc::ClientContext* context, const ::pkg_grpc::ClientMessage& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::pkg_grpc::MessageReply, ::pkg_grpc::ClientMessage, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_ReceiveMessages_, context, request);
}

::grpc::ClientAsyncResponseReader< ::pkg_grpc::MessageReply>* SecurityService::Stub::AsyncReceiveMessagesRaw(::grpc::ClientContext* context, const ::pkg_grpc::ClientMessage& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncReceiveMessagesRaw(context, request, cq);
  result->StartCall();
  return result;
}

SecurityService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SecurityService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SecurityService::Service, ::pkg_grpc::ClientMessage, ::pkg_grpc::MessageReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](SecurityService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::pkg_grpc::ClientMessage* req,
             ::pkg_grpc::MessageReply* resp) {
               return service->ReceiveMessages(ctx, req, resp);
             }, this)));
}

SecurityService::Service::~Service() {
}

::grpc::Status SecurityService::Service::ReceiveMessages(::grpc::ServerContext* context, const ::pkg_grpc::ClientMessage* request, ::pkg_grpc::MessageReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace pkg_grpc
