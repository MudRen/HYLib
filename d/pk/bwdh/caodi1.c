//caodi.c �ݵ� 

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIG"�ݵ�"NOR);
        set("long", @LONG
һƬ�����ĵĲ�ƺ�����ɵ������ˣ��޴���Ϊ���軺��Ũ�̿���������
�������������������ɫһ���£����Ӳ��������أ�����Զ�����ഺ����ӽ
�����졣
LONG
        );
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));

        set("exits", ([
        "west" : __DIR__"huilang1",
        "southeast" : __DIR__"qianting",
        "northeast" : __DIR__"quqiao2",
        "east" : __DIR__"zoulang1",
        ]));
        
        set("no_death",1);set("bwdhpk",1);
        set("outdoors", "�Խ�ɽׯ");

        setup();
}

