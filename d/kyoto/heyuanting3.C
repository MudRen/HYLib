// Room: d/kyoto/heyuanting3.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��ԭ�");
set("long", @LONG
������������ĺ�Դ�������͵������еĵط���������Ǻպ�����
�����ε������������˾�ͨ���¸�����ѧ�����µ�����ǧ���б��������궼
Ͷ������ϰ�䣬ϣ���г�һ�ճ�Ϊ��ѧ̩����
LONG );
set("exits",  ([
        "north"  : __DIR__"yuzhidaochang",
        "west"  : __DIR__"heyuanting2",
      ]));
        setup();
        replace_program(ROOM);
}