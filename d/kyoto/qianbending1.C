// Room: d/kyoto/qianbending1
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "ǧ���");
set("long", @LONG
�������ǧ����ᴩ���������Ĵ�����Ҳ������Ľ���������
�йݵ����۴��αȡ�������һ���ƹݣ��Ծ��������������������ʿ�й�
��ʿ������������Ϣ�����໥�д���ѧ��
LONG );
set("exits",  ([
        "east"  : __DIR__"qianbending2",
        "west"  : __DIR__"ximen",
        "north"  : __DIR__"jiuguan",
        "south"  : __DIR__"wushixingguan",
      ]));
        setup();
        replace_program(ROOM);
}