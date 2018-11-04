// Room: /d/xiangyang/conglin4.c
// by dubei
#include <ansi.h>
inherit ROOM;

string xiaowu(object);
string shanlu(object);
 

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ɽ´(shanlu)�ϵ�һ��յأ�·�Ե��Ӳݺ���ľ����
�������ˡ�·����һ������ľ�����С�ݣ�С��(xiaowu)���ſ�
��һЩ��������Ϣ��һЩ��������������·�Ե����ϡ�
LONG	);
	set("exits", ([  
        "eastdown" : __DIR__"conglin3",
          
        ]));
    set("item_desc", ([
                "xiaowu" : (: xiaowu :),
               "shanlu" : (: shanlu :),
    ]));
        set("objects",([
              __DIR__"npc/shijiqiang" : 1,
              __DIR__"npc/shibowei" : 1,
              __DIR__"npc/shimengjie" : 1,
              __DIR__"npc/shishugang" : 1,
              __DIR__"npc/shizhongmeng" : 1,
        ]));      
	 
        set("outdoors", "xiangyang");
	setup();
}
 
string xiaowu(object me)
{
            me = this_player();
            if(!me->query_temp("make/xtj_look1")){
            return "һ����ͨ��Сľ�ݡ�\n";
            }
            me->set_temp("make/xtj_enter",1);
            return "һ����ͨ��Сľ�ݣ����Ű����ţ������ƺ��ѻ���һЩ���\n";
}
string shanlu(object me)
{
            me = this_player();
            if (!me->query_temp("make/xtj_look1")){
            return "һ�����ʵ�ɽ´��\n";
            }
            me->set_temp("make/xtj_shan",1);
          return "һ�����ʵ�ɽ´�����ƺ��о��������ƺ���Щʲ�ᡣ\n";
}
void init()
{
    object ob = this_player();

    if(!userp(ob)) return;

 
    if(interactive(ob) && (int)ob->query_skill("force") > 100
    && random(20) < 5){
    write("���Ȼ���������ɽ��������������\n",this_player());
    ob->set_temp("make/xtj_look1",1);
        }
 
    add_action("do_enter", "enter");
    add_action("do_enter", "jin");
    add_action("do_climb", "climb");
}
int do_enter(string arg)
{
    object me=this_player(); 
       if (!me->query_temp("make/xtj_enter"))
       return 0;
      
    if((!arg) || (arg != "muwu"))
        return notify_fail("��Ҫ�����\n");
     message_vision("$N�����ƿ��ţ��߽���ľ�ݡ�\n", me);
    me->delete_temp("make/xtj_enter");
       me->move(__DIR__"muwu");
    message("vision", me->name() + "�������˽�����\n", environment(me), ({me}) );
    return 1;
}
int do_climb(string arg)
{
    object me=this_player(); 
    if (!me->query_temp("make/xtj_shan"))
    return 0;
    if((!arg) || (arg != "shanlu"))
    return notify_fail("������������\n");
    me->delete_temp("make/xtj_shan");
    message_vision("$N΢΢���������������ɽ´��ȥ��\n", me);
    me->move(__DIR__"linhai1");
    message("vision", me->name() + "����������������\n", environment(me), ({me}) );
    return 1;
}

