 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","�齫��");
  set("long",@LONG
һ���ţ�һ�����Ŵ�������������ŮЦ��ӭ�����������������λ�ϣ���������
�´��¹Һã���ϸ�ĵĹ۲�����Χ���������ɰ���ǽ�Ϲ��ż����黭����Ȼ�㿴����
��˭����Ʒ�����϶��ǳ�������֮�֡�����һ�����Σ����ζ��Ǻ�̴ľ���ƣ�������
���Ϸֱ����Ż�����������������֮Ƥ���ٿ����Ѿ��ںõ��ķ�Χ�ǣ��㿴���Ǹ���
���������������ƣ�����ĸ�ɫͼ�궼���Ա�ʯ��Ƕ��������һ��С��д����������
���������㾪��֮�ʣ��ղ�����Ů�Ѿ����ϲ�ˮ���ģ����ʴ�ҵ������Կ�ʼ����
��ϸ�Ĺ����뿴���������������䣩���齫ָ�ϣ�����룩��
LONG
  );
  set("exits",([
         "east" : __DIR__"mjgate",
               ]));
set("no_fight",1);
        set("objects", ([
//            __DIR__"npc/jiaoqi" : 1,
//            __DIR__"npc/east" : 1,
//            __DIR__"npc/west" : 1,
//            __DIR__"npc/south" : 1, 
            __DIR__"npc/mj" : 1,                                        
       ]) );
        set("item_desc",([
"board":"
                       ��  ��  ��  ��
            setmj ���õ����Զ�����  ������������ʽ������
--------------------------------------------------------------------
����1: setmj pon 1w        �趨���Զ���1w �����˴��һ��ʱ���Զ���һ��
       setmj gon 1w                                         �Զ�  һ��
       setmj tin 1w                                         �Զ���һ��
����2: setmj show ����        �趨Ϊֻ��ʾ���롣
       setmj show color �趨Ϊ��ɫ��ʾ��
����3: setmj tin none        ȡ�����Զ������趨��
       setmj gon none
       setmj pon none
����4: setmj auto tin        �趨�Զ����ơ�
--------------------------------------------------------------------
",
"book":"
      ָ  ��         ��          ��                ˵    ��
    ������������������������������������������������������������������
    �� look  l mj��.���Լ���,l 1p��.1�����1����                ��
    ��       l all��..��ȫ��,l end������l dump��      ����      ��
    �� mo    ���������Ͱ������������ƣ���������      ����      ��
    �� dump         dump <����>��                     ����     ��
    �� eat          eat <����1> <����2>��             ����     ��
    ��addin  �����ž�   pon    ����    hu  ����  start �ƾֿ�ʼ  ��
    �� gon          gon �� gon <����>(������)��       ����      ��
    �� setmj        help setmj��                     �趨����  ��
    �� restart   restart �� restart mj��             ���¿�ʼ  ��
    �� continue     ��NPC����ҳ��ƣ��������ʱ�ر����á�         ��
    �� top   top aip,top -p,top -w,top -h,top -d              ��
    ��       top -l��ȫ��,-lw,-lh,-ld��               ������    ��
    ��������������������������������������������������������������������
",
]));       
        set("coor/x",10);
        set("coor/y",1910);
        set("coor/z",0);
    set("no_magic",1);
    set("no_cast",1);
    set("no_usemark",1);
    set("no_usemark1",1);
    set("no_usemark2",1);
    set("no_fight",1);
    set("NONPC",1);
    set("no_spells",1);
    setup(); 
} 
void init()
{
    object *ob,me;
    int i;
    me=this_player();
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) 
        {
            if( !interactive(ob[i]) || ob[i]==me ) continue;
                if(query_ip_number(ob[i]) == query_ip_number(me))
            return notify_fail("������ѽ�����Ѿ��и����������ˡ�\n");   
    }   
    add_action("do_give", "give");
    add_action("do_leave", "leave");
} 
int valid_leave(object me, string dir)
{       object room;
        room=this_object();
        
        if(userp(me) && me->query_temp("playing_mj") && dir="east")
                return notify_fail("�ľ����ڽ����У���������߶���\n");         
        return 1;
} 
int do_give()
{
    if(userp(this_player()))
    write("���ﲻ��ת��ʲô��Ʒ��\n");
    return 1;
}
 
int do_leave()
{
    if(interactive(this_player()) && this_player()->query_temp("playing_mj"))
    {
    this_player()->delete_temp("playing_mj");
    tell_room(environment(),this_player()->name()+"�������ˡ�\n");
    }
    return 1;
}       
