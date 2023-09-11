# Copyright 2020 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""The Python AsyncIO implementation of the GRPC helloworld.Greeter server."""

import asyncio
import logging

import grpc
import rpc_message_pb2
import rpc_message_pb2_grpc


class RpcServer(rpc_message_pb2_grpc.SecurityService):
    async def ReceiveMessages(
        self,
        request: rpc_message_pb2.ClientMessage,
        context: grpc.aio.ServicerContext,
    ) -> rpc_message_pb2.MessageReply:
        print(context.peer() + '\n')
        return rpc_message_pb2.MessageReply(message="%s!" % request.message)


async def serve() -> None:
    server = grpc.aio.server()
    rpc_message_pb2_grpc.add_SecurityServiceServicer_to_server(RpcServer(), server)
    listen_addr = "[::]:50051"
    server.add_insecure_port(listen_addr)
    logging.info("Starting server on %s", listen_addr)
    await server.start()
    await server.wait_for_termination()


if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    asyncio.run(serve())
