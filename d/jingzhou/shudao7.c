// Room: /d/chengdu/shudao6
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "ջ��" NOR );
        set("long", @LONG
����ѣ����������죬�غ����޹�������д��·�����������
ν�����ޱȣ�һ�������ϵĽ�ˮ��һ�����絶�а���ͱڣ���������
·���ߣ�ֻ���ͱ�����һЩʯ�ѣ������ʵǶ��ϣ��򶫣�ȴ��ҡҡ��
�ε�ջ���� 
LONG
        );
        set("exits", ([
  "east" :  __DIR__"shudao6",
  "up" : __DIR__"shudao8",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

