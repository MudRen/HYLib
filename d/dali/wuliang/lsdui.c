// Room: lsdui.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
��Ƭ�̼�ת��ɽ�ֻ꣬��һ�����ʯ֮���������Ŷ�ʮ���ˡ��˴���һ��
��С����������һ�����֮�ϣ��߳����ˡ�
LONG
        );
        set("exits", ([ 
            "southwest" : __DIR__"xiaolu2",
        ]));
        set("objects", ([
                __DIR__"npc/sikong_xuan" : 1, 
        ]));
        set("outdoors", "����");

        setup();
}

