// Room: d/kyoto/juechuan
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��");
set("long", @LONG
���ﱻ�����򴨣���һ����Դ���Ϻ������Ϫ����Ϊ���Ǻ��ṩ��ˮ����
���߾����Ϻ����磬��˵�����ӡ���Ϲ�ʱ�ڿ��µ�������

LONG );
set("exits",  ([
        "east"  : __DIR__"shangheshenshe",
        "west"  : __DIR__"hongqiao",
      ]));
        setup();
        replace_program(ROOM);
}