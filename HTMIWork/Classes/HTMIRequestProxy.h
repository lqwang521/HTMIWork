//
//  HTMIRequestProxy.h
//  LXProject
//
//  Created by sharejoy_lx on 16-10-18.
//  Copyright © 2016年 wlx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking/AFNetworking.h"
#import "HTMIResponse.h"

typedef void(^suceesBlock)(NSURLSessionDataTask *task, id reponseObject);
typedef void(^failureBlock)(NSURLSessionDataTask *task, NSError *error);
typedef void(^HTMIProxyCallback)(HTMIResponse * response);
typedef void(^multipart)(id<AFMultipartFormData>);
typedef NS_ENUM(NSInteger, RequestType) {
    REQUEST_GET = 0,
    REQUEST_POST,
    REQUEST_UPLOAD,
    REQUEST_FormUrl
};


@interface HTMIRequestProxy : NSObject

+ (instancetype)sharedInstance;

- (NSInteger)callGETWithParams:(NSDictionary *)params url:(NSString *)url  headers:(NSDictionary*)headers methodName:(NSString *)methodName success:(HTMIProxyCallback)success fail:(HTMIProxyCallback)fail;

- (NSInteger)callPOSTWithParams:(NSDictionary *)params url:(NSString *)url  headers:(NSDictionary*)headers methodName:(NSString *)methodName success:(HTMIProxyCallback)success fail:(HTMIProxyCallback)fail;

- (NSInteger)callUPLOADWithParams:(NSDictionary *)params url:(NSString *)url headers:(NSDictionary*)headers uploads:(NSDictionary*)uploads methodName:(NSString *)methodName success:(HTMIProxyCallback)success fail:(HTMIProxyCallback)fail;

- (NSInteger)callFormUrlWithParams:(NSDictionary *)params url:(NSString *)url headers:(NSDictionary *)headers methodName:(NSString *)methodName success:(HTMIProxyCallback)success fail:(HTMIProxyCallback)fail;

- (void)cancelRequestWithRequestID:(NSNumber *)requestID;
- (void)cancelRequestWithRequestIDList:(NSArray *)requestIDList;

@end
