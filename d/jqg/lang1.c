//changlang1.c ����
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short",HIY"����"NOR);
            set("long",@LONG
�������ľ��ĳ��ȣ����߾����ź�ɫ�񻨷����������԰�ɫ�ķ�ǽ���Ե�
ʮ�����š������ǹ��ڳ������µ�ˮ�����ᣬ��΢����ḧ֮�£�����һ����
ϸ���ö���������������˼�׷ɡ����ȱ�ͨ��԰����ͨ����á�
LONG
    );

            set("exits",([
               "north": __DIR__"huayuan",
               "south": __DIR__"houtang",
               "east": __DIR__"lang2",
               "west": __DIR__"lang4",
            ]));
             
	    setup();
            replace_program(ROOM);
}
