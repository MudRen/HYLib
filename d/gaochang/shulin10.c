// Room: /d/gaochang/shulin10.c

inherit ROOM;




void create()
{
        set("short", "�߲��Թ�");
        set("long", @LONG
������������ĳ���,��ǰ���������������
�Թ�֮�ڲ����㼣ָ�����㲻֪��Ҫ������·�ߡ�
����ϸ���������ף����׺�ǰ������·�϶��е������㼣��
���ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
        );

        set("exits", ([
                "east" : __DIR__"shulin"+(random(8)+6),
                "south" : __DIR__"shulin"+(random(8)+6),
                "west" : __DIR__"shulin"+(random(8)+6),
                "north" : __DIR__"shulin"+(random(8)+6),
        ]));
        set("no_acc_drop",1);
        set("outdoors", "gaochang");
        set("objects",([
         __DIR__"npc/wuaer" : 1,       
         __DIR__"npc/ghost" : 3,
        ]));
        setup();
        replace_program(ROOM);
}



