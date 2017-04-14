//
//  ViewController.m
//  TicTacToe
//
//  Created by Daniel Prvornii on 10.04.17.
//  Copyright © 2017 Bitca Ernest. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize s1, s2, s3, s4, s5, s6, s7, s8 , s9, x, o,gx, gy, s_x, s_y,
            v1, v2, v3, v4, v5, v6 ,v7, v8, v9;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    oImg = [UIImage imageNamed: @"o.png"];
    xImg = [UIImage imageNamed: @"x.png"];
    g_x = [UIImage imageNamed: @"gx.png"];
    xm = [UIImage imageNamed: @"xm.png"];
    g_y = [UIImage imageNamed: @"gy.png"];
    OK = [UIImage imageNamed: @"ok.png"];
    x.image = xImg;
    o.image = oImg;
    playerToken = 1;
    gx.image = g_x;
    gy.image = NULL;
    step = 0;
    score[0] = score[1] = 0;
    u[0] = s1;
    u[1] = s2;
    u[2] = s3;
    u[3] = s4;
    u[4] = s5;
    u[5] = s6;
    u[6] = s7;
    u[7] = s8;
    u[8] = s9;
    v[0] = v1;
    v[1] = v2;
    v[2] = v3;
    v[3] = v4;
    v[4] = v5;
    v[5] = v6;
    v[6] = v7;
    v[7] = v8;
    v[8] = v9;
    winner[0] = @"Player X won";
    winner[1] = @"Player O won";
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) UpdatePlayerInfo{
    if (playerToken ==1 && !g_t)
    {
        playerToken = 2;
        gx.image = NULL;
        gy.image = g_y;
    }
    else if (playerToken == 2)
    {
        playerToken = 1;
        gx.image = g_x;
        gy.image = NULL;
    }
}

-(short) find_zero{
    int i;
    for (i = 0; i < 3; ++i)
        if (c[i] == 0)
            return (i);
    return (0);
}

-(BOOL) check_last{
    
    
    int i;
    int offset;
    short zer;
    BOOL flag;
    
    for (offset = 0; offset < 9; offset += 3)
    {
        flag = 1;
        c[0] = c[1] = c[2] = 0;
        for(i = 0; i < 3; ++i)
            if (a[i + offset] == 2)
                c[i] = 1;
            else if (a[i + offset] == 1)
                flag = 0;
        if (c[0] + c[1] + c[2] == 2 && flag)
        {
            zer =[self find_zero];
            u[zer + offset].image = oImg;
            a[zer + offset] = 2;
            return 1;
        }
    }
    
    for (offset = 0; offset < 3; offset ++)
    {
        c[0] = c[1] = c[2] = 0;
        flag = 1;
        for (i = 0; i < 9; i += 3)
            if (a[i + offset] == 2)
                c[i / 3] = 1;
            else if (a[i + offset] == 1)
                flag = 0 ;
        if (c[0] + c[1] + c[2] == 2 && flag)
        {
            zer = [self find_zero];
            u[offset + zer * 3].image = oImg;
            a[offset + zer * 3] = 2;
            return 1;
        }
    }
    flag = 1;
    c[0] = c[1] = c[2] = 0;
    if (a[2] == 2)
        c[0] = 1;
    if (a[4] == 2)
        c[1] = 1;
    if (a[6] == 2)
        c[2] = 1;
    if (a[2] == 1 || a[4] == 1 || a[6] == 1)
        flag = 0;
    if (c[0] + c[1] + c[2] == 2 && flag)
    {
        zer = [self find_zero];
        a[2 + 2 * zer] = 2;
        u[2 + 2 * zer].image = oImg;
        return 1;
    }
    flag = 1;
    c[0] = c[1] = c[2] = 0;
    if (a[0] == 2)
        c[0] = 1;
    if (a[4] == 2)
        c[1] = 1;
    if (a[8] == 2)
        c[2] = 1;
    if (a[0] == 1 || a[4] == 1 || a[8] == 1)
        flag = 0;
    if (c[0] + c[1] + c[2] == 2 && flag)
    {
        zer = [self find_zero];
        a[4 * zer] = 2;
        u[4 * zer].image = oImg;
        return 1;
    }
    return (0);
}

