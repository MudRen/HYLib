// Room: /d/heimuya/pingdingzhou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
    set("short", "ƽ����");
    set("long", @LONG
ƽ�����ںӱ����ڣ��ݸ����󣬵��ش�Ҫ�壬ʮ����Ҫ��
�������ǵĿ��̴���Ƶ��������������½�ͽ���ֱײ������
ץ�ˣ�����ھ��ܣ�ȴ˿��û���ٸ��������
LONG );

    set("exits", ([
        "east" : __DIR__"road3",
        "south" : "/d/taiyuan/nroad3",	
        "west" : __DIR__"road2",
    ]));
    set("outdoors", "heimuya");
    set("objects",([
            "quest/menpaijob/riyue/zhike" : 1,
            "d/heimuya/npc/dizi" : 3,
        ]));


    setup();
}
void init()
{
        add_action("do_quit","quit");
        add_action("do_quit","halt");
        add_action("do_quit","learn"); 
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","persuade");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
        add_action("do_quit","study");
        add_action("do_quit","yandu");        
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
}


int valid_leave(object me, string dir)
{
        if (me->is_fighting()) 
        return notify_fail("���������������!\n");
        if (me->is_busy()) 
        return notify_fail("������������!\n");

        if (me->query_temp("in_guard") &&
                objectp(present("riyue hufa", environment(me))))
           return notify_fail("���»�����ס��˵��ֵ��ʱ��δ������������ְ�ء�\n");

        me->delete_temp("in_guard"); 
        me->delete("guardry");
        remove_call_out("clone_meng");

        return ::valid_leave(me, dir);
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"�����ĵ��ػ���\n");
        return 1;
}
