// Room: xiaoting.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
һ�����µ�С�������ϵ���һ�Ծ��򣬶��������ķ������������÷����
�գ�����˳��ȴ�ҳ�������÷�գ������ϵĴ����ﶬ����ҳ��˶��Ĵ����
���˼����˱��Ǹ����ˡ�
LONG
        );
        set("exits", ([
            "east" : __DIR__"guzhong",           
        ]));

        set("objects", ([
            __DIR__"npc/zhong_ling" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
