//      shanmen.c ѩɽ��ɽ��
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","ѩɽ��ɽ��");
        set("long",@LONG
�����Ǵ����µ�ɽ�ţ���ǰ�����ﲻ���Ľ��㳯ʥ��
��ͽ���е�����������˿�����ϵĲ�˿��ɽ��(gate)ǰվ
�˸��ֳַ����ĸ��ײ���ά�����򣬶�����һ����ʯ����
�ɵ�ɽ·��
LONG );
        set("outdoors","xueshan");
        set("exits",([
"westup"    : __DIR__"xuelu1",
                "north"    : __DIR__"guangchang",
                "eastdown" : "/d/xuedao/nroad4",
        ]));
        set("item_desc",([
                "gate" : "���Ⱥ���ͭɫ���ţ��Ǻ�����֮�����������ƶ��ġ�\n",
        ]));
        set("objects",([
                "/clone/misc/dache" : 1 ,
                CLASS_D("xueshan")+"/ka": 1,
                "/d/wudang/npc/guest": 2,
                __DIR__"npc/sengbing": 2,
                __DIR__"npc/wang": 1,
                __DIR__"npc/oldman": 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "ѩɽ��") && dir == "north" &&
                objectp(present("seng bing", environment(me))))
           return notify_fail("����ɮ������ס��˵����׼����ʲ�ṩ�����Ƿ�үѽ��\n");

        return ::valid_leave(me, dir);
}

