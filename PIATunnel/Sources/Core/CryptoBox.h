//
//  CryptoBox.h
//  PIATunnel
//
//  Created by Davide De Rosa on 2/4/17.
//  Copyright © 2018 London Trust Media. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol Encrypter;
@protocol Decrypter;

@interface CryptoBox : NSObject

+ (BOOL)preparePRNGWithSeed:(nonnull const uint8_t *)seed length:(NSInteger)length;

- (nonnull instancetype)initWithCipherAlgorithm:(nonnull NSString *)cipherAlgorithm
                                digestAlgorithm:(nullable NSString *)digestAlgorithm;

- (BOOL)configureWithCipherEncKey:(nonnull const uint8_t *)cipherEncKey
                     cipherDecKey:(nonnull const uint8_t *)cipherDecKey
                       hmacEncKey:(nonnull const uint8_t *)hmacEncKey
                       hmacDecKey:(nonnull const uint8_t *)hmacDecKey
                            error:(NSError **)error;

// WARNING: hmac must be able to hold HMAC result
+ (BOOL)hmacWithDigestName:(nonnull NSString *)digestName
                    secret:(nonnull const uint8_t *)secret
              secretLength:(NSInteger)secretLength
                      data:(nonnull const uint8_t *)data
                dataLength:(NSInteger)dataLength
                      hmac:(nonnull uint8_t *)hmac
                hmacLength:(nonnull NSInteger *)hmacLength
                     error:(NSError **)error;

// encrypt/decrypt are mutually thread-safe
- (nonnull id<Encrypter>)encrypter;
- (nonnull id<Decrypter>)decrypter;

@end
