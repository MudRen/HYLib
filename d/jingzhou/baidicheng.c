// Room: /d/chengdu/baidicheng
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "�׵۳�" NOR );
        set("long", @LONG
���ǰ׵۲��Ƽ䣬ǧ�ｭ��һ�ջ�������Գ���䲻ס��ǧ���Թ�����ɽ��
������������İ׵۳��ˣ�ң�����ܣ�ֻ����ɽ��ˮ��һƬ��÷羰������
����������������һ���˵���ƾ�����ţ��ĳ���ӿ������������
LONG
        );
        set("exits", ([
  "southdown" :  __DIR__"shudao10",
	"east" : __DIR__"shudao9",
  "north": "/d/jiangling/baidicheng",	
   ]));
        set("no_fight",1);

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

