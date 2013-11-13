//
//  UMOMockHTTPResponse.h
//  URLMock
//
//  Created by Prachi Gauriar on 11/8/2013.
//  Copyright (c) 2013 Prachi Gauriar. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import <URLMock/UMOMockHTTPMessage.h>

@class UMOMockHTTPRequest;

@interface UMOMockHTTPResponse : UMOMockHTTPMessage

+ (instancetype)mockResponseWithError:(NSError *)error;

+ (instancetype)mockResponseWithStatusCode:(NSInteger)statusCode;
+ (instancetype)mockResponseWithStatusCode:(NSInteger)statusCode headers:(NSDictionary *)headers;
+ (instancetype)mockResponseWithStatusCode:(NSInteger)statusCode body:(NSData *)body;
+ (instancetype)mockResponseWithStatusCode:(NSInteger)statusCode headers:(NSDictionary *)headers body:(NSData *)body;
+ (instancetype)mockResponseWithStatusCode:(NSInteger)statusCode headers:(NSDictionary *)headers
                                      body:(NSData *)body chunkCountHint:(NSUInteger)hint;
+ (instancetype)mockResponseWithStatusCode:(NSInteger)statusCode headers:(NSDictionary *)headers body:(NSData *)body
                            chunkCountHint:(NSUInteger)hint delayBetweenChunks:(NSTimeInterval)delay;

// TODO: Mock responses for redirects and authentication challenges

- (void)respondToMockRequest:(UMOMockHTTPRequest *)request client:(id <NSURLProtocolClient>)client protocol:(NSURLProtocol *)protocol;
- (void)cancelResponse;

@end