-(BOOL) check_deffence{
    int i;
    int offset;
    short zer;
    BOOL flag;
    
    for (offset = 0; offset < 9; offset += 3)
    {
        flag = 1;
        c[0] = c[1] = c[2] = 0;
        for(i = 0; i < 3; ++i)
            if (a[i + offset] == 1)
                c[i] = 1;
            else if (a[i + offset] == 2)
                flag = 0;
        if (c[0] + c[1] + c[2] == 2 && flag)
        {
            zer =[self find_zero];
            u[zer + offset].image = oImg;
            a[zer + offset] = 2;
            return 1;
        }
    }
    
    for (offset = 0; offset < 3; offset ++)
    {
        c[0] = c[1] = c[2] = 0;
        flag = 1;
        for (i = 0; i < 9; i += 3)
            if (a[i + offset] == 1)
                c[i / 3] = 1;
            else if (a[i + offset] == 2)
                flag = 0 ;
        if (c[0] + c[1] + c[2] == 2 && flag)
        {
            zer = [self find_zero];
            u[offset + zer * 3].image = oImg;
            a[offset + zer * 3] = 2;
            return 1;
        }
    }
    flag = 1;
    c[0] = c[1] = c[2] = 0;
    if (a[2] == 1)
        c[0] = 1;
    if (a[4] == 1)
        c[1] = 1;
    if (a[6] == 1)
        c[2] = 1;
    if (a[2] == 2 || a[4] == 2 || a[6] == 2)
        flag = 0;
    if (c[0] + c[1] + c[2] == 2 && flag)
    {
        zer = [self find_zero];
        a[2 + 2 * zer] = 2;
        u[2 + 2 * zer].image = oImg;
        return 1;
    }
    flag = 1;
    c[0] = c[1] = c[2] = 0;
    if (a[0] == 1)
        c[0] = 1;
    if (a[4] == 1)
        c[1] = 1;
    if (a[8] == 1)
        c[2] = 1;
    if (a[0] == 2 || a[4] == 2 || a[8] == 2)
        flag = 0;
    if (c[0] + c[1] + c[2] == 2 && flag)
    {
        zer = [self find_zero];
        a[4 * zer] = 2;
        u[4 * zer].image = oImg;
        return 1;
    }
    return 0;
}

-(BOOL) check_center{
    if (a[4] == 0)
    {
        a[4] = 2;
        u[4].image = oImg;
        return (1);
    }
    return 0;
}

-(BOOL) check_attack{
    
    int cand[9];
    int k = 0;
    int rez;
    time_t t;
    
    for (int i = 0; i < 9; ++i)
        if (a[i] == 0)
            cand[k++] = i;
    if (!k)
        return (0);
    if (k == 1)
    {
        rez = cand[0];
        a[rez] = 2;
        u[rez].image = oImg;
        return 1;
    }
    srand((unsigned) time(&t));
    rez = cand[rand() % k];
    a[rez] = 2;
    u[rez].image = oImg;
    return 1;
}

-(void) ai_play{
    if ([self check_last])
        return ;
    else if ([self check_deffence])
        return ;
    else if ([self check_center])
        return ;
    else
        [self check_attack];
    return;
}
- (void)alertView:(UIAlertView *)alertView
didDismissWithButtonIndex:(NSInteger) buttonIndex
{
    if (buttonIndex == 0)
    {
        [NSThread sleepForTimeInterval:0.8f];
        [self ResetBoard];
    }
}

