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
        "west" : __DIR__"road2",
    ]));
    set("outdoors", "heimuya");
    set("objects",([
            "quest/menpaijob/riyue/zhike" : 1,
            "d/heimuya/npc/dizi" : 3,
        ]));


    setup();
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("in_guard") &&
                objectp(present("riyue hufa", environment(me))))
           return notify_fail("���»�����ס��˵��ֵ��ʱ��δ������������ְ�ء�\n");

        me->delete_temp("in_guard"); 
        me->delete("guard");
        remove_call_out("clone_meng");

        return ::valid_leave(me, dir);
}
