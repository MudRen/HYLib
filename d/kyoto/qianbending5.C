// Room: d/kyoto/qianbending5
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "ǧ���");
set("long", @LONG
�������ǧ����ᴩ���������Ĵ�����Ҳ������Ľ���������
�йݵ����۴��αȡ�������һ����Ժ�������������洫����������������
Ȼߴ����������������������ֺ���βҩ�̣��ϰ���β��һ����������
��������������

LONG );
set("exits",  ([
        "east"  : __DIR__"qianbending6",
        "west"  : __DIR__"qianbending4",
        "south"  : __DIR__"shanggeshuyuan",
        "north"  : __DIR__"tengweiyaoshe",
      ]));
        setup();
        replace_program(ROOM);
}