-(void) ch_win{
    win = [self CheckForWin];
    if (win)
    {
        UIAlertView * some = [[UIAlertView alloc] initWithTitle:
                              @"Congratulations !"
        message: winner[win - 1] delegate: self cancelButtonTitle:@"OK"otherButtonTitles: nil];
        [some show];
        ++score[win - 1];
        return ;
        
    }
    if (upd_status)
    {
        step += g_t + 1;
        if (step >= 9 && !win)
        {
            UIAlertView * some = [[UIAlertView alloc] initWithTitle:@"No Winner!"
                        message: @"Play again" delegate: self cancelButtonTitle:@"OK"otherButtonTitles: nil];
            [some show];
            return ;
        }
        [self UpdatePlayerInfo];
    }
}

-(void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch  *touch = [[event allTouches] anyObject];
    
    upd_status = 0;
    win = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (CGRectContainsPoint([u[i] frame], [touch locationInView: self.view]))
        {
            if (!a[i])
                upd_status = 1;
            if (playerToken == 1 && !a[i])
            {
                u[i].image = xImg;
                a[i] = 1;
                if (g_t)
                    [self performSelector:@selector(ai_play) withObject:nil afterDelay:0.22];
            }
            else if (playerToken == 2 && !a[i]) {u[i].image = oImg; a[i] = 2;}
        }
    }
    if (g_t)
        [self performSelector:@selector(ch_win) withObject:nil afterDelay:0.25];
    else
        [self ch_win];
}

-(void) show_ok:(int)w :(int)y :(int)z {
    v[w].image = v[y].image = v[z].image = OK;
}


-(short)CheckForWin{
    if (a[0] == a[1] && a[0] == a[2] && a[0] != 0)
    {
        [self show_ok:0 :1 :2];
        return (a[0]); // rind 1
    }
    else if (a[0] == a[3] && a[0] == a[6] && a[0] != 0)
    {
        [self show_ok:0 :3 :6];
        return (a[0]); // col 1
    }
    else if (a[0] == a[4] && a[0] == a[8] && a[0] != 0)
    {
        [self show_ok:0 :4 :8];
        return (a[0]); // diagon prin
    }
    else if (a[1] == a[4] && a[1] == a[7] && a[1] != 0)
    {
        [self show_ok:1 :4 :7];
        return (a[1]); // col 2
    }
    else if (a[2] == a[5] && a[2] == a[8] && a[2] != 0)
    {
        [self show_ok:2 :5 :8];
        return (a[2]); // col 3
    }
    else if (a[3] == a[4] && a[3] == a[5] && a[3] != 0)
    {
        [self show_ok:3 :4 :5];
        return (a[3]); // rind 2
    }
    else if (a[6] == a[7] && a[6] == a[8] && a[6] != 0)
    {
        [self show_ok:6 :7 :8];
        return (a[7]); // rind 3
    }
    else if (a[2] == a[4] && a[2] == a[6] && a[2] != 0)
    {
        [self show_ok:2 :4 :6];
        return (a[2]); // diagon mica
    }
    return (0);
}

-(void) ResetBoard{
   
    playerToken = 1;
    step = 0;
    gx.image = g_x;
    gy.image = NULL;
    for (int i =0; i < 9; ++i)
    {
        u[i].image = NULL;		
        v[i].image = NULL;
        a[i] = 0;
    }
    s_x.text = [NSString stringWithFormat:@"%d",score[0]];
    s_y.text = [NSString stringWithFormat:@"%d",score[1]];
}

- (IBAction)ResetButton:(UIButton *)sender {
    [self ResetBoard];
}

- (IBAction)type:(UIButton *)sender {
    if (g_t == 0)
    {
        [sender setTitle:@"AI" forState:UIControlStateNormal];
        [sender setTitleColor:[UIColor colorWithRed:1.0 green:0.0 blue:0.0 alpha:1.0] forState:UIControlStateNormal];
        
        score[0] = score[1] = 0;
        [self ResetBoard];
        g_t = 1;
    }
    else
    {
        [sender setTitle:@"PVP" forState:UIControlStateNormal];
        [sender setTitleColor:[UIColor colorWithRed:0.0 green:1.0 blue:0.0 alpha:1.0] forState:UIControlStateNormal];
        score[0] = score[1] = 0;
        [self ResetBoard];
        g_t = 0;
    }
}

@end
