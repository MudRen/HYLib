// Room: d/kyoto/heyuanting1.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��ԭ�");
set("long", @LONG
������������ĺ�Դ�������͵������еĵط���������Ǻպ�����
�����Ժ���������������ɮ������ʿ�ж��������ġ����ղ�Ϣ��������ʿ
�������ﲻ���������ó��������ĵİ�����
LONG );
set("exits",  ([
        "west"  : __DIR__"heyuan1",
        "north"  : __DIR__"shenguangyuan",
        "east"  : __DIR__"heyuanting2",
      ]));
        setup();
        replace_program(ROOM);
}