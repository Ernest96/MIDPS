//
//  ViewController.h
//  TicTacToe
//
//  Created by Daniel Prvornii on 10.04.17.
//  Copyright © 2017 Bitca Ernest. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
{
    IBOutlet UIImage *oImg;
    IBOutlet UIImage *xImg;
    IBOutlet UIImage *g_x;
    IBOutlet UIImage *xm;
    IBOutlet UIImage *OK;
    IBOutlet UIImage *g_y;
    NSInteger playerToken;
    BOOL upd_status;
    short win;
    short step;
    int a[9];
    short score[2];
    UIImageView *u[9];
    UIImageView *v[9];
    BOOL g_t;
    NSString *winner[2];
    short c[3];
    int g_chg;
    
}

@property (weak, nonatomic) IBOutlet UILabel *s_x;
@property (weak, nonatomic) IBOutlet UILabel *s_y;
@property (weak, nonatomic) IBOutlet UIImageView *s1;
@property (weak, nonatomic) IBOutlet UIImageView *s2;
@property (weak, nonatomic) IBOutlet UIImageView *s3;
@property (weak, nonatomic) IBOutlet UIImageView *s4;
@property (weak, nonatomic) IBOutlet UIImageView *s5;
@property (weak, nonatomic) IBOutlet UIImageView *s6;
@property (weak, nonatomic) IBOutlet UIImageView *s7;
@property (weak, nonatomic) IBOutlet UIImageView *s8;
@property (weak, nonatomic) IBOutlet UIImageView *s9;
@property (weak, nonatomic) IBOutlet UIImageView *x;
@property (weak, nonatomic) IBOutlet UIImageView *o;
@property (weak, nonatomic) IBOutlet UIImageView *gx;
@property (weak, nonatomic) IBOutlet UIImageView *gy;
@property (weak, nonatomic) IBOutlet UIImageView *Board;
@property (weak, nonatomic) IBOutlet UIImageView *v1;
@property (weak, nonatomic) IBOutlet UIImageView *v2;
@property (weak, nonatomic) IBOutlet UIImageView *v3;
@property (weak, nonatomic) IBOutlet UIImageView *v4;
@property (weak, nonatomic) IBOutlet UIImageView *v5;
@property (weak, nonatomic) IBOutlet UIImageView *v6;
@property (weak, nonatomic) IBOutlet UIImageView *v7;
@property (weak, nonatomic) IBOutlet UIImageView *v8;
@property (weak, nonatomic) IBOutlet UIImageView *v9;


- (IBAction)ResetButton:(UIButton *)sender;
- (IBAction)type:(UIButton *)sender;
-(void)UpdatePlayerInfo;
-(void)ResetBoard;
-(short) CheckForWin;
-(void) ai_play;
-(BOOL) check_last;
-(BOOL) check_attack;
-(BOOL) check_center;
-(BOOL) check_deffence;
-(short) find_zero;
-(void) show_ok:(int)w :(int)y :(int)z;
- (void)alertView:(UIAlertView *)alertView
didDismissWithButtonIndex:(NSInteger) buttonIndex;
@end
