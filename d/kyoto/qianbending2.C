// Room: d/kyoto/qianbending2
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "ǧ���");
set("long", @LONG
�������ǧ����ᴩ���������Ĵ�����Ҳ������Ľ���������
�йݵ����۴��αȡ���������������ĳ����ݣ��ǳ��ݵ�Ļ��ͬ��׫�鷢
����ս�ĵط����������糴彣��Ϊ����ά��־ʿͬ��׫�鼤ս��С�
�¸�ʮ�꣬�·������������ཻ������������Ѫ�����͡�
LONG );
set("exits",  ([
        "east"  : __DIR__"qianbending3",
        "west"  : __DIR__"qianbending1",
        "north"  : __DIR__"chitianwu",
        "south"  : __DIR__"xiaoxiang1",
      ]));
        setup();
        replace_program(ROOM);
}