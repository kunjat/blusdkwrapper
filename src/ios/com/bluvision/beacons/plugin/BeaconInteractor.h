//
//  BeaconInteractor.h
//  BluPro
//
//  Created by Abhishek on 03/05/19.
//  Copyright © 2019 Abhishek. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@import Bluvision;
@import BluzoneCloud;

@protocol BeaconInteractorDelegate <NSObject>

- (void)signInSuccess:(BZCUser *)user;
- (void)signInFailure:(NSError *)error;
- (void)beaconFound:(BLUSBeacon *)beacon;
- (void)beaconLost:(BLUSBeacon *)beacon;
- (void)enableBluetooth;
- (void)requestLocationPermissions;
- (void)loadTemplateSucess:(NSArray *)templates;
- (void)loadTemplateError:(NSString *)message;
- (void)provisionSuccess;
- (void)provisionError:(NSString *)message;
- (void)provisionStatusChange:(NSString *)status;
- (void)provisionDescriptionChange:(NSString *)description;

@end

@interface BeaconInteractor : NSObject

- (id)initWithDelegate:(id <BeaconInteractorDelegate>)delegate;
- (void)signIn:(NSString *)token;
- (void)startScan;
- (void)stopScan;
- (void)loadTemplates:(NSString *)identifier;
- (void)provisionBeaconForTemplate:(int)templateId notes:(NSString *)notes;

@end

NS_ASSUME_NONNULL_END