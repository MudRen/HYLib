//quqiao.c ����

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIY"����"NOR);
        set("long", @LONG
һ��С�ɾ��Ƶ����ź���ڳ����ϣ�������������һ��Ϊ�����������ˮ
�����峺�����渡��Щʢ����˯����͸��˯���ķ�϶��Լ�ɼ���β��ɫ������
ˮ�����еػ����ζ���Զ����ǽ���µ�һ�԰Ž������Ļ��俪�������֣���
�������ĳ�����������������
LONG
        );
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));

        set("exits", ([
        "west" : __DIR__"jiashan",
        "southwest" : __DIR__"quqiao2",
        "northwest" : __DIR__"quqiao4",
        "east" : __DIR__"huilang4",

        ]));
        
        set("no_death",1);set("bwdhpk",1);
        set("outdoors", "�Խ�ɽׯ");

        setup();
}

