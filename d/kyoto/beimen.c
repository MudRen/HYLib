// Room: d/kyoto/beimen.c
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "��������");
set("long", @LONG
���Ǳ����ţ���Ϊ����ʧ�𣬵����ڳ�ǽ���Ǻں����ģ�������ȥ
������������������ú�����˵����ħ��--֯���ų������ں��ף���˵
�е�����Ҳͬ�ų�һ�����������ú������Ͼ��Ƿ����ľ�������Ϧ����
�ʶ������ڡ�

LONG );
set("exits",  ([
        "south"  : __DIR__"longandao1",
      ]));
        setup();
        replace_program(ROOM);
}