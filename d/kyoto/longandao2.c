// Room: d/kyoto/longandao2.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "������");
set("long", @LONG
�������������Ǿ����Ǳ��Ľ�ͨҪ�壬���������ò��������˵���
�����¶�������������������£��Ǿ����������������и�ɮ�Ƽ���
�����п���ʹ�������������ǰ����ɮ�Դ���ˮ�����Ǵ�˵������Ҳ��
���ٻ���������а��֮ͽ���þͻ�����˼䡣
LONG );
set("exits",  ([
        "north"  : __DIR__"longandao1",
        "west"  : __DIR__"longangate",
        "south"  : __DIR__"longandao3",
      ]));
        setup();
        replace_program(ROOM);
